//
//  SirqulEnums.h
//  SirqulNetworkInterface
//
//  Created by Josh Clarke on 8/2/13.
//  Copyright (c) 2013 Sirqul. All rights reserved.
//

#import <Foundation/Foundation.h>

enum PermissionableType {
    kPermissionableTypeACCOUNT = 0,
    kPermissionableTypeALBUM = 1,
    kPermissionableTypeALBUM_CONTEST = 2,
    kPermissionableTypeCOLLECTION = 3,
    kPermissionableTypeGAMELEVEL = 4,
    kPermissionableTypeNULL = 5,
    kPermissionableTypeTHEME_DESCRIPTOR = 6
};

enum AudienceGender {
    kAudienceGenderANY = 7,
    kAudienceGenderFEMALE = 8,
    kAudienceGenderMALE = 9,
    kAudienceGenderNULL = 10
};

enum AccountType {
    kAccountTypeAGENT = 11,
    kAccountTypeDEVELOPER = 12,
    kAccountTypeEXECUTIVE = 13,
    kAccountTypeGUEST = 14,
    kAccountTypeMEMBER = 15,
    kAccountTypeNULL = 16,
    kAccountTypePARTNER = 17,
    kAccountTypePREMIUM_MEMBER = 18,
    kAccountTypeRETAILER = 19,
    kAccountTypeRETAILER_GROUP = 20,
    kAccountTypeRETAILER_LIMITED = 21
};

enum ClassNameApiMap {
    kClassNameApiMapACCOUNT = 22,
    kClassNameApiMapALBUM = 23,
    kClassNameApiMapALBUM_CONTEST = 24,
    kClassNameApiMapASSET = 25,
    kClassNameApiMapCOLLECTION = 26,
    kClassNameApiMapGAME_LEVEL = 27,
    kClassNameApiMapNOTE = 28,
    kClassNameApiMapNULL = 29
};

enum BarCodeType {
    kBarCodeTypeCODE_128 = 30,
    kBarCodeTypeCUSTOM_MEDIA = 31,
    kBarCodeTypeNONE = 32,
    kBarCodeTypeNULL = 33,
    kBarCodeTypeUPC = 34
};

enum OfferType {
    kOfferTypeCOUPON = 35,
    kOfferTypeEVENT = 36,
    kOfferTypeMEDIA = 37,
    kOfferTypeNULL = 38,
    kOfferTypePRODUCT = 39,
    kOfferTypeVOUCHER = 40
};

enum CouponType {
    kCouponTypeCOUPON = 41,
    kCouponTypeNULL = 42,
    kCouponTypeVOUCHER = 43
};

enum SpecialOfferType {
    kSpecialOfferTypeACT_NOW = 44,
    kSpecialOfferTypeALL = 45,
    kSpecialOfferTypeGET_THERE_NOW = 46,
    kSpecialOfferTypeNULL = 47,
    kSpecialOfferTypeREGULAR_OFFER = 48,
    kSpecialOfferTypeSQOOT = 49,
    kSpecialOfferTypeTICKETS = 50
};

enum OfferVisibility {
    kOfferVisibilityALL_MISSIONS = 51,
    kOfferVisibilityMY_MISSIONS = 52,
    kOfferVisibilityNULL = 53,
    kOfferVisibilityPUBLIC = 54
};

enum RankType {
    kRankTypeACTIONS = 55,
    kRankTypeCREATIONS = 56,
    kRankTypeDOWNLOADS = 57,
    kRankTypeINVITATIONS = 58,
    kRankTypeNULL = 59,
    kRankTypePOINTS = 60,
    kRankTypeREDEEMED = 61,
    kRankTypeVOTES = 62
};

enum Visibility {
    kVisibilityNULL = 63,
    kVisibilityPRIVATE = 64,
    kVisibilityPUBLIC = 65
};

enum AgeGroup {
    kAgeGroupAGE_0_13 = 66,
    kAgeGroupAGE_14_17 = 67,
    kAgeGroupAGE_18_22 = 68,
    kAgeGroupAGE_23_30 = 69,
    kAgeGroupAGE_31_54 = 70,
    kAgeGroupAGE_55_PLUS = 71,
    kAgeGroupNULL = 72
};

