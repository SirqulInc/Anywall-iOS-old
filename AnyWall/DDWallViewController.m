//
//  PAWWallViewController.m
//  Anywall
//
//  Created by Christopher Bowns on 1/30/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import "DDWallViewController.h"

#import "DDSettingsViewController.h"
#import "DDWallPostCreateViewController.h"
#import "DDAppDelegate.h"
#import "DDWallPostsTableViewController.h"
#import "DDSearchRadius.h"
#import "DDCircleView.h"
#import "DDPost.h"
#import <CoreLocation/CoreLocation.h>

// private methods and properties
@interface DDWallViewController ()

@property (nonatomic, strong) CLLocationManager *_locationManager;
@property (nonatomic, strong) DDSearchRadius *searchRadius;
@property (nonatomic, strong) DDCircleView *circleView;
@property (nonatomic, strong) NSMutableArray *annotations;
@property (nonatomic, copy) NSString *className;
@property (nonatomic, strong) DDWallPostsTableViewController *wallPostsTableViewController;
@property (nonatomic, assign) BOOL mapPinsPlaced;
@property (nonatomic, assign) BOOL mapPannedSinceLocationUpdate;

// posts:
@property (nonatomic, strong) NSMutableArray *allPosts;

- (void)startStandardUpdates;

// CLLocationManagerDelegate methods:
- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation;

- (void)locationManager:(CLLocationManager *)manager
       didFailWithError:(NSError *)error;

- (IBAction)settingsButtonSelected:(id)sender;
- (IBAction)postButtonSelected:(id)sender;
- (void)queryForAllPostsNearLocation:(CLLocation *)currentLocation withNearbyDistance:(CLLocationAccuracy)nearbyDistance;
- (void)updatePostsForLocation:(CLLocation *)location withNearbyDistance:(CLLocationAccuracy) filterDistance;

// NSNotification callbacks
- (void)distanceFilterDidChange:(NSNotification *)note;
- (void)locationDidChange:(NSNotification *)note;
- (void)postWasCreated:(NSNotification *)note;

@end

@implementation DDWallViewController

@synthesize mapView;
@synthesize _locationManager = locationManager;
@synthesize searchRadius;
@synthesize circleView;
@synthesize annotations;
@synthesize className;
@synthesize wallPostsTableViewController;
@synthesize wallTableView;
@synthesize allPosts;
@synthesize mapPinsPlaced;
@synthesize mapPannedSinceLocationUpdate;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.title = @"Anywall";
		self.className = kPAWParsePostsClassKey;
		annotations = [[NSMutableArray alloc] initWithCapacity:10];
		allPosts = [[NSMutableArray alloc] initWithCapacity:10];
	}
	return self;
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
	
	if ([self respondsToSelector:@selector(edgesForExtendedLayout)])
        self.edgesForExtendedLayout = UIRectEdgeNone;

	// Add the wall posts tableview as a subview with view containment (new in iOS 5.0):
//	self.wallPostsTableViewController = [[DDWallPostsTableViewController alloc] initWithStyle:UITableViewStylePlain];
//	[self addChildViewController:self.wallPostsTableViewController];
//
//	self.wallPostsTableViewController.view.frame = CGRectMake(6.0f, 215.0f, 308.0f, self.view.bounds.size.height - 215.0f);
//	[self.view addSubview:self.wallPostsTableViewController.view];
	[wallTableView setBackgroundColor:[UIColor clearColor]];
	[wallTableView setSeparatorStyle:UITableViewCellSeparatorStyleNone];
	[wallTableView setDelegate:self];
	[wallTableView setDataSource:self];

	refreshControl = [[UIRefreshControl alloc]init];
	[refreshControl addTarget:self action:@selector(refreshTable) forControlEvents:UIControlEventValueChanged];
	[wallTableView addSubview:refreshControl];

	// Set our nav bar items.
	[self.navigationController setNavigationBarHidden:NO animated:NO];
	self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]
											  initWithTitle:@"Post" style:UIBarButtonItemStylePlain target:self action:@selector(postButtonSelected:)];
	self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc]
											 initWithTitle:@"Settings" style:UIBarButtonItemStylePlain target:self action:@selector(settingsButtonSelected:)];
	self.navigationItem.titleView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"logo.png"]];
	
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(distanceFilterDidChange:) name:kPAWFilterDistanceChangeNotification object:nil];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(locationDidChange:) name:kPAWLocationChangeNotification object:nil];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(postWasCreated:) name:kPAWPostCreatedNotification object:nil];

	self.mapView.region = MKCoordinateRegionMake(CLLocationCoordinate2DMake(37.332495f, -122.029095f), MKCoordinateSpanMake(0.008516f, 0.021801f));
	self.mapPannedSinceLocationUpdate = NO;
	[self startStandardUpdates];
}

