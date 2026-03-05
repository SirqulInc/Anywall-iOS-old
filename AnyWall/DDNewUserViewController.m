//
//  PAWNewUserViewController.m
//  Anywall
//
//  Created by Christopher Bowns on 2/1/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import "DDNewUserViewController.h"

#import <Parse/Parse.h>
#import "DDWallViewController.h"
#import "DDConstants.h"

@interface DDNewUserViewController ()

- (void)processFieldEntries;
- (void)textInputChanged:(NSNotification *)note;
- (BOOL)shouldEnableDoneButton;

@end

@implementation DDNewUserViewController

@synthesize doneButton;
@synthesize usernameField;
@synthesize passwordField, passwordAgainField;


#pragma mark - UIViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	if ([self respondsToSelector:@selector(edgesForExtendedLayout)])
        self.edgesForExtendedLayout = UIRectEdgeNone;
	
    // Do any additional setup after loading the view from its nib.
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textInputChanged:) name:UITextFieldTextDidChangeNotification object:usernameField];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textInputChanged:) name:UITextFieldTextDidChangeNotification object:passwordField];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textInputChanged:) name:UITextFieldTextDidChangeNotification object:passwordAgainField];

	doneButton.enabled = NO;
}

- (void)viewWillAppear:(BOOL)animated {
	[usernameField becomeFirstResponder];
	[super viewWillAppear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)dealloc {
	[[NSNotificationCenter defaultCenter] removeObserver:self name:UITextFieldTextDidChangeNotification object:usernameField];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:UITextFieldTextDidChangeNotification object:passwordField];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:UITextFieldTextDidChangeNotification object:passwordAgainField];
}


#pragma mark - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
	if (textField == usernameField) {
		[passwordField becomeFirstResponder];
	}
	if (textField == passwordField) {
		[passwordAgainField becomeFirstResponder];
	}
	if (textField == passwordAgainField) {
		[passwordAgainField resignFirstResponder];
		[self processFieldEntries];
	}

	return YES;
}

#pragma mark - ()

- (BOOL)shouldEnableDoneButton {
	BOOL enableDoneButton = NO;
	if (usernameField.text != nil &&
		usernameField.text.length > 0 &&
		passwordField.text != nil &&
		passwordField.text.length > 0 &&
		passwordAgainField.text != nil &&
		passwordAgainField.text.length > 0) {
		enableDoneButton = YES;
	}
	return enableDoneButton;
}

- (void)textInputChanged:(NSNotification *)note {
	doneButton.enabled = [self shouldEnableDoneButton];
}

- (IBAction)cancel:(id)sender {
	[self.presentingViewController dismissModalViewControllerAnimated:YES];
}

- (IBAction)done:(id)sender {
	[usernameField resignFirstResponder];
	[passwordField resignFirstResponder];
	[passwordAgainField resignFirstResponder];
	[self processFieldEntries];
}