enum GameExperienceLevel {
    kGameExperienceLevelANY = 73,
    kGameExperienceLevelBEGINNER = 74,
    kGameExperienceLevelEXPERT = 75,
    kGameExperienceLevelINTERMEDIATE = 76,
    kGameExperienceLevelNEW = 77,
    kGameExperienceLevelNULL = 78
};

enum Events {
    kEventsACCOUNT_LIKE = 79,
    kEventsALBUM_LIKE = 80,
    kEventsALBUM_NOTE = 81,
    kEventsALBUM_PHOTOS_ADDED = 82,
    kEventsALBUM_SHARED = 83,
    kEventsASSET_LIKE = 84,
    kEventsASSET_NOTE = 85,
    kEventsASSIGNMENT_CHANGE = 86,
    kEventsCHALLENGE = 87,
    kEventsCOLLECTION_ASSETS_ADDED = 88,
    kEventsCOLLECTION_LIKE = 89,
    kEventsCOLLECTION_NOTE = 90,
    kEventsCOLLECTION_SHARED = 91,
    kEventsCOMMENT = 92,
    kEventsCUSTOM = 93,
    kEventsEARN_COMMISSION_TICKETS = 94,
    kEventsFEEDBACK = 95,
    kEventsFOLLOW = 96,
    kEventsFRIEND_ADDED = 97,
    kEventsFRIEND_REMOVED = 98,
    kEventsFRIEND_REQUEST_ACCEPTED = 99,
    kEventsFRIEND_REQUEST_REJECTED = 100,
    kEventsFRIEND_REQUESTED = 101,
    kEventsGAME_LEVEL_LIKE = 102,
    kEventsGAME_LEVEL_NOTE = 103,
    kEventsLIKE = 104,
    kEventsNEW_SIGNUP = 105,
    kEventsNOTE_LIKE = 106,
    kEventsNULL = 107,
    kEventsPARTNER_CODE_INVITE = 108,
    kEventsPARTNER_EXISTING_INVITE = 109,
    kEventsPARTNER_INVITE = 110,
    kEventsPASSWORD_CHANGED = 111,
    kEventsPROFILE_PROXIMITY = 112,
    kEventsPURCHASE_ITEM_GIFTED = 113,
    kEventsREASSIGNMENT_REQUEST = 114,
    kEventsRESET_PASSWORD = 115,
    kEventsSUGGESTION_RECEIVED = 116,
    kEventsVALIDATE_MEMBER = 117,
    kEventsVOUCHER_PURCHASED = 118,
    kEventsWELCOME_BUSINESS = 119,
    kEventsWELCOME_EMAIL = 120,
    kEventsWELCOME_PARTNER = 121
};

enum AnalyticsApiMap {
    kAnalyticsApiMapACCOUNT = 122,
    kAnalyticsApiMapACCOUNT_AGE_GROUP = 123,
    kAnalyticsApiMapACCOUNT_BIRTHDAY = 124,
    kAnalyticsApiMapACCOUNT_CREATED = 125,
    kAnalyticsApiMapACCOUNT_DISPLAY = 126,
    kAnalyticsApiMapACCOUNT_GENDER = 127,
    kAnalyticsApiMapACCOUNT_ID = 128,
    kAnalyticsApiMapACCOUNT_USERNAME = 129,
    kAnalyticsApiMapACTIVE = 130,
    kAnalyticsApiMapAPPLICATION_ID = 131,
    kAnalyticsApiMapAPPLICATION_NAME = 132,
    kAnalyticsApiMapCITY = 133,
    kAnalyticsApiMapCOUNTRY = 134,
    kAnalyticsApiMapCREATED = 135,
    kAnalyticsApiMapCUSTOM_ID = 136,
    kAnalyticsApiMapDEVICE = 137,
    kAnalyticsApiMapDEVICE_ID = 138,
    kAnalyticsApiMapDEVICE_OS = 139,
    kAnalyticsApiMapDEVICE_TYPE = 140,
    kAnalyticsApiMapIP_ADDRESS = 141,
    kAnalyticsApiMapLAST_UPDATED = 142,
    kAnalyticsApiMapMODEL = 143,
    kAnalyticsApiMapNULL = 144,
    kAnalyticsApiMapSTATE = 145,
    kAnalyticsApiMapTAG = 146,
    kAnalyticsApiMapTAG_COUNT = 147,
    kAnalyticsApiMapTOKEN = 148,
    kAnalyticsApiMapUPDATED = 149,
    kAnalyticsApiMapZIP = 150
};

