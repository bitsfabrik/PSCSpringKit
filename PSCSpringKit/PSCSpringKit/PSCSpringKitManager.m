//
//  PSCSpringKitManager.m
//  PSCSpringKitManager
//
//  Created by Manfred Scheiner on 15.02.13.
//  Copyright (c) 2013 PocketScience GmbH. All rights reserved.
//

#import "PSCSpringKitManager.h"

@interface PSCSpringKitManager ()

@property (nonatomic, strong) Spring *spring;
@property (nonatomic, strong) NSArray *hitTestClasses;

@end

@implementation PSCSpringKitManager

- (id)initWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path hitTestClasses:(NSArray *)hitTestClasses {
    self = [super init];
    if (self != nil) {
        _spring = [[Spring alloc] initWithSiteAndApplication:site application:application];
        _path = path;
        _hitTestClasses = hitTestClasses;
        [self performCount];
    }
    return self;
}

- (void)performCount {
    [self performCountWithPath:self.path];
}

- (void)performCountWithPath:(NSString *)path {
    //dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
    NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithObject:path forKey:@"cp"];
    [self.spring commit:dict];
    //});
}

- (BOOL)containsHitTestClass:(Class)hitTestClass {
    for (Class class in self.hitTestClasses) {
        if ([hitTestClass isSubclassOfClass:class]) {
            return YES;
        }
    }
    return NO;
}

////////////////////////////////////////////////////////////////////////
#pragma mark - Singleton definitons
////////////////////////////////////////////////////////////////////////

static PSCSpringKitManager *sharedSpringKitManager = nil;

+ (PSCSpringKitManager *)createSharedSpringKitManagerWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path hitTestClasses:(NSArray *)hitTestClasses {
    sharedSpringKitManager = [[PSCSpringKitManager alloc] initWithSite:site application:application path:path hitTestClasses:hitTestClasses];
    return [PSCSpringKitManager sharedSpringKitManager];
}

+ (PSCSpringKitManager *)sharedSpringKitManager {
    return sharedSpringKitManager;
}

+ (void)performCount {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        [[PSCSpringKitManager sharedSpringKitManager] performCount];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
}

+ (void)performCountWithPath:(NSString *)path {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        [[PSCSpringKitManager sharedSpringKitManager] performCountWithPath:path];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
}

+ (BOOL)containsHitTestClass:(Class)hitTestClass {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        return [[PSCSpringKitManager sharedSpringKitManager] containsHitTestClass:hitTestClass];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
    return NO;
}

@end
