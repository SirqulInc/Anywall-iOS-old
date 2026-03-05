//
//  PAWLoginViewController.h
//  DoneDid
//
//  Created by Christopher Bowns on 2/1/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import <UIKit/UIKit.h>
#import "DDActivityView.h"
#import "SirqulNetworkInterface.h"
//Sirqul Implementation - Import "SirqulNetworkInterface.h" and set class to confirm
//to SirqulNetworkInterface delegate.

@interface DDLoginViewController : UIViewController <UITextFieldDelegate, SirqulNetworkInterfaceDelegate>{
	DDActivityView *activityView;
}

@property (nonatomic, strong) IBOutlet UIBarButtonItem *doneButton;

@property (nonatomic, strong) IBOutlet UITextField *usernameField;
@property (nonatomic, strong) IBOutlet UITextField *passwordField;

- (IBAction)cancel:(id)sender;
- (IBAction)done:(id)sender;

@end
