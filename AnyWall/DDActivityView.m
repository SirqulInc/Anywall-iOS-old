//
//  PAWActivityView.m
//  DoneDid
//
//  Created by Christopher Bowns on 2/6/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//
//  Modified by Josh Clarke on 4/16/14.
//

static CGFloat const kPAWActivityViewActivityIndicatorPadding = 10.f;

#import "DDActivityView.h"

@implementation DDActivityView

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
		self.label = [[UILabel alloc] initWithFrame:CGRectZero];
		self.label.textColor = [UIColor whiteColor];
		self.label.backgroundColor = [UIColor clearColor];

		self.activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];

		self.backgroundColor = [UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.7f];

		[self addSubview:self.label];
		[self addSubview:self.activityIndicator];
    }
    return self;
}

- (void)setLabel:(UILabel *)aLabel {
	[_label removeFromSuperview];
	[self addSubview:aLabel];
}

- (void)layoutSubviews {
	// center the label and activity indicator.
	[self.label sizeToFit];
	self.label.center = CGPointMake(self.frame.size.width / 2 + 10.f, self.frame.size.height / 2);
	self.label.frame = CGRectIntegral(self.label.frame);

	self.activityIndicator.center = CGPointMake(self.label.frame.origin.x - (self.activityIndicator.frame.size.width / 2) - kPAWActivityViewActivityIndicatorPadding, self.label.frame.origin.y + (self.label.frame.size.height / 2));
}

@end
