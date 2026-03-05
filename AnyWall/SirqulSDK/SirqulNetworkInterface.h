//
//  SirqulNetworkInterface.h
//  Sirqul
//
//  Created by Josh Clarke on 4/23/12.
//  Copyright (c) 2012 Gripwire.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "SirqulASIFormDataRequest.h"
#import "SNIHelper.h"

#import "SirqulEnums.h"

@class SirqulNetworkInterface;
@protocol SirqulNetworkInterfaceDelegate <NSObject>
- (void)networkRequestDidSucceed:(NSDictionary*)jsonData withInterface:(SirqulNetworkInterface*)sni;
- (void)networkRequest:(SirqulNetworkInterface*)sni didFailWithError:(NSError*)error;
@optional
- (void)networkRequestComplete:(SirqulNetworkInterface*)sni __deprecated;
- (void)ASIHTTPRequestDidFinish:(NSDictionary*)results __deprecated;
- (void)ASIHTTPRequestDidFinish:(NSDictionary*)results withInterface:(SirqulNetworkInterface*)sni __deprecated;

@end

enum SirqulNetworkInterfaceStatus{
    kSirqulStatusAcceptInvite,
    kSirqulStatusAddAnalytic,
    kSirqulStatusAddAnalyticBatch,
    kSirqulStatusAddBillableEntity,
    kSirqulStatusAddConnectionsToAlbum,
    kSirqulStatusAddConnectionsToPermissionable,
    kSirqulStatusAddConnectionToGroup,
    kSirqulStatusAddEmployee,
    kSirqulStatusAddFavorite,
    kSirqulStatusAddFlag,
    kSirqulStatusAddLike,
    kSirqulStatusAddMediaFinished,
    kSirqulStatusAddOffer,
    kSirqulStatusAddOrUpdateAchievement,
    kSirqulStatusAddOrUpdateAlbumContest,
    kSirqulStatusAddOrUpdateAssetCollection,
    kSirqulStatusAddOrUpdateAudience,
    kSirqulStatusAddOrUpdateConnection,
    kSirqulStatusAddOrUpdateGameLevel,
    kSirqulStatusAddOrUpdateGroup,
    kSirqulStatusAddOrUpdateMission,
    kSirqulStatusAddPaymentMethod,
    kSirqulStatusAddToBalance,
    kSirqulStatusAddWallet,
    kSirqulStatusAddWalletWithPoints,
    kSirqulStatusAddWalletWithCard,
    kSirqulStatusApproveAlbum,
    kSirqulStatusApproveAlbumContest,
    kSirqulStatusAssignEmployeeToRetailerLocation,
    kSirqulStatusAttendEvent,
    kSirqulStatusConnectionAccept,
    kSirqulStatusConnectionBlock,
    kSirqulStatusConnectionReject,
    kSirqulStatusConnectionRequest,
    kSirqulStatusCreateData,
    kSirqulStatusCreateGameLevel,
    kSirqulStatusCreateMission,
    kSirqulStatusCreateMissionInvite,
    kSirqulStatusCreateNote,
    kSirqulStatusCreateRating,
    kSirqulStatusCreateRetailerLocationConsumer,
    kSirqulStatusDeleteData,
    kSirqulStatusDeleteMissionInvite,
    kSirqulStatusDeleteRating,
    kSirqulStatusFacebookGraphInterface,
    kSirqulStatusFindChallenges,
    kSirqulStatusFindMissions,
    kSirqulStatusGetAchievement,
    kSirqulStatusGetAchievements,
    kSirqulStatusGetAgeGroups,
    kSirqulStatusGetAlbum,
    kSirqulStatusGetAlbumContest,
    kSirqulStatusGetAnalyticsAggregatedFiltered,
    kSirqulStatusGetAnalyticsFiltered,
    kSirqulStatusGetAnalyticsUserActivity,
    kSirqulStatusGetAppData,
    kSirqulStatusGetApplication,
    kSirqulStatusGetApplicationList,
    kSirqulStatusGetApplicationUsers,
    kSirqulStatusGetApplicationVersions,
    kSirqulStatusGetAssetCollection,
    kSirqulStatusGetAudience,
    kSirqulStatusGetAudienceList,
    kSirqulStatusGetBillableEntity,
    kSirqulStatusGetCategories,
    kSirqulStatusGetConnections,
    kSirqulStatusGetConnectionsBlocked,
    kSirqulStatusGetConnectionsPending,
    kSirqulStatusGetConnectionsRequested,
    kSirqulStatusGetData,
    kSirqulStatusGetEmployee,
    kSirqulStatusGetEmployees,
    kSirqulStatusGetFacebookToken,
    kSirqulStatusGetFavorites,
    kSirqulStatusGetGameLevel,
    kSirqulStatusGetGameLevelsByBillableEntity,
    kSirqulStatusGetGroupDetails,
    kSirqulStatusGetGroups,
    kSirqulStatusGetScore,
    kSirqulStatusGetInterests,
    kSirqulStatusGetInvite,
    kSirqulStatusGetInviteUrlForAlbum,
    kSirqulStatusGetInviteUrlForAlbumContest,
    kSirqulStatusGetInviteUrlForGameLevel,
    kSirqulStatusGetInviteUrlForMission,
    kSirqulStatusGetLicense,
    kSirqulStatusGetListingId,
    kSirqulStatusGetListingSummary,
    kSirqulStatusGetLocationDetails,
    kSirqulStatusGetMatchMakingQuestions,
    kSirqulStatusGetMedia,
    kSirqulStatusGetMission,
    kSirqulStatusGetMissionInvite,
    kSirqulStatusGetMissionList,
    kSirqulStatusGetOffer,
    kSirqulStatusGetOfferDetails,
    kSirqulStatusGetOfferListCount,
    kSirqulStatusGetOffersCategoriesRetailersList,
    kSirqulStatusGetOffersList,
    kSirqulStatusGetOfferTransactionsForRetailers,
    kSirqulStatusGetPaymentMethod,
    kSirqulStatusGetProfile,
    kSirqulStatusGetProfileAssets,
    kSirqulStatusGetPurchasedVouchers,
    kSirqulStatusGetPurchaseList,
    kSirqulStatusGetRankings,
    kSirqulStatusGetRetailer,
    kSirqulStatusGetRetailerLocation,
    kSirqulStatusGetThemeDescriptor,
    kSirqulStatusGetTicketCount,
    kSirqulStatusGetTicketList,
    kSirqulStatusGetTicketOffers,
    kSirqulStatusGetTopOffers,
    kSirqulStatusGetTrackingLegs,
    kSirqulStatusGetTrigger,
    kSirqulStatusGetTriggersList,
    kSirqulStatusGetTriggersListByAccount,
    kSirqulStatusGetTriggersListForUserLocation,
    kSirqulStatusGetTriggersListLastestByAccount,
    kSirqulStatusGetVoucherDetails,
    kSirqulStatusGetWalletOffers,
    kSirqulStatusGetWeather,
    kSirqulStatusInvite,
    kSirqulStatusLeaveAlbum,
    kSirqulStatusLeaveFromPermissionable,
    kSirqulStatusLogin,
    kSirqulStatusLoginSecure,
    kSirqulStatusLoginWithFacebook,
    kSirqulStatusLogout,
    kSirqulStatusNotifications,
    kSirqulStatusPasswordChange,
    kSirqulStatusPasswordReset,
    kSirqulStatusPasswordResetRequest,
    kSirqulStatusPurchaseGift,
    kSirqulStatusPurchase,
    kSirqulStatusRedeemVoucher,
    kSirqulStatusRegenerateAppData,
    kSirqulStatusRegenerateThemeDescriptor,
    kSirqulStatusRegisterApnsToken,
    kSirqulStatusRemoveAchievement,
    kSirqulStatusRemoveAchievementTier,
    kSirqulStatusRemoveAlbum,
    kSirqulStatusRemoveAlbumContest,
    kSirqulStatusRemoveApplication,
    kSirqulStatusRemoveAudience,
    kSirqulStatusRemoveBillableEntity,
    kSirqulStatusRemoveConnection,
    kSirqulStatusRemoveConnectionFromGroup,
    kSirqulStatusRemoveConnectionsFromAlbum,
    kSirqulStatusRemoveEmployee,
    kSirqulStatusRemoveFavorite,
    kSirqulStatusRemoveFlag,
    kSirqulStatusRemoveGameLevel,
    kSirqulStatusRemoveGroup,
    kSirqulStatusRemoveLike,
    kSirqulStatusRemoveMedia,
    kSirqulStatusRemoveMission,
    kSirqulStatusRemoveOffer,
    kSirqulStatusRemoveOfferLocation,
    kSirqulStatusRemoveRetailer,
    kSirqulStatusRemoveRetailerLocation,
    kSirqulStatusRemoveSubGroups,
    kSirqulStatusRemoveThemeDescriptor,
    kSirqulStatusRemoveTrigger,
    kSirqulStatusRemoveUsersFromPermissionable,
    kSirqulStatusRemoveWallet,
    kSirqulStatusSaveTrackingLeg,
    kSirqulStatusSearchAchievements,
    kSirqulStatusSearchAlbumContests,
    kSirqulStatusSearchAlbums,
    kSirqulStatusSearchAlbumsByDistance,
    kSirqulStatusSearchApplications,
    kSirqulStatusSearchAssetCollections,
    kSirqulStatusSearchCategories,
    kSirqulStatusSearchConnectionsByName,
    kSirqulStatusSearchConnectionsByRangeAndName,
    kSirqulStatusSearchData,
    kSirqulStatusSearchEmployees,
    kSirqulStatusSearchFilters,
    kSirqulStatusSearchListings,
    kSirqulStatusSearchLocations,
    kSirqulStatusSearchMissions,
    kSirqulStatusSearchMissionsByBillableEntity,
    kSirqulStatusSearchMissionInvites,
    kSirqulStatusSearchOffersForRetailers,
    kSirqulStatusSearchRatingIndexes,
    kSirqulStatusSearchRatings,
    kSirqulStatusSearchRecipients,
    kSirqulStatusSearchRetailerLocations,
    kSirqulStatusSearchRetailerLocationsByRange,
    kSirqulStatusSearchRetailers,
    kSirqulStatusSearchScores,
    kSirqulStatusSearchThemeDescriptors,
    kSirqulStatusSearchWalletOffers,
    kSirqulStatusSendNotification,
    kSirqulStatusSignUp,
    kSirqulStatusSignUpSecure,
    kSirqulStatusUpdateAlbum,
    kSirqulStatusUpdateAlbumNotifications,
    kSirqulStatusUpdateAppData,
    kSirqulStatusUpdateApplicationActive,
    kSirqulStatusUpdateBillableEntity,
    kSirqulStatusUpdateData,
    kSirqulStatusUpdateEmployee,
    kSirqulStatusUpdateGameLevel,
    kSirqulStatusUpdateMatchMakingToken,
    kSirqulStatusUpdateMedia,
    kSirqulStatusUpdateMissionInvite,
    kSirqulStatusUpdateOffer,
    kSirqulStatusUpdateOfferStatus,
    kSirqulStatusUpdatePaymentMethod,
    kSirqulStatusUpdateProfile,
    kSirqulStatusUpdateSettings,
    kSirqulStatusUpdateTicket,
    kSirqulStatusUpdateTrigger,
    kSirqulStatusUpdateWalletOfferStatus,
    kSirqulStatusUpdateNote,
    kSirqulStatusValidateAccountSignup,
    kSirqulStatusValidatePasswordReset,
    kSirqulStatusValidateSubscription,
    kSirqulStatusVoteOnAlbumContest,
    kSirqulStatusWhoHasFavorited,
    kSirqulStatusAddAchievementTier,
    kSirqulStatusAddAlbum,
    kSirqulStatusAddMedia,
    kSirqulStatusAddMediaImage,
    kSirqulStatusAddMediaAudio,
    kSirqulStatusAddMediaVideo,
    kSirqulStatusAddOrUppdateApplication,
    kSirqulStatusAddOrUpdateScore,
    kSirqulStatusAddOrUpdateThemeDescriptor,
    kSirqulStatusAddRetailer,
    kSirqulStatusAddRetailerLocation,
    kSirqulStatusAddSubGroups,
    kSirqulStatusUpdateRetailer,
    kSirqulStatusUpdateRetailerLocation,
    kSirqulStatusUpdateVoucherStatus
};
typedef enum SirqulNetworkInterfaceStatus SirqulNetworkInterfaceStatus;

@class SirqulNetworkInterface;

/**
 The SirqulNetworkInterface
 */

@interface SirqulNetworkInterface : NSObject<NSURLConnectionDelegate, ASIHTTPRequestDelegate>{
	NSMutableData*			dataAccumulator;
    NSURLConnection*        lastConnection;
    NSString*               lastSecurityDataString;
    BOOL                    errorAnalytic;
    NSDictionary*           lastErrorDict;
    NSArray*                lastErrorBatch;
}
/** The response data */
@property (nonatomic, retain) NSMutableData *responseData;
/** the delegate */
@property (nonatomic, retain)			id					delegate;
@property (nonatomic, retain)			id					context;
@property (nonatomic, assign) enum SirqulNetworkInterfaceStatus status;
@property (nonatomic, retain) NSString *host, *appVersion, *applicationKey, *privateKey, *apiVersion;
@property (nonatomic, retain) CLLocationManager *locationManager;
@property (nonatomic, retain) NSNumber *myAccountId;
@property int timeout;

@property BOOL dontShowLogs;

/** the init method */
- (id)initWithDelegate:(id)object andHost:(NSString*)theHost andLocationManager:(CLLocationManager*)locManager andAppVersion:(NSString*)theAppVersion andAppKey:(NSString*)theAppKey andAPIVersion:(NSString*)theAPIVersion andPrivateKey:(NSString*)thePrivateKey andConnectionTimeout:(int)cTimeout andAccountId:(NSNumber*)accountId;
- (id)initWithDelegate:(id)object andAppKey:(NSString*)theAppKey andPrivateKey:(NSString*)thePrivateKey;

- (NSString*)getUUID;


#pragma mark - New methods

/**
 *  Allows a user to accept an invite.
 *  Target API Endpoint: /invite/accept
 *
 *  @param accountId       The accountId of the user who is accepting the invite
 *  @param token           The invite token
 *  @param autoFriend      The autoFriend boolean
 *  @param autoAttendEvent The autoAttendEvent boolean
 */
-(void)acceptInviteWithAccountId:(NSNumber*)accountId andToken:(NSString*)token andAutoFriend:(/*BOOL*/NSNumber*)autoFriend andAutoAttendEvent:(/*BOOL*/NSNumber*)autoAttendEvent;



/**
 *  Record an analytic record for a known state within the application.
 *  Target API Endpoint: /analytics/usage
 *
 *  @param accountId            The logged in user ID
 *  @param tag                  The tag to apply: the name of the action or thing being logged.
 *  @param appKey               The application key unique to each application.
 *  @param theAppVersion        The current build version of the application
 *  @param device               The name of the device being used (iPhone5,1 , HTC Nexus One, x86_64, etc.)
 *  @param deviceType           The type of device (Handheld or Desktop)
 *  @param deviceOS             The operating system that the device is using (iPhone OS 5.0, Android OS 2.3.6, Windows 7 Service Pack 1, etc.)
 *  @param model                The model of the device (iPhone5,1 , Nexus One, etc.)
 *  @param theLocation          The current position of the user.  Will be split into latitude and longitude.
 *  @param customId             A customId used to associate the usage record with some other record in the system
 *  @param achievementIncrement Determines how many achievement points and/or ranking points the user gets if this analytic is associated with an achievement
 *  @param city                 The current city of the user
 *  @param state                The current state of the user
 *  @param country              The current country of the user
 *  @param zip                  The current zip of the user
 *  @param locationDescription  The general description of the user's location
 *  @param clientTime           Timestamp sent from device
 *  @param errorMessage         The error message to send
 *  @param backgroundEvent      Determines if the analytic was sent while the app was in the background.
 */
- (void)addAnalyticWithAccountId:(NSNumber*)accountId andTag:(NSString*)tag andAppKey:(NSString*)appKey andAppVersion:(NSString*)theAppVersion andDevice:(NSString*)device andDeviceType:(NSString*)deviceType andDeviceOS:(NSString*)deviceOS andModel:(NSString*)model andLocation:(CLLocation*)theLocation andCustomId:(NSNumber*)customId andAchievementIncrement:(NSNumber*)achievementIncrement andCity:(NSString*)city andState:(NSString*)state andCountry:(NSString*)country andZip:(NSString*)zip andLocationDescription:(NSString*)locationDescription andClientTime:(NSNumber*)clientTime andErrorMessage:(NSString*)errorMessage andBackgroundEvent:(/*BOOL*/ NSNumber*)backgroundEvent;


/**
 *  Sends multiple analytics. Can be used to send in the user's stored usage when they did not have internet access.
 *  Target API Endpoint: /analytics/usage/batch
 *
 *  @param accountId     The account ID of the logged in user making the request
 *  @param appKey        The application key unique to each application.
 *  @param theAppVersion The current build version of the application
 *  @param device        The name of the device being used (iPhone5,1 , HTC Nexus One, x86_64, etc.)
 *  @param deviceType    The type of device (Handheld or Desktop)
 *  @param deviceOS      The operating system that the device is using (iPhone OS 5.0, Android OS 2.3.6, Windows 7 Service Pack 1, etc.)
 *  @param model         The model of the device (iPhone5,1 , Nexus One, etc.)
 *  @param data          The analytic data AnalyticListResponse
 */
- (void)addAnalyticBatchWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andAppVersion:(NSString*)theAppVersion andDevice:(NSString*)device andDeviceType:(NSString*)deviceType andDeviceOS:(NSString*)deviceOS andModel:(NSString*)model andData:(NSString*)data;



/**
 *  Create a billable entity for an account. The creator is assumed to be the responsible account. An account can only have one billable entity.
 *  Target API Endpoint: /billable/create
 *
 *  @param accountId        The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param name             The name of the entity responsible for billing
 *  @param streetAddress    The street address
 *  @param streetAddress2   Additional address information (such as a suite number, floor number, building name, or PO Box)
 *  @param city             The city
 *  @param state            The state
 *  @param postalCode       The postal code
 *  @param businessPhone    The business phone
 *  @param businessPhoneExt The business phone extension
 */
- (void)addBillableEntityWithAccountId:(NSNumber*)accountId andName:(NSString*)name andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andBusinessPhone:(NSString*)businessPhone andBusinessPhoneExt:(NSString*)businessPhoneExt;


/**
 *  Adds users to album as participants.
 *  Target API Endpoint: /consumer/album/user/add
 *
 *  @param accountId          the account ID of the user (deviceId or accountId required)
 *  @param albumId            the album ID
 *  @param read               determines whether the users being added have read permissions
 *  @param write              determines whether the users being added have write permissions
 *  @param deleteBool         determines whether the users being added have delete permissions
 *  @param add                determines whether the users being added have add permissions
 *  @param connectionIds      comma separated list of connection IDs
 *  @param connectionGroupIds comma separated list of connection group IDs
 *  @param includeFriendGroup determines whether to include all friends as participants
 */
- (void)addConnectionsToAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andRead:(/*BOOL*/ NSNumber*)read andWrite:(/*BOOL*/ NSNumber*)write andDelete:(/*BOOL*/ NSNumber*)deleteBool andAdd:(/*BOOL*/ NSNumber*)add andConnectionIds:(NSArray*)connectionIds andConnectionGroupIds:(NSArray*)connectionGroupIds andIncludeFriendGroup:(/*BOOL*/ NSNumber*)includeFriendGroup;


/**
 *  Adds a user to a permissionable object.
 *  Target API Endpoint: /consumer/permissions/add
 *
 *  @param accountId          the account id of the user (deviceId or accountId required)
 *  @param permissionableType the permissionable type PermissionableType
 *  @param permissionableId   the id of the permissionable object
 *  @param read               the read permission of the users/groups (Default: YES)
 *  @param write              the write permission of the users/groups (Default: NO)
 *  @param deleteBool         the delete permission of the users/groups (Default: NO)
 *  @param add                the add permission of the users/groups (Default: NO)
 *  @param connectionIds      a comma separated list of connection ids (NOT the account ids)
 *  @param connectionGroupIds a comma separated list of connection group ids (these are groups made by the user)
 *  @param includeFriendGroup flag to determine whether to include the built-in "friends" group
 *  @param location           the current location of the user.  Will be split into latitude and longitude
 */
- (void)addConnectionsToPermissionableWithAccountId:(NSNumber*)accountId andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andRead:(/*BOOL*/ NSNumber*)read andWrite:(/*BOOL*/ NSNumber*)write andDelete:(/*BOOL*/ NSNumber*)deleteBool andAdd:(/*BOOL*/ NSNumber*)add andConnectionIds:(NSArray*)connectionIds andConnectionGroupIds:(NSArray*)connectionGroupIds andIncludeFriendGroup:(/*BOOL*/ NSNumber*)includeFriendGroup andLocation:(CLLocation*)location;


