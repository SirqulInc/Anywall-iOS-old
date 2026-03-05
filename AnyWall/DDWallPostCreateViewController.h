//
//  PAWWallPostCreateViewController.h
//  DoneDid
//
//  Created by Christopher Bowns on 1/31/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import <UIKit/UIKit.h>
#import "SirqulNetworkInterface.h"

@interface DDWallPostCreateViewController : UIViewController<SirqulNetworkInterfaceDelegate>

@property (nonatomic, strong) IBOutlet UITextView *textView;
@property (nonatomic, strong) IBOutlet UILabel *characterCount;
@property (nonatomic, strong) IBOutlet UIBarButtonItem *postButton;

- (IBAction)cancelPost:(id)sender;
- (IBAction)postPost:(id)sender;

@end
