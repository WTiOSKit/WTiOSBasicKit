//
//  QQingUtils.h
//  QQing
//
//  Created by 李杰 on 1/28/15.
//
//

#import <Foundation/Foundation.h>

@interface QQingUtils : NSObject

// Toast
+ (void)showToastWithText:(NSString *)text;
+ (void)showToastWithText:(NSString *)text isLoading:(BOOL)isLoading isBottom:(BOOL)isBottom;

+ (UIViewController *)topVisibleViewController;

@end