/**
 *  Adds a connection to a group.
 *  Target API Endpoint: /consumer/connection/group/addConnection
 *
 *  @param accountId           the account id of the user (deviceId or accountId required)
 *  @param connectionId        the connection id
 *  @param connectionAccountId the connection account id
 *  @param pendingId           the pending id
 *  @param groupId             the group id
 *  @param location            the current location of the user.  Will be split into latitude and longitude
 */
- (void)addConnectionToGroupWithAccountId:(NSNumber*)accountId andConnectionId:(NSNumber*)connectionId andConnectionAccountId:(NSNumber*)connectionAccountId andPendingId:(NSNumber*)pendingId andGroupId:(NSNumber*)groupId andLocation:(CLLocation*)location;


/**
 *  Create a new account record with the provided information.
 *  Target API Endpoint: /employee/create
 *
 *  @param accountId        The account id of the logged in user
 *  @param managerAccountId The account id of the manager to assign under
 *  @param prefixName       The name prefix; Mr, Mrs, etc
 *  @param firstName        The first name
 *  @param middleName       The middle name
 *  @param lastName         The last name
 *  @param suffixName       The name suffix; Jr, Sr, III, etc
 *  @param title            The title of the user
 *  @param username         The username/email for the new user. This must be unique across the entire the system.
 *  @param password         The password for the new user
 *  @param assetId          the asset id to set the user's profile image
 *  @param gender           The gender {MALE, FEMALE, ANY}
 *  @param homePhone        The home phone number
 *  @param cellPhone        The cellular phone number
 *  @param cellPhoneCarrier The cellular service provider. This is required for sending SMS. Leave this empty if the provider is not on the list of supported carriers. Supported Carriers: {ATT, QWEST, T_MOBILE, VERIZON, SPRINT, VIRIGIN_MOBILE, NEXTEL, ALLTEL, METRO_PCS, POWERTEL, BOOST_MOBILE, SUNCOM, TRACFONE, US_CELLULAR}
 *  @param businessPhone    The business phone number
 *  @param emailAddress     The user's contact email address (NOT the username)
 *  @param streetAddress    The street address of the user's contact location
 *  @param streetAddress2   Additional address information (such as a suite number, floor number, building name, or PO Box)
 *  @param city             The city of the user's contact location
 *  @param state            The state of the user's contact location
 *  @param zipcode          The zipcode of the user's contact location
 *  @param country          The country of the user's contact location
 *  @param role             The role; RETAILER or RETAILER_LIMITED, defaulted to RETAILER_LIMITED
 */
- (void)addEmployeeWithAccountId:(NSNumber*)accountId andManagerAccountId:(NSNumber*)managerAccountId andPrefixName:(NSString*)prefixName andFirstName:(NSString*)firstName andMiddleName:(NSString*)middleName andLastName:(NSString*)lastName andSuffixName:(NSString*)suffixName andTitle:(NSString*)title andUsername:(NSString*)username andPassword:(NSString*)password andAssetId:(NSNumber*)assetId andGender:(enum AudienceGender)gender andHomePhone:(NSString*)homePhone andCellPhone:(NSString*)cellPhone andCellPhoneCarrier:(enum CellPhoneCarrierMap)cellPhoneCarrier andBusinessPhone:(NSString*)businessPhone andEmailAddress:(NSString*)emailAddress andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andZipcode:(NSString*)zipcode andCountry:(NSString*)country andRole:(enum AccountType)role;


/**
 *  Adds an offer, offer location, retailer location, or category to your favorites.
 *  Target API Endpoint: /favorite/create
 *
 *  @param accountId       The account ID of the user (deviceId or accountId required)
 *  @param favoritableId   The ID of the object to favorite {offerId, offerLocationId, retailerLocationId, categoryId}
 *  @param favoritableType The type of the object to favorite {OFFER, OFFER_LOCATION, RETAILER_LOCATION, CATEGORY}
 *  @param location        The current location of the user.  Will be split into latitude and longitude.
 */
- (void)addFavoriteWithAccountId:(NSNumber*)accountId andFavoritableId:(NSNumber*)favoritableId andFavoritableType:(NSString*)favoritableType andLocation:(CLLocation*)location;


/**
 *  Allows a user to flag an object that the user deems inappropriate or offensive. Flagable objects include accounts, albums, album contests, assets, game levels, and theme descriptors,
 *  Target API Endpoint: /flag
 *
 *  @param accountId            The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param itemBeingFlaggedType The flagable object type {ACCOUNT, ALBUM, ALBUM_CONTEST, ASSET, GAME_LEVEL, THEME_DESCRIPTOR}
 *  @param itemBeingFlaggedId   The flagable object id
 *  @param flagDescription      An optional description of why is it being flagged
 *  @param location             The current location of the user.  Will be split into latitude and longitude
 */
- (void)addFlagWithAccountId:(NSNumber*)accountId andItemBeingFlaggedType:(enum ClassNameApiMap)itemBeingFlaggedType andItemBeingFlaggedId:(NSNumber*)itemBeingFlaggedId andFlagDescription:(NSString*)flagDescription andLocation:(CLLocation*)location;


/**
 *  Allows a user to like or dislike accounts, albums, album contests, assets, game levels, notes, and theme descriptors. Multiple likes\dislikes on the same object will replace the previous one.
 *  Target API Endpoint: /like
 *
 *  @param accountId          The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param likableType        The type of likable object {ALBUM, ALBUM_CONTEST, ASSET, GAME_LEVEL, NOTE, THEME_DESCRIPTOR}
 *  @param likableId          The id of the likable object
 *  @param permissionableType This is used for sending out group notifications. For example, when someone likes an asset which is also a part of an album, everyone in the album will receive a notification. This is achieved by passing in the permissionable type (in this case "album"), and the permissionable id (the album id). Possible types: {ALBUM, ALBUM_CONTEST, GAME_LEVEL, THEME_DESCRIPTOR}
 *  @param permissionableId   The id of the permissionable object (for sending group notifications)
 *  @param like               determines whether the user likes or dislikes the object
 *  @param location           The current locaition of the user.  Will be split into latitude and longitude
 */
- (void)addLikeWithAccountId:(NSNumber*)accountId andLikableType:(enum ClassNameApiMap)likableType andLikableId:(NSNumber*)likableId andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andLike:(/*BOOL*/ NSNumber*)like andLocation:(CLLocation*)location;



/**
 *  Triggers a notification to be sent to all album participants when a user add assets to an album.
 *  Target API Endpoint: /consumer/media/add/finished
 *
 *  @param accountId the account ID of the user (deviceId or accountId required)
 *  @param albumId   the album ID
 *  @param assetIds  comma separated list of asset IDs that have been added
 */
- (void)addMediaFinishedWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andAssetIds:(NSArray*)assetIds;


/**
 *  Create an offer and assign it to the provided retailer locations.
 *  Target API Endpoint: /retailer/offer/create
 *
 *  @param accountId             The account id (deviceId or accountId required)
 *  @param retailerLocationIds   Comma separated list of retailer location ids. This will assign the offer to these retailer locations.
 *  @param title                 The title (255 char limit)
 *  @param subTitle              The sub title (255 char limit)
 *  @param details               The details
 *  @param subDetails            A string for custom details (255 char limit)
 *  @param finePrint             The fine print
 *  @param barCodeType           The bar code type {NONE, UPC, CODE_128, QR, CUSTOM_MEDIA}
 *  @param barCodeEntry          The bar code entry string
 *  @param externalRedeemOptions An external identifier. What the identifier will be used for and how it is formatted is up to the frontend developer
 *  @param ticketsReward         Determines how many tickets are awarded
 *  @param activated             The date of when the offer will be visible to consumers
 *  @param expires               The date of when the offer expires
 *  @param noExpiration          Overrides the expiration date so that the offer does not expire
 *  @param availableLimit        The limit of how many times the offer can be used by consumers
 *  @param availableLimitPerUser The limit of how many times a user can used the same offer
 *  @param addedLimit            The limit of how many times the offer can be added to consumer wallets
 *  @param viewLimit             The limit of how many times the offer can be viewed
 *  @param maxPrints             The maximum number of times the offer can be printed
 *  @param ticketPrice           The cost of the offer in tickets
 *  @param fullPrice             The retail/full price cost of the offer in real currency
 *  @param discountPrice         The cost of the offer at a discounted price (what the consumer pays)
 *  @param showRemaining         The show remaining
 *  @param showRedeemed          The show redeemed
 *  @param replaced              The replaced
 *  @param featured              The featured
 *  @param offerType             The offer type {VOUCHER, COUPON, PRODUCT, EVENT, MEDIA}
 *  @param specialOfferType      The special offer type {ALL, REGULAR_OFFER, ACT_NOW, GET_THERE_NOW}
 *  @param offerVisibility       The offer visibility {PUBLIC, REWARDABLE, TRIGGERABLE}
 *  @param categoryIds           Comma separated list of category ids
 *  @param filterIds             Comma separated list of filter ids
 *  @param active                Sets the active flag
 *  @param barcodeAssetId        The id of the barcode asset
 *  @param imageAssetId          The id of the an offer asset
 *  @param imageAssetId1         The id of the an offer asset
 *  @param imageAssetId2         The id of the an offer asset
 *  @param imageAssetId3         The id of the an offer asset
 *  @param imageAssetId4         The id of the an offer asset
 *  @param imageAssetId5         The id of the an offer asset
 *  @param publisher             The maker of the item.
 *  @param redeemableStart       The redeemable start date/time of the offer.
 *  @param redeemableEnd         The redeemable start date/time of the offer.
 *  @param brand                 The brand. OfferType PRODUCT only.
 *  @param productType           The product type. OfferType PRODUCT only.
 *  @param conditionType         The condition. OfferType PRODUCT only.
 *  @param isbn                  The ISBN id. OfferType PRODUCT only.
 *  @param asin                  The ASIN id. OfferType PRODUCT only.
 *  @param catalogNumbers        The list of catelog numbers, comma seperated. OfferType PRODUCT only.
 *  @param department            The department name. The OfferType PRODUCT only.
 *  @param features              The list of features, comma seperated. OfferType PRODUCT only.
 *  @param minimumPrice          The MAP price. OfferType PRODUCT only.
 *  @param width                 The width of the item. OfferType PRODUCT only.
 *  @param height                The height of the item. OfferType PRODUCT only.
 *  @param depth                 The depth of the item. OfferType PRODUCT only.
 *  @param weight                The weight of the item. OfferType PRODUCT only.
 *  @param unit                  The unit of measurement. OfferType PRODUCT only.
 *  @param studio                The studio name. OfferType PRODUCT only.
 *  @param parentalRating        The parental control rating. OfferType PRODUCT only.
 *  @param publishDate           The date published. OfferType PRODUCT only.
 *  @param availabilityDate      The date available. OfferType PRODUCT only.
 *  @param sizeId                The sizeId
 *  @param listingId             The ID of the event listing
 *  @param duration              The total playing time of the media item. OfferType MEDIA only.
 *  @param author                The created/author of the media item. OfferType MEDIA only.
 *  @param releaseDate           The date/time of when the media item was originally released. OfferType MEDIA only.
 */
- (void)addOfferWithAccountId:(NSNumber*)accountId andRetailerLocationIds:(NSArray*)retailerLocationIds andTitle:(NSString*)title andSubTitle:(NSString*)subTitle andDetails:(NSString*)details andSubDetails:(NSString*)subDetails andFinePrint:(NSString*)finePrint andBarCodeType:(enum BarCodeType)barCodeType andBarCodeEntry:(NSString*)barCodeEntry andExternalRedeemOptions:(NSString*)externalRedeemOptions andTicketsReward:(NSNumber*)ticketsReward andActivated:(NSNumber*)activated andExpires:(NSNumber*)expires andNoExpiration:(/*BOOL*/ NSNumber*)noExpiration andAvailableLimit:(NSNumber*)availableLimit andAvailableLimitPerUser:(NSNumber*)availableLimitPerUser andAddedLimit:(NSNumber*)addedLimit andViewLimit:(NSNumber*)viewLimit andMaxPrints:(NSNumber*)maxPrints andTicketPrice:(NSNumber*)ticketPrice andFullPrice:(NSNumber*)fullPrice andDiscountPrice:(NSNumber*)discountPrice  andShowRemaining:(/*BOOL*/ NSNumber* /*BOOL*/)showRemaining andShowRedeemed:(/*BOOL*/ NSNumber* /*BOOL*/)showRedeemed andReplaced:(/*BOOL*/ NSNumber* /*BOOL*/)replaced andFeatured:(/*BOOL*/ NSNumber* /*BOOL*/)featured andOfferType:(enum OfferType)offerType andSpecialOfferType:(enum SpecialOfferType)specialOfferType andOfferVisibility:(enum OfferVisibility)offerVisibility andCategoryIds:(NSArray*)categoryIds andFilterIds:(NSArray*)filterIds andActive:(/*BOOL*/ NSNumber* /*BOOL*/)active andBarcodeAssetId:(NSNumber*)barcodeAssetId andImageAssetId:(NSNumber*)imageAssetId andImageAssetId1:(NSNumber*)imageAssetId1 andImageAssetId2:(NSNumber*)imageAssetId2 andImageAssetId3:(NSNumber*)imageAssetId3 andImageAssetId4:(NSNumber*)imageAssetId4 andImageAssetId5:(NSNumber*)imageAssetId5 andPublisher:(NSString*)publisher andRedeemableStart:(NSNumber*)redeemableStart andRedeemableEnd:(NSString*)redeemableEnd andBrand:(NSString*)brand andProductType:(enum ProductType)productType andConditionType:(enum ConditionType)conditionType andISBN:(NSString*)isbn andASIN:(NSString*)asin andCatalogNumbers:(NSString*)catalogNumbers andDepartment:(NSString*)department andFeatures:(NSString*)features andMinimumPrice:(NSNumber*)minimumPrice andWidth:(NSNumber*)width andHeight:(NSNumber*)height andDepth:(NSNumber*)depth andWeight:(NSNumber*)weight andUnit:(enum UnitType)unit andStudio:(NSString*)studio andParentalRating:(NSString*)parentalRating andPublishDate:(NSNumber*)publishDate andAvailabilityDate:(NSNumber*)availabilityDate andSizeId:(NSNumber*)sizeId andListingId:(NSNumber*)listingId andDuration:(NSNumber*)duration andAuthor:(NSString*)author andReleaseDate:(NSNumber*)releaseDate;



/**
 *  Create or update an achievement (for developer/retailer use). User must have permissions to the application the achievement is created for.
 *  Target API Endpoint: /achievement
 *
 *  @param accountId     the account id of the user (deviceId or accountId required)
 *  @param appKey        the application key the achievement is for
 *  @param achievementId the achievement ID for updating an existing achievement, leave empty for creating a new achievement
 *  @param analyticsTag  the analytics tag that will trigger when a user's achievement count gets updated
 *  @param title         the title of the achievement (255 character limit)
 *  @param description   the description of the achievement
 *  @param rankType      the rank type for updating leader boards
 *  @param rankIncrement determines how much the rank count is incremented
 *  @param validate      determines whether the customId on analytics are used to validate a user's acheivement progress.
 */
- (void)addOrUpdateAchievementWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andAchievementId:(NSNumber*)achievementId andAnalyticsTag:(NSString*)analyticsTag andTitle:(NSString*)title andDescription:(NSString*)description andRankType:(enum RankType)rankType andRankIncrement:(NSNumber*)rankIncrement andValidate:(/*BOOL*/ NSNumber* /*BOOL*/)validate;



/**
 *  Creates or updates an album contest.
 *  Target API Endpoint: /consumer/album/contest
 *
 *  @param accountId               the account ID of the user (deviceId or accountId required)
 *  @param contestType             a custom field used for aggregation and searching
 *  @param albumContestId          the album contest ID for updating (don't pass in if creating)
 *  @param title                   the title of the contest
 *  @param description             the description of the contest
 *  @param albumId1                the album ID for the first album
 *  @param removeAlbum1            removes album1 from the contest
 *  @param albumId2                the album ID for the second album
 *  @param removeAlbum2            removes album2 from the contest
 *  @param startDate               the start date of the contest (time-stamp in milliseconds)
 *  @param endDate                 the end date of the contest (time-stamp in milliseconds)
 *  @param publicRead              determines whether the contest's participants has read permissions
 *  @param publicWrite             determines whether the contest's participants has write permissions
 *  @param publicDelete            determines whether the contest's participants has delete permissions
 *  @param publicAdd               determines whether the contest's participants has add permissions
 *  @param locationDescription     the location description of the contest taking place
 *  @param visibility              the determines the album's participants (PUBLIC - includes everyone in the system as a potential participant, PRIVATE - only considers people who have been invited as participants)
 *  @param connectionIdsToAdd      comma separated list of connection IDs
 *  @param connectionGroupIdsToAdd comma separated list of connection group IDs
 *  @param includeFriendGroup      determines whether to include all friends as participants
 *  @param location                location used to update the user's current location.  Will be split into latitude and longitude
 */
- (void)addOrUpdateAlbumContestWithAccountId:(NSNumber*)accountId andContestType:(NSString*)contestType andAlbumContestId:(NSNumber*)albumContestId andTitle:(NSString*)title andDescription:(NSString*)description andAlbumId1:(NSNumber*)albumId1 andRemoveAlbum1:(/*BOOL*/ NSNumber*)removeAlbum1 andAlbumId2:(NSNumber*)albumId2 andRemoveAlbum2:(/*BOOL*/ NSNumber*)removeAlbum2 andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andPublicRead:(/*BOOL*/ NSNumber* /*BOOL*/)publicRead andPublicWrite:(/*BOOL*/ NSNumber* /*BOOL*/)publicWrite andPublicDelete:(/*BOOL*/ NSNumber* /*BOOL*/)publicDelete andPublicAdd:(/*BOOL*/ NSNumber* /*BOOL*/)publicAdd andLocationDescription:(NSString*)locationDescription andVisibility:(enum Visibility)visibility andConnectionIdsToAdd:(NSArray*)connectionIdsToAdd andConnectionGroupIdsToAdd:(NSArray*)connectionGroupIdsToAdd andIncludeFriendGroup:(/*BOOL*/ NSNumber* /*BOOL*/)includeFriendGroup andLocation:(CLLocation*)location;



/**
 *  Adds or Updates an asset collection. If the "collectionId" parameter is false, this will create a new AssetCollection. If "collectionId" is a valid id, this will update that collection.
 *  Target API Endpoint: /consumer/collection
 *
 *  @param accountId           the account id
 *  @param appId               the app id
 *  @param collectionType      the collection type
 *  @param collectionId        the collection id
 *  @param title               the title
 *  @param coverAssetId        the cover asset id
 *  @param startDate           the start date
 *  @param endDate             the end date
 *  @param tags                the tags
 *  @param description         the description
 *  @param publicRead          the public read (Default: NO)
 *  @param publicWrite         the public write (Default: NO)
 *  @param publicDelete        the public delete  (Default: NO)
 *  @param publicAdd           the public add (Default: NO)
 *  @param locationDescription the location description
 *  @param visibility          the visibility
 *  @param location            the location.  Will be split into latitude and longitude
 */
- (void)addOrUpdateAssetCollectionWithAccountId:(NSNumber*)accountId andAppId:(NSString*)appId andCollectionType:(NSString*)collectionType andCollectionId:(NSNumber*)collectionId andTitle:(NSString*)title andCoverAssetId:(NSNumber*)coverAssetId andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andTags:(NSString*)tags andDescription:(NSString*)description andPublicRead:(/*BOOL*/ NSNumber* /*BOOL*/)publicRead andPublicWrite:(/*BOOL*/ NSNumber* /*BOOL*/)publicWrite andPublicDelete:(/*BOOL*/ NSNumber* /*BOOL*/)publicDelete andPublicAdd:(/*BOOL*/ NSNumber* /*BOOL*/)publicAdd andLocationDescription:(NSString*)locationDescription andVisibility:(enum Visibility)visibility andLocation:(CLLocation*)location;



//#warning remove?
//- (void)addOrUpdateAudienceWithAccountId:(NSNumber*)accountId andAudienceId:(NSNumber*)audienceId andName:(NSString*)name andGender:(enum AudienceGender)gender andAgeGroups:(NSArray*)ageGroups andInterestIds:(NSArray*)interestIds andGameExperienceLevel:(enum GameExperienceLevel)gameExperienceLevel;



