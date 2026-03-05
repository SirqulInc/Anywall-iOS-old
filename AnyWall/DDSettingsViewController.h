//
//  PAWSettingsViewController.h
//  DoneDid
//
//  Created by Christopher Bowns on 1/30/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import <UIKit/UIKit.h>
#import "SirqulNetworkInterface.h"

@interface DDSettingsViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UIAlertViewDelegate, SirqulNetworkInterfaceDelegate>

@property (nonatomic, strong) IBOutlet UITableView *tableView;

@end
