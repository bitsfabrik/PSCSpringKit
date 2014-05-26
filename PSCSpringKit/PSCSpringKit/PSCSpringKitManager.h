//
//  PSCSpringKitManager.h
//  PSCSpringKitManager
//
//  Created by Manfred Scheiner on 15.02.13.
//  Copyright (c) 2013 PocketScience GmbH. All rights reserved.
//

@interface PSCSpringKitManager : NSObject

@property (nonatomic, strong) NSString *path;

+ (PSCSpringKitManager *)createSharedSpringKitManagerWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path hitTestClasses:(NSArray *)hitTestClasses;
+ (void)performCount;
+ (void)performCountWithPath:(NSString *)path;
+ (BOOL)containsHitTestClass:(Class)hitTestClass;

@end