enum ResponseFormat {
    kResponseFormatHTML = 151,
    kResponseFormatJSON = 152,
    kResponseFormatNULL = 153,
    kResponseFormatXML = 154
};

enum GameLevelApiMap {
    kGameLevelApiMapGAME_DESCRIPTION = 155,
    kGameLevelApiMapGAME_DISLIKES = 156,
    kGameLevelApiMapGAME_LIKES = 157,
    kGameLevelApiMapGAME_OWNER_DISPLAY = 158,
    kGameLevelApiMapGAME_TITLE = 159,
    kGameLevelApiMapLEVEL_ACTIVE = 160,
    kGameLevelApiMapLEVEL_COMPLETES = 161,
    kGameLevelApiMapLEVEL_CREATED = 162,
    kGameLevelApiMapLEVEL_DESCRIPTION = 163,
    kGameLevelApiMapLEVEL_DISLIKES = 164,
    kGameLevelApiMapLEVEL_DOWNLOADS = 165,
    kGameLevelApiMapLEVEL_LIKES = 166,
    kGameLevelApiMapLEVEL_MISSION_TYPE = 167,
    kGameLevelApiMapLEVEL_NAME = 168,
    kGameLevelApiMapLEVEL_NOTES = 169,
    kGameLevelApiMapLEVEL_PLAYS = 170,
    kGameLevelApiMapLEVEL_QUITS = 171,
    kGameLevelApiMapLEVEL_UPDATED = 172,
    kGameLevelApiMapLEVEL_VERSION = 173,
    kGameLevelApiMapNULL = 174
};

enum Ownership {
    kOwnershipALL = 175,
    kOwnershipALL_PUBLIC = 176,
    kOwnershipFRIENDS = 177,
    kOwnershipLIKED = 178,
    kOwnershipMINE = 179,
    kOwnershipNULL = 180,
    kOwnershipPUBLIC = 181
};

enum PurchaseType {
    kPurchaseTypeAMAZON = 182,
    kPurchaseTypeFREE = 183,
    kPurchaseTypeGOOGLE = 184,
    kPurchaseTypeIOS = 185,
    kPurchaseTypeMAC = 186,
    kPurchaseTypeNULL = 187,
    kPurchaseTypeSIRQUL = 188,
    kPurchaseTypeITUNES = 189
};

enum ConnectionApiMap {
    kConnectionApiMapACCOUNT_DISPLAY = 190,
    kConnectionApiMapACCOUNT_USERNAME = 191,
    kConnectionApiMapBLOCKED = 192,
    kConnectionApiMapDISPLAY = 193,
    kConnectionApiMapEXCLUDE_THIRD_PARTY = 194,
    kConnectionApiMapFOLLOWER = 195,
    kConnectionApiMapFOLLOWING = 196,
    kConnectionApiMapFRIENDS = 197,
    kConnectionApiMapNULL = 198,
    kConnectionApiMapPENDING = 199,
    kConnectionApiMapREQUESTED = 200,
    kConnectionApiMapTRUSTED = 201,
    kConnectionApiMapVIEWER = 202
};

enum SortFilter {
    kSortFilterBUSINESS_NAME = 203,
    kSortFilterDISTANCE = 204,
    kSortFilterNULL = 205
};

enum ProfileFilters {
    kProfileFiltersAPPS = 206,
    kProfileFiltersAPPS_STATS = 207,
    kProfileFiltersAPPS_TICKETS = 208,
    kProfileFiltersAPPS_ACHIEVEMENTS = 209,
    kProfileFiltersCONNECTIONS = 210,
    kProfileFiltersCONNECTIONS_EVERYONE = 211,
    kProfileFiltersCONNECTIONS_FRIENDS_GROUP = 212,
    kProfileFiltersCONNECTIONS_PRIVATE_GROUP = 213,
    kProfileFiltersNULL = 214,
    kProfileFiltersPROFILE = 215,
    kProfileFiltersPROFILE_CONTACT = 216,
    kProfileFiltersPROFILE_PERSONAL = 217
};

