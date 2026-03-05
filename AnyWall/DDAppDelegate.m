//
//  PAWAppDelegate.m
//  DoneDid
//
//  Created by Christopher Bowns on 1/30/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

static NSString * const defaultsFilterDistanceKey = @"filterDistance";
static NSString * const defaultsLocationKey = @"currentLocation";

#import "SirqulNetworkInterface.h"

#import "DDAppDelegate.h"

#import <Parse/Parse.h>

#import "DDWelcomeViewController.h"
#import "DDWallViewController.h"

@interface DDAppDelegate ()


@end

@implementation DDAppDelegate

@synthesize window = _window;
@synthesize viewController = _viewController;
@synthesize filterDistance;
@synthesize currentLocation;


#pragma mark - UIApplicationDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
	
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
	
	// Grab values from NSUserDefaults:
	NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
	
	// Set the global tint on the navigation bar
	[[UINavigationBar appearance] setTintColor:[UIColor colorWithRed:200.0f/255.0f green:83.0f/255.0f blue:70.0f/255.0f alpha:1.0f]];
//	[[UINavigationBar appearance] setBackgroundImage:[UIImage imageNamed:@"bar.png"] forBarMetrics:UIBarMetricsDefault];
	
	// Desired search radius:
	if ([userDefaults doubleForKey:defaultsFilterDistanceKey]) {
		// use the ivar instead of self.accuracy to avoid an unnecessary write to NAND on launch.
		filterDistance = [userDefaults doubleForKey:defaultsFilterDistanceKey];
	} else {
		// if we have no accuracy in defaults, set it to 1000 feet.
		self.filterDistance = 1000 * kPAWFeetToMeters;
	}

	UINavigationController *navController = nil;

	if ([userDefaults boolForKey:@"loggedIn"] == YES) {
		// Skip straight to the main view.
		DDWallViewController *wallViewController = [[DDWallViewController alloc] initWithNibName:nil bundle:nil];
		navController = [[UINavigationController alloc] initWithRootViewController:wallViewController];
		navController.navigationBarHidden = NO;
		self.viewController = navController;
		self.window.rootViewController = self.viewController;
	} else {
		// Go to the welcome screen and have them log in or create an account.
		[self presentWelcomeViewController];
	}

	SirqulNetworkInterface *interface = [[SirqulNetworkInterface alloc]initWithDelegate:self andAppKey:sirqulAppKey andPrivateKey:sirqulPrivateKey];
	[interface quickAnalyticWithAccountId:[[NSUserDefaults standardUserDefaults]objectForKey:@"accountId"] andTag:@"AppLaunched" andCustomId:nil andLocation:nil andErrorMessage:nil];
	
    [self.window makeKeyAndVisible];
    return YES;
}


#pragma mark - PAWAppDelegate

- (void)setFilterDistance:(CLLocationAccuracy)aFilterDistance {
	filterDistance = aFilterDistance;

	NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
	[userDefaults setDouble:filterDistance forKey:defaultsFilterDistanceKey];
	[userDefaults synchronize];

	// Notify the app of the filterDistance change:
	NSDictionary *userInfo = [NSDictionary dictionaryWithObject:[NSNumber numberWithDouble:filterDistance] forKey:kPAWFilterDistanceKey];
	dispatch_async(dispatch_get_main_queue(), ^{
		[[NSNotificationCenter defaultCenter] postNotificationName:kPAWFilterDistanceChangeNotification object:nil userInfo:userInfo];
	});
}

- (void)setCurrentLocation:(CLLocation *)aCurrentLocation {
	currentLocation = aCurrentLocation;

	// Notify the app of the location change:
	NSDictionary *userInfo = [NSDictionary dictionaryWithObject:currentLocation forKey:kPAWLocationKey];
	dispatch_async(dispatch_get_main_queue(), ^{
		[[NSNotificationCenter defaultCenter] postNotificationName:kPAWLocationChangeNotification object:nil userInfo:userInfo];
	});
}

- (void)presentWelcomeViewController {
	// Go to the welcome screen and have them log in or create an account.
	DDWelcomeViewController *welcomeViewController = [[DDWelcomeViewController alloc] initWithNibName:@"DDWelcomeViewController" bundle:nil];
	welcomeViewController.title = @"Welcome to DoneDid";
	
	UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:welcomeViewController];
	navController.navigationBarHidden = YES;

	self.viewController = navController;
	self.window.rootViewController = self.viewController;
}

@end
