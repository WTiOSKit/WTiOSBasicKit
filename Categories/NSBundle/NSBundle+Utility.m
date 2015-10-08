//
//  NSBundle+Utility.m
//  QQingCommon
//
//  Created by Ben on 15/8/5.
//  Copyright (c) 2015年 QQingiOSTeam. All rights reserved.
//

#import "NSBundle+Utility.h"

@implementation NSBundle (Utility)

+ (NSBundle *)qqingCommonBundle {
    static NSBundle *g_commonBundle = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        g_commonBundle = [NSBundle bundleWithName:@"QQingCommonBundle"];
    });
    
    return g_commonBundle;
}

+ (NSBundle *)qqingMomBundle {
    static NSBundle *g_momBundle = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        g_momBundle = [NSBundle bundleWithName:@"mom"];
    });
    
    return g_momBundle;
}

+ (NSBundle *)bundleWithName:(NSString *)bundleName {
    NSString *bundlePath = [[NSBundle mainBundle] pathForResource:bundleName ofType:@"bundle"];
    return [NSBundle bundleWithPath:bundlePath];
}

@end
