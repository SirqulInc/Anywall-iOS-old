//
//  PAWSearchRadius.h
//  DoneDid
//
//  Created by Christopher Bowns on 2/8/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

#import <MapKit/MapKit.h>

@interface DDSearchRadius : NSObject <MKOverlay>

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, assign) CLLocationDistance radius;
@property (nonatomic, assign) MKMapRect boundingMapRect;

- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate radius:(CLLocationDistance)radius;

@end