- (void)viewWillAppear:(BOOL)animated {
	if ([locationManager respondsToSelector:@selector(requestWhenInUseAuthorization)]) {
		[locationManager requestWhenInUseAuthorization];
	}
	[locationManager startUpdatingLocation];
	[super viewWillAppear:animated];
}

- (void)viewDidDisappear:(BOOL)animated {
	[locationManager stopUpdatingLocation];
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)dealloc {
	[locationManager stopUpdatingLocation];
	
	[[NSNotificationCenter defaultCenter] removeObserver:self name:kPAWFilterDistanceChangeNotification object:nil];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:kPAWLocationChangeNotification object:nil];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:kPAWPostCreatedNotification object:nil];
	
	self.mapPinsPlaced = NO; // reset this for the next time we show the map.
}

#pragma mark - NSNotificationCenter notification handlers

- (void)distanceFilterDidChange:(NSNotification *)note {
	CLLocationAccuracy filterDistance = [[[note userInfo] objectForKey:kPAWFilterDistanceKey] doubleValue];
	DDAppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];

	if (self.searchRadius == nil) {
		self.searchRadius = [[DDSearchRadius alloc] initWithCoordinate:appDelegate.currentLocation.coordinate radius:appDelegate.filterDistance];
		[mapView addOverlay:self.searchRadius];
	} else {
		self.searchRadius.radius = appDelegate.filterDistance;
	}

	// Update our pins for the new filter distance:
	[self updatePostsForLocation:appDelegate.currentLocation withNearbyDistance:filterDistance];
	
	// If they panned the map since our last location update, don't recenter it.
	if (!self.mapPannedSinceLocationUpdate) {
		// Set the map's region centered on their location at 2x filterDistance
		MKCoordinateRegion newRegion = MKCoordinateRegionMakeWithDistance(appDelegate.currentLocation.coordinate, appDelegate.filterDistance * 2.0f, appDelegate.filterDistance * 2.0f);

		[mapView setRegion:newRegion animated:YES];
		self.mapPannedSinceLocationUpdate = NO;
	} else {
		// Just zoom to the new search radius (or maybe don't even do that?)
		MKCoordinateRegion currentRegion = mapView.region;
		MKCoordinateRegion newRegion = MKCoordinateRegionMakeWithDistance(currentRegion.center, appDelegate.filterDistance * 2.0f, appDelegate.filterDistance * 2.0f);

		BOOL oldMapPannedValue = self.mapPannedSinceLocationUpdate;
		[mapView setRegion:newRegion animated:YES];
		self.mapPannedSinceLocationUpdate = oldMapPannedValue;
	}
}