enum AssetApiMap{
    kAssetApiMapCAPTION = 218,
    kAssetApiMapCREATED = 219,
    kAssetApiMapDISLIKES = 220,
    kAssetApiMapFILENAME = 221,
    kAssetApiMapLIKES = 222,
    kAssetApiMapMEDIA_TYPE = 223,
    kAssetApiMapMIME_TYPE = 224,
    kAssetApiMapNULL = 225,
    kAssetApiMapOWNER_DISPLAY = 226,
    kAssetApiMapUPDATED = 227
};

enum RankMode {
    kRankModeCUSTOM = 228,
    kRankModeFRIENDS = 229,
    kRankModeGLOBAL = 230,
    kRankModeLOCAL = 231,
    kRankModeNULL = 232,
    kRankModeSEARCH = 233
};

enum RankApiMap {
    kRankApiMapAPPLICATION_ID = 234,
    kRankApiMapDAILY = 235,
    kRankApiMapNULL = 236,
    kRankApiMapOWNER_DISPLAY = 237,
    kRankApiMapOWNER_ID = 238,
    kRankApiMapRANK_TYPE = 239,
    kRankApiMapTOP = 240,
    kRankApiMapTOTAL = 241,
    kRankApiMapWEEKLY = 242
};

enum TicketObjectType {
    kTicketObjectTypeAPPLICATION = 243,
    kTicketObjectTypeASSET = 244,
    kTicketObjectTypeGAME = 245,
    kTicketObjectTypeGAME_LEVEL = 246,
    kTicketObjectTypeGAME_OBJECT = 247,
    kTicketObjectTypeMISSION = 248,
    kTicketObjectTypeNULL = 249,
    kTicketObjectTypePACK = 250,
    kTicketObjectTypePROFILE = 251,
    kTicketObjectTypeTICKETS = 252
};

enum TicketActionType {
    kTicketActionTypeCOMPLETED = 253,
    kTicketActionTypeGIFTED = 254,
    kTicketActionTypeNULL = 255,
    kTicketActionTypePURCHASED = 256,
    kTicketActionTypeREDEEMED = 257,
    kTicketActionTypeSUMATION = 258,
    kTicketActionTypeUSERS_PLAYED = 259
};

enum AchievementApiMap {
    kAchievementApiMapACTIVE = 260,
    kAchievementApiMapAPPLICATION_ID = 261,
    kAchievementApiMapAPPLICATION_NAME = 262,
    kAchievementApiMapCREATED = 263,
    kAchievementApiMapDELETED = 264,
    kAchievementApiMapDESCRIPTION = 265,
    kAchievementApiMapNULL = 266,
    kAchievementApiMapRANK_TYPE = 267,
    kAchievementApiMapSEARCH_TAGS = 268,
    kAchievementApiMapTITLE = 269,
    kAchievementApiMapUPDATED = 270
};

enum AlbumContestApiMap {
    kAlbumContestApiMapCREATED = 271,
    kAlbumContestApiMapDESCRIPTION = 272,
    kAlbumContestApiMapDISLIKES = 273,
    kAlbumContestApiMapDISTANCE = 274,
    kAlbumContestApiMapEND_DATE = 275,
    kAlbumContestApiMapLIKES = 276,
    kAlbumContestApiMapNULL = 277,
    kAlbumContestApiMapOWNER_DISPLAY = 278,
    kAlbumContestApiMapSTART_DATE = 279,
    kAlbumContestApiMapTITLE = 280,
    kAlbumContestApiMapUPDATED = 281,
    kAlbumContestApiMapTRENDING = 282
};

enum AlbumApiMap{
    kAlbumApiMapALBUM_CREATED = 283,
    kAlbumApiMapALBUM_DESCRIPTION = 284,
    kAlbumApiMapALBUM_DISLIKES = 285,
    kAlbumApiMapALBUM_DISTANCE = 286,
    kAlbumApiMapALBUM_END_DATE = 287,
    kAlbumApiMapALBUM_LIKES = 288,
    kAlbumApiMapALBUM_START_DATE = 289,
    kAlbumApiMapALBUM_TITLE = 290,
    kAlbumApiMapTRENDING = 291,
    kAlbumApiMapALBUM_UPDATED = 292,
    kAlbumApiMapNULL = 293,
    kAlbumApiMapOWNER_DISPLAY = 294
};

