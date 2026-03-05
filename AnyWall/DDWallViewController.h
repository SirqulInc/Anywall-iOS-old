//
//  PAWWallViewController.h
//  DoneDid
//
//  Created by Christopher Bowns on 1/30/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <Parse/Parse.h>
#import "DDPost.h"
#import "SirqulNetworkInterface.h"

@interface DDWallViewController : UIViewController <MKMapViewDelegate, CLLocationManagerDelegate, SirqulNetworkInterfaceDelegate, UITableViewDataSource, UITableViewDelegate>{
	CLLocationAccuracy lastNearbyDistance;
	NSArray *wallPosts, *allWallposts;
	UIRefreshControl *refreshControl;
}

@property (nonatomic, strong) IBOutlet MKMapView *mapView;
@property (weak, nonatomic) IBOutlet UITableView *wallTableView;

@end

@protocol DDWallViewControllerHighlight <NSObject>

- (void)highlightCellForPost:(DDPost *)post;
- (void)unhighlightCellForPost:(DDPost *)post;

@end
