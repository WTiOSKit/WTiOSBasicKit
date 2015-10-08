//
//  NSString+App.m
//  QQingCommon
//
//  Created by Ben on 15/8/18.
//  Copyright (c) 2015年 QQingiOSTeam. All rights reserved.
//

#import "NSString+App.h"

@implementation NSString (App)

+ (NSString *)currentPlatform {
    static NSString *currentPlatform = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        currentPlatform = @"ios";
    });
    
    return currentPlatform;
}

+ (NSString *)currentAppName {
    static NSString *currentAppName = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSString *bundleID = [NSString appBundleIdentifier];
        if ([bundleID hasPrefix:@"com.qq.student"]) {
            currentAppName = @"student";
        } else if ([bundleID hasPrefix:@"com.qq.teacher"]) {
            currentAppName = @"teacher";
        } else {
            currentAppName = @"unknown";
        }
    });
    
    return currentAppName;
}

+ (NSString *)currentBundleVersion {
    static NSString *bundleVersion = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        bundleVersion = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
        NSLog(@"Current Version: %@", bundleVersion);
    });
    
    return bundleVersion;
}

+ (NSString *)appBundleIdentifier {
    static NSString * bundleID = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        bundleID = [[NSBundle mainBundle] objectForInfoDictionaryKey:(NSString *)kCFBundleIdentifierKey];
    });
    
    return bundleID;
}

// 后台请求统一添加appplatform, appname, appversion三个字段，方便线上问题紧急修复（带URL域名）
// 后台请求统一添加guid（唯一标示符），方便后台分析日志（带URL域名）
+ (NSMutableString *)appendCommonArgsFromURLString:(NSString *)str
{
    static NSString *const apppltFirstSubStr = @"?appplatform=";
    static NSString *const appnameFirstSubStr = @"?appname=";
    static NSString *const appverFirstSubStr = @"?appversion=";
    static NSString *const guidFirstSubStr = @"?guid=";
    
    static NSString *const apppltNotFirstSubStr = @"&appplatform=";
    static NSString *const appnameNotFirstSubStr = @"&appname=";
    static NSString *const appverNotFirstSubStr = @"&appversion=";
    static NSString *const guidNotFirstSubStr = @"&guid=";
    
    NSMutableString *resultString = [NSMutableString stringWithString:str];
    if (([resultString rangeOfString:apppltFirstSubStr].location == NSNotFound) && ([resultString rangeOfString:apppltNotFirstSubStr].location == NSNotFound)) {
        [resultString appendFormat:@"%@%@", ([resultString rangeOfString:@"?"].location == NSNotFound) ? apppltFirstSubStr : apppltNotFirstSubStr, [NSString currentPlatform]];
    }
    if (([resultString rangeOfString:appnameFirstSubStr].location == NSNotFound) && ([resultString rangeOfString:appnameNotFirstSubStr].location == NSNotFound)) {
        [resultString appendFormat:@"%@%@", appnameNotFirstSubStr, [NSString currentAppName]];
    }
    if (([resultString rangeOfString:appverFirstSubStr].location == NSNotFound) && ([resultString rangeOfString:appverNotFirstSubStr].location == NSNotFound)) {
        [resultString appendFormat:@"%@%@", appverNotFirstSubStr, [NSString currentBundleVersion]];
    }
    if (([resultString rangeOfString:guidFirstSubStr].location == NSNotFound) && ([resultString rangeOfString:guidNotFirstSubStr].location == NSNotFound)) {
        [resultString appendFormat:@"%@%@", guidNotFirstSubStr, [NSString getUuidArg]];
    }
    
    return resultString;
}

// Private methods
+ (NSString *)getUuidArg
{
    CFUUIDRef   uuid = CFUUIDCreate(NULL);
    CFStringRef uuidStr = CFUUIDCreateString(NULL, uuid);
    
    NSString *uuidArg = [NSString stringWithString:(__bridge NSString *)uuidStr];
    
    CFRelease(uuidStr);
    CFRelease(uuid);
    
    return uuidArg;
}

@end
