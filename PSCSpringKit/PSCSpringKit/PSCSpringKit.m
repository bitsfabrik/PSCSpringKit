//
//  PSCSpringKit.m
//  PSCSpringKit
//
//  Created by Manfred Scheiner on 17.12.12.
//  Copyright (c) 2012 PocketScience GmbH. All rights reserved.
//

#import "PSCSpringKit.h"

@interface PSCSpringKit ()

@property (nonatomic, strong) SpringOEWA *spring;

@end

@implementation PSCSpringKit

- (id)initWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path {
    self = [super init];
    if (self != nil) {
        _spring = [[SpringOEWA alloc] initWithSiteAndApplication:site application:application];
        _path = path;
        [self performCount];
    }
    return self;
}

- (void)performCount {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
        NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithObject:self.path forKey:@"cp"];
        [self.spring commit:dict];
    });
}

////////////////////////////////////////////////////////////////////////
#pragma mark - Singleton definitons
////////////////////////////////////////////////////////////////////////

static PSCSpringKit *sharedSpringKit = nil;

+ (PSCSpringKit *)createSharedSpringKitWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path {
    sharedSpringKit = [[PSCSpringKit alloc] initWithSite:site application:application path:path];
    return [PSCSpringKit sharedSpringKit];
}

+ (PSCSpringKit *)sharedSpringKit {
    return sharedSpringKit;
}

+ (void)performCount {
    if ([PSCSpringKit sharedSpringKit] != nil) {
        [[PSCSpringKit sharedSpringKit] performCount];
    }
    else {
        NSLog(@"Shared PSCSpringKit not created yet!");
    }
}

@end