enum ApplicationApiMap {
    kApplicationApiMapABOUT = 295,
    kApplicationApiMapACTIVE = 296,
    kApplicationApiMapAPI_VERSION = 297,
    kApplicationApiMapAPP_TYPE = 298,
    kApplicationApiMapAPPLICATION_ID = 299,
    kApplicationApiMapBILLABLE_ENTITY_ID = 300,
    kApplicationApiMapBILLABLE_ENTITY_NAME = 301,
    kApplicationApiMapBUILD_VERSION = 302,
    kApplicationApiMapBUNDLE_ID = 303,
    kApplicationApiMapCREATED = 304,
    kApplicationApiMapDELETED = 305,
    kApplicationApiMapDESCRIPTION = 306,
    kApplicationApiMapEULA_VERSION = 307,
    kApplicationApiMapGAME_TYPE = 308,
    kApplicationApiMapLANDING_PAGE_URL = 309,
    kApplicationApiMapNAME = 310,
    kApplicationApiMapNULL = 311,
    kApplicationApiMapRESPONSIBLE_DISPLAY = 312,
    kApplicationApiMapSCORING_TYPE = 313,
    kApplicationApiMapSEARCH_TAGS = 314,
    kApplicationApiMapTITLE = 315,
    kApplicationApiMapUPDATED = 316
};

enum AssetCollectionApiMap {
    kAssetCollectionApiMapCREATED = 317,
    kAssetCollectionApiMapDESCRIPTION = 318,
    kAssetCollectionApiMapDISLIKES = 319,
    kAssetCollectionApiMapEND_DATE = 320,
    kAssetCollectionApiMapLIKES = 321,
    kAssetCollectionApiMapNULL = 322,
    kAssetCollectionApiMapOWNER_DISPLAY = 323,
    kAssetCollectionApiMapSTART_DATE = 324,
    kAssetCollectionApiMapTITLE = 325
};

enum OfferLocationApiMap {
    kOfferLocationApiMapACTIVATED = 326,
    kOfferLocationApiMapACTIVE = 327,
    kOfferLocationApiMapBILLABLE_ENTITY_ID = 328,
    kOfferLocationApiMapBILLABLE_ENTITY_NAME = 329,
    kOfferLocationApiMapCOUPON_TYPE = 330,
    kOfferLocationApiMapCREATED = 331,
    kOfferLocationApiMapDELETED = 332,
    kOfferLocationApiMapDETAILS = 333,
    kOfferLocationApiMapEXPIRES = 334,
    kOfferLocationApiMapID = 335,
    kOfferLocationApiMapNULL = 336,
    kOfferLocationApiMapOFFER_TYPE = 337,
    kOfferLocationApiMapOFFER_VISIBILITY = 338,
    kOfferLocationApiMapRESPONSIBLE_DISPLAY = 339,
    kOfferLocationApiMapRETAILER_ID = 340,
    kOfferLocationApiMapRETAILER_LOCATION_ID = 341,
    kOfferLocationApiMapSEARCH_TAGS = 342,
    kOfferLocationApiMapSPECIAL_OFFER_TYPE = 343,
    kOfferLocationApiMapSUBTITLE = 344,
    kOfferLocationApiMapTITLE = 345,
    kOfferLocationApiMapUPDATED = 346
};

enum RetailerLocationApiMap {
    kRetailerLocationApiMapACTIVE = 347,
    kRetailerLocationApiMapBILLABLE_ENTITY_ID = 348,
    kRetailerLocationApiMapBILLABLE_ENTITY_NAME = 349,
    kRetailerLocationApiMapCODE = 350,
    kRetailerLocationApiMapCREATED = 351,
    kRetailerLocationApiMapDELETED = 352,
    kRetailerLocationApiMapID = 353,
    kRetailerLocationApiMapNAME = 354,
    kRetailerLocationApiMapNULL = 355,
    kRetailerLocationApiMapRESPONSIBLE_DISPLAY = 356,
    kRetailerLocationApiMapSEARCH_TAGS = 357,
    kRetailerLocationApiMapUPDATED = 358
};

