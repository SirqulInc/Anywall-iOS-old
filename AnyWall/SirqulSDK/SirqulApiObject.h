//
//  SirqulApiObject.h
//  SirqulNetworkInterface
//
//  Created by Josh Clarke on 8/27/13.
//  Copyright (c) 2013 Sirqul. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SirqulNetworkInterface.h"
#import "SirqulEnums.h"
#import "KeyRing.h"

@interface SirqulApiObject : NSObject{
    SirqulNetworkInterface *connection;
    NSDictionary *fields;
}

- (id)initWithConnection:(SirqulNetworkInterface*)aConnection;
- (NSDictionary*)getFields:(NSString*)method;
- (NSDictionary*)getRequiredFields:(NSString*)method;
- (void)sendRequestWithFunction:(enum Crud)function serviceMethod:(NSString*)serviceMethod andParams:(NSDictionary*)params;
- (BOOL)validateMethod:(NSString*)method andParams:(NSDictionary*)params;

//Abstract
- (void)createWithParams:(NSDictionary*)params;
- (void)readWithParams:(NSDictionary*)params;
- (void)updateWithParams:(NSDictionary*)params;
- (void)deleteWithParams:(NSDictionary*)params;
- (void)searchWithParams:(NSDictionary*)params;

@end
