/*
 * (c) Copyright 2000-2011 spring saarlouis
 * All Rights Reserved.
 * 
 * contact info@spring.de for more information
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString *const OEWA_SPRING_VAR_ACTION;
extern NSString *const OEWA_SPRING_APP_STARTED;
extern NSString *const OEWA_SPRING_APP_FOREGROUND;
extern NSString *const OEWA_SPRING_APP_BACKGROUND;
extern NSString *const OEWA_SPRING_APP_CLOSED;


@interface SpringOEWA : NSObject {
}

@property(nonatomic, getter=isTracking) BOOL tracking;
@property(nonatomic) BOOL debug;
@property(assign) NSTimeInterval timeout;

- (id)initWithSiteAndApplication:(NSString *)theSite application:(NSString *)theApplication;

- (void)commit:(NSMutableDictionary *)theDictionary;

@end