enum RetailerApiMap {
    kRetailerApiMapACTIVE = 359,
    kRetailerApiMapBILLABLE_ENTITY_ID = 360,
    kRetailerApiMapBILLABLE_ENTITY_NAME = 361,
    kRetailerApiMapCREATED = 362,
    kRetailerApiMapDELETED = 363,
    kRetailerApiMapID = 364,
    kRetailerApiMapNAME = 365,
    kRetailerApiMapNULL = 366,
    kRetailerApiMapRESPONSIBLE_DISPLAY = 367,
    kRetailerApiMapSEARCH_TAGS = 368,
    kRetailerApiMapUPDATED = 369
};

enum ThemeDescriptorApiMap {
    kThemeDescriptorApiMapCREATED = 370,
    kThemeDescriptorApiMapDESCRIPTION = 371,
    kThemeDescriptorApiMapDISLIKES = 372,
    kThemeDescriptorApiMapDISTANCE = 373,
    kThemeDescriptorApiMapLIKES = 374,
    kThemeDescriptorApiMapNULL = 375,
    kThemeDescriptorApiMapOWNER_DISPLAY = 376,
    kThemeDescriptorApiMapTITLE = 377,
    kThemeDescriptorApiMapUPDATED = 378
};

enum MissionInviteStatus {
    kMissionInviteStatusACCEPTED = 379,
    kMissionInviteStatusACTIVE = 380,
    kMissionInviteStatusAVAILABLE = 381,
    kMissionInviteStatusCOMPLETED = 382,
    kMissionInviteStatusNULL = 383,
    kMissionInviteStatusPENDING = 384,
    kMissionInviteStatusPENDING_REVIEW = 385,
    kMissionInviteStatusQUIT = 386,
    kMissionInviteStatusREJECTED = 387,
    kMissionInviteStatusUPDATED = 388
};

enum Role {
    kRoleDEVELOPER = 389,
    kRoleMEMBER = 390,
    kRoleNULL = 391,
    kRoleRETAILER = 392
};

enum Platform {
    kPlatformANDROID = 393,
    kPlatformCOCOS2D = 394,
    kPlatformIOS = 395,
    kPlatformKINDLE = 396,
    kPlatformMAC = 397,
    kPlatformNULL = 398,
    kPlatformUNITY3D = 399,
    kPlatformWINDOWSPHONE = 400
};

enum CellPhoneCarrierMap {
    kCellPhoneCarrierMapALLTEL = 401,
    kCellPhoneCarrierMapATT = 402,
    kCellPhoneCarrierMapBOOST_MOBILE = 403,
    kCellPhoneCarrierMapMETRO_PCS = 404,
    kCellPhoneCarrierMapNEXTEL = 405,
    kCellPhoneCarrierMapNULL = 406,
    kCellPhoneCarrierMapPOWERTEL = 407,
    kCellPhoneCarrierMapQWEST = 408,
    kCellPhoneCarrierMapSPRINT = 409,
    kCellPhoneCarrierMapSUNCOM = 410,
    kCellPhoneCarrierMapT_MOBILE = 411,
    kCellPhoneCarrierMapTRACFONE = 412,
    kCellPhoneCarrierMapUS_CELLULAR = 413,
    kCellPhoneCarrierMapVERIZON = 414,
    kCellPhoneCarrierMapVIRIGIN_MOBILE = 415
};

enum Conduits {
    kConduitAPNS = 416,
    kConduitEMAIL = 417,
    kConduitMOBILE_NOTIFICATION = 418,
    kConduitNULL = 419,
    kConduitSAVE = 420,
    kConduitSMS = 421
};

enum DefaultAlbumType {
    kDefaultAlbumTypeDEFAULT_APP_ICON = 422,
    kDefaultAlbumTypeDEFAULT_APP_LOGO = 423,
    kDefaultAlbumTypeDEFAULT_PROFILE_AVATAR = 424,
    kDefaultAlbumTypeNULL = 425,
    kDefaultAlbumTypePROFILE = 426
};

enum ScoringType{
    kScoringTypeGAME_LEVEL = 427,
    kScoringTypeGAME_OBJECT = 428,
    kScoringTypeNULL = 429
};

enum GameDifficulty{
    kGameDifficultyEASY = 430,
    kGameDifficultyHARD = 431,
    kGameDifficultyMEDIUM = 432,
    kGameDifficultyNULL = 433,
    kGameDifficultyVERY_EASY = 434,
    kGameDifficultyVERY_HARD = 435
};

enum MissionType{
    kMissionTypeADVERT = 436,
    kMissionTypeNULL = 437,
    kMissionTypePUBLIC = 438,
    kMissionTypeSHARED = 439
};

enum Crud {
    kCrudCreate = 440,
    kCrudRead = 441,
    kCrudUpdate = 442,
    kCrudDelete = 443,
    kCrudSearch = 444
};

enum ApprovalStatus {
    kApprovalStatusAPPROVED = 445,
    kApprovalStatusFEATURED = 446,
    kApprovalStatusNULL = 447,
    kApprovalStatusPENDING = 448,
    kApprovalStatusREJECTED = 449
};

enum AccountApiMap {
    kAccountApiMapDISPLAY = 450,
    kAccountApiMapCREATED = 451,
    kAccountApiMapUPDATED = 452,
    kAccountApiMapACTIVE = 453,
    kAccountApiMapDELETED = 454,
    kAccountApiMapLAST_LOGGED_IN = 455,
    kAccountApiMapCONTACT_EMAIL = 456,
    kAccountApiMapRETAILER_LOCATION_NAME = 457,
    kAccountApiMapRETAILER_NAME = 458
};

enum OfferTransactionApiMap {
    kOfferTransactionApiMapACTIVATED = 459,
    kOfferTransactionApiMapACTIVE = 460,
    kOfferTransactionApiMapBILLABLE_ENTITY_ID = 461,
    kOfferTransactionApiMapBILLABLE_ENTITY_NAME = 462,
    kOfferTransactionApiMapCOUPON_TYPE = 463,
    kOfferTransactionApiMapCREATED = 464,
    kOfferTransactionApiMapCUSTOMER_DISPLAY = 465,
    kOfferTransactionApiMapCUSTOMER_ID = 466,
    kOfferTransactionApiMapDELETED = 467,
    kOfferTransactionApiMapDETAILS = 468,
    kOfferTransactionApiMapEXPIRES = 469,
    kOfferTransactionApiMapID = 470,
    kOfferTransactionApiMapNULL = 471,
    kOfferTransactionApiMapOFFER_TYPE = 472,
    kOfferTransactionApiMapOFFER_VISIBILITY = 473,
    kOfferTransactionApiMapRESPONSIBLE_DISPLAY = 474,
    kOfferTransactionApiMapRETAILER_ID = 475,
    kOfferTransactionApiMapRETAILER_LOCATION_ID = 476,
    kOfferTransactionApiMapRETAILER_LOCATION_NAME = 477,
    kOfferTransactionApiMapRETAILER_NAME = 478,
    kOfferTransactionApiMapSEARCH_TAGS = 479,
    kOfferTransactionApiMapSPECIAL_OFFER_TYPE = 480,
    kOfferTransactionApiMapSUBTITLE = 481,
    kOfferTransactionApiMapTITLE = 482,
    kOfferTransactionApiMapUPDATED = 483
};

enum MediaType {
    kMediaTypeIMAGE = 484,
    kMediaTypeVIDEO = 485
};

enum CategoryApiMap {
    kCategoryApiMapID = 486,
    kCategoryApiMapCREATED = 487,
    kCategoryApiMapUPDATED = 488,
    kCategoryApiMapACTIVE = 489,
    kCategoryApiMapNAME = 490,
    kCategoryApiMapDISPLAY = 491,
    kCategoryApiMapNULL = 492
};

enum RatingIndexApiMap {
    kRatingIndexApiID = 493,
    kRatingIndexApiCREATED = 494,
    kRatingIndexApiUPDATED = 495,
    kRatingIndexApiDELETED = 496,
    kRatingIndexApiSEARCH_TAGS = 497,
    kRatingIndexApiACTIVE = 498,
    kRatingIndexApiRATABLE_TYPE = 499,
    kRatingIndexApiRATABLE_ID = 500,
    kRatingIndexApiRATABLE_DISPLAY = 501,
    kRatingIndexApiCATEGORY_ID = 502,
    kRatingIndexApiCATEGORY_NAME = 503,
    kRatingIndexApiCATEGORY_SHORT_NAME = 504,
    kRatingIndexApiCATEGORY_DISPLAY = 505,
    kRatingIndexApiCOUNT = 506,
    kRatingIndexApiSUMMATION = 507,
    kRatingIndexApiAVERAGE = 508,
    kRatingIndexApiVALUE = 509,
    kRatingIndexApiNULL = 510
};

