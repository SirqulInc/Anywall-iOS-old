//
//  PAWSearchRadius.m
//  DoneDid
//
//  Created by Christopher Bowns on 2/8/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import "DDSearchRadius.h"

@implementation DDSearchRadius

- (id)initWithCoordinate:(CLLocationCoordinate2D)aCoordinate radius:(CLLocationDistance)aRadius {
	self = [super init];
	if (self) {
		self.coordinate = aCoordinate;
		self.radius = aRadius;
	}
	return self;
}

- (MKMapRect)boundingMapRect {
	return MKMapRectWorld;
}

@end
