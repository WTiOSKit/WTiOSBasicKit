//
//  NSString+App.h


#import <Foundation/Foundation.h>

@interface NSString (App)

+ (NSString *)currentPlatform;
+ (NSString *)currentAppName;
+ (NSString *)currentBundleVersion;
+ (NSString *)appBundleIdentifier;

// 后台请求统一添加appplatform, appname, appversion三个字段，方便线上问题紧急修复（带URL域名）
// 后台请求统一添加guid（唯一标示符），方便后台分析日志（带URL域名）
+ (NSMutableString *)appendCommonArgsFromURLString:(NSString *)str;

@end