enum RatingApiMap {
    kRatingApiMapID = 511,
    kRatingApiMapCREATED = 512,
    kRatingApiMapUPDATED = 513,
    kRatingApiMapDELETED = 514,
    kRatingApiMapSEARCH_TAGS = 515,
    kRatingApiMapACTIVE = 516,
    kRatingApiMapOWNER_DISPLAY = 517,
    kRatingApiMapRATABLE_TYPE = 518,
    kRatingApiMapRATABLE_ID = 519,
    kRatingApiMapRATABLE_DISPLAY = 520,
    kRatingApiMapCATEGORY_ID = 521,
    kRatingApiMapCATEGORY_NAME = 522,
    kRatingApiMapCATEGORY_SHORT_NAME = 523,
    kRatingApiMapCATEGORY_DISPLAY = 524,
    kRatingApiMapVALUE = 525
};

enum ProductType {  
    kProductTypeAPPAREL = 526,
    kProductTypeAPPLIANCES = 527,
    kProductTypeAPPS = 528,
    kProductTypeARTS_CRAFTS = 529,
    kProductTypeAUTOMOTIVE = 530,
    kProductTypeBABY = 531,
    kProductTypeBEAUTY = 532,
    kProductTypeBOOKS = 533,
    kProductTypeCLASSICAL = 534,
    kProductTypeCOLLECTIBLES = 535,
    kProductTypeDVD = 536,
    kProductTypeELECTRONICS = 537,
    kProductTypeGIFT_CARDS = 538,
    kProductTypeGOURMET_FOOD = 539,
    kProductTypeGROCERY = 540,
    kProductTypeHEALTH_PERSONAL_CARE = 541,
    kProductTypeHOME_GARDEN = 542,
    kProductTypeINDUSTRIAL = 543,
    kProductTypeJEWELRY = 544,
    kProductTypeKITCHEN = 545,
    kProductTypeLAWN_GARDEN = 546,
    kProductTypeMAGAZINES = 547,
    kProductTypeMISCELLANEOUS = 548,
    kProductTypeMUSICAL_INSTRUMENTS = 549,
    kProductTypeNULL = 550,
    kProductTypeOFFICE_PRODUCTS = 551,
    kProductTypeOTHER = 552,
    kProductTypeOUTDOOR_LIVING = 553,
    kProductTypePC_HARDWARE = 554,
    kProductTypePET_SUPPLIES = 555,
    kProductTypeSHOES = 556,
    kProductTypeSOFTWARE = 557,
    kProductTypeSPORTING_GOODS = 558,
    kProductTypeTOOLS = 559,
    kProductTypeTOYS = 560,
    kProductTypeVIDEO_GAMES = 561,
    kProductTypeWATCHES = 562,
    kProductTypeWIRELESS = 563,
    kProductTypeWIRELESS_ACCESSORIES = 564
};

enum ConditionType {
    kConditionTypeNEW = 565,
    kConditionTypeNULL = 566,
    kConditionTypeOTHER = 567,
    kConditionTypeREFURBISHED = 568,
    kConditionTypeUSED = 569
};

enum UnitType { 
    kUnitTypeCENTIMETER = 570,
    kUnitTypeFOOT = 571,
    kUnitTypeINCH = 572,
    kUnitTypeMETER = 573,
    kUnitTypeMILIMETER = 574,
    kUnitTypeNULL = 575,
    kUnitTypeYARD = 576
};

enum GlobalConfigApiMap {
    kGlobalConfigApiMapID = 577,
    kGlobalConfigApiMapCREATED = 578,
    kGlobalConfigApiMapUPDATED = 579,
    kGlobalConfigApiMapACTIVE = 580,
    kGlobalConfigApiMapNAME = 581,
    kGlobalConfigApiMapSETTING = 582,
    kGlobalConfigApiMapSETTING_TYPE = 583,
    kGlobalConfigApiMapDESCRIPTION = 584,
    kGlobalConfigApiMapNULL = 585
};

@interface SirqulEnums : NSObject

+ (NSString*)stringForEnum:(int)theEnum;
+ (NSArray*)arrayOfStringsForEnums:(NSArray*)enums;

@end
