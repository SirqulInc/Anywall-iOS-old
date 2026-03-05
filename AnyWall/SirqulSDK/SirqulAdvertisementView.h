//
//  SirqulAdvertisementView.h
//  SirqulNetworkInterface
//
//  Created by Josh Clarke on 8/11/14.
//  Copyright (c) 2014 Sirqul. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SirqulNetworkInterface.h"

@class SirqulAdvertisementView;
@protocol SirqulAdvertisementDelegate <NSObject>

@optional
- (BOOL)adViewShouldLoadAdInSafari:(NSDictionary*)adData;
- (void)noAdsAvailable:(SirqulAdvertisementView*)sirqulAdView;
- (void)adShown:(NSDictionary*)adData sirqulAdView:(SirqulAdvertisementView*)sirqulAdView;

@end

@interface SirqulAdvertisementView : UIImageView<SirqulNetworkInterfaceDelegate>{
    NSString *appKey, *privateKey;
    NSInteger nextAdIndex;
    NSMutableArray *ads;
    NSDictionary *recentGameData;
    NSTimer *adTimer;
    BOOL downloadingAd;
    UIButton *button;
}

@property (nonatomic, retain) NSString *host, *adType;
@property (nonatomic, retain) NSDictionary *currentAd;
@property (nonatomic, retain) NSArray *missionIds;
@property NSInteger start, limit;
@property double adTimeLimit;
@property (nonatomic, retain) NSNumber *accountId;
@property (nonatomic, retain) id<SirqulAdvertisementDelegate> delegate;
@property BOOL dontShowLogs;

- (instancetype)initWithFrame:(CGRect)frame appKey:(NSString*)theAppKey privateKey:(NSString*)thePrivateKey accountId:(NSNumber*)theAccountId adType:(NSString*)theAdType;
- (instancetype)initWithHost:(NSString*)aHost frame:(CGRect)frame appKey:(NSString*)theAppKey privateKey:(NSString*)thePrivateKey accountId:(NSNumber*)theAccountId adType:(NSString*)theAdType;
- (void)openCurrentAd;
- (void)showAds;
- (void)stopShowingAds;
- (void)configureAdViewWithHost:(NSString*)aHost frame:(CGRect)frame appKey:(NSString*)theAppKey privateKey:(NSString*)thePrivateKey accountId:(NSNumber*)theAccountId adType:(NSString*)theAdType;

@end