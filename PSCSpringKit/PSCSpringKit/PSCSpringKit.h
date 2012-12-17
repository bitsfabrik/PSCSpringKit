//
//  PSCSpringKit.h
//  PSCSpringKit
//
//  Created by Manfred Scheiner on 17.12.12.
//  Copyright (c) 2012 PocketScience GmbH. All rights reserved.
//

@interface PSCSpringKit : NSObject

@property (nonatomic, strong) NSString *path;

+ (PSCSpringKit *)createSharedSpringKitWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path;
+ (PSCSpringKit *)sharedSpringKit;
+ (void)performCount;

@end
