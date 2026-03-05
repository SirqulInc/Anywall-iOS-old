//
//  PAWWallPostsTableViewController.h
//  DoneDid
//
//  Created by Christopher Bowns on 2/6/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import <UIKit/UIKit.h>
#import <Parse/Parse.h>
#import "DDWallViewController.h"


static CGFloat const kPAWWallPostTableViewFontSize = 12.f;
static CGFloat const kPAWWallPostTableViewCellWidth = 230.f; // subject to change.

// Cell dimension and positioning constants
static CGFloat const kPAWCellPaddingTop = 5.0f;
static CGFloat const kPAWCellPaddingBottom = 1.0f;
static CGFloat const kPAWCellPaddingSides = 0.0f;
static CGFloat const kPAWCellTextPaddingTop = 6.0f;
static CGFloat const kPAWCellTextPaddingBottom = 5.0f;
static CGFloat const kPAWCellTextPaddingSides = 5.0f;

static CGFloat const kPAWCellUsernameHeight = 15.0f;
static CGFloat const kPAWCellBkgdHeight = 32.0f;
static CGFloat const kPAWCellBkgdOffset = kPAWCellBkgdHeight - kPAWCellUsernameHeight;

// TableViewCell ContentView tags
static NSInteger kPAWCellBackgroundTag = 2;
static NSInteger kPAWCellTextLabelTag = 3;
static NSInteger kPAWCellNameLabelTag = 4;

@interface DDWallPostsTableViewController : PFQueryTableViewController <DDWallViewControllerHighlight>

- (void)highlightCellForPost:(DDPost *)post;
- (void)unhighlightCellForPost:(DDPost *)post;

@end
