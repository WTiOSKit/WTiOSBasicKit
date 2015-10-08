//
//  NSBundle+Utility.h
//  QQingCommon
//
//  Created by Ben on 15/8/5.
//  Copyright (c) 2015年 QQingiOSTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSBundle (Utility)

+ (NSBundle *)qqingCommonBundle;

+ (NSBundle *)qqingMomBundle;

+ (NSBundle *)bundleWithName:(NSString *)bundleName;

@end