- (void)locationDidChange:(NSNotification *)note {
	DDAppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];

	// If they panned the map since our last location update, don't recenter it.
	if (!self.mapPannedSinceLocationUpdate) {
		// Set the map's region centered on their new location at 2x filterDistance
		MKCoordinateRegion newRegion = MKCoordinateRegionMakeWithDistance(appDelegate.currentLocation.coordinate, appDelegate.filterDistance * 2.0f, appDelegate.filterDistance * 2.0f);

		BOOL oldMapPannedValue = self.mapPannedSinceLocationUpdate;
		[mapView setRegion:newRegion animated:YES];
		self.mapPannedSinceLocationUpdate = oldMapPannedValue;
	} // else do nothing.

	// If we haven't drawn the search radius on the map, initialize it.
	if (self.searchRadius == nil) {
		self.searchRadius = [[DDSearchRadius alloc] initWithCoordinate:appDelegate.currentLocation.coordinate radius:appDelegate.filterDistance];
		[mapView addOverlay:self.searchRadius];
	} else {
		self.searchRadius.coordinate = appDelegate.currentLocation.coordinate;
	}

	// Update the map with new pins:
	[self queryForAllPostsNearLocation:appDelegate.currentLocation withNearbyDistance:appDelegate.filterDistance];
	// And update the existing pins to reflect any changes in filter distance:
	[self updatePostsForLocation:appDelegate.currentLocation withNearbyDistance:appDelegate.filterDistance];
}

- (void)postWasCreated:(NSNotification *)note {
	DDAppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
	[self queryForAllPostsNearLocation:appDelegate.currentLocation withNearbyDistance:appDelegate.filterDistance];
}

#pragma mark - UINavigationBar-based actions

- (IBAction)settingsButtonSelected:(id)sender {
	DDSettingsViewController *settingsViewController = [[DDSettingsViewController alloc] initWithNibName:nil bundle:nil];
	settingsViewController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
	[self.navigationController presentViewController:settingsViewController animated:YES completion:nil];
}

- (IBAction)postButtonSelected:(id)sender {
	DDWallPostCreateViewController *createPostViewController = [[DDWallPostCreateViewController alloc] initWithNibName:nil bundle:nil];
	[self.navigationController presentViewController:createPostViewController animated:YES completion:nil];
}

#pragma mark - CLLocationManagerDelegate methods and helpers

- (void)startStandardUpdates {
	if (nil == locationManager) {
		locationManager = [[CLLocationManager alloc] init];
	}

	locationManager.delegate = self;
	locationManager.desiredAccuracy = kCLLocationAccuracyBest;

	// Set a movement threshold for new events.
	locationManager.distanceFilter = kCLLocationAccuracyNearestTenMeters;

	[locationManager startUpdatingLocation];

	CLLocation *currentLocation = locationManager.location;
	if (currentLocation) {
		DDAppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
		appDelegate.currentLocation = currentLocation;
	}
}

- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
	NSLog(@"%s", __PRETTY_FUNCTION__);
	switch (status) {
		case kCLAuthorizationStatusAuthorized:
			NSLog(@"kCLAuthorizationStatusAuthorized");
			// Re-enable the post button if it was disabled before.
			self.navigationItem.rightBarButtonItem.enabled = YES;
			[locationManager startUpdatingLocation];
			break;
		case kCLAuthorizationStatusDenied:
			NSLog(@"kCLAuthorizationStatusDenied");
			{{
				UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Anywall can’t access your current location.\n\nTo view nearby posts or create a post at your current location, turn on access for Anywall to your location in the Settings app under Location Services." message:nil delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil];
				[alertView show];
				// Disable the post button.
				self.navigationItem.rightBarButtonItem.enabled = NO;
			}}
			break;
		case kCLAuthorizationStatusNotDetermined:
			NSLog(@"kCLAuthorizationStatusNotDetermined");
			break;
		case kCLAuthorizationStatusRestricted:
			NSLog(@"kCLAuthorizationStatusRestricted");
			break;
	}
}

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation {
	NSLog(@"%s", __PRETTY_FUNCTION__);

	DDAppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
	appDelegate.currentLocation = newLocation;
}

- (void)locationManager:(CLLocationManager *)manager
       didFailWithError:(NSError *)error {
	NSLog(@"%s", __PRETTY_FUNCTION__);
	NSLog(@"Error: %@", [error description]);

	if (error.code == kCLErrorDenied) {
		[locationManager stopUpdatingLocation];
	} else if (error.code == kCLErrorLocationUnknown) {
		// todo: retry?
		// set a timer for five seconds to cycle location, and if it fails again, bail and tell the user.
	} else {
		UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error retrieving location"
		                                                message:[error description]
		                                               delegate:nil
		                                      cancelButtonTitle:nil
		                                      otherButtonTitles:@"Ok", nil];
		[alert show];
	}
}

