//
//  PAWViewController.m
//  DoneDid
//
//  Created by Christopher Bowns on 1/30/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import "DDWelcomeViewController.h"

#import "DDWallViewController.h"
#import "DDLoginViewController.h"
#import "DDNewUserViewController.h"

@implementation DDWelcomeViewController

-(void)viewDidLoad{
	[super viewDidLoad];
	if ([self respondsToSelector:@selector(edgesForExtendedLayout)])
        self.edgesForExtendedLayout = UIRectEdgeNone;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - Transition methods

- (IBAction)loginButtonSelected:(id)sender {
	DDLoginViewController *loginViewController = [[DDLoginViewController alloc] initWithNibName:nil bundle:nil];
	[self.navigationController presentViewController:loginViewController animated:YES completion:^{}];
}

- (IBAction)createButtonSelected:(id)sender {
	DDNewUserViewController *newUserViewController = [[DDNewUserViewController alloc] initWithNibName:nil bundle:nil];
	[self.navigationController presentViewController:newUserViewController animated:YES completion:^{}];
}

- (IBAction)gotoSirqul:(id)sender {
	UIApplication *ourApplication = [UIApplication sharedApplication];
    NSURL *url = [NSURL URLWithString:@"https://www.sirqul.com/"];
    [ourApplication openURL:url];
}

#pragma mark - View lifecycle

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

@end