- (void)processFieldEntries {
	// Check that we have a non-zero username and passwords.
	// Compare password and passwordAgain for equality
	// Throw up a dialog that tells them what they did wrong if they did it wrong.

	NSString *username = usernameField.text;
	NSString *password = passwordField.text;
	NSString *passwordAgain = passwordAgainField.text;
	NSString *errorText = @"Please ";
	NSString *usernameBlankText = @"enter a username";
	NSString *passwordBlankText = @"enter a password";
	NSString *joinText = @", and ";
	NSString *passwordMismatchText = @"enter the same password twice";

	BOOL textError = NO;

	// Messaging nil will return 0, so these checks implicitly check for nil text.
	if (username.length == 0 || password.length == 0 || passwordAgain.length == 0) {
		textError = YES;

		// Set up the keyboard for the first field missing input:
		if (passwordAgain.length == 0) {
			[passwordAgainField becomeFirstResponder];
		}
		if (password.length == 0) {
			[passwordField becomeFirstResponder];
		}
		if (username.length == 0) {
			[usernameField becomeFirstResponder];
		}

		if (username.length == 0) {
			errorText = [errorText stringByAppendingString:usernameBlankText];
		}

		if (password.length == 0 || passwordAgain.length == 0) {
			if (username.length == 0) { // We need some joining text in the error:
				errorText = [errorText stringByAppendingString:joinText];
			}
			errorText = [errorText stringByAppendingString:passwordBlankText];
		}
	} else if ([password compare:passwordAgain] != NSOrderedSame) {
		// We have non-zero strings.
		// Check for equal password strings.
		textError = YES;
		errorText = [errorText stringByAppendingString:passwordMismatchText];
		[passwordField becomeFirstResponder];
	}

	if (textError) {
		UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:errorText message:nil delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil];
		[alertView show];
		return;
	}

	// Everything looks good; try to log in.
	// Disable the done button for now.
	doneButton.enabled = NO;
	activityView = [[DDActivityView alloc] initWithFrame:CGRectMake(0.f, 0.f, self.view.frame.size.width, self.view.frame.size.height)];
	UILabel *label = activityView.label;
	label.text = @"Signing You Up";
	label.font = [UIFont boldSystemFontOfSize:20.f];
	[activityView.activityIndicator startAnimating];
	[activityView layoutSubviews];

	[self.view addSubview:activityView];

	//Sirqul Implementation - Create an instance of SirqulNetworkInterface and use the quickSignUp method.
	//Reponse will appear in the callback methods below.
	
	SirqulNetworkInterface *interface = [[SirqulNetworkInterface alloc]initWithDelegate:self andAppKey:sirqulAppKey andPrivateKey:sirqulPrivateKey];
	[interface setStatus:kSirqulStatusSignUp];
	[interface quickSignUpWithName:username andEmail:username andPassword:password];
}

#pragma mark - SirqulSDK Methods

-(void)networkRequestDidSucceed:(NSDictionary *)jsonData withInterface:(SirqulNetworkInterface *)sni{
	if ([SNIHelper checkIfValid:jsonData]) {
		if (sni.status == kSirqulStatusSignUp) {
			SirqulNetworkInterface *interface = [[SirqulNetworkInterface alloc]initWithDelegate:self andAppKey:sirqulAppKey andPrivateKey:sirqulPrivateKey];
			[interface setStatus:kSirqulStatusLogin];
			[interface loginWithUsername:usernameField.text andPassword:passwordField.text andLocation:nil andReturnProfile:nil andResponseFilters:nil];
		}else if (sni.status == kSirqulStatusLogin) {
			if ([SNIHelper checkDictionary:jsonData objectForKey:@"account"]) {
				NSDictionary *account = [jsonData objectForKey:@"account"];
				if ([SNIHelper checkDictionary:account objectForKey:@"accountId"]) {
					[[NSUserDefaults standardUserDefaults]setObject:[account objectForKey:@"accountId"] forKey:@"accountId"];
				}
			}
			[[NSUserDefaults standardUserDefaults]setBool:YES forKey:@"loggedIn"];
			[[NSUserDefaults standardUserDefaults]synchronize];

			// Success!
			[activityView.activityIndicator stopAnimating];
			[activityView removeFromSuperview];
			
			DDWallViewController *wallViewController = [[DDWallViewController alloc] initWithNibName:nil bundle:nil];
			[(UINavigationController *)self.presentingViewController pushViewController:wallViewController animated:NO];
			[self.presentingViewController dismissModalViewControllerAnimated:YES];
		}
	}else{
		UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:[jsonData objectForKey:@"message"] delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil];
		[alertView show];
		doneButton.enabled = [self shouldEnableDoneButton];
		[activityView.activityIndicator stopAnimating];
		[activityView removeFromSuperview];
		// Bring the keyboard back up, because they'll probably need to change something.
		[usernameField becomeFirstResponder];
	}
}

-(void)networkRequest:(SirqulNetworkInterface *)sni didFailWithError:(NSError *)error{
	if (sni.status == kSirqulStatusSignUp) {
		UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:error.description message:nil delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil];
		[alertView show];
		doneButton.enabled = [self shouldEnableDoneButton];
		[activityView.activityIndicator stopAnimating];
		[activityView removeFromSuperview];
		// Bring the keyboard back up, because they'll probably need to change something.
		[usernameField becomeFirstResponder];
	}
}

@end