#pragma mark - MKMapViewDelegate methods

- (MKOverlayView *)mapView:(MKMapView *)mapView viewForOverlay:(id <MKOverlay>)overlay {
	MKOverlayView *result = nil;
	float version = [[[UIDevice currentDevice] systemVersion] floatValue];
	
	// Only display the search radius in iOS 5.1+
	if (version >= 5.1f && [overlay isKindOfClass:[DDSearchRadius class]]) {
		result = [[DDCircleView alloc] initWithSearchRadius:(DDSearchRadius *)overlay];
		[(MKOverlayPathView *)result setFillColor:[[UIColor darkGrayColor] colorWithAlphaComponent:0.2f]];
		[(MKOverlayPathView *)result setStrokeColor:[[UIColor darkGrayColor] colorWithAlphaComponent:0.7f]];
		[(MKOverlayPathView *)result setLineWidth:2.0];
	}
	return result;
}

- (MKAnnotationView *)mapView:(MKMapView *)aMapView viewForAnnotation:(id<MKAnnotation>)annotation {
	// Let the system handle user location annotations.
	if ([annotation isKindOfClass:[MKUserLocation class]]) {
		return nil;
	}

	static NSString *pinIdentifier = @"CustomPinAnnotation";

	// Handle any custom annotations.
	if ([annotation isKindOfClass:[DDPost class]])
	{
		// Try to dequeue an existing pin view first.
		MKPinAnnotationView *pinView = (MKPinAnnotationView*)[aMapView dequeueReusableAnnotationViewWithIdentifier:pinIdentifier];

		if (!pinView)
		{
			// If an existing pin view was not available, create one.
			pinView = [[MKPinAnnotationView alloc] initWithAnnotation:annotation
			                                          reuseIdentifier:pinIdentifier];
		}
		else {
			pinView.annotation = annotation;
		}
		pinView.pinColor = [(DDPost *)annotation pinColor];
		pinView.animatesDrop = [((DDPost *)annotation) animatesDrop];
		pinView.canShowCallout = YES;

		return pinView;
	}

	return nil;
}

- (void)mapView:(MKMapView *)mapView didSelectAnnotationView:(MKAnnotationView *)view {
	id<MKAnnotation> annotation = [view annotation];
	if ([annotation isKindOfClass:[DDPost class]]) {
		DDPost *post = [view annotation];
		[wallPostsTableViewController highlightCellForPost:post];
		[wallTableView selectRowAtIndexPath:[NSIndexPath indexPathForRow:[wallPosts indexOfObject:[self dictionaryForPost:post]] inSection:0] animated:YES scrollPosition:UITableViewScrollPositionMiddle];
	} else if ([annotation isKindOfClass:[MKUserLocation class]]) {
		// Center the map on the user's current location:
		DDAppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
		MKCoordinateRegion newRegion = MKCoordinateRegionMakeWithDistance(appDelegate.currentLocation.coordinate, appDelegate.filterDistance * 2, appDelegate.filterDistance * 2);

		[self.mapView setRegion:newRegion animated:YES];
		self.mapPannedSinceLocationUpdate = NO;
	}
}

- (void)mapView:(MKMapView *)mapView didDeselectAnnotationView:(MKAnnotationView *)view {
	id<MKAnnotation> annotation = [view annotation];
	if ([annotation isKindOfClass:[DDPost class]]) {
		DDPost *post = [view annotation];
//		[wallPostsTableViewController unhighlightCellForPost:post];
		[wallTableView deselectRowAtIndexPath:[NSIndexPath indexPathForRow:[wallPosts indexOfObject:[self dictionaryForPost:post]] inSection:0] animated:YES];
	}
}

- (void)mapView:(MKMapView *)mapView regionWillChangeAnimated:(BOOL)animated {
	self.mapPannedSinceLocationUpdate = YES;
}

#pragma mark - Fetch map pins