/**
 *  Creates or updates the connection of the user and another account. Allows a user to follow, block, mark as trusted, and/or add someone to a group.
 *  Target API Endpoint: /consumer/connection/add
 *
 *  @param accountId           the account id of the user (deviceId or accountId required)
 *  @param connectionId        the connection id for editing
 *  @param connectionAccountId the connection account id (i.e. the account id of another user)
 *  @param pendingId           the pending id (usually for people who do not have a Sirqul account but are already friends via other third party apps)
 *  @param groupId             optional group id if the user wants to add this person into a group
 *  @param appKey              the appKey.  Will be sent as gameType.
 *  @param isTrusted           determines whether the user is trusting this account
 *  @param isBlocked           determines whether the user is blocking this account
 *  @param isFollowing         determines whether the user is following this account
 */
- (void)addOrUpdateConnectionWithAccountId:(NSNumber*)accountId andConnectionId:(NSNumber*)connectionId andConnectionAccountId:(NSNumber*)connectionAccountId andPendingId:(NSNumber*)pendingId andGroupId:(NSNumber*)groupId andAppKey:(NSString*)appKey andIsTrusted:(/*BOOL*/ NSNumber* /*BOOL*/)isTrusted andIsBlocked:(/*BOOL*/ NSNumber* /*BOOL*/)isBlocked andIsFollowing:(/*BOOL*/ NSNumber* /*BOOL*/)isFollowing;



//#warning remove?
//- (void)addOrUpdateGameLevelWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andGameLevelId:(NSNumber*)gameLevelId andName:(NSString*)name andDescription:(NSString*)description andGameDifficulty:(enum GameDifficulty)gameDifficulty andAppVersion:(NSString*)appVersion andAssetImageId:(NSNumber*)assetImageId andAssetIconId:(NSNumber*)assetIconId andGameData:(NSString*)gameData andGameDataSuffix:(NSString*)gameDataSuffix andVisibility:(enum Visibility)visibility andFriendGroup:(/*BOOL*/ NSNumber*)friendGroup andConnectionIds:(NSArray*)connectionIds andConnectionGroupIds:(NSArray*)connectionGroupIds andCreateMission:(/*BOOL*/ NSNumber*)createMission andMissionType:(enum MissionType)missionType;



/**
 *  Creates a new private group.
 *  Target API Endpoint: /consumer/connection/group
 *
 *  @param accountId          the account id of the user (deviceId or accountId required)
 *  @param name               the name of the group
 *  @param groupId            the group id to update a group (don't pass anything in if you want to create a new group)
 *  @param assetId            the asset to attach to the group
 *  @param connections        comma separated list of connection IDs
 *  @param description        the description of the group
 *  @param canViewProfileInfo determines whether the connections in the group can see the user's profile info
 *  @param canViewGameInfo    determines whether the connections in the group can see the user's game info
 *  @param canViewFriendInfo  determines whether the connections in the group can see the user's friends/connections
 *  @param location           the location.  Will be split into latitude and longitude
 */
- (void)addOrUpdateGroupWithAccountId:(NSNumber*)accountId andName:(NSString*)name andGroupId:(NSNumber*)groupId andAssetId:(NSNumber*)assetId andConnections:(NSString*)connections andDescription:(NSString*)description andCanViewProfileInfo:(/*BOOL*/ NSNumber*)canViewProfileInfo andCanViewGameInfo:(/*BOOL*/ NSNumber*)canViewGameInfo andCanViewFriendInfo:(/*BOOL*/ NSNumber*)canViewFriendInfo andLocation:(CLLocation*)location;


//#warning remove?
//- (void)addOrUpdateMissionWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId andTitle:(NSString*)title andGameLevelId:(NSNumber*)gameLevelId andAudienceIds:(NSArray*)audienceIds andMisisonType:(enum MissionType)missionType;



/**
 *  Add a new billing account information and credit card on file.
 *  Target API Endpoint: /billing/create
 *
 *  @param accountId             The account used to perform the the request
 *  @param firstName             The first name on the credit card
 *  @param lastName              The last name on the credit card
 *  @param address               The billing address of the credit card
 *  @param city                  The billing city of the credit card
 *  @param state                 The billing state of the credit card
 *  @param postalCode            The billing zip code of the credit card
 *  @param phone                 The billing phone of the credit card
 *  @param creditCardNumber      The full credit card number to store on file
 *  @param expirationDate        The credit card expiration date YYYY-MM
 *  @param ccv                   The 3 digit confirmation code
 *  @param paymentMethodNickname The nickname to give the payment method
 *  @param defaultPaymentMethod  Whether this should be the default payment method
 *  @param authToken             an authorization token for providers that provide this (like Amazon Payments)
 *  @param provider              the payment provider (see PaymentMethodProvider)
 */
- (void)addPaymentMethodWithAccountId:(NSNumber*)accountId andFirstName:(NSString*)firstName andLastName:(NSString*)lastName andAddress:(NSString*)address andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andPhone:(NSString*)phone andCreditCardNumber:(NSString*)creditCardNumber andExpirationDate:(NSString*)expirationDate andCCV:(NSString*)ccv andPaymentMethodNickname:(NSString*)paymentMethodNickname andDefaultPaymentMethod:(/*BOOL*/ NSNumber*)defaultPaymentMethod andAuthToken:(NSString*)authToken andProvider:(NSString*)provider;


/**
 *  Add funds to the account balance using the card on file.
 *  Target API Endpoint: /billing/purchase/bucks
 *
 *  @param accountId the accountId
 *  @param addFunds  the amount of funds to add
 */
- (void)addToBalanceWithAccountId:(NSNumber*)accountId andAddFunds:(NSNumber*)addFunds;


/**
 *  Adds an offer to the wallet. If type VOUCHER then attempts to purchase, otherwise it is just added to the wallet directly.
 *  Target API Endpoint: /wallet/create
 *
 *  @param accountId       the account id of the user (deviceId or accountId required)
 *  @param offerId         The id of the offer being added (offerId or offeLocationId required)
 *  @param offerLocationId The id of the offer location being added (offerId or offeLocationId required)
 *  @param usePoints       if a voucher and set to true then use points, otherwise use credit card on file
 */
- (void)addWalletWithAccountId:(NSNumber*)accountId andOfferId:(NSNumber*)offerId andOfferLocationId:(NSNumber*)offerLocationId andUsePoints:(/*BOOL*/ NSNumber* /*BOOL*/)usePoints;


/**
 *  Sets the approval status of an album. Only an approval status of APPROVED or FEATURED will be returned when searching for public content. Only someone with EXECUTIVE rights or rights to edit the application can approve/feature the content.
 *  Target API Endpoint: /consumer/album/approve
 *
 *  @param accountId      The account ID of the user (deviceId or accountId required)
 *  @param albumId        The ID of the album
 *  @param approvalStatus The approval status to set {PENDING, REJECTED, APPROVED, FEATURED}
 */
- (void)approveAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andApprovalStatus:(enum ApprovalStatus)approvalStatus;

- (void)approveAlbumContestWithAccountId:(NSNumber*)accountId andAlbumContestId:(NSNumber*)albumContestId andApprovalStatus:(enum ApprovalStatus)approvalStatus;


/**
 *  Assign or unassign the account to a retailer location.
 *  Target API Endpoint: /employee/assignToLocation
 *
 *  @param accountId  The account id of the logged in user
 *  @param employeeId The account id of the user to apply the change to
 *  @param locationId The retailer location to apply the change to
 *  @param assign     If true (default) assign to the location, otherwise remove from the retailer
 */
- (void)assignEmployeeToRetailerLocationWithAccountId:(NSNumber*)accountId andEmployeeId:(NSNumber*)employeeId andLocationId:(NSNumber*)locationId andAssign:(/*BOOL*/ NSNumber*)assign;



/**
 *  Endpoint to specify whether the user is attending an event at a particular location. This can also be used as a "check-in" action.
 *  Target API Endpoint: /event/attend
 *
 *  @param accountId          The account id (deviceId or accountId required)
 *  @param appKey             The appKey
 *  @param listingId          The ID of the event listing
 *  @param retailerLocationId The retailer location id of where the event will take place
 *  @param location           The current location of the user.  Will be split into latitude and longitude
 */
- (void)attendEventWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andListingId:(NSNumber*)listingId andRetailerLocationId:(NSNumber*)retailerLocationId andLocation:(CLLocation*)location;



/**
 *  Create a game level. Currently does NOT support game objects.
 *  Target API Endpoint: /level/create
 *
 *  @param accountId          The logged in user.
 *  @param appKey             The game application key to save the level for.
 *  @param name               The name of the level.
 *  @param description        The description of the level.
 *  @param difficulty         The difficulty, possible values are: VERY_EASY, EASY, MEDIUM, HARD, VERY_HARD.
 *  @param levelAppVersion    The version number of the application required to correctly load/play the level.
 *  @param assetImageId       The asset Id of the level image.
 *  @param assetIconId        The asset Id of the level icon.
 *  @param gameData           The game level data: xml, json, or other text based format.
 *  @param gameDataSuffix     The game level data format type.
 *  @param visibility         Is the level visible to others, possible values are: PUBLIC, PRIVATE.
 *  @param friendGroup        Make the level be readable by all friends.
 *  @param connectionIds      Make the level be readable by connections in this list.
 *  @param connectionGroupIds Make the level be readable by connection groups in this list.
 *  @param balance            Set the amount of money available to spend, once 0 deactivate level. Set to a negative value for unlimited.
 *  @param active             If true set the game level as active. Default is false.
 *  @param allocateTickets    If true then scoring will give tickets. Default is false.
 */
- (void)createGameLevelWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andName:(NSString*)name andDescription:(NSString*)description andDifficulty:(enum GameDifficulty)difficulty andAppVersion:(NSNumber*)levelAppVersion andAssetImageId:(NSNumber*)assetImageId andAssetIconId:(NSNumber*)assetIconId andGameData:(NSString*)gameData andGameDataSuffix:(NSString*)gameDataSuffix andVisibility:(enum Visibility)visibility andFriendGroup:(/*BOOL*/ NSNumber*)friendGroup andConnectionIds:(NSArray*)connectionIds andConnectionGroupIds:(NSArray*)connectionGroupIds andBalance:(NSNumber*)balance andActive:(/*BOOL*/ NSNumber*)active andAllocateTickets:(/*BOOL*/ NSNumber*)allocateTickets;



/**
 *  Create a user defined mission.
 *  Target API Endpoint: /mission/create
 *
 *  @param accountId    The logged in user.
 *  @param title        The title of the mission
 *  @param description  The description of the mission
 *  @param startDate    The date/time to start the mission, send 0 to unset
 *  @param endDate      The date/time to end the mission, send 0 to unset
 *  @param active       Activate/deactivate the mission
 *  @param gameLevelIds the game level ids to include in the mission, comma separated
 *  @param audienceIds  the audienceIds
 *  @param formatType   The string identifier for a mission format (this is not the missionFormatId)
 *  @param offerId      The offerId to give as a reward
 *  @param balance      Set the amount of money available to spend, once 0 deactivate mission. Set to a negative value for unlimited.
 */
- (void)createMissionWithAccountId:(NSNumber*)accountId andTitle:(NSString*)title andDescription:(NSString*)description andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andActive:(/*BOOL*/ NSNumber*)active andGameLevelIds:(NSArray*)gameLevelIds andAudienceIds:(NSString*)audienceIds andFormatType:(NSString*)formatType andOfferId:(NSNumber*)offerId andBalance:(NSNumber*)balance;


/**
 *  Create the mission invite. An account can only be invited to a mission one time. For missions that require user submission and reviewing the permissionableType and permissionableId need to be provided.
 *  Target API Endpoint: /mission/invite/create
 *
 *  @param accountId          the account id of the user (deviceId or accountId required).
 *  @param missionId          The mission to find the invite for.
 *  @param permissionableType the permissionableType
 *  @param permissionableId   the permissionableId
 *  @param includeGameData    Include the game level data with the mission.
 */
- (void)createMissionInviteWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData;



/**
 *  Accept a friend request and optionally sends a notification.
 *  Target API Endpoint: /consumer/friend/accept
 *
 *  @param accountId           the account id of the user (deviceId or accountId required)
 *  @param friendAccountId     the friend's account id
 *  @param appKey              the legacy unique id of the app GameType, this will be deprecated in future releases.  Will be sent as gameType
 *  @param notifyFriend        determines whether to send a notification to the afflicting party
 *  @param notificationMessage optional message to send in a notification
 */
- (void)connectionAcceptWithAccountId:(NSNumber*)accountId andFriendAccountId:(NSNumber*)friendAccountId andAppKey:(NSString*)appKey andNotifyFriend:(/*BOOL*/ NSNumber* /*BOOL*/)notifyFriend andNotificationMessage:(NSString*)notificationMessage;



/**
 *  Moves or removes an account into the user's blocked group.
 *  Target API Endpoint: /account/block
 *
 *  @param accountId                 the account id of the user (deviceId or accountId required)
 *  @param accountIdBeingBlocked     the id of the account to be blocked/unblocked
 *  @param blockFlagValue            determines whether the account is blocked or unblocked
 *  @param removeFromGroupsIfBlocked determines whether the account is removed from all other groups if blocked
 *  @param location                  the current location of the user.  Will be split into latitude and longitude
 */
- (void)connectionBlockWithAccountId:(NSNumber*)accountId andAccountIdBeingBlocked:(NSNumber*)accountIdBeingBlocked andBlockFlagValue:(/*BOOL*/ NSNumber*)blockFlagValue andRemoveFromGroupsIfBlocked:(/*BOOL*/ NSNumber*)removeFromGroupsIfBlocked andLocation:(CLLocation*)location;



/**
 *  Request a friend request and optionally sends a notification.
 *  Target API Endpoint: /consumer/friend/reject
 *
 *  @param accountId           the account id of the user (deviceId or accountId required)
 *  @param friendAccountId     the friend's account id
 *  @param appKey              the legacy unique id of the app GameType, this will be deprecated in future releases.  Will be sent as gameType
 *  @param notifyFriend        determines whether to send a notification to the afflicting party
 *  @param notificationMessage optional message to send in a notification
 */
- (void)connectionRejectWithAccountId:(NSNumber*)accountId andFriendAccountId:(NSNumber*)friendAccountId andAppKey:(NSString*)appKey andNotifyFriend:(/*BOOL*/ NSNumber* /*BOOL*/)notifyFriend andNotificationMessage:(NSString*)notificationMessage;



/**
 *  Sends a friend request notification to another user.
 *  Target API Endpoint: /consumer/friend/request
 *
 *  @param accountId           the account id of the user (deviceId or accountId required)
 *  @param friendAccountId     the friend's account id
 *  @param appKey              the legacy unique id of the app GameType, this will be deprecated in future releases.  Will be sent as gameType
 *  @param notificationMessage optional message to send in a notification
 */
- (void)connectionRequestWithAccountId:(NSNumber*)accountId andFriendAccountId:(NSNumber*)friendAccountId andAppKey:(NSString*)appKey andNotificationMessage:(NSString*)notificationMessage;



/**
 *  This is used to leave a comment (note) on a notable object (i.e. albums, album contests, assets, game levels, offers, offer locations, retailers, retailer locations, and theme descriptors). Leaving a comment on a notable object will be visiable to everyone who has access to view the object.
 *  Target API Endpoint: /note/create
 *
 *  @param accountId           The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param notableType         The notable object type {ALBUM, ALBUM_CONTEST, ASSET, GAME_LEVEL, OFFER, OFFER_LOCATION, RETAILER, RETAILER_LOCATION, THEME_DESCRIPTOR}
 *  @param notableId           The id of the notable object
 *  @param comment             The message the user wishes to leave a comment on
 *  @param assetIds            A comma separated list of asset IDs to add with the note
 *  @param tags                search tags
 *  @param permissionableType  This is used for sending out group notifications. For example, when someone adds a note to an asset which is also a part of an album, everyone in the album will receive a notification. This is achieved by passing in the permissionable type (in this case "album"), and the permissionable id (the album id). Possible types: {ALBUM, ALBUM_CONTEST, GAME_LEVEL, THEME_DESCRIPTOR}
 *  @param permissionableId    The id of the permissionable object (for sending group notifications)
 *  @param appKey              The application key used to identify the application
 *  @param locationDescription The description of the location
 *  @param location            The current location of the user.  Will be split into latitude and longitude
 */
- (void)createNoteWithAccountId:(NSNumber*)accountId andNotableType:(enum ClassNameApiMap)notableType andNotableId:(NSNumber*)notableId andComment:(NSString*)comment andAssetIds:(NSArray*)assetIds andTags:(NSArray*)tags andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andAppKey:(NSString*)appKey andLocationDescription:(NSString*)locationDescription andLocation:(CLLocation*)location;



/**
 *  The full name of the user. If this parameter is not empty, the following parameters will be ignored: prefixName, firstName, middleName, lastName, and suffixName
 *  Target API Endpoint: /account/create
 *
 *  @param name                    The full name of the user. If this parameter is not empty, the following parameters will be ignored: prefixName, firstName, middleName, lastName, and suffixName
 *  @param prefixName              if the parameter 'name' is empty or not present, this field will be used to set the prefix of the user's name
 *  @param firstName               if the parameter 'name' is empty or not present, this field will be used to set the user's first name
 *  @param middleName              if the parameter 'name' is empty or not present, this field will be used to set the user's middle name
 *  @param lastName                if the parameter 'name' is empty or not present, this field will be used to set the user's last name
 *  @param suffixName              if the parameter 'name' is empty or not present, this field will be used to set the suffix of the user's name
 *  @param title                   this field will be used to set the user's job title
 *  @param username                the email of the user, this is what will be used when they login
 *  @param password                the password of the user
 *  @param assetId                 the asset id to set the user's profile image
 *  @param streetAddress           the street address of the user's contact location
 *  @param zipcode                 the street zipcode of the user's contact location
 *  @param gender                  the gender of the user AudienceGender
 *  @param birthday                the birthday date of the user in milliseconds
 *  @param homePhone               the homePhone
 *  @param cellPhone               the cellPhone
 *  @param cellPhoneCarrier        the cellPhoneCarrier
 *  @param businessPhone           the businessPhone
 *  @param role                    the type of account being created {RETAILER, MEMBER, DEVELOPER, GUEST}
 *  @param platforms               comma separated list of development platforms {MAC, WINDOWS, IOS, ANDROID, WINDOWSPHONE, KINDLE, UNITY3D, COCOS2D, HTML5, FACEBOOK}
 *  @param tags                    search tags
 *  @param gameExperience          game experience level of the user {ANY, NEW, BEGINNER, INTERMEDIATE, EXPERT}
 *  @param hometown                the user's hometown
 *  @param height                  the user's height
 *  @param heightIndex             the user's height in a numerical value that can be used for ordering/searching
 *  @param ethnicity               the user's ethnicity
 *  @param bodyType                the user's body type
 *  @param maritalStatus           the user's maritial status
 *  @param children                the user's children status
 *  @param religion                the user's religion
 *  @param education               the user's education
 *  @param educationIndex          the user's education in a numerical value that can be used for ordering/searching
 *  @param smoke                   the user's smoke status
 *  @param drink                   the user's drink status
 *  @param companionship           the user's companionship status
 *  @param companionshipIndex      the user's companionship index
 *  @param preferredMinAge         the preferred minimum age in the account location search
 *  @param preferredMaxAge         the preferred maximum age in the account location search
 *  @param preferredMinHeight      the preferred minimum height in the account location search
 *  @param preferredMaxHeight      the preferred maximum height in the account location search
 *  @param preferredGender         the preferred gender in the account location search
 *  @param preferredEducation      the preferred education in the account location search
 *  @param preferredEducationIndex the preferred education in a numerical value that can be used for ordering/searching
 *  @param preferredBodyType       the preferred body type in the account location search
 *  @param preferredEthnicity      the preferred ethnicity in the account location search
 *  @param preferredLocation       the preferred location in the account location search
 *  @param preferredLocationRange  the preferred location range in the account location search
 *  @param location                the current location of the user.  Will be split into latitude and longitude
 *  @param acceptedTerms           determines if the user has accepted the terms
 *  @param appKey                  the legacy unique id of the app GameType, this will be deprecated in future releases.  Will be sent as gameType
 *  @param theAppVersion           the app version
 *  @param responseType            returns an AccountLoginResponse if "AccountLoginResponse" is passed in
 */
