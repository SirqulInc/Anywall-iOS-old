//
//  SNIHelper.h
//  SirqulBase
//
//  Created by Josh Clarke on 11/29/12.
//  Copyright (c) 2012 Josh Clarke. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreLocation/CoreLocation.h>

#define SNIHomeDirectoryPath [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

@class SirqulNetworkInterface;
@interface SNIHelper : NSObject <CLLocationManagerDelegate, UIActionSheetDelegate, UIAlertViewDelegate>{
    SirqulNetworkInterface *interface;
}

@property (retain, nonatomic) CLLocation *location;
@property (retain, nonatomic) id loginVC;
@property BOOL dontShowFBLoadingView;

+ (SNIHelper *) instance;

+ (NSString*)commaSeparatedStringFromArray:(NSArray*)array;

+ (BOOL)checkIfValid:(NSDictionary*)jsonData;
+ (BOOL)checkDictionary:(NSDictionary*)dictionary objectForKey:(NSString*)key;
+ (NSString*)appendAnalyticsToGriplyURL:(NSString*)griplyURL;

@end