- (void)queryForAllPostsNearLocation:(CLLocation *)currentLocation withNearbyDistance:(CLLocationAccuracy)nearbyDistance {
	lastNearbyDistance = nearbyDistance;
	
	if (currentLocation == nil) {
		NSLog(@"%s got a nil location!", __PRETTY_FUNCTION__);
	}

	//Sirqul Implementation - Create an instance of SirqulNetworkInterface and use the searchAlbumsByDistance method.
	//Reponse will appear in the callback methods below.
	NSNumber *accountId =[[NSUserDefaults standardUserDefaults]objectForKey:@"accountId"];
	SirqulNetworkInterface *interface = [[SirqulNetworkInterface alloc]initWithDelegate:self andAppKey:sirqulAppKey andPrivateKey:sirqulPrivateKey];
	[interface setStatus:kSirqulStatusSearchAlbumsByDistance];
	[interface searchAlbumsByDistanceWithAccountId:accountId andOwnerId:nil andQuery:nil andFilters:[NSArray arrayWithObject:@"PUBLIC"] andAlbumTypes:nil andStart:[NSNumber numberWithInteger:0] andLimit:[NSNumber numberWithInteger:100] andDateCreated:0 andLocation:currentLocation andRange:[NSNumber numberWithInteger:50]];
}

// When we update the search filter distance, we need to update our pins' titles to match.
- (void)updatePostsForLocation:(CLLocation *)currentLocation withNearbyDistance:(CLLocationAccuracy) nearbyDistance {
	NSMutableArray *newWallposts = [NSMutableArray array];
	for (DDPost *post in allPosts) {
		CLLocation *objectLocation = [[CLLocation alloc] initWithLatitude:post.coordinate.latitude longitude:post.coordinate.longitude];
		// if this post is outside the filter distance, don't show the regular callout.
		CLLocationDistance distanceFromCurrent = [currentLocation distanceFromLocation:objectLocation];
		if (distanceFromCurrent > nearbyDistance) { // Outside search radius
			[post setTitleAndSubtitleOutsideDistance:YES];
			[mapView viewForAnnotation:post];
			[(MKPinAnnotationView *) [mapView viewForAnnotation:post] setPinColor:post.pinColor];
		} else {
			[newWallposts addObject:[self dictionaryForPost:post]];
			[post setTitleAndSubtitleOutsideDistance:NO]; // Inside search radius
			[mapView viewForAnnotation:post];
			[(MKPinAnnotationView *) [mapView viewForAnnotation:post] setPinColor:post.pinColor];
		}
	}
	wallPosts = [[NSArray alloc]initWithArray:newWallposts];
	[wallTableView reloadData];
}

- (void)refreshTable{
	DDAppDelegate *appDelegate = [[UIApplication sharedApplication]delegate];
	[self queryForAllPostsNearLocation:appDelegate.currentLocation withNearbyDistance:lastNearbyDistance];
}

#pragma mark - SirqulSDK Methods