- (void)createAccountWithName:(NSString*)name andPrefixName:(NSString*)prefixName andFirstName:(NSString*)firstName andMiddleName:(NSString*)middleName andLastName:(NSString*)lastName andSuffixName:(NSString*)suffixName andTitle:(NSString*)title andUsername:(NSString*)username andPassword:(NSString*)password andAssetId:(NSNumber*)assetId andStreetAddress:(NSString*)streetAddress andZipcode:(NSString*)zipcode andGender:(enum AudienceGender)gender andBirthday:(NSTimeInterval)birthday andHomePhone:(NSString*)homePhone andCellPhone:(NSString*)cellPhone andCellPhoneCarrier:(NSString*)cellPhoneCarrier andBusinessPhone:(NSString*)businessPhone andRole:(enum Role)role andPlatforms:(NSArray*)platforms andTags:(NSArray*)tags andGameExperience:(enum GameExperienceLevel)gameExperience andHometown:(NSString*)hometown andHeight:(NSString*)height andHeightIndex:(NSNumber*)heightIndex andEthnicity:(NSString*)ethnicity andBodyType:(NSString*)bodyType andMaritalStatus:(NSString*)maritalStatus andChildren:(NSString*)children andReligion:(NSString*)religion andEducation:(NSString*)education andEducationIndex:(NSNumber*)educationIndex andSmoke:(NSString*)smoke andDrink:(NSString*)drink andCompanionship:(NSString*)companionship andCompanionshipIndex:(NSNumber*)companionshipIndex andPreferredMinAge:(NSNumber*)preferredMinAge andPreferredMaxAge:(NSNumber*)preferredMaxAge andPreferredMinHeight:(NSNumber*)preferredMinHeight andPreferredMaxHeight:(NSNumber*)preferredMaxHeight andPreferredGender:(enum AudienceGender)preferredGender andPreferredEducation:(NSString*)preferredEducation andPreferredEducationIndex:(NSNumber*)preferredEducationIndex andPreferredBodyType:(NSString*)preferredBodyType andPreferredEthnicity:(NSString*)preferredEthnicity andPreferredLocation:(NSString*)preferredLocation andPreferredLocationRange:(/*double*/ NSNumber*)preferredLocationRange andLocation:(CLLocation*)location andAcceptedTerms:(/*BOOL*/ NSNumber* /*BOOL*/)acceptedTerms andAppKey:(NSString*)appKey andAppVersion:(NSString*)theAppVersion andResponseType:(NSString*)responseType;


- (void)createCategoryWithAccountId:(NSNumber*)accountId appKey:(NSString*)appKey parentCategoryId:(NSNumber*)parentCategoryId name:(NSString*)name description:(NSString*)description assetId:(NSNumber*)assetId externalCategorySlug:(NSString*)externalCategorySlug sqootSlug:(NSString*)sqootSlug active:(/*BOOL*/ NSNumber* /*BOOL*/)active;



/**
 *  Create a record for the specified object. If the object does not exist then a new one will be created prior to inserting the record. If any of the fields included does not exist for the object then they are added to the object.
 *  Target API Endpoint: /object/data/create
 *
 *  @param accountId  The account id of the logged in user
 *  @param appKey     The application key for updating an existing application
 *  @param objectName The name of the object to add data to
 *  @param data       The content to add, structured JSON
 */
- (void)createDataWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andObjectName:(NSString*)objectName andData:(NSString*)data;


- (void)createListingWithAccountId:(NSNumber*)accountId name:(NSString*)name filterIds:(NSString*)filterIds description:(NSString*)description start:(NSNumber*)start end:(NSNumber*)end locationName:(NSString*)locationName locationDescription:(NSString*)locationDescription isPrivate:(/*BOOL*/ NSNumber* /*BOOL*/)isPrivate externalId:(NSString*)externalId externalGroupId:(NSString*)externalGroupId active:(/*BOOL*/ NSNumber* /*BOOL*/)active;


/**searchListingsWithAccountId
 *  This is used to leave rating on a ratable object (i.e. retailer locations). Each user can only rate on a ratable object once per category. If a user rates on the same object and category, the previous rating will be overwritten. Leaving a rating on a ratable object will be visible to everyone who has access to view the object.
 *  Target API Endpoint: /rating/create
 *
 *  @param accountId           The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param ratableType         The ratable object type {RETAILER_LOCATION}
 *  @param ratableId           The id of the ratable object
 *  @param ratingValue         The integer value of 0-255
 *  @param categoryId          The categoryId
 *  @param locationDescription The description of the location
 *  @param location            The current location of the user.  Will be split into latitude and longitude
 */
- (void)createRatingWithAccountId:(NSNumber*)accountId andRatableType:(NSString*)ratableType andRatableId:(NSNumber*)ratableId andRatingValue:(NSNumber*)ratingValue andCategoryId:(NSNumber*)categoryId andLocationDescription:(NSString*)locationDescription andLocation:(CLLocation*)location;



/**
 *  Creates a location record for an application that can support crowd sourced locations.
 *  Target API Endpoint: /location/create
 *
 *  @param accountId        The account id of the user (deviceId or accountId required)
 *  @param appKey           The appKey
 *  @param name             The name of the retailer location
 *  @param streetAddress    The street address of the retailer location
 *  @param streetAddress2   Additional address information (such as a suite number, floor number, building name, or PO Box)
 *  @param city             The city
 *  @param state            The state
 *  @param postalCode       The postal code
 *  @param businessPhone    The business phone
 *  @param businessPhoneExt The business phone extension
 *  @param website          The website of the retailer location
 *  @param email            The email of the retailer location
 *  @param detailsHeader    A brief description about the retailer location (255 character limit)
 *  @param detailsBody      A detailed description about the retailer location
 *  @param hours            The hours of operation
 *  @param logoAssetId      The retailer location logo asset id
 *  @param picture1AssetId  An asset id
 *  @param picture2AssetId  An asset id
 *  @param categoryIds      Comma separated list of category IDs used to filter retailer locations by categories
 *  @param filterIds        Comma separated list of filter IDs used to filter retailer locations
 *  @param location         The latitude and longitude of the location.  Will be split into latitude and longitude
 */
- (void)createRetailerLocationConsumerWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andName:(NSString*)name andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andBusinessPhone:(NSString*)businessPhone andBusinessPhoneExt:(NSString*)businessPhoneExt andWebsite:(NSString*)website andEmail:(NSString*)email andDetailsHeader:(NSString*)detailsHeader andDetailsBody:(NSString*)detailsBody andHours:(NSString*)hours andLogoAssetId:(NSNumber*)logoAssetId andPicture1AssetId:(NSNumber*)picture1AssetId andPicture2AssetId:(NSNumber*)picture2AssetId andCategoryIds:(NSString*)categoryIds andFilterIds:(NSString*)filterIds andLocation:(CLLocation*)location;



/**
 *  Delete a record for the specified object. Cannot be undone so use only when abolutely sure.
 *  Target API Endpoint: /object/data/delete
 *
 *  @param accountId  The account id of the logged in user
 *  @param appKey     The application key for updating an existing application
 *  @param objectName The name of the object to add data to
 *  @param objectId   objectId The id of the record to update
 */
- (void)deleteDataWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andObjectName:(NSString*)objectName andObjectId:(NSString*)objectId;


/**
 *  Sets a rating as deleted.
 *  Target API Endpoint: /rating/delete
 *
 *  @param accountId The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param ratingId  The ID of the rating to delete
 */
- (void)deleteRatingWithAccountId:(NSNumber*)accountId andRatingId:(NSNumber*)ratingId;


/**
 *  Update the mission invite status to quit.
 *  Target API Endpoint: /mission/invite/delete
 *
 *  @param accountId       the account id of the user (deviceId or accountId required).
 *  @param missionId       The mission to find the invite for (missionId or missionInviteId requried).
 *  @param missionInviteId The mission invite id. This checks on the user's billable for permission (missionId or missionInviteId requried).
 *  @param includeGameData Include the game level data with the mission.
 */
- (void)deleteMissionInviteWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId andMissionInviteId:(NSNumber*)missionInviteId andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData;


/**
 *  Delete a mission.
 *  Target API Endpoint: /mission/delete
 *
 *  @param accountId The logged in user.
 *  @param missionId The id of the mission to delete.
 */
- (void)deleteMissionWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId;


/**
 *  Sets a comment (note) as deleted.
 *  Target API Endpoint: /note/delete
 *
 *  @param accountId The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param noteId The ID of the note to delete
 *  @param location The current location of the user.  Will be split into latitude and longitude.
 */
- (void)deleteNoteWithAccountId:(NSNumber*)accountId andNoteId:(NSNumber*)noteId andLocation:(CLLocation*)location;


/**
 *  Allows a user to invite people to attend an event This will generate an invite token, which when used, will allow the invitee to add the offer to their wallet.
 *  Target API Endpoint: /invite/event
 *
 *  @param accountId          the account ID of the user making the share
 *  @param receiverAccountIds the account ID of a Sirqul user they would like to share an event with
 *  @param appKey             the application key
 *  @param listingId          The ID of the event listing
 *  @param retailerLocationId The retailer location id of where the event will take place
 */
- (void)eventInviteWithAccountId:(NSNumber*)accountId andReceiverAccountIds:(NSString*)receiverAccountIds andAppKey:(NSString*)appKey andListingId:(NSNumber*)listingId andRetailerLocationId:(NSNumber*)retailerLocationId;



/**
 *  Make Facebook posts on behalf of the user.
 *  Target API Endpoint: /facebook/graph
 *
 *  @param accountId          the account id of the user (deviceId or accountId required)
 *  @param event              the type of Sirqul event {DOWNLOADED_APP, CHALLENGE, LEVEL_COMPLETED, LEVEL_CREATED}
 *  @param permissionableType for posting about information related to an object. Possible types: {ALBUM, ALBUM_CONTEST, GAME_LEVEL, THEME_DESCRIPTOR}
 *  @param permissionableId   the object id
 *  @param assetId            used to include an asset on a Facebook post
 *  @param appKey             the application key to specify which application the post came from.  Will be sent as gameType
 *  @param location           used to update the user's current location.  Will be split into latitude and longitude
 */
- (void)facebookGraphInterfaceWithAccountId:(NSNumber*)accountId andEvent:(enum Events)event andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andAssetId:(NSNumber*)assetId andAppKey:(NSNumber*)appKey andLocation:(CLLocation*)location;



//#warning remove?
//- (void)findChallengesWithAccountId:(NSNumber*)accountId andAddedSince:(NSNumber*)addedSince;


/**
 *  Get a set of ad filtered by the parameters provided.
 *  Target API Endpoint: /mission/find
 *
 *  @param accountId         The logged in user.
 *  @param appKey            The application key, if provided return missions specific for the app. Will always return mission levels that are app agnostic.
 *  @param suffix            The type of mission to get, possible values are: click_banner, click_leaderboard, click_skyscraper, click_full, click_video, or click_zip
 *  @param missionAppVersion The version of the application, will not return levels newer than the appVersion.  Will be sent as appVersion
 *  @param location          The current location of the requesting device.  Will be split into latitude and longitude
 *  @param device            Should use deviceId if possible. The name of the requesting device; possible values are: Android, iPhone, iPad, iPod, etc. use /audience/devices for list.
 *  @param deviceIdentifier  The device ID of the requesting device, use /audience/devices for list
 *  @param deviceVersion     The requesting device version; examples are: 2.3, 5.1.4, 6.1.4. Supports X, X.X, or X.X.X formated string.
 *  @param start             The index into the record set to start with.
 *  @param limit             The total number of record to return.
 *  @param includeScores     The includeScores
 *  @param includeGameData   Include the game level data with the mission.
 *  @param includeAudiences  If true then return the audience data in the response. Default is false.
 *  @param allocatesTickets  If true/false only return missions whose game levels allocate (or don't allocate) tickets. Do not provide a value to return both.
 *  @param randomize         The randomize
 *  @param targetedAdsOnly   The targetedAdsOnly
 *  @param missionIds        The missionIds
 */
- (void)findMissionsWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andSuffix:(NSString*)suffix andAppVersion:(NSNumber*)missionAppVersion andLocation:(CLLocation*)location andDevice:(NSString*)device andDeviceIdentifier:(NSNumber*)deviceIdentifier andDeviceVersion:(NSString*)deviceVersion andStart:(NSNumber*)start andLimit:(NSNumber*)limit andIncludeScores:(/*BOOL*/ NSNumber*)includeScores andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData andIncludeAudiences:(/*BOOL*/ NSNumber*)includeAudiences andAllocatesTickets:(/*BOOL*/ NSNumber*)allocatesTickets andRandomize:(/*BOOL*/ NSNumber*)randomize andTargetedAdsOnly:(/*BOOL*/ NSNumber*)targetedAdsOnly andMissionIds:(NSArray*)missionIds;


/**
 *  Get detailed information about an achievement (for developer/retailer use). User must have permissions to the application the achievement was created for.
 *  Target API Endpoint: /achievement/get
 *
 *  @param accountId     the account id of the user (deviceId or accountId required)
 *  @param achievementId the achievement ID
 */
- (void)getAchievementWithAccountId:(NSNumber*)accountId andAchievementId:(NSNumber*)achievementId;


/**
 *  Gets a list of of user achievement progress.
 *  Target API Endpoint: /consumer/achievement/get
 *
 *  @param accountId              the account id of the user (deviceId or accountId required)
 *  @param appKey                 the application key for filtering results by application
 *  @param connectionAccountEmail the email of the account to view achievements
 *  @param connectionAccountId    the id of the account to view achievements
 *  @param includeUndiscovered    determines whether to return achievements that the user has not discovered yet
 *  @param location               The current location of the user.  Will be split into latitude and longitude
 */
- (void)getAchievementsWithAccountId:(NSNumber*)accountId  andAppKey:(NSString*)appKey andConnectionAccountEmail:(NSString*)connectionAccountEmail andConnectionAccountId:(NSNumber*)connectionAccountId andIncludeUndiscovered:(/*BOOL*/ NSNumber*)includeUndiscovered andLocation:(CLLocation*)location;


/**
 *  Gets the list of available age groups that can be selected by consumers and retailers targeting offers.
 *  Target API Endpoint: /audience/ageGroups
 */
- (void)getAgeGroups;



/**
 *  Gets an album.
 *  Target API Endpoint: /consumer/album/get
 *
 *  @param accountId the account ID of the user (deviceId or accountId required)
 *  @param albumId   the album to look up
 */
- (void)getAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId;



/**
 *  Gets the contest object including the likes and notes
 *  Target API Endpoint: /consumer/album/contest/get
 *
 *  @param accountId      the account ID of the user (deviceId or accountId required)
 *  @param appKey         the unique title of an application given from the admin tool
 *  @param albumContestId the album contest ID
 *  @param location       Location used to update the user's current location.  Will be split into latitude and longitude.
 */
- (void)getAlbumContestWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andAlbumContestId:(NSNumber*)albumContestId andLocation:(CLLocation*)location;



/**
 *  Query analytics to get data used for nested graphs and charts.
 *  Target API Endpoint: /analytics/aggregatedFilteredUsage
 *
 *  @param accountId           The account id of the user (deviceId or accountId required)
 *  @param appKey              The application key used to filter results by application
 *  @param startDate           Used to search for results after or equal to this date (UNIX time-stamp in milliseconds)
 *  @param endDate             Used to search for results before or equal to this date (UNIX time-stamp in milliseconds)
 *  @param deviceType          The device type to filter results by (performs a LIKE search)
 *  @param device              The device to filter results by (performs a LIKE search)
 *  @param deviceOS            The device OS to filter results by (performs a LIKE search)
 *  @param gender              The gender to filter results by {MALE, FEMALE}
 *  @param ageGroup            Comma separated list of age groups to filter by {AGE_0_13, AGE_14_17, AGE_18_22, AGE_23_30, AGE_31_54, AGE_55_PLUS}
 *  @param country             The country to filter results by (performs a wild-card search)
 *  @param state               The state to filter results by (performs a wild-card search)
 *  @param city                The city to filter results by (performs a wild-card search)
 *  @param zip                 The zip to filter results by (performs a wild-card search)
 *  @param model               The model to filter results by (performs a wild-card search)
 *  @param tag                 The tag to filter results by (performs a wild-card search)
 *  @param userAccountId       The account id to filter results for a particular user
 *  @param userAccountDisplay  The user display to filter results by (performs a wild-card search)
 *  @param userAccountUsername The username to filter results by (performs a wild-card search)
 *  @param groupByRoot         Determines how to group results. For example, passing in 'CREATED' will return results by date. Passing in 'ACCOUNT' will return results by user {TAG, CUSTOM_ID, TOKEN, MODEL, DEVICE_TYPE, DEVICE, DEVICE_OS, IP_ADDRESS, STATE, CITY, ZIP, COUNTRY, ACCOUNT, APPLICATION_ID, APPLICATION_NAME_BY_ID}
 *  @param groupBy             Determines how to group the nested data. {TAG, CUSTOM_ID, TOKEN, MODEL, DEVICE_TYPE, DEVICE, DEVICE_OS, IP_ADDRESS, STATE, CITY, ZIP, COUNTRY, ACCOUNT, APPLICATION_ID, APPLICATION_NAME_BY_ID}
 *  @param distinctCount       Performs a unique query on the specified column. For example, passing in 'ACCOUNT' will return the number of unique users. {TAG, CUSTOM_ID, TOKEN, MODEL, DEVICE_TYPE, DEVICE, DEVICE_OS, IP_ADDRESS, STATE, CITY, ZIP, COUNTRY, ACCOUNT, APPLICATION_ID, NEW_ACCOUNT}
 *  @param sortField           Determines whether the results will be sorted by day or by number of hits {CREATED, TAG_COUNT}
 *  @param descending          Determines whether to return results in descending order
 *  @param hideUnknown         Determines whether to return data that has empty or unknown values
 *  @param responseFormat      Determines whether to return a JOSN or XML representation of the graph results
 *  @param limit               Used to limit results to get a cleaner graph. The results that gets filtered out will be combined
 *  @param location            The current location of the user.  Will be split into latitude and longitude
 */
- (void)getAnalyticsAggregatedFilteredWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andDeviceType:(NSString*)deviceType andDevice:(NSString*)device andDeviceOS:(NSString*)deviceOS andAudienceGender:(enum AudienceGender)gender andAgeGroup:(enum AgeGroup)ageGroup andCountry:(NSString*)country andState:(NSString*)state andCity:(NSString*)city andZip:(NSString*)zip andModel:(NSString*)model andTag:(NSString*)tag andUserAccountId:(NSNumber*)userAccountId andUserAccountDisplay:(NSString*)userAccountDisplay andUserAccountUsername:(NSString*)userAccountUsername andGroupByRoot:(enum AnalyticsApiMap)groupByRoot andGroupBy:(enum AnalyticsApiMap)groupBy andDistinctCount:(enum AnalyticsApiMap)distinctCount andSortField:(enum AnalyticsApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andHideUnknown:(/*BOOL*/ NSNumber*)hideUnknown andResponseFormat:(enum ResponseFormat)responseFormat andLimit:(NSNumber*)limit andLocation:(CLLocation*)location;


/**
 *  Query analytics to get data used for graphs and charts.
 *  Target API Endpoint: /analytics/filteredUsage
 *
 *  @param accountId           The account id of the user (deviceId or accountId required)
 *  @param appKey              The application key used to filter results by application
 *  @param startDate           Used to search for results after or equal to this date (UNIX time-stamp in milliseconds)
 *  @param endDate             Used to search for results before or equal to this date (UNIX time-stamp in milliseconds)
 *  @param deviceType          The device type to filter results by (performs a LIKE search)
 *  @param device              The device to filter results by (performs a LIKE search)
 *  @param deviceOS            The device OS to filter results by (performs a LIKE search)
 *  @param gender              The gender to filter results by {MALE, FEMALE}
 *  @param ageGroup            Comma separated list of age groups to filter by {AGE_0_13, AGE_14_17, AGE_18_22, AGE_23_30, AGE_31_54, AGE_55_PLUS}
 *  @param country             The country to filter results by (performs a wild-card search)
 *  @param state               The state to filter results by (performs a wild-card search)
 *  @param city                The city to filter results by (performs a wild-card search)
 *  @param zip                 The zip to filter results by (performs a wild-card search)
 *  @param model               The model to filter results by (performs a wild-card search)
 *  @param tag                 The tag to filter results by (performs a wild-card search)
 *  @param userAccountId       The account id to filter results for a particular user
 *  @param userAccountDisplay  The user display to filter results by (performs a wild-card search)
 *  @param userAccountUsername The username to filter results by (performs a wild-card search)
 *  @param groupByRoot         Determines how to group results. For example, passing in 'CREATED' will return results by date. Passing in 'ACCOUNT' will return results by user {TAG, CUSTOM_ID, TOKEN, MODEL, DEVICE_TYPE, DEVICE, DEVICE_OS, IP_ADDRESS, STATE, CITY, ZIP, COUNTRY, ACCOUNT, APPLICATION_ID, APPLICATION_NAME_BY_ID}
 *  @param groupBy             Determines how to group results. For example, passing in 'CREATED' will return results by date. Passing in 'ACCOUNT' will return results by user {TAG, CUSTOM_ID, TOKEN, MODEL, DEVICE_TYPE, DEVICE, DEVICE_OS, DEVICE_ID, IP_ADDRESS, STATE, CITY, ZIP, COUNTRY, ACCOUNT, APPLICATION_ID}
 *  @param distinctCount       Performs a unique query on the specified column. For example, passing in 'ACCOUNT' will return the number of unique users. {TAG, CUSTOM_ID, TOKEN, MODEL, DEVICE_TYPE, DEVICE, DEVICE_OS, DEVICE_ID, IP_ADDRESS, STATE, CITY, ZIP, COUNTRY, ACCOUNT, APPLICATION_ID}
 *  @param sortField           Determines whether the results will be sorted by day or by number of hits {CREATED, TAG_COUNT}
 *  @param descending          Determines whether to return results in descending order
 *  @param hideUnknown         Determines whether to return data that has empty or unknown values
 *  @param responseFormat      Determines whether to return a JOSN or XML representation of the graph results
 *  @param limit               Used to limit results to get a cleaner graph. The results that gets filtered out will be combined
 *  @param location            The current location of the user.
 */
- (void)getAnalyticsFilteredWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andDeviceType:(NSString*)deviceType andDevice:(NSString*)device andDeviceOS:(NSString*)deviceOS andAudienceGender:(enum AudienceGender)gender andAgeGroup:(enum AgeGroup)ageGroup andCountry:(NSString*)country andState:(NSString*)state andCity:(NSString*)city andZip:(NSString*)zip andModel:(NSString*)model andTag:(NSString*)tag andUserAccountId:(NSNumber*)userAccountId andUserAccountDisplay:(NSString*)userAccountDisplay andUserAccountUsername:(NSString*)userAccountUsername andGroupByRoot:(enum AnalyticsApiMap)groupByRoot andGroupBy:(enum AnalyticsApiMap)groupBy andDistinctCount:(enum AnalyticsApiMap)distinctCount andSortField:(enum AnalyticsApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andHideUnknown:(/*BOOL*/ NSNumber*)hideUnknown andResponseFormat:(enum ResponseFormat)responseFormat andLimit:(NSNumber*)limit andLocation:(CLLocation*)location;


/**
 *  Get an activity feed by user.
 *  Target API Endpoint: /analytics/useractivity
 *
 *  @param accountId the account id of the user
 *  @param start     The start of the pagination
 *  @param limit     The limit of the pagination
 */
- (void)getAnalyticsUserActivityWithAccountId:(NSNumber*)accountId andStart:(NSNumber*)start andLimit:(NSNumber*)limit;



/**
 *  Get the application data structure. The basic structure is a node tree, with the root node being a AppResponse. The response contains the user's profile, messages from the system, and a list of MissionResponse. A mission can have any number of GameResponses but typically is a single game type. A game then has any number of PackResponses which help group the game levels. Packs are then composed of any number of GameLevelResponses.
 *  Using the various parameters can return the applications default mission (built-in packs to play), the list of community levels published, the user's saved levels, or explicity levels desired. You can choose to include the profile or not, or just return parts of the profile. You can also filter out game levels that have been published with a higher version of the application.
 *  Target API Endpoint: /app/get
 *
 *  @param accountId                  the account id of the user (deviceId or accountId required).
 *  @param appKey                     the game to retrieve the data for, use your application key.  Will be sent as gameType
 *  @param includeGameData            if true then include the game data blob, otherwise don't include.
 *  @param keyword                    query string used to filter the search results when looking for community and saved levels.
 *  @param sortField                  how to sort the results when looking for community and saved levels. possible values are: LEVEL_NAME, LEVEL_CREATED, LEVEL_UPDATED, LEVEL_LIKES, LEVEL_DISLIKES, LEVEL_NOTES, LEVEL_PLAYS.
 *  @param descending                 order the search results descending or ascending when looking for community and saved levels.
 *  @param start                      start the search results at a record.
 *  @param limit                      limit the search results to some number.
 *  @param gameObjectCount            if true then include the game object count, otherwise don't include.
 *  @param filter                     restrict the search to items with certain permissions, possible values are: MINE, FRIENDS, PUBLIC, ALL_PUBLIC, ALL, LIKED
 *  @param dateCreated                restrict the search to items created less then date
 *  @param ownerId                    get levels owned by a particular account
 *  @param missionIds                 get missions by specified id, comman seperated list of long ids
 *  @param gameIds                    get games by specified id, comman seperated list of long ids
 *  @param packIds                    get packs by specified id, comman seperated list of long ids
 *  @param gameLevelIds               get game levels by specified id, comman seperated list of long ids
 *  @param theAppVersion              the application version, used to version the game level data
 *  @param includeHigherVersionPacks  default is false and will not include any packs that have levels above the specified appVersion. If true then will return all levels regardless of version.
 *  @param includeHigherVersionLevels default is false and will not include any levels above the specified appVersion. If true then will return all levels regardless of version.
 *  @param responseGroups             use response groups to include large parts of the structure. possible values are: MISSION_DEFAULT (default) - include the default mission (built-in packs), excludes all other mission groups.  MISSION_DEFAULT_LEVELS_SAVED - include saved levels, excludes all other mission groups.  MISSION_DEFAULT_LEVELS_COMMUNITY - include community levels, excludes all other mission groups.  MISSION_INVITED (default) - include challenges sent to user. PROFILE (default) - include entire profile.  PROFILE_DATA - only include profile date (exclude friends).  PROFILE_FRIENDS - include friends list
 *  @param purchaseType               the will return the correct in app purchases for the device, possible values are:  SIRQUL (default) - purchasing from the sirqul store using tickets.  IOS - purchasing from the itunes store for iPhone, iPod, iPod Touch.  GOOGLE - purchasing from the google android store.  AMAZON - purchasing from the amazon android store.  MAC - purchasing from the itunes store for OSX.  FREE - the item is free to purchase.
 */
- (void)getAppDataWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andIncludeGameData:(/*BOOL*/ NSNumber* /*BOOL*/)includeGameData andKeyword:(NSString*)keyword andSortField:(enum GameLevelApiMap)sortField andDescending:(/*BOOL*/ NSNumber* /*BOOL*/)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andGameObjectCount:(/*BOOL*/ NSNumber* /*BOOL*/)gameObjectCount andFilter:(enum Ownership)filter andDateCreated:(NSTimeInterval)dateCreated andOwnerId:(NSNumber*)ownerId andMissionIds:(NSArray*)missionIds andGameIds:(NSArray*)gameIds andPackIds:(NSArray*)packIds andGameLevelIds:(NSArray*)gameLevelIds andAppVersion:(NSString*)theAppVersion andIncludeHigherVersionPacks:(/*BOOL*/ NSNumber* /*BOOL*/)includeHigherVersionPacks andIncludeHigherVersionLevels:(/*BOOL*/ NSNumber* /*BOOL*/)includeHigherVersionLevels andResponseGroups:(NSArray*)responseGroups andPurchaseType:(enum PurchaseType)purchaseType;


/**
 *  Get a specifc application by appKey
 *  Target API Endpoint: /application/get
 *
 *  @param theAppKey The key of the application
 */
- (void)getApplicationWithAppKey:(NSString*)theAppKey;


/**
 *  List active applications matching the criteria (as a consumer)
 *  Target API Endpoint: /application/list
 *
 *  @param accountId           The account id of the application owner/manager
 *  @param keyword             The keyword used to search for title, about, and description fields
 *  @param platforms           Deprecated, use deviceIds and deviceVersions
 *  @param deviceIds           The list of targeted device ids, comma separated; possible values are retreived via /api/{version}/audience/devices getDevices (pass in deviceId values)
 *  @param deviceVersions      The list of targeted device version ranges that are aligned with the provided devices list (see devices param for possible values), comma separated; examples are: 2.3-X, 0-5.1.4, 4.3.1-6.1.4 where X is no maximum and 0 is no minimum.
 *  @param categoryIds         The list of category ids to filter the list by
 *  @param sortField           The column to sort the search on, possible values include: UPDATED (default), CREATED, TITLE
 *  @param hasAds              Filter results on whether the application supports ads or not. Ignore this parameter to return all results.
 *  @param publicNotifications Filter results on whether the application is available for public trigger notifications
 *  @param filterBillable      Determines whether to only return applications that the user has access to
 *  @param descending          The order to return the search results
 *  @param start               The start of the pagination
 *  @param limit               The limit of the pagination
 *  @param applicationIds      The list of application ids, comma separated. If provided will ignore all other params.
 *  @param hasObjectStore      Only include applications with a object store (default is false)
 */
- (void)getApplicationListWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andPlatforms:(NSArray*)platforms andDeviceIds:(NSString*)deviceIds andDeviceVersions:(NSString*)deviceVersions andCategoryIds:(NSArray*)categoryIds andSortField:(enum ApplicationApiMap)sortField andHasAds:(/*BOOL*/ NSNumber*)hasAds andPublicNotifications:(/*BOOL*/ NSNumber*)publicNotifications andFilterBillable:(/*BOOL*/ NSNumber*)filterBillable andDescending:(/*BOOL*/ NSNumber* /*BOOL*/)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andApplicationIds:(NSString*)applicationIds andHasObjectStore:(/*BOOL*/ NSNumber*)hasObjectStore;


/**
 *  Get a list of users per application.
 *  Target API Endpoint: /application/users
 *
 *  @param keyword The keyword used to search
 *  @param appKey  The application key
 *  @param since   return accounts that have been active after this date (UNIX time-stamp in milliseconds)
 *  @param start   The start of the pagination
 *  @param limit   The limit of the pagination
 */
- (void)getApplicationUsersWithKeyword:(NSString*)keyword andAppKey:(NSString*)appKey andSince:(NSTimeInterval)since andStart:(NSNumber*)start andLimit:(NSNumber*)limit;


/**
 *  Get the supported Api versions. Will return a comma separated list of numbers, newest first. For example: 3.0, 2.2, 2.1, 1.8
 *  Target API Endpoint: /application/versions
 */
- (void)getApplicationVersions;


/**
 *  Gets the asset collection.
 *  Target API Endpoint: /consumer/collection/get
 *
 *  @param accountId    the account id
 *  @param collectionId the collection id
 *  @param location     the location.  Will be split into latitude and longitude
 */
- (void)getAssetCollectionWithAccountId:(NSNumber*)accountId andCollectionId:(NSNumber*)collectionId andLocation:(CLLocation*)location;


/**
 *  Get an audience. The audience and account must be valid and have the appropriate permissions to view the content.
 *  Target API Endpoint: /audience/get
 *
 *  @param accountId  The logged in user.
 *  @param audienceId The id of the audience to return.
 */
- (void)getAudienceWithAccountId:(NSNumber*)accountId andAudienceId:(NSNumber*)audienceId;


//#warning remove?
//- (void)getAudienceListWithAccountId:(NSNumber*)accountId;


/**
 *  Used to determine the associated BillableEntity of an account.
 *  Target API Endpoint: /billable/get
 *
 *  @param accountId       The unique accountId that made the request (either deviceId or accountId must be used)
 *  @param includeCounts   Determines whether to include the retailer dash board counts into the response.  Default: NO
 *  @param includePayments Default: YES
 */
- (void)getBillableEntityWithAccountId:(NSNumber*)accountId andIncludeCounts:(/*BOOL*/ NSNumber* /*BOOL*/)includeCounts andIncludePayments:(/*BOOL*/ NSNumber*)includePayments;



/**
 *  Get the details of a category including child categories.
 *  Target API Endpoint: /category/get
 *
 *  @param categoryId     The ID of the category
 *  @param returnExternal The returnExternal
 */
- (void)getCategoriesWithCategoryId:(NSNumber*)categoryId andReturnExternal:(/*BOOL*/ NSNumber*)returnExternal;



/**
 *  Gets the connections.
 *  Target API Endpoint: /consumer/connection/get
 *
 *  @param accountId           the account id (deviceId or accountId required)
 *  @param connectionAccountId optional parameter to search on other account's connections
 *  @param filters             a comma separated list of ConnectionApiMap. (NOTE on FOLLOWER vs FOLLOWING: FOLLOWER will get me a list of followers, FOLLOWING will get me a list of people I am following)
 *  @param keyword             an optional keyword to search on, this parameter is ignored if empty
 *  @param sortField           sorts the response list by ConnectionApiMap
 *  @param descending          sorts the response list by descending order if true
 *  @param start               start index of the pagination
 *  @param limit               limit of the pagination
 *  @param location            the current location of the user.  Will be split into latitude and longitude
 */
- (void)getConnectionsWithAccountId:(NSNumber*)accountId andConnectionAccountId:(NSNumber*)connectionAccountId andFilters:(NSArray*)filters andKeyword:(NSString*)keyword andSortField:(enum ConnectionApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andLocation:(CLLocation*)location;



/**
 *  Gets the connection sent friend requests.
 *  Target API Endpoint: /consumer/connection/getRequested
 *
 *  @param accountId the account id (deviceId or accountId required)

 */
- (void)getConnectionsRequestedWithAccountId:(NSNumber*)accountId;



/**
 *  Get a specific record from a specified object.
 *  Target API Endpoint: /object/data/get
 *
 *  @param accountId  The account id of the logged in user
 *  @param appKey     the appKey
 *  @param objectName The name of the object to search upon
 *  @param objectId   objectId The id of the record to return
 *  @param include    the include
 */
- (void)getDataWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andObjectName:(NSString*)objectName andObjectId:(NSString*)objectId andInclude:(NSString*)include;



/**
 *  Get the account record for the account id provided.
 *  Target API Endpoint: /employee/get
 *
 *  @param accountId  The account id of the logged in user
 *  @param employeeId The account id of the user to look up
 */
- (void)getEmployeeWithAccountId:(NSNumber*)accountId andEmployeeId:(NSNumber*)employeeId;



//#warning Remove?
//- (void)getEmployeesWithAccountId:(NSNumber*)accountId andRole:(enum AccountType)role andKeyword:(NSString*)keyword andStart:(NSNumber*)start andLimit:(NSNumber*)limit;



/**
 *  Gets a user's Facebook token.
 *  Target API Endpoint: /facebook/getfbtoken
 *
 *  @param accountId the account id of the user (deviceId or accountId required)
 *  @param location  used to update the user's current location.  Will be split into latitude and longitude
 */
- (void)getFacebookTokenWithAccountId:(NSNumber*)accountId andLocation:(CLLocation*)location;



/**
 *  Retrieves a single favorited item.
 *  Target API Endpoint: /favorite/get
 *
 *  @param accountId  The account ID of the user (deviceId or accountId required)
 *  @param favoriteId The ID of the favorite reference record
 *  @param location   The current location of the user.  Will be split into latitude and longitude.
 */
- (void)getFavoriteWithAccountId:(NSNumber*)accountId andFavoriteId:(NSNumber*)favoriteId andLocation:(CLLocation*)location;



/**
 *  Searches on the user's favorites.
 *  Target API Endpoint: /favorite/search
 *
 *  @param accountId           The account ID of the user (deviceId or accountId required)
 *  @param connectionAccountId The ID of an account the user would like to view favorites for
 *  @param favoritableType     The type of the object to favorite {OFFER, OFFER_LOCATION, RETAILER_LOCATION, CATEGORY}
 *  @param secondaryType       The secondary type
 *  @param keyword             The keyword to search for
 *  @param sortField           Determines what to sort the results by {CREATED, UPDATED, DISPLAY}
 *  @param descending          Determines whether the results are in descending order
 *  @param start               The start index for pagination
 *  @param limit               The limit for pagination (there is a hard limit of 1000)
 *  @param activeOnly          Determines whether to only return active favorites
 *  @param returnFullResponse  Determines whether to return a detailed version of the response list
 *  @param location            The current location of the user.  Will be split into latitude and longitude
 */
- (void)getFavoritesWithAccountId:(NSNumber*)accountId andConnectionAccountId:(NSNumber *)connectionAccountId andFavoritableType:(NSString *)favoritableType andSecondaryType:(NSString*)secondaryType andKeyword:(NSString *)keyword andSortField:(NSString *)sortField andDescending:(NSNumber *)descending andStart:(NSNumber *)start andLimit:(NSNumber *)limit andActiveOnly:(NSNumber *)activeOnly andReturnFullResponse:(NSNumber*)returnFullResponse andLocation:(CLLocation *)location;



/**
 *  Get a game level. The level and account must be valid and have the appropirate permissions to view the content.
 *  Target API Endpoint: /level/get
 *
 *  @param accountId       The logged in user.
 *  @param levelId         The id of the level to return.
 *  @param includeGameData If true include the game level data, otherwise don't. default is false.
 */
- (void)getGameLevelWithAccountId:(NSNumber*)accountId andLevelId:(NSNumber*)levelId andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData;



/**
 *  Get a list of levels for an application, just those the account has permissions to view.
 *  Target API Endpoint: /level/search
 *
 *  @param accountId       The logged in user.
 *  @param appKey          The appKey
 *  @param keyword         Match the keyword to the owner name or level name.
 *  @param start           Start the result set at some index.
 *  @param limit           Limit the result to some number.
 *  @param version         The maximum version of the level to return.
 *  @param includeGameData If true include the game level data, otherwise don't.
 */
- (void)getGameLevelsByApplicationWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andKeyword:(NSString*)keyword andStart:(NSNumber*)start andLimit:(NSNumber*)limit andAppVersion:(NSNumber*)version andIncludeGameData:(/*BOOL*/ NSNumber* /*BOOL*/)includeGameData;



/**
 *  Searches on game levels that the logged in user has access to. A user would have access if the creator of the game level is managed under the same BillableEntity.
 *  Target API Endpoint: /game/getGameLevelsByBillableEntity
 *
 *  @param accountId  The account id of the user
 *  @param keyword    The keyword used to search
 *  @param sortField  The column to sort the search on
 *  @param descending The order to return the search results
 *  @param activeOnly Return only active results
 *  @param start      The record to begin the return set on
 *  @param limit      The number of records to return
 */
- (void)getGameLevelsByBillableEntityWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andSortField:(enum GameLevelApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly andStart:(NSNumber*)start andLimit:(NSNumber*)limit;


/**
 *  Get the details of a global config setting.
 *  Target API Endpoint: /congif/get
 *
 *  @param accountId        The account id of the user
 *  @param globalConfigId   The ID of the globalConfig
 */
- (void)getGlobalConfigWithAccountId:(NSNumber*)accountId andGlobalConfigId:(NSNumber*)globalConfigId;


/**
 *  Get detailed information about a group.
 *  Target API Endpoint: /consumer/connection/group/details/get
 *
 *  @param accountId          the account id of the user (deviceId or accountId required)
 *  @param groupId            the group id
 *  @param combineConnections The combineConnections
 *  @param location           the current location of the user.  Will be split into latitude and longitude.
 */
- (void)getGroupDetailsWithAccountId:(NSNumber*)accountId andGroupId:(NSNumber*)groupId andCombineConnections:(/*BOOL*/ NSNumber*)combineConnections andLocation:(CLLocation*)location;



/**
 *  Gets a user's private groups and default groups.
 *  Target API Endpoint: /consumer/connection/group/get
 *
 *  @param accountId              the account id of the user (deviceId or accountId required)
 *  @param connectionAccountEmail the connection account email
 *  @param connectionAccountId    the connection account id
 *  @param responseFilters        a comma separated list of ProfileFilters for filtering the returned response data
 *  @param location               the current location of the user.  Will be split into latitude and longitude.
 */
- (void)getGroupsWithAccountId:(NSNumber*)accountId andConnectionAccountEmail:(NSString*)connectionAccountEmail andConnectionAccountId:(NSNumber*)connectionAccountId andResponseFilter:(NSArray *)responseFilters andLocation:(CLLocation *)location;



/**
 *  Get the high score for an item. Pass in the full path IDs for the score.
 *
 *  @param accountId    The logged in user.
 *  @param appKey       The game application key to get the level for.
 *  @param missionId    The missionId to score for, null if not playing mission.
 *  @param gameId       The gameId to score for, null if not playing mission.
 *  @param packId       The packId to score for, null if playing community levels.
 *  @param gameLevelId  The gameLevelId to score for.
 *  @param gameObjectId The gameObjectId to score for, null if level based scoring.
 */
- (void)getScoreWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andMisisonId:(NSNumber*)missionId andGameId:(NSNumber*)gameId andPackId:(NSNumber*)packId andGameLevelId:(NSNumber*)gameLevelId andGameObjectid:(NSNumber*)gameObjectId;


/**
 *  This service has been deprecated, use com.sirqul.geoapps.common.service.CategoryApi.searchCategories
 *  Target API Endpoint: /audience/interests
 *
 *  @param requireAsset If true then only return interests with assets, otherwise return all
 */
- (void)getInterestsWithRequireAsset:(/*BOOL*/ NSNumber*)requireAsset __deprecated;



/**
 *  This is used to determine whether an invite token is valid. If the token is valid, this will also return information about who invited the user, and what they are invited to.
 *  Target API Endpoint: /invite/get
 *
 *  @param accountId Account ID of the user if they are logged in
 *  @param token     the invite token
 */
- (void)getInviteWithAccountId:(NSNumber*)accountId andToken:(NSString*)token;



/**
 *  Allows a user to invite people to gain access to an album. This will generate an invite token, which when used, will give the invitee access to an album (whether it is private or not). The invitee will also become the user's friend when the invitation is accepted.
 *  Target API Endpoint: /invite/album
 *
 *  @param accountId the account ID of the user (deviceId or accountId required)
 *  @param albumId   the album to share
 *  @param appKey    the application key
 *  @param location  the current location of the user.  Will be split into latitude and longitude.
 */
- (void)getInviteUrlForAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andAppKey:(NSString*)appKey andLocation:(CLLocation*)location;



/**
 *  Allows a user to invite people to gain access to an album contest. This will generate an invite token, which when used, will give the invitee access to an album contest (whether it is private or not). The invitee will also become the user's friend when the invitation is accepted.
 *  Target API Endpoint: /consumer/albumcontent/invite
 *
 *  @param accountId      the account ID of the user (deviceId or accountId required)
 *  @param albumContestId the album contest to share
 *  @param appKey         the application key
 *  @param location       the current location of the user.  Will be split into latitude and longitude
 */
- (void)getInviteUrlForAlbumContestWithAccountId:(NSNumber*)accountId andAlbumContestId:(NSNumber*)albumContestId andAppKey:(NSString*)appKey andLocation:(CLLocation*)location;



/**
 *  Allows a user to invite people to play their custom game level. This will generate an invite token, which when used, will give the invitee access to play the game level (whether it is private or not). The invitee will also become the user's friend when the invitation is accepted.
 *  Target API Endpoint: /consumer/gamelevel/invite
 *
 *  @param accountId   the account ID of the user (deviceId or accountId required)
 *  @param gameLevelId the game level that the user owns and is giving access to
 *  @param appKey      the application key
 *  @param location    the current location of the user.  Will be split into latitude and longitude
 */
- (void)getInviteUrlForGameLevelWithAccountId:(NSNumber*)accountId andGameLevelId:(NSNumber*)gameLevelId andAppKey:(NSString*)appKey andLocation:(CLLocation*)location;



/**
 *  Allows a user to invite people to complete a mission. This will generate an invite token, which when used, will give the invitee access to complete a mission (whether it is private or not). The invitee will also become the user's friend when the invitation is accepted.
 *  Target API Endpoint: /consumer/mission/invite
 *
 *  @param accountId the account ID of the user (deviceId or accountId required)
 *  @param missionId the mission to share
 *  @param appKey    the application key
 *  @param location  the current location of the user.  Will be split into latitude and longitude
 */
- (void)getInviteUrlForMissionWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId andAppKey:(NSString*)appKey andLocation:(CLLocation*)location;


/**
 *  Allows a user to invite people to gain access to an offer.
 *  Target API Endpoint: /consumer/albumcontent/invite
 *
 *  @param accountId      the account ID of the user (deviceId or accountId required)
 *  @param offerId        the offer to share
 *  @param appKey         the application key
 */
- (void)getInviteUrlForOfferWithAccountId:(NSNumber*)accountId andOfferId:(NSNumber*)offerId andAppKey:(NSString*)appKey;


/**
 *  Use the provided application key to determine if the license is currently valid and then send back the available modules.
 *  Target API Endpoint: /license/get
 *
 *  @param appKey the appKey
 */
- (void)getLicenseWithAppKey:(NSString*)appKey;



/**
 *  Get a listing by id
 *  Target API Endpoint: /listing/get
 *
 *  @param listingId The id of the listing
 */
- (void)getListingId:(NSNumber*)listingId;



/**
 *  Search for a list of summary listings from the start time up to 8 days out.
 *
 *  @param accountId        the account id of the user
 *  @param categoryIds      the list of categories to search on
 *  @param startDate        the start date to search from
 *  @param daysToInclude    the number of days to search for
 */
- (void)getListingSummaryWithAccountId:(NSNumber*)accountId andCategoryIds:(NSString*)categoryIds andStartDate:(NSTimeInterval)startDate andDaysToInclude:(NSNumber*)daysToInclude;



/**
 *  Gets the details of a retailer location as a consumer.
 *  Target API Endpoint: /location/get
 *
 *  @param accountId          The account id for returning account information (i.e. favorites)
 *  @param retailerLocationId The retailer location id
 */
- (void)getLocationDetailsWithAccountId:(NSNumber*)accountId andRetailerLocationId:(NSNumber*)retailerLocationId;



/**
 *  Used to retrieve a set of questions for match making. Each question will contain what the user has answer in the past (or whether it was skipped). Can also be used to view someone else's result.
 *  Target API Endpoint: /matchQuestions/get
 *
 *  @param accountId           The account id of the user (deviceId or accountId required)
 *  @param connectionAccountId the account id of someone else to retrieve their results
 *  @param gameType            the application key
 */
- (void)getMatchMakingQuestionsWithAccountId:(NSNumber*)accountId andConnectionAccountId:(NSNumber*)connectionAccountId andGameType:(NSString*)gameType;



/**
 *  Gets the full asset response including attached likes and notes.
 *  Target API Endpoint: /consumer/media/get
 *
 *  @param accountId      the account ID of the user (deviceId or accountId required)
 *  @param assetId        the asset ID
 *  @param noteDescending determines whether the notes on the asset are in descending order
 */
- (void)getMediaWithAccountId:(NSNumber*)accountId andAssetId:(NSNumber*)assetId andNoteDescending:(/*BOOL*/ NSNumber*)noteDescending;



/**
 *  Get a mission.
 *  Target API Endpoint: /mission/get
 *
 *  @param accountId The logged in user.
 *  @param missionId The id of the mission to return.
 */
- (void)getMissionWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId;



/**
 *  Get a the mission invite. An account can only be invited to a mission one time.
 *  Target API Endpoint: /mission/invite/get
 *
 *  @param accountId       the account id of the user (deviceId or accountId required).
 *  @param missionId       The mission to find the invite for (missionId or missionInviteId requried).
 *  @param missionInviteId The mission invite id. This checks on the user's billable for permission (missionId or missionInviteId requried).
 *  @param includeGameData Include the game level data with the mission.
 */
- (void)getMissionInviteWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId andMissionInviteId:(NSNumber*)missionInviteId andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData;



//#warning Remove?
//- (void)getMissionListWithAccountId:(NSNumber*)accountId andStart:(NSNumber*)start andLimit:(NSNumber*)limit;



/**
 *  Gets the details of an offer that the user has access to.
 *  Target API Endpoint: /retailer/offer/get
 *
 *  @param accountId The account id (deviceId or accountId required)
 *  @param offerId   The id of the offer
 */
- (void)getOfferWithAccountId:(NSNumber*)accountId andOfferId:(NSNumber*)offerId;



/**
 *  Gets offer or offer location details as a consumer. Will check if it is a favorite if the deviceId/accountId is provided. If the offerId is provided it will look up the main offer and ignore the the offerLocationId. If no offerId is provided then an offerLocationId must be specified.
 *  Target API Endpoint: /offer/get
 *
 *  @param accountId       The account id for returning account information (i.e. favorites)
 *  @param offerId         The offer id (either offeLocationId or offerId must be provided)
 *  @param offerLocationId The offer location id (either offeLocationId or offerId must be provided)
 *  @param distance        The distance of the offer from the user's current location (this is returned when the offer is searched)
 *  @param location        The location to calculate distance from the offer.  Will be split into latitude and longitude
 *  @param includeOfferLocations Always include offer locations
 */
- (void)getOfferDetailsWithAccountId:(NSNumber*)accountId andOfferId:(NSNumber*)offerId andOfferLocationId:(NSNumber*)offerLocationId andDistance:(/*double*/ NSNumber*)distance andLocation:(CLLocation*)location andIncludeOfferLocations:(/*BOOL*/ NSNumber*)includeOfferLocations;



/**
 *  <#Description#>
 *
 *  @param accountId   <#accountId description#>
 *  @param location    <#location description#>
 *  @param searchRange <#searchRange description#>
 */
- (void)getOfferListCountWithAccountId:(NSNumber*)accountId andLocation:(CLLocation*)location andSearchRange:(/*double*/ NSNumber*)searchRange;

- (void)getOffersCategoriesRetailersListWithAccountId:(NSNumber*)accountId andCategoryId:(NSNumber*)categoryId andLocationId:(NSNumber*)locationId andLocation:(CLLocation*)location andSearchRange:(/*double*/ NSNumber*)searchRange andKeyword:(NSString*)keyword andCategories:(NSArray*)categories andFilters:(NSArray*)filters andType:(enum SpecialOfferType)type andShowPreview:(/*BOOL*/ NSNumber*)showPreview andIgnoreMap:(/*BOOL*/ NSNumber*)ignoreMap andStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)getOffersListWithAccountId:(NSNumber*)accountId andLocation:(CLLocation*)location andSearchRange:(/*double*/ NSNumber*)searchRange andKeyword:(NSString*)keyword andCategoryIds:(NSArray*)categoryIds andFilters:(NSArray*)filters andType:(enum SpecialOfferType)type andOfferTypes:(NSArray*)offerTypes andSortField:(enum SortFilter)sortField andLocationId:(NSNumber*)locationId andIncludeMission:(/*BOOL*/ NSNumber* /*BOOL*/)includeMission includeCategories:(/*BOOL*/ NSNumber* /*BOOL*/)includeCategories includeFilters:(/*BOOL*/ NSNumber* /*BOOL*/)includeFilters andStart:(NSNumber*)start andLimit:(NSNumber*)limit andAppKey:(NSString*)appKey andIncludeFavorite:(/*BOOL*/ NSNumber* /*BOOL*/)includeFavorite;

- (void)getOfferTransactionWithAccountId:(NSNumber*)accountId andTransactionId:(NSNumber*)transactionId andIncludeMission:(/*BOOL*/ NSNumber*)includeMission andLocation:(CLLocation*)location;

- (void)getOfferTransactionsForRetailersWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andRetailerId:(NSNumber*)retailerId andRetailerLocationId:(NSNumber*)retailerLocationId andRedeemed:(/*BOOL*/ NSNumber*)redeemed andOfferType:(enum CouponType)offerType andSpecialOfferType:(enum SpecialOfferType)specialOfferType andCustomerAccountIds:(NSArray*)customerAccountIds andSortField:(enum OfferTransactionApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly;

- (void)getPaymentMethodWithAccountId:(NSNumber*)accountId;

- (void)getProfileWithAccountId:(NSNumber*)accountId andConnectionAccountEmail:(NSString*)connectionAccountEmail andConnectionAccountId:(NSNumber*)connectionAccountId andResponseFilters:(NSArray*)responseFilters andPurchaseType:(enum PurchaseType)purchaseType andUpdateViewedDate:(/*BOOL*/ NSNumber*)updateViewedDate andLocation:(CLLocation*)location;

- (void)getProfileAssetsWithAccountId:(NSNumber*)accountId andOwnerId:(NSNumber*)ownerId andMediaTypes:(NSArray*)mediaTypes andMimeTypes:(NSArray*)mimeTypes andSortField:(enum AssetApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andLocation:(CLLocation*)location andStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)getPurchasedVouchersWithAccountId:(NSNumber*)accountId andFilters:(NSString*)filters;

- (void)getPurchaseListWithAccountId:(NSNumber*)accountId andPurchaseTypes:(NSArray*)purchaseTypes andServiceAction:(NSString*)serviceAction;

- (void)getRankingsWithAccountId:(NSNumber*)accountId andQuery:(NSString*)query andRankType:(enum RankType)rankType andLeaderboardMode:(enum RankMode)leaderboardMode andWithinAccountIds:(NSArray*)withinAccountIds andSortField:(enum RankApiMap)sortField andStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)getRetailerWithAccountId:(NSNumber*)accountId andRetailerId:(NSNumber*)retailerId andIncludeCounts:(/*BOOL*/ NSNumber* /*BOOL*/)includeCounts;

- (void)getRetailerWithAccountId:(NSNumber*)accountId andRetailerLocationId:(NSNumber*)retailerLocationId;

- (void)getRetailerLocationConsumerWithAccountId:(NSNumber*)accountId andRetailerLocationId:(NSNumber*)retailerLocationId;

- (void)getThemeDescriptorWithAccountId:(NSNumber*)accountId andThemeDescriptorId:(NSNumber*)themeDescriptorId andLocation:(CLLocation*)location;

- (void)getTicketCountWithAccountId:(NSNumber*)accountId andGameType:(NSString*)gameType;

- (void)getTicketListWithAccountId:(NSNumber*)accountId andTicketObjectTypes:(NSArray*)ticketObjectTypes andActionTypes:(NSArray*)actionTypes andTicketIds:(NSArray*)ticketIds andObjectIds:(NSArray*)objectIds;

- (void)getTicketOffers;

- (void)getTrackingLegsWithAccountId:(NSNumber*)accountId andOwnerId:(NSNumber*)ownerId andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate;

- (void)getTriggerWithAccountId:(NSNumber*)accountId andTriggerId:(NSNumber*)triggerId;

- (void)getTriggersListWithAccountId:(NSNumber*)accountId;

- (void)getTriggersListByAccountWithAccountId:(NSNumber*)accountId andSendSuggestions:(/*BOOL*/ NSNumber*)sendSuggestions;

- (void)getTriggersListForUserLocation:(CLLocation*)location andGender:(enum AudienceGender)gender andAges:(NSArray*)ages andGameExperiences:(NSArray*)gameExperiences andInterests:(NSArray*)interests andStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)getTriggersListLastestByAccountWithAccountId:(NSNumber*)accountId andTimeFrame:(NSNumber*)timeFrame;

- (void)getVoucherDetailsWithAccountId:(NSNumber*)accountId andFilters:(NSString*)filters;

- (void)getWeatherWithRegionId:(NSNumber*)regionId andTimezoneOffset:(NSNumber*)timezoneOffset;

- (void)inviteWithToken:(NSString*)token;

- (void)leaveAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId;

- (void)leaveFromPermissionableWithAccountId:(NSNumber*)accountId andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andLocation:(CLLocation*)location;

- (void)loginWithUsername:(NSString*)username andPassword:(NSString*)password andLocation:(CLLocation*)location andReturnProfile:(/*BOOL*/ NSNumber*)returnProfile andResponseFilters:(NSArray*)responseFilters;

- (void)loginSecureWithUsername:(NSString*)username andPassword:(NSString*)password andCharsetName:(NSString*)charsetName andLocation:(CLLocation*)location andReturnProfile:(/*BOOL*/ NSNumber*)returnProfile andResponseFilters:(NSArray*)responseFilters;

- (void)loginWithFacebookWithToken:(NSString*)token andAgeRestriction:(NSNumber*)ageRestriction andLocation:(CLLocation*)location andReturnProfile:(/*BOOL*/ NSNumber*)returnProfile andResponseFilters:(NSArray*)responseFilters;

- (void)logoutWithAccountId:(NSNumber*)accountId andLocation:(CLLocation*)location;

- (void)notificationsWithAccountId:(NSNumber*)accountId andConnectionAccountId:(NSNumber*)connectionAccountId andEventTypes:(NSArray*)eventTypes andContentIds:(NSArray*)contentIds andContentTypes:(NSArray*)contentTypes andParentIds:(NSArray*)parentIds andParentTypes:(NSArray*)parentTypes andQuery:(NSString*)query andReturnReadMessages:(/*BOOL*/ NSNumber* /*BOOL*/)returnReadMessages andMarkAsRead:(/*BOOL*/ NSNumber* /*BOOL*/)markAsRead andFromDate:(NSTimeInterval)fromDate andLocation:(CLLocation*)location andStart:(NSNumber*)start andLimit:(NSNumber*)limit andDescending:(/*BOOL*/ NSNumber* /*BOOL*/)descending andAppKey:(NSString*)applicationKey;

- (void)offerLocationInviteWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andOfferLocationId:(NSNumber*)offerLocationId;

- (void)passwordChangeWithAccountId:(NSNumber*)accountId andOldPassword:(NSString*)oldPassword andNewPassword:(NSString*)newPassword andConfirmPassword:(NSString*)confirmPassword;

- (void)passwordResetWithToken:(NSString*)token andPassword:(NSString*)password andConfirmPassword:(NSString*)confirmPassword;

- (void)passwordResetRequestWithEmail:(NSString*)email andReferer:(NSString*)referer;

- (void)purchaseGiftWithAccountId:(NSNumber*)accountId andReceiverAccountId:(NSNumber*)receiverAccountId andTicketId:(NSNumber*)ticketId andAssetId:(NSNumber*)assetId andCustomMessage:(NSString*)customMessage;

- (void)purchaseWithCardOnFileWithAccountId:(NSNumber*)accountId andOfferLocationId:(NSNumber*)offerLocationId;

- (void)purchaseWithCreditOnFileWithAccountId:(NSNumber*)accountId andOfferLocationId:(NSNumber*)offerLocationId;

- (void)purchaseWithNewCardWithAccountId:(NSNumber*)accountId andOfferLocationId:(NSNumber*)offerLocationId andOfferId:(NSNumber*)offerId andOfferTransactionId:(NSString*)offerTransactionId andFirstName:(NSString*)firstName andLastName:(NSString*)lastName andAddress:(NSString*)address andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andPhone:(NSString*)phone andCreditCardNumber:(NSString*)creditCardNumber andExpirationDate:(NSString*)expirationDate andCCV:(NSString*)ccv;

- (void)redeemVoucherWithAccountId:(NSNumber*)accountId andFilters:(NSString*)filters;

- (void)regenerateAppDataWithAccountId:(NSNumber*)accountId;

- (void)regenerateThemeDescriptor;

- (void)registerApnsTokenWithAccountId:(NSNumber*)accountId andToken:(NSString*)token andActive:(/*BOOL*/ NSNumber* /*BOOL*/)active andLocation:(CLLocation*)location andPushType:(NSString*)pushType;

- (void)removeAchievementWithAccountId:(NSNumber*)accountId andAchievementId:(NSNumber*)achievementId;

- (void)removeAchievementTierWithAccountId:(NSNumber*)accountId andAchievementTierId:(NSNumber*)achievementTierId;

- (void)removeAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId;

- (void)removeAlbumContestWithAccountId:(NSNumber*)accountId andAlbumContestId:(NSNumber*)albumContestId andLocation:(CLLocation*)location;

- (void)removeApplicationWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey;

- (void)removeAudienceWithAccountId:(NSNumber*)accountId andAudienceId:(NSNumber*)audienceId;

- (void)removeBillableEntityWithAccountId:(NSNumber*)accountId;

- (void)removeConnectionWithAccountId:(NSNumber*)accountId andFriendAccountId:(NSNumber*)friendAccountId andNotifyFriend:(/*BOOL*/ NSNumber*)notifyFriend andRemoveFromGroups:(/*BOOL*/ NSNumber*)removeFromGroups;

- (void)removeConnectionFromGroupWithAccountId:(NSNumber*)accountId andConnectionId:(NSNumber*)connectionId andConnectionAccountId:(NSNumber*)connectionAccountId andPendingId:(NSNumber*)pendingId andGroupId:(NSNumber*)groupId andLocation:(CLLocation*)location;

- (void)removeConnectionsFromAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andConnectionIds:(NSArray*)connectionIds andConnectionGroupIds:(NSArray*)connectionGroupIds andRemoveFriendGroup:(/*BOOL*/ NSNumber*)removeFriendGroup;

- (void)removeEmployeeWithAccountId:(NSNumber*)accountId andEmployeeId:(NSNumber*)employeeId;

- (void)removeFavoriteWithAccountId:(NSNumber*)accountId andFavoriteId:(NSNumber*)favoriteId andFavoritableId:(NSNumber*)favoritableId andFavoritableType:(NSString*)favoritableType;

- (void)removeFlagWithAccountId:(NSNumber*)accountId andItemBeingFlaggedType:(enum ClassNameApiMap)itemBeingFlaggedType andItemBeingFlaggedId:(NSNumber*)itemBeingFlaggedId;

- (void)removeGameLevelWithAccountId:(NSNumber*)accountId andLevelId:(NSNumber*)levelId;

- (void)removeGroupWithAccountId:(NSNumber*)accountId andGroupId:(NSNumber*)groupId andLocation:(CLLocation*)location;

- (void)removeLikeWithAccountId:(NSNumber*)accountId andLikableType:(enum ClassNameApiMap)likableType andLikableId:(NSNumber*)likableId andLocation:(CLLocation*)location;

- (void)removeMediaWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andCollectionId:(NSNumber*)collectionId andContestId:(NSNumber*)contestId andRemoveFromAssetList2:(/*BOOL*/ NSNumber*)removeFromAssetList2 andAssetId:(NSNumber*)assetId andRemoveFromDefaultAlbums:(/*BOOL*/ NSNumber*)removeFromDefaultAlbums andLocation:(CLLocation*)location;

- (void)removeMissionWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId;

- (void)removeOfferWithAccountId:(NSNumber*)accountId andOfferId:(NSNumber*)offerId;

- (void)removeOfferLocationWithAccountId:(NSNumber*)accountId andOfferLocationId:(NSNumber*)offerLocationId;

- (void)removeRetailerWithAccountId:(NSNumber*)accountId andRetailerId:(NSNumber*)retailerId;

- (void)removeRetailerLocationWithAccountId:(NSNumber*)accountId andRetailerLocationId:(NSNumber*)retailerLocationId;

- (void)removeSubGroupsWithAccountId:(NSNumber*)accountId andGroupId:(NSNumber*)groupId andSubGroupIds:(NSArray*)subGroupIds andLocation:(CLLocation*)location;

- (void)removeThemeDescriptorWithAccountId:(NSNumber*)accountId andThemeDescriptorId:(NSNumber*)themeDescriptorId andLocation:(CLLocation*)location;

- (void)removeTriggerWithAccountId:(NSNumber*)accountId andTriggerId:(NSNumber*)triggerId;

- (void)removeUsersFromPermissionableWithAccountId:(NSNumber*)accountId andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andConnectionIds:(NSArray*)connectionIds andConnectionGroupIds:(NSArray*)connectionGroupIds andRemoveFriendGroup:(/*BOOL*/ NSNumber*)removeFriendGroup andLocation:(CLLocation*)location;

- (void)removeWalletWithAccountId:(NSNumber*)accountId andTransactionId:(NSNumber*)transactionId;

- (void)retailerLocationInviteWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andRetailerLocationId:(NSNumber*)retailerLocationId;

- (void)saveTrackingLegWithAccountId:(NSNumber*)accountId andDistance:(float)distance andDuration:(NSNumber*)duration andStartLocation:(CLLocation*)startLocation andEndLocation:(CLLocation*)endLocation andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andSteps:(NSString*)steps;

- (void)searchAchievementsWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andSortField:(enum AchievementApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)searchAlbumContestsWithAccountId:(NSNumber*)accountId andContestType:(NSString*)contestType andOwnerId:(NSNumber*)ownerId andKeyword:(NSString*)keyword andFilters:(NSArray*)filters andSortField:(enum AlbumContestApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andDateCreated:(NSTimeInterval)dateCreated andLocation:(CLLocation*)location;

- (void)searchAlbumsWithAccountId:(NSNumber*)accountId andOwnerId:(NSNumber*)ownerId andConnectionAccountId:(NSNumber*)connectionAccountId andKeyword:(NSString*)keyword andFilters:(NSArray*)filters andAlbumType:(NSString*)albumType andSortField:(enum AlbumApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andDateCreated:(NSTimeInterval)dateCreated andLocation:(CLLocation*)location andRange:(NSNumber*)range;

- (void)searchAlbumsByDistanceWithAccountId:(NSNumber*)accountId andOwnerId:(NSNumber*)ownerId andQuery:(NSString*)query andFilters:(NSArray*)filters andAlbumTypes:(NSArray*)albumTypes andStart:(NSNumber*)start andLimit:(NSNumber*)limit andDateCreated:(NSTimeInterval)dateCreated andLocation:(CLLocation*)location andRange:(/*double*/ NSNumber*)range;

- (void)searchApplicationsWithAccountId:(NSNumber*)accountId andLocation:(CLLocation*)location andQuery:(NSString*)query andQuerySearchFields:(NSArray*)querySearchFields andSortField:(enum ApplicationApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActive:(/*BOOL*/ NSNumber*)active;

- (void)searchAssetCollectionsWithAccountId:(NSNumber*)accountId andCollectionType:(NSString*)collectionType andOwnerId:(NSNumber*)ownerId andQuery:(NSString*)query andFilters:(NSArray*)filters andSortField:(enum AssetCollectionApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andDateCreated:(NSTimeInterval)dateCreated andLocation:(CLLocation*)location;

- (void)searchCategoriesWithCategoryId:(NSNumber*)categoryId andKeyword:(NSString*)keyword andRootOnly:(/*BOOL*/ NSNumber*)rootOnly andSortField:(enum CategoryApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly andAppKey:(NSString*)appKey;

- (void)searchConnectionsByNameWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andQuery:(NSString*)query andStart:(NSNumber*)start andLimit:(NSNumber*)limit andLocation:(CLLocation*)location;

- (void)searchConnectionsByRangeAndNameWithAccountId:(NSNumber*)accountId andFilters:(NSArray*)filters andQuery:(NSString*)query andPostalCode:(NSString*)postalCode andLocation:(CLLocation*)location andRange:(/*double*/ NSNumber*)range andLocationLastUpdated:(NSTimeInterval)locationLastUpdated andGender:(enum AudienceGender)gender andMinimumAge:(NSNumber*)minimumAge andMaximumAge:(NSNumber*)maximumAge andCompanionshipIndex:(NSNumber*)companionshipIndex andStart:(NSNumber*)start andLimit:(NSNumber*)limit andupdateCurrentLocation:(/*BOOL*/ NSNumber*)updateCurrentLocation andUpdatePreferredSettings:(/*BOOL*/ NSNumber*)updatePreferredSettings;

- (void)searchDataWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andObjectName:(NSString*)objectName andCriteria:(NSString*)criteria andCount:(/*BOOL*/ NSNumber*)count andStart:(NSNumber*)start andLimit:(NSNumber*)limit andOrder:(NSString*)order andInclude:(NSString*)include;

- (void)searchEmployeesWithAccountId:(NSNumber*)accountId andRole:(enum AccountType)role andKeyword:(NSString*)keyword andRetailerId:(NSNumber*)retailerId andRetailerLocationId:(NSNumber*)retailerLocationId andSortField:(enum AccountApiMap)sortField andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly;

- (void)searchEventTransactionsWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andRetailerId:(NSNumber*)retailerId andRetailerLocationId:(NSNumber*)retailerLocationId andListingId:(NSNumber*)listingId andOfferId:(NSNumber*)offerId andOfferLocationId:(NSNumber*)offerLocationId andCustomerAccountIds:(NSString*)customerAccountIds andAffiliatedCategoryIds:(NSString*)affiliatedCategoryIds andSortField:(enum OfferTransactionApiMap)sortField andDescending:(/*BOOL*/NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)searchFiltersWithQuery:(NSString*)query andTreeResponse:(/*BOOL*/ NSNumber*)treeResponse;

- (void)searchGlobalConfigsWithNames:(NSString*)names andKeyword:(NSString*)keyword andSortField:(enum GlobalConfigApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly;

- (void)searchLocationRatingIndexesWithCategoryIds:(NSString*)categoryIds andKeyword:(NSString*)keyword andFilters:(NSString*)filters andReturnOverallRating:(/*BOOL*/ NSNumber*)returnOverallRating andSortField:(enum RatingIndexApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andSearchRange:(NSNumber*)searchRange andLocation:(CLLocation*)location;

- (void)searchListingsWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andCategoryIds:(NSString*)categoryIds andStart:(NSNumber*)start andLimit:(NSNumber*)limit andLocation:(CLLocation*)location;

- (void)searchLocationsWithAccountId:(NSNumber*)accountId andCurrentLocation:(CLLocation*)currentLocation andQuery:(NSString*)query andZipcode:(NSString*)zipcode andLocation:(CLLocation*)selectedMapLocation andSearchRange:(/*double*/ NSNumber*)searchRange andStart:(NSNumber*)start andLimit:(NSNumber*)limit useGeocode:(NSNumber*)useGeocode;

- (void)searchMissionsWithAccountId:(NSNumber*)accountId andStart:(NSNumber*)start andLimit:(NSNumber*)limit andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData andIncludeAudiences:(/*BOOL*/ NSNumber*)includeAudiences andIncludeInactive:(/*BOOL*/ NSNumber*)includeInactive andSuffix:(NSString*)suffix;

- (void)searchMissionsByBillableEntityWithAccountId:(NSNumber*)accountId andStart:(NSNumber*)start andLimit:(NSNumber*)limit andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData andIncludeAudiences:(/*BOOL*/ NSNumber*)includeAudiences andIncludeInactive:(/*BOOL*/ NSNumber*)includeInactive andSuffix:(NSString*)suffix;

- (void)searchMissionInvitesWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andAppVersion:(NSString*)theAppVersion andMissionId:(NSNumber*)missionId andStatus:(enum MissionInviteStatus)missionInviteStatus andLastUpdated:(NSNumber*)lastUpdated andStart:(NSNumber*)start andLimit:(NSNumber*)limit andFilterByBillable:(/*BOOL*/ NSNumber*)filterByBillable andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData;

- (void)searchOffersForRetailersWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andRetailerId:(NSNumber*)retailerId andRetailerLocationId:(NSNumber*)retailerLocationid andOfferType:(enum OfferType)offerType andSpecialOfferType:(enum SpecialOfferType)specialOfferType andSortField:(enum OfferLocationApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly;

- (void)searchRatingIndexesWithRatableType:(NSString*)ratableType andRatableIds:(NSString *)ratableIds andCategoryIds:(NSString *)categoryIds andKeyword:(NSString *)keyword andSortField:(enum RatingIndexApiMap)sortField andDescending:(NSNumber *)descending andStart:(NSNumber *)start andLimit:(NSNumber *)limit andReturnRatable:(/*BOOL*/ NSNumber*)returnRatable andReturnOverallRating:(/*BOOL*/ NSNumber*)returnOverallRating;

-(void)searchRatingsWithAccountId:(NSNumber *)accountId andFilterAccountId:(NSNumber*)filterAccountId andRatableType:(NSString *)ratableType andRatableId:(NSNumber *)ratableId andCategoryIds:(NSString *)categoryIds andKeyword:(NSString *)keyword andSortField:(enum RatingIndexApiMap)sortField andDescending:(NSNumber *)descending andStart:(NSNumber *)start andLimit:(NSNumber *)limit;

- (void)searchRecipientsWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andConduit:(enum Conduits)conduit andStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)searchRetailerLocationsWithStart:(NSNumber*)start andLimit:(NSNumber*)limit andQuery:(NSString*)query andBooleanQuery:(NSString*)booleanQuery andSearchRange:(NSNumber*)searchRange andHasOffers:(/*BOOL*/ NSNumber*)hasOffers andCategories:(NSString*)categories andFilters:(NSString*)filters andSortField:(NSString*)sortField andLocation:(CLLocation*)location;

- (void)searchRetailerLocationsWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andSortField:(enum RetailerLocationApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly;

- (void)searchRetailerLocationsByRangeWithLocation:(CLLocation*)location andSearchRange:(/*double*/ NSNumber*)searchRange andCategories:(NSString*)categories andFilters:(NSString*)filters andStart:(NSNumber*)start andLimit:(NSNumber*)limit andKeyword:(NSString*)keyword andBooleanQuery:(NSString*)booleanQuery andHasOffers:(/*BOOL*/ NSNumber*)hasOffers andSortField:(NSString*)sortField;

- (void)searchRetailersWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andSortField:(enum RetailerApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly;

- (void)searchScoresWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andMissionId:(NSNumber*)missionId andGameId:(NSNumber*)gameId andPackId:(NSNumber*)packId andGameLevelId:(NSNumber*)gameLevelId andGameObjectId:(NSNumber*)gameObjectId;

- (void)searchThemeDescriptorsWithAccountId:(NSNumber*)accountId andContestType:(NSString*)contestType andOwnerId:(NSNumber*)ownerId andKeyword:(NSString*)keyword andFilters:(NSArray*)filters andSortField:(enum ThemeDescriptorApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andDateCreated:(NSTimeInterval)dateCreated andLocation:(CLLocation*)location;

- (void)searchWalletOffersWithAccountId:(NSNumber*)accountId andKeyword:(NSString*)keyword andRetailerId:(NSNumber*)retailerId andRetailerLocationId:(NSNumber*)retailerLocationId andOfferType:(enum OfferType)offerType andSortField:(enum RetailerApiMap)sortField andDescending:(/*BOOL*/ NSNumber* /*BOOL*/)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andLocation:(CLLocation*)location andRedeemed:(/*BOOL*/ NSNumber*)redeemed andActiveOnly:(/*BOOL*/ NSNumber*)activeOnly;

- (void)sendNotificationWithAccountId:(NSNumber*)accountId andReceiverAccountIds:(NSArray*)receiverAccountIds andContentId:(NSNumber*)contentId andContentName:(NSString*)contentName andContentType:(NSString*)contentType andParentId:(NSNumber*)parentId andParentType:(NSString*)parentType andCustomMessage:(NSString*)customMessage andLocation:(CLLocation*)location andAppKey:(NSString*)appkey conduit:(NSString*)conduit;

- (void)signUpSecureWithName:(NSString*)name andPrefixName:(NSString*)prefixName andFirstName:(NSString*)firstName andMiddleName:(NSString*)middleName andLastName:(NSString*)lastName andSuffixName:(NSString*)suffixName andTitle:(NSString*)title andEmail:(NSString*)email andPassword:(NSString*)password andAddress:(NSString*)address andZipcode:(NSString*)zipcode andGender:(enum AudienceGender)gender andBirthday:(NSTimeInterval)birthday andHomePhone:(NSString*)homePhone andCellPhone:(NSString*)cellPhone andCellPhoneCarrier:(enum CellPhoneCarrierMap)cellPhoneCarrier andBusinessPhone:(NSString*)businessPhone andRole:(enum Role)role andPlatforms:(NSArray*)platforms andTags:(NSArray*)tags andGameExperience:(enum GameExperienceLevel)gameExperience andHometown:(NSString*)hometown andHeight:(NSString*)height andHeightIndex:(NSNumber*)heightIndex andEthnicity:(NSString*)ethnicity andBodyType:(NSString*)bodyType andMaritalStatus:(NSString*)maritalStatus andChildren:(NSString*)children andReligion:(NSString*)religion andEducation:(NSString*)education andEducationIndex:(NSNumber*)educationIndex andSmoke:(NSString*)smoke andDrink:(NSString*)drink andCompanionship:(NSString*)companionship andCompanionshipIndex:(NSNumber*)companionshipIndex andPreferredMinAge:(NSNumber*)preferredMinAge andPreferredMaxAge:(NSNumber*)preferredMaxAge andPreferredMinHeight:(NSNumber*)preferredMinHeight andPreferredMaxHeight:(NSNumber*)preferredMaxHeight andPreferredGender:(enum AudienceGender)preferredGender andPreferredEducation:(NSString*)preferredEducation andPreferredEducationIndex:(NSNumber*)preferredEducationIndex andPreferredBodyType:(NSString*)preferredBodyType andPreferredEthnicity:(NSString*)preferredEthnicity andPreferredLocation:(NSString*)preferredLocation andPreferredLocationRange:(/*double*/ NSNumber*)preferredLocationRange andLocation:(CLLocation*)location andAcceptedTerms:(/*BOOL*/ NSNumber*)acceptedTerms andResponseType:(NSString*)responseType;

- (void)getTopOfferTransactionsWithStart:(NSNumber*)start andLimit:(NSNumber*)limit;

- (void)updateAccountLocationWithAccountId:(NSNumber*)accountId andLocation:(CLLocation*)location;

- (void)updateAlbumWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andAssetId:(NSNumber*)assetId andTitle:(NSString*)title andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andTags:(NSArray*)tags andDescription:(NSString*)description andPublicRead:(/*BOOL*/ NSNumber*)publicRead andPublicWrite:(/*BOOL*/ NSNumber*)publicWrite andPublicDelete:(/*BOOL*/ NSNumber*)publicDelete andPublicAdd:(/*BOOL*/ NSNumber*)publicAdd andLocation:(CLLocation*)location andAlbumType:(NSString*)albumType andLocationDescription:(NSString*)locationDescription andVisiblity:(enum Visibility)visibility andAnonymous:(/*BOOL*/ NSNumber*)anonymous;

- (void)updateAlbumNotificationsWithAccountId:(NSNumber*)accountId andAlbumId:(NSNumber*)albumId andBlocked:(/*BOOL*/ NSNumber*)blocked andNotifications:(/*BOOL*/ NSNumber*)notifications;

- (void)updateAppDataWithAccountId:(NSNumber*)accountId andIncludeGameData:(/*BOOL*/ NSNumber*)includeGameData andKeyword:(NSString*)keyword andSortField:(enum GameLevelApiMap)sortField andDescending:(/*BOOL*/ NSNumber*)descending andStart:(NSNumber*)start andLimit:(NSNumber*)limit andGameObjectCount:(/*BOOL*/ NSNumber*)gameObjectCount andFilter:(enum Ownership)filter andDateCreated:(NSTimeInterval)dateCreated andOwnerId:(NSNumber*)ownerId andMissionIds:(NSArray*)missionIds andChallengeIds:(NSArray*)challengeIds andGameIds:(NSArray*)gameIds andPackIds:(NSArray*)packIds andGameLevelIds:(NSArray*)gameLevelIds andIncludeHigherVersionPacks:(/*BOOL*/ NSNumber*)includeHigherVersionPacks andIncludeHigherVersionLevels:(/*BOOL*/ NSNumber*)includeHigherVersionLevels andResponseGroups:(NSArray*)responseGroups andPurchaseType:(enum PurchaseType)purchaseType andData:(NSString*)data;

- (void)updateApplicationActiveWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andActive:(/*BOOL*/ NSNumber*)active;

- (void)updateBillableEntityWithAccountId:(NSNumber*)accountId andName:(NSString*)name andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andBusinessPhone:(NSString*)businessPhone andBusinessPhoneExt:(NSString*)businessPhoneExt;

- (void)updateDataWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andObjectName:(NSString*)objectName andObjectId:(NSString*)objectId andData:(NSString*)data;

- (void)updateEmployeeWithAccountId:(NSNumber*)accountId andEmployeeId:(NSNumber*)employeeId andManagerId:(NSNumber*)managerId andPrefixName:(NSString*)prefixName andFirstName:(NSString*)firstName andMiddleName:(NSString*)middleName andLastName:(NSString*)lastName andSuffixName:(NSString*)suffixName andStreet:(NSString*)street andZipcode:(NSString*)zipcode andHomePhone:(NSString*)homePhone andCellPhone:(NSString*)cellPhone andGender:(enum AudienceGender)gender andRole:(enum AccountType)role;

- (void)updateGameLevelWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andLevelId:(NSNumber*)levelId andName:(NSString*)name andDescription:(NSString*)description andDifficulty:(enum GameDifficulty)difficulty andAppVersion:(NSNumber*)levelAppVersion andAssetImageId:(NSNumber*)assetImageId andAssetIconId:(NSNumber*)assetIconId andGameData:(NSString*)gameData andGameDataSuffix:(NSString*)gameDataSuffix andVisibility:(enum Visibility)visibility andFriendGroup:(/*BOOL*/ NSNumber*)friendGroup andConnectionIds:(NSArray*)connectionIds andConnectionGroupIds:(NSArray*)connectionGroupIds andBalance:(NSNumber*)balance andActive:(/*BOOL*/ NSNumber*)active andAllocateTickets:(/*BOOL*/ NSNumber*)allocateTickets;

- (void)updateListingWithAccountId:(NSNumber*)accountId listingId:(NSNumber*)listingId name:(NSString*)name filterIds:(NSString*)filterIds description:(NSString*)description start:(NSNumber*)start end:(NSNumber*)end locationName:(NSString*)locationName locationDescription:(NSString*)locationDescription isPrivate:(/*BOOL*/ NSNumber* /*BOOL*/)isPrivate externalId:(NSString*)externalId externalGroupId:(NSString*)externalGroupId active:(/*BOOL*/ NSNumber* /*BOOL*/)active;

- (void)updateMatchMakingTokenWithAccountId:(NSNumber*)accountId andMatchToken:(NSString*)matchToken andLocation:(CLLocation*)location;

- (void)updateMediaWithAccountId:(NSNumber*)accountId andAssetId:(NSNumber*)assetId andAlbumId:(NSNumber*)albumId andAttachedAssetId:(NSNumber*)attachedAssetId andCaption:(NSString*)caption andLocationDescription:(NSString*)locationDescription andLocation:(CLLocation*)location;

- (void)updateMissionWithAccountId:(NSNumber*)accountId andMissionId:(NSNumber*)missionId andTitle:(NSString*)title andDescription:(NSString*)description andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andActive:(/*BOOL*/ NSNumber*)active andGameLevelIds:(NSArray*)gameLevelIds andAudienceIds:(NSString*)audienceIds andOfferId:(NSNumber*)offerId andBalance:(NSNumber*)balance;

- (void)updateMissionInviteWithAccountId:(NSNumber *)accountId andMissionId:(NSNumber *)missionId andMissionInviteId:(NSNumber*)missionInviteId andMissionInviteStatus:(enum MissionInviteStatus)missionInviteStatus andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber *)permissionableId andIncludeGameData:(NSNumber *)includeGameData;

- (void)updateNoteWithAccountId:(NSNumber*)accountId andNoteId:(NSNumber*)noteId andComment:(NSString*)comment andAssetIds:(NSArray*)assetIds andTags:(NSArray*)tags andPermissionableType:(enum PermissionableType)permissionableType andPermissionableId:(NSNumber*)permissionableId andAppKey:(NSString*)appKey andLocationDescription:(NSString*)locationDescription andLocation:(CLLocation*)location;

- (void)updateOfferWithAccountId:(NSNumber*)accountId offerId:(NSNumber*)offerId retailerLocationIds:(NSArray*)retailerLocationIds title:(NSString*)title subTitle:(NSString*)subTitle details:(NSString*)details subDetails:(NSString*)subDetails finePrint:(NSString*)finePrint barCodeType:(enum BarCodeType)barCodeType barCodeEntry:(NSString*)barCodeEntry externalRedeemOptions:(NSString*)externalRedeemOptions ticketsReward:(NSNumber*)ticketsReward activated:(NSNumber*)activated expires:(NSNumber*)expires noExpiration:(/*BOOL*/ NSNumber* /*BOOL*/)noExpiration availableLimit:(NSNumber*)availableLimit availableLimitPerUser:(NSNumber*)availableLimitPerUser addedLimit:(NSNumber*)addedLimit viewLimit:(NSNumber*)viewLimit maxPrints:(NSNumber*)maxPrints ticketPrice:(NSNumber*)ticketPrice fullPrice:(NSNumber*)fullPrice discountPrice:(NSNumber*)discountPrice showRemaining:(/*BOOL*/ NSNumber* /*BOOL*/)showRemaining showRedeemed:(/*BOOL*/ NSNumber* /*BOOL*/)showRedeemed replaced:(/*BOOL*/ NSNumber* /*BOOL*/)replaced featured:(/*BOOL*/ NSNumber* /*BOOL*/)featured offerType:(enum OfferType)offerType specialOfferType:(enum SpecialOfferType)specialOfferType offerVisibility:(enum OfferVisibility)offerVisibility categoryIds:(NSArray*)categoryIds filterIds:(NSArray*)filterIds active:(/*BOOL*/ NSNumber* /*BOOL*/)active barcodeAssetId:(NSNumber*)barcodeAssetId imageAssetId:(NSNumber*)imageAssetId imageAssetId1:(NSNumber*)imageAssetId1 imageAssetId2:(NSNumber*)imageAssetId2 imageAssetId3:(NSNumber*)imageAssetId3 imageAssetId4:(NSNumber*)imageAssetId4 imageAssetId5:(NSNumber*)imageAssetId5 publisher:(NSString*)publisher redeemableStart:(NSNumber*)redeemableStart redeemableEnd:(NSNumber*)redeemableEnd brand:(NSString*)brand productType:(enum ProductType)productType conditionType:(enum ConditionType)conditionType isbn:(NSString*)isbn asin:(NSString*)asin catelogNumbers:(NSString*)catelogNumbers department:(NSString*)department features:(NSString*)features minimumPrice:(NSNumber*)minimumPrice width:(NSNumber*)width height:(NSNumber*)height depth:(NSNumber*)depth weight:(NSNumber*)weight unit:(enum UnitType)unit studio:(NSString*)studio parentalRating:(NSString*)parentalRating publishDate:(NSNumber*)publishDate availabilityDate:(NSNumber*)availabliltyDate sizeId:(NSNumber*)sizeId listingId:(NSNumber*)listingId duration:(NSNumber*)duration author:(NSString*)author releaseDate:(NSNumber*)releaseDate;

- (void)updateOfferStatusWithAccountId:(NSNumber*)accountId andOfferIds:(NSArray*)offerIds andActive:(/*BOOL*/ NSNumber*)active;

- (void)updatePaymentMethodWithAccountId:(NSNumber*)accountId andCreditCardNumber:(NSString*)creditCardNumber andExpirationDate:(NSString*)expirationDate andName:(NSString*)name andCCV:(NSString*)ccv;

- (void)updateProfileWithAccountId:(NSNumber*)accountId andAssetId:(NSNumber*)assetId andName:(NSString*)name andPrefixName:(NSString*)prefixName andFirstName:(NSString*)firstName andMiddleName:(NSString*)middleName andLastName:(NSString*)lastName andSuffixName:(NSString*)suffixName andGender:(enum AudienceGender)gender andAge:(NSNumber*)age andBirthday:(NSTimeInterval)birthday andHomePhone:(NSString*)homePhone andCellPhone:(NSString*)cellPhone andBusinessPhone:(NSString*)businessPhone andMakeProfileInfoPublic:(/*BOOL*/ NSNumber*)makeProfileInfoPublic andMakeGameInfoPublic:(/*BOOL*/ NSNumber*)makeGameInfoPublic andMakeFriendsInfoPublic:(/*BOOL*/ NSNumber*)makeFriendsInfoPublic andStreetAddress:(NSString*)streetAddress andHometown:(NSString*)hometown andZipcode:(NSString*)zipCode andHeight:(NSString*)height andHeightIndex:(NSNumber*)heightIndex andEthnicity:(NSString*)ethnicity andBodyType:(NSString*)bodyType andMaritalStatus:(NSString*)maritalStatus andChildren:(NSString*)children andReligion:(NSString*)religion andEducation:(NSString*)education andEducationIndex:(NSNumber*)educationIndex andSmoke:(NSString*)smoke andDrink:(NSString*)drink andCompanionship:(NSString*)companionship andCompanionshipIndex:(NSNumber*)companionshipIndex andPreferredMinAge:(NSNumber*)preferredMinAge andPreferredMaxAge:(NSNumber*)preferredMaxAge andPreferredMinHeight:(NSNumber*)preferredMinHeight andPreferredMaxHeight:(NSNumber*)preferredMaxHeight andPreferredGender:(enum AudienceGender)preferredGender andPreferredEducation:(NSString*)preferredEducation andPreferredEducationIndex:(NSNumber*)preferredEducationIndex andPreferredBodyType:(NSString*)preferredBodyType andPreferredEthnicity:(NSString*)preferredEthnicity andPreferredLocation:(NSString*)preferredLocation andPreferredLocationRange:(/*double*/ NSNumber*)preferredLocationRange andPlatforms:(NSArray*)platforms andMatchToken:(NSString*)matchToken andInterests:(NSArray*)interests andResponseFilters:(NSArray*)responseFilters andShowAsZipcode:(/*BOOL*/ NSNumber*)showAsZipcode andShowExactLocation:(/*BOOL*/ NSNumber*)showExactLocation andShowOthersLocation:(/*BOOL*/ NSNumber*)showOthersLocation andAcceptedTerms:(/*BOOL*/ NSNumber*)acceptedTerms andLocation:(CLLocation*)location;

- (void)updateRatingWithAccountId:(NSNumber*)accountId andRatingId:(NSNumber*)ratingId andRatingValue:(NSNumber*)ratingValue andCategoryId:(NSNumber*)categoryId andLocationDescription:(NSString*)locationDescription andLocation:(CLLocation*)location;

- (void)updateSettingsWithAccountId:(NSNumber*)accountId andBlockedNotifications:(NSArray*)blockedNotifications andSugestionMethod:(enum Conduits)suggestionMethod andSuggestionCount:(NSNumber*)suggestionCount andSuggestionTimeFrame:(NSNumber*)suggestionTimeFrame andShowExactLocation:(/*BOOL*/ NSNumber*)showExactLocation andLocation:(CLLocation*)location;

- (void)updateTicketWithAccountId:(NSNumber*)accountId andActionType:(enum TicketActionType)actionType andTicketObjectType:(enum TicketObjectType)ticketObjectType andObjectId:(NSNumber*)objectId andPurchaseCode:(NSString*)purchaseCode andReceiptToken:(NSString*)receiptToken andReceiptData:(NSString*)receiptData andCount:(NSNumber*)count andPurchaseProvider:(enum PurchaseType)purchaseProvider andPurchaseTypes:(NSArray*)purchaseTypes andReturnProfileResponse:(/*BOOL*/ NSNumber*)returnProfileResponse andIncludeProfileResponse:(/*BOOL*/ NSNumber*)includeProfileResponse;

- (void)updateTriggerWithAccountId:(NSNumber*)accountId andTriggerId:(NSNumber*)triggerId andName:(NSString*)name andRadius:(/*double*/ NSNumber*)radius andGender:(enum AudienceGender)gender andAges:(NSArray*)ages andGameExperiences:(NSArray*)gameExperiences andInterests:(NSArray*)interests;

- (void)updateVoucherStatusWithAccountId:(NSNumber*)accountId andOfferTransactionId:(NSNumber*)offerTransactionId andStatus:(NSNumber*)theStatus;

- (void)updateWalletOfferStatusWithAccountId:(NSNumber*)accountId andTransactionId:(NSNumber*)transactionId andOfferLocationId:(NSNumber*)offerLocationId andUsePoints:(/*BOOL*/ NSNumber*)usePoints andStatus:(NSNumber*)theStatus;

- (void)validateAccountSignupWithToken:(NSString*)token;

- (void)validatePasswordResetWithToken:(NSString*)token;

- (void)validateSubscriptionWithAccountId:(NSNumber*)accountId andLocation:(CLLocation*)location andResponseFilters:(NSArray*)responseFilters;

- (void)voteOnAlbumContestWithAccountId:(NSNumber*)accountId andAlbumContestId:(NSNumber*)albumContestId andAlbumId:(NSNumber*)albumId andContestType:(NSString*)contestType andLocation:(CLLocation*)location;

- (void)whoHasFavoritedWithAccountId:(NSNumber*)accountId andFavoritableId:(NSNumber*)favoritableId andFavoritableType:(NSString*)favoritableType andKeyword:(NSString*)keyword andStart:(NSNumber*)start andlimit:(NSNumber*)limit andLocation:(CLLocation*)location;

#pragma mark - ASI methods

- (void)addAchievementTierWithAccountId:(NSNumber*)accountId andAchievementId:(NSNumber*)achievementId andIcon:(UIImage*)icon andTitle:(NSString*)title andDescription:(NSString*)description andGoalCount:(NSNumber*)goalCount;

- (void)addAlbumWithAccountId:(NSNumber*)accountId andTitle:(NSString*)title andMedia:(NSData*)media andAttachedMedia:(NSData*)attachedMedia andAttachedMediaIsVideo:(/*BOOL*/ NSNumber*)attachedMediaIsVideo andAttachedMediaURL:(NSString*)attachedMediaURL andCoverAssetNullable:(/*BOOL*/ NSNumber*)coverAssetNullable andStartDate:(NSTimeInterval)startDate andEndDate:(NSTimeInterval)endDate andTags:(NSArray*)tags andDescription:(NSString*)description andPublicRead:(/*BOOL*/ NSNumber*)publicRead andpublicWrite:(/*BOOL*/ NSNumber*)publicWrite andPublicDelete:(/*BOOL*/ NSNumber*)publicDelete andPublicAdd:(/*BOOL*/ NSNumber*)publicAdd andLocation:(CLLocation*)location andLocationDescription:(NSString*)locationDescription andAlbumType:(NSString*)albumType andVisibility:(enum Visibility)visibility andIncludeCoverInAssetList:(/*BOOL*/ NSNumber*)includeCoverInAssetList andAnonymous:(/*BOOL*/ NSNumber*)anonymous;

- (void)addMediaWithAccountId:(NSNumber*)accountId andAssetId:(NSNumber*)assetId andAlbumId:(NSNumber*)albumId andCollectionId:(NSNumber*)collectionId andAddToDefaultAlbum:(enum DefaultAlbumType)addToDefaultAlbum andCaption:(NSString*)caption andLocationDescription:(NSString*)locationDescription andLocation:(CLLocation*)location andNotificationMessage:(NSString*)notificationMessage andMedia:(NSData*)media andMediaContentType:(NSString*)contentType andMediaFileExtension:(NSString*)fileExtension andAttachedMedia:(NSData*)attachedMedia andAttachedMediaUrl:(NSString*)attachedMediaUrl andAttachedMediaContentType:(NSString*)attachedContentType andAttachedMediaFileExtension:(NSString*)attachedFileExtension;

- (void)addOrUppdateApplicationWithAccountId:(NSNumber*)accountId andAppName:(NSString*)appName andAbout:(NSString*)about andBundleId:(NSString*)bundleId andCertificateFilePath:(NSString*)certificateFilePath andAppIcon:(NSData*)appIcon andFacebookAppId:(NSString*)facebookAppId andFacebookAppSecret:(NSString*)facebookAppSecret andUpdateEULADate:(/*BOOL*/ NSNumber*)updateEULADate andEulaVersion:(NSString*)eulaVersion andLandingPageUrl:(NSString*)landingPageUrl andShowInActivities:(/*BOOL*/ NSNumber*)showInActivities andActivityDescription:(NSString*)activityDescription andCssClass:(NSString*)cssClass andInviteWelcomeText:(NSString*)inviteWelcomeText andInvitePageUrl:(NSString*)invitePageUrl andScoringType:(enum ScoringType)scoringType andHintCost:(NSString*)hintCost andMaxScore:(NSNumber*)maxScore andTicketsPerPoint:(float)ticketsPerPoint andHasGameData:(/*BOOL*/ NSNumber*)hasGameData andGlobalTickets:(/*BOOL*/ NSNumber*)globalTickets andBuildVersion:(float)buildVersion andApiVersion:(float)theApiVersion andResponseFormat:(enum ResponseFormat)responseFormat;

- (void)addOrUpdateScoreWithAccountId:(NSNumber*)accountId andAppKey:(NSString*)appKey andMissionId:(NSNumber*)missionId andGameId:(NSNumber*)gameId andPackId:(NSNumber*)packId andGameLevelId:(NSNumber*)gameLevelId andGameObjectId:(NSNumber*)gameObjectId andPoints:(NSNumber*)points andTimeTaken:(NSNumber*)timeTaken;

- (void)addOrUpdateThemeDescriptorWithAccountId:(NSNumber*)accountId andThemeDescriptorId:(NSNumber*)themeDescriptorId andTitle:(NSString*)title andDescription:(NSString*)description andPublicRead:(/*BOOL*/ NSNumber*)publicRead andPublicWrite:(/*BOOL*/ NSNumber*)publicWrite andPublicDelete:(/*BOOL*/ NSNumber*)publicDelete andPublicAdd:(/*BOOL*/ NSNumber*)publicAdd andVisibility:(enum Visibility)visibility andConnectionIdsToAdd:(NSArray*)connectionIdsToAdd andConnectionGroupIdsToAdd:(NSArray*)connectionGroupIdsToAdd andIncludeFriendGroup:(/*BOOL*/ NSNumber*)includeFriendGroup andColorValueJson:(NSString*)colorValueJson andStringReplacerJson:(NSString*)stringReplacerJson andCustomJsonObjects:(NSString*)customJsonObjects andIconImage:(NSData*)iconImage andSceneAtlasImage:(NSData*)sceneAtlasImage andBgImage:(NSData*)bgImage andBgSound:(NSData*)bgSound andMusicSelection:(NSString*)musicSelection andCompleteWithDefaultValues:(/*BOOL*/ NSNumber*)completeWithDefaultValues andLocationDescription:(NSString*)locationDescription andLocation:(CLLocation*)location;

- (void)addRetailerWithAccountId:(NSNumber*)accountId andName:(NSString*)name andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andBusinessPhone:(NSString*)businessPhone andBusinessPhoneExt:(NSString*)businessPhoneExt andWebsite:(NSString*)website andFacebookUrl:(NSString*)facebookUrl andTwitterUrl:(NSString*)twitterUrl andLogo:(NSData*)logo andLogoAssetId:(NSNumber*)logoAssetId andPicture1:(NSData*)picture1 andPicture1AssetId:(NSNumber*)picture1AssetId andPicture2:(NSData*)picture2 andPicture2AssetId:(NSNumber*)picture2AssetId andCategoryIds:(NSArray*)categoryIds andFilterIds:(NSArray*)filterIds andLocation:(CLLocation*)location andResponseFormat:(enum ResponseFormat)responseFormat andCreateDefaultLocation:(/*BOOL*/ NSNumber*)createDefaultLocation;

- (void)addRetailerLocationWithAccountId:(NSNumber*)accountId andRetailerId:(NSNumber*)retailerId andName:(NSString*)name andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andBusinessPhone:(NSString*)businessPhone andBusinessPhoneExt:(NSString*)businessPhoneExt andWebsite:(NSString*)website andInternalId:(NSString*)internalId andDetailsHeader:(NSString*)detailsHeader andDetailsBody:(NSString*)detailsBody andHours:(NSString*)hours andLogo:(NSData*)logo andPicture1:(NSData*)picture1 andPicture2:(NSData*)picture2 andCategoryIds:(NSArray*)categoryIds andFilterIds:(NSArray*)filterIds andLocation:(CLLocation*)location andResponseFormat:(enum ResponseFormat)responseFormat;

- (void)addSubGroupsWithAccountId:(NSNumber*)accountId andGroupId:(NSNumber*)groupId andSubGroupIds:(NSArray*)subGroupIds andLocation:(CLLocation*)location;

- (void)importApplicationSalesWithPurchaseProvider:(NSString*)purchaseProvider andData:(NSString*)data;

- (void)updateRetailerWithAccountId:(NSNumber*)accountId andRetailerId:(NSNumber*)retailerId andName:(NSString*)name andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andBusinessPhone:(NSString*)businessPhone andBusinessPhoneExt:(NSString*)businessPhoneExt andWebsite:(NSString*)website andFacebookUrl:(NSString*)facebookUrl andTwitterUrl:(NSString*)twitterUrl andLogo:(NSData*)logo andPicture1:(NSData*)picture1 andPicture2:(NSData*)picture2 andCategoryIds:(NSArray*)categoryIds andFilterIds:(NSArray*)filterIds andLocation:(CLLocation*)location andResponseFormat:(enum ResponseFormat)responseFormat;

- (void)updateRetailerLocationWithAccountId:(NSNumber*)accountId andRetailerLocationId:(NSNumber*)retailerLocationId andName:(NSString*)name andStreetAddress:(NSString*)streetAddress andStreetAddress2:(NSString*)streetAddress2 andCity:(NSString*)city andState:(NSString*)state andPostalCode:(NSString*)postalCode andBusinessPhone:(NSString*)businessPhone andBusinessPhoneExt:(NSString*)businessPhoneExt andWebsite:(NSString*)website andInternalId:(NSString*)internalId andDetailsHeader:(NSString*)detailsHeader andDetailsBody:(NSString*)detailsBody andHours:(NSString*)hours andLogo:(NSData*)logo andPicture1:(NSData*)picture1 andPicture2:(NSData*)picture2 andCategoryIds:(NSArray*)categoryIds andFilterIds:(NSArray*)filterIds andLocation:(CLLocation*)location andResponseFormat:(enum ResponseFormat)responseFormat;

- (void)updateTicketWithFileUploadWithAccountId:(NSNumber*)accountId andActionType:(enum TicketActionType)actionType andTicketObjectType:(enum TicketObjectType)ticketObjectType andObjectId:(NSNumber*)objectId andPurchaseCode:(NSString*)purchaseCode andReceiptToken:(NSString*)receiptToken andReceiptDate:(NSData*)receiptData andCount:(NSNumber*)count andPurchaseProvider:(enum PurchaseType)purchaseProvider andPurchaseTypes:(NSArray*)purchaseTypes andReturnProfileResponse:(/*BOOL*/ NSNumber*)returnProfileResponse andIncludeProfileResponse:(/*BOOL*/ NSNumber*)includeProfileResponse;


- (void)quickAnalyticWithAccountId:(NSNumber*)accountId andTag:(NSString*)tag andCustomId:(NSNumber*)customId andLocation:(CLLocation*)location andErrorMessage:(NSString*)errorMessage;

- (void)quickSignUpWithName:(NSString*)name andEmail:(NSString*)email andPassword:(NSString*)password;

- (void)doPostWithUri:(NSString*)uri postParameters:(NSString*)postParameters;

- (void)cancel;

@end