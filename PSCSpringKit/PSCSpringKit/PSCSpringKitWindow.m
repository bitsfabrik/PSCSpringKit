//
//  PSCSpringWindow.m
//  PSCSpringKit
//
//  Created by Manfred Scheiner on 15.02.13.
//  Copyright (c) 2013 PocketScience GmbH. All rights reserved.
//

#import "PSCSpringKitWindow.h"
#import "PSCSpringKitManager.h"

@implementation PSCSpringKitWindow

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    UIView *hitView = [super hitTest:point withEvent:event];
    
    NSTimeInterval system = [[NSProcessInfo processInfo] systemUptime];
    if (system - event.timestamp < 0.05 && [PSCSpringKitManager containsHitTestClass:[hitView class]]) {
        [PSCSpringKitManager performCount];
    }
    
    return hitView;
}

@end