-(void)networkRequestDidSucceed:(NSDictionary *)jsonData withInterface:(SirqulNetworkInterface *)sni{
	if ([SNIHelper checkIfValid:jsonData]) {
		if (sni.status == kSirqulStatusSearchAlbumsByDistance) {
			allWallposts = [[NSArray alloc]initWithArray:[jsonData objectForKey:@"listResponse"]];
			
			// We need to make new post objects from objects,
			// and update allPosts and the map to reflect this new array.
			// But we don't want to remove all annotations from the mapview blindly,
			// so let's do some work to figure out what's new and what needs removing.
			
			// 1. Find genuinely new posts:
			NSMutableArray *newPosts = [[NSMutableArray alloc] initWithCapacity:kPAWWallPostsSearch];
			// (Cache the objects we make for the search in step 2:)
			NSMutableArray *allNewPosts = [[NSMutableArray alloc] initWithCapacity:kPAWWallPostsSearch];
			
			if ([SNIHelper checkDictionary:jsonData objectForKey:@"listResponse"]) {
				NSArray *listResponse = [jsonData objectForKey:@"listResponse"];
				for (NSDictionary *object in listResponse) {
					DDPost *newPost = [[DDPost alloc]initWithSirqulObject:object];
					if ([SNIHelper checkDictionary:object objectForKey:@"albumId"]) {
						newPost.objectId = [[object objectForKey:@"albumId"]integerValue];
					}
					[allNewPosts addObject:newPost];
					BOOL found = NO;
					for (DDPost *currentPost in allPosts) {
						if ([newPost equalToPost:currentPost]) {
							found = YES;
						}
					}
					if (!found) {
						[newPosts addObject:newPost];
					}
				}
			}
			// newPosts now contains our new objects.
			
			// 2. Find posts in allPosts that didn't make the cut.
			NSMutableArray *postsToRemove = [[NSMutableArray alloc] initWithCapacity:kPAWWallPostsSearch];
			for (DDPost *currentPost in allPosts) {
				BOOL found = NO;
				// Use our object cache from the first loop to save some work.
				for (DDPost *allNewPost in allNewPosts) {
					if ([currentPost equalToPost:allNewPost]) {
						found = YES;
					}
				}
				if (!found) {
					[postsToRemove addObject:currentPost];
				}
			}
			// postsToRemove has objects that didn't come in with our new results.
			
			// 3. Configure our new posts; these are about to go onto the map.
			DDAppDelegate *appDelegate = [[UIApplication sharedApplication]delegate];
			for (DDPost *newPost in newPosts) {
				CLLocation *objectLocation = [[CLLocation alloc] initWithLatitude:newPost.coordinate.latitude longitude:newPost.coordinate.longitude];
				// if this post is outside the filter distance, don't show the regular callout.
				CLLocationDistance distanceFromCurrent = [appDelegate.currentLocation distanceFromLocation:objectLocation];
				[newPost setTitleAndSubtitleOutsideDistance:( distanceFromCurrent > lastNearbyDistance ? YES : NO )];
				// Animate all pins after the initial load:
				newPost.animatesDrop = mapPinsPlaced;
			}
			
			// At this point, newAllPosts contains a new list of post objects.
			// We should add everything in newPosts to the map, remove everything in postsToRemove,
			// and add newPosts to allPosts.
			[mapView removeAnnotations:postsToRemove];
			[mapView addAnnotations:newPosts];
			[allPosts addObjectsFromArray:newPosts];
			[allPosts removeObjectsInArray:postsToRemove];
			
			self.mapPinsPlaced = YES;
			
			[self updatePostsForLocation:appDelegate.currentLocation withNearbyDistance:lastNearbyDistance];
			
		}
	}
	[refreshControl endRefreshing];
}

-(void)networkRequest:(SirqulNetworkInterface *)sni didFailWithError:(NSError *)error{
	[refreshControl endRefreshing];
}

- (NSDictionary*)dictionaryForPost:(DDPost*)post{
	for (NSDictionary *dict in allWallposts) {
		if ([SNIHelper checkDictionary:dict objectForKey:@"albumId"]) {
			NSInteger albumId = [[dict objectForKey:@"albumId"]integerValue];
			if (albumId == post.objectId) {
				return dict;
			}
		}
	}
	return nil;
}

- (DDPost*)postForDictionary:(NSDictionary*)dict{
	NSInteger albumId = [[dict objectForKey:@"albumId"]integerValue];
	for (DDPost *post in allPosts) {
		if (post.objectId == albumId) {
			return post;
		}
	}
	return nil;
}

