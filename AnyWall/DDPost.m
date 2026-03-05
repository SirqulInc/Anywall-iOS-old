//
//  PAWPost.m
//  DoneDid
//
//  Created by Christopher Bowns on 2/8/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import "DDPost.h"
#import "DDAppDelegate.h"
#import "SNIHelper.h"

@interface DDPost ()

// Redefine these properties to make them read/write for internal class accesses and mutations.
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;

@property (nonatomic, strong) PFObject *object;
@property (nonatomic, strong) PFGeoPoint *geopoint;
@property (nonatomic, strong) PFUser *user;
@property (nonatomic, assign) MKPinAnnotationColor pinColor;

@end

@implementation DDPost

- (id)initWithCoordinate:(CLLocationCoordinate2D)aCoordinate andTitle:(NSString *)aTitle andSubtitle:(NSString *)aSubtitle {
	self = [super init];
	if (self) {
		self.coordinate = aCoordinate;
		self.title = aTitle;
		self.subtitle = aSubtitle;
		self.animatesDrop = NO;
	}
	return self;
}

- (id)initWithPFObject:(PFObject *)anObject {
	self.object = anObject;
	self.geopoint = [anObject objectForKey:kPAWParseLocationKey];
	self.user = [anObject objectForKey:kPAWParseUserKey];

	[anObject fetchIfNeeded]; 
	CLLocationCoordinate2D aCoordinate = CLLocationCoordinate2DMake(self.geopoint.latitude, self.geopoint.longitude);
	NSString *aTitle = [anObject objectForKey:kPAWParseTextKey];
	NSString *aSubtitle = [[anObject objectForKey:kPAWParseUserKey] objectForKey:kPAWParseUsernameKey];

	return [self initWithCoordinate:aCoordinate andTitle:aTitle andSubtitle:aSubtitle];
}

- (id)initWithSirqulObject:(NSDictionary*)anObject{
	self.sirqulObject = [[NSDictionary alloc]initWithDictionary:anObject];
	CLLocationCoordinate2D coord;
	if ([SNIHelper checkDictionary:anObject objectForKey:@"latitude"] && [SNIHelper checkDictionary:anObject objectForKey:@"longitude"]) {
		coord = CLLocationCoordinate2DMake([[anObject objectForKey:@"latitude"]doubleValue], [[anObject objectForKey:@"longitude"]doubleValue]);
	}
	NSString *title = nil;
	if ([SNIHelper checkDictionary:anObject objectForKey:@"title"]) {
		title = [anObject objectForKey:@"title"];
	}
	NSString *subtitle = nil;
	if ([SNIHelper checkDictionary:anObject objectForKey:@"owner"]) {
		NSDictionary *owner = [anObject objectForKey:@"owner"];
		if ([SNIHelper checkDictionary:owner objectForKey:@"display"]) {
			subtitle = [owner objectForKey:@"display"];
		}
	}
	
	return [self initWithCoordinate:coord andTitle:title andSubtitle:subtitle];
}

- (BOOL)equalToPost:(DDPost *)aPost {
	if (aPost == nil) {
		return NO;
	}

	if (aPost.object && self.object) {
		// We have a PFObject inside the PAWPost, use that instead.
		if ([aPost.object.objectId compare:self.object.objectId] != NSOrderedSame) {
			return NO;
		}
		return YES;
	} else {
		// Fallback code:

		if ([aPost.title compare:self.title] != NSOrderedSame ||
			[aPost.subtitle compare:self.subtitle] != NSOrderedSame ||
			aPost.coordinate.latitude != self.coordinate.latitude ||
			aPost.coordinate.longitude != self.coordinate.longitude ) {
			return NO;
		}

		return YES;
	}
}

- (void)setTitleAndSubtitleOutsideDistance:(BOOL)outside {
	if (outside) {
		self.subtitle = nil;
		self.title = kPAWWallCantViewPost;
		self.pinColor = MKPinAnnotationColorRed;
	} else {
//		self.title = [self.object objectForKey:kPAWParseTextKey];
//		self.subtitle = [[self.object objectForKey:kPAWParseUserKey] objectForKey:kPAWParseUsernameKey];
		self.pinColor = MKPinAnnotationColorGreen;
	}
}

@end