#pragma mark - UITableView methods

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
	return [wallPosts count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
	NSDictionary *cellDict = [wallPosts objectAtIndex:indexPath.row];
	
	// Reuse identifiers for left and right cells
	static NSString *RightCellIdentifier = @"RightCell";
	static NSString *LeftCellIdentifier = @"LeftCell";
	
	NSInteger albumID = [[cellDict objectForKey:@"albumId"]integerValue];
	
	// Try to reuse a cell
	BOOL cellIsRight = [[cellDict objectForKey:@"ownerId"]integerValue] == [[[NSUserDefaults standardUserDefaults]objectForKey:@"accountId"]integerValue];
	UITableViewCell *cell;
	if (cellIsRight) { // User's post so create blue bubble
		cell = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"%@%i", RightCellIdentifier, albumID]];
		if (cell == nil) {
			cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:[NSString stringWithFormat:@"%@%i", RightCellIdentifier, albumID]];
						
			UIImageView *backgroundImage = [[UIImageView alloc] initWithImage:[[UIImage imageNamed:@"blueBubble.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(15.0f, 11.0f, 16.0f, 11.0f)]];
			[backgroundImage setTag:kPAWCellBackgroundTag];
			[cell.contentView addSubview:backgroundImage];
			
			UILabel *textLabel = [[UILabel alloc] init];
			[textLabel setTag:kPAWCellTextLabelTag];
			[cell.contentView addSubview:textLabel];
			
			UILabel *nameLabel = [[UILabel alloc] init];
			[nameLabel setTag:kPAWCellNameLabelTag];
			[cell.contentView addSubview:nameLabel];
		}
	} else { // Someone else's post so create gray bubble
		cell = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"%@%i", LeftCellIdentifier, albumID]];
		if (cell == nil) {
			cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:[NSString stringWithFormat:@"%@%i", LeftCellIdentifier, albumID]];
			
			UIImageView *backgroundImage = [[UIImageView alloc] initWithImage:[[UIImage imageNamed:@"grayBubble.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(15.0f, 11.0f, 16.0f, 11.0f)]];
			[backgroundImage setTag:kPAWCellBackgroundTag];
			[cell.contentView addSubview:backgroundImage];
			
			UILabel *textLabel = [[UILabel alloc] init];
			[textLabel setTag:kPAWCellTextLabelTag];
			[cell.contentView addSubview:textLabel];
			
			UILabel *nameLabel = [[UILabel alloc] init];
			[nameLabel setTag:kPAWCellNameLabelTag];
			[cell.contentView addSubview:nameLabel];
		}
	}
	
	[cell setBackgroundColor:[UIColor clearColor]];
	
	// Configure the cell content
	UILabel *textLabel = (UILabel*) [cell.contentView viewWithTag:kPAWCellTextLabelTag];
	textLabel.text = [cellDict objectForKey:@"title"];
	textLabel.lineBreakMode = NSLineBreakByWordWrapping;
	textLabel.numberOfLines = 0;
	textLabel.font = [UIFont systemFontOfSize:kPAWWallPostTableViewFontSize];
	textLabel.textColor = [UIColor whiteColor];
	textLabel.backgroundColor = [UIColor clearColor];
	
	NSString *username = [NSString stringWithFormat:@"- %@",[[cellDict objectForKey:@"owner"] objectForKey:@"display"]];
	UILabel *nameLabel = (UILabel*) [cell.contentView viewWithTag:kPAWCellNameLabelTag];
	nameLabel.text = username;
	nameLabel.font = [UIFont systemFontOfSize:kPAWWallPostTableViewFontSize];
	nameLabel.backgroundColor = [UIColor clearColor];
	if (cellIsRight) {
		nameLabel.textColor = [UIColor colorWithRed:175.0f/255.0f green:172.0f/255.0f blue:172.0f/255.0f alpha:1.0f];
		nameLabel.shadowColor = [UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.35f];
		nameLabel.shadowOffset = CGSizeMake(0.0f, 0.5f);
	} else {
		nameLabel.textColor = [UIColor blackColor];
		nameLabel.shadowColor = [UIColor colorWithRed:0.9f green:0.9f blue:0.9f alpha:0.35f];
		nameLabel.shadowOffset = CGSizeMake(0.0f, 0.5f);
	}
	
	UIImageView *backgroundImage = (UIImageView*) [cell.contentView viewWithTag:kPAWCellBackgroundTag];
	
	// Move cell content to the right position
	// Calculate the size of the post's text and username
	CGSize textSize = [[cellDict objectForKey:@"title"] sizeWithFont:[UIFont systemFontOfSize:kPAWWallPostTableViewFontSize] constrainedToSize:CGSizeMake(kPAWWallPostTableViewCellWidth, FLT_MAX) lineBreakMode:NSLineBreakByWordWrapping];
	CGSize nameSize = [username sizeWithFont:[UIFont systemFontOfSize:kPAWWallPostTableViewFontSize] forWidth:kPAWWallPostTableViewCellWidth lineBreakMode:NSLineBreakByTruncatingTail];
	
	
	CGFloat cellHeight = [self tableView:tableView heightForRowAtIndexPath:indexPath]; // Get the height of the cell
	CGFloat textWidth = textSize.width > nameSize.width ? textSize.width : nameSize.width; // Set the width to the largest (text of username)
	
	// Place the content in the correct position depending on the type
	if (cellIsRight) {
		[nameLabel setFrame:CGRectMake(wallTableView.frame.size.width-textWidth-kPAWCellTextPaddingSides-kPAWCellPaddingSides,
									   kPAWCellPaddingTop+kPAWCellTextPaddingTop+textSize.height,
									   nameSize.width,
									   nameSize.height)];
		[textLabel setFrame:CGRectMake(wallTableView.frame.size.width-textWidth-kPAWCellTextPaddingSides-kPAWCellPaddingSides,
									   kPAWCellPaddingTop+kPAWCellTextPaddingTop,
									   textSize.width,
									   textSize.height)];
		[backgroundImage setFrame:CGRectMake(wallTableView.frame.size.width-textWidth-kPAWCellTextPaddingSides*2-kPAWCellPaddingSides,
											 kPAWCellPaddingTop,
											 textWidth+kPAWCellTextPaddingSides*2,
											 cellHeight-kPAWCellPaddingTop-kPAWCellPaddingBottom)];
		
	} else {
		[nameLabel setFrame:CGRectMake(kPAWCellTextPaddingSides-kPAWCellPaddingSides,
									   kPAWCellPaddingTop+kPAWCellTextPaddingTop+textSize.height,
									   nameSize.width,
									   nameSize.height)];
		[textLabel setFrame:CGRectMake(kPAWCellPaddingSides+kPAWCellTextPaddingSides,
									   kPAWCellPaddingTop+kPAWCellTextPaddingTop,
									   textSize.width,
									   textSize.height)];
		[backgroundImage setFrame:CGRectMake(kPAWCellPaddingSides,
											 kPAWCellPaddingTop,
											 textWidth+kPAWCellTextPaddingSides*2,
											 cellHeight-kPAWCellPaddingTop-kPAWCellPaddingBottom)];
	}
	
	cell.selectionStyle = UITableViewCellSelectionStyleDefault;
	return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	// Account for the load more cell at the bottom of the tableview if we hit the pagination limit:
	if ( (NSUInteger)indexPath.row >= [wallPosts count]) {
		return [tableView rowHeight];
	}
	
	// Retrieve the text and username for this row:
	NSDictionary *cellDict = [wallPosts objectAtIndex:indexPath.row];
	NSString *text = [cellDict objectForKey:@"title"];
	NSString *username = [[cellDict objectForKey:@"owner"]objectForKey:@"display"];
	
	// Calculate what the frame to fit the post text and the username
	CGSize textSize = [text sizeWithFont:[UIFont systemFontOfSize:kPAWWallPostTableViewFontSize] constrainedToSize:CGSizeMake(kPAWWallPostTableViewCellWidth, FLT_MAX) lineBreakMode:NSLineBreakByWordWrapping];
	CGSize nameSize = [username sizeWithFont:[UIFont systemFontOfSize:kPAWWallPostTableViewFontSize] forWidth:kPAWWallPostTableViewCellWidth lineBreakMode:NSLineBreakByTruncatingTail];
	
	// And return this height plus cell padding and the offset of the bubble image height (without taking into account the text height twice)
	CGFloat rowHeight = kPAWCellPaddingTop + textSize.height + nameSize.height + kPAWCellBkgdOffset;
	return rowHeight;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	DDPost *post = [self postForDictionary:[wallPosts objectAtIndex:indexPath.row]];
	if (post) {
		[mapView selectAnnotation:post animated:YES];
	}
}

@end
