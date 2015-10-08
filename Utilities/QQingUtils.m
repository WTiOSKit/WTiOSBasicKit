//
//  QQingUtils.m
//  QQing
//
//  Created by 李杰 on 1/28/15.
//
//

#import "QQingUtils.h"
#import "TSMessage.h"
#import "TSMessageView.h"

@implementation QQingUtils

+ (void)showToastWithText:(NSString *)text {
    [QQingUtils showToastWithText:text isLoading:NO isBottom:NO];
}

+ (void)showToastWithText:(NSString *)text isLoading:(BOOL)isLoading isBottom:(BOOL)isBottom {
    dispatch_async(dispatch_get_main_queue(), ^{
        [TSMessage setDefaultViewController:[[UIApplication sharedApplication].delegate.window rootViewController]];
        
        [TSMessage showNotificationWithTitle:text//NSLocalizedString(@"Tell the user something", nil)
                                    subtitle:nil//NSLocalizedString(@"This is some neutral notification!", nil)
                                        type:TSMessageNotificationTypeMessage];
    });
}

+ (UIViewController *)topVisibleViewController {
    UIViewController *vc = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (vc.presentedViewController) {
        vc = vc.presentedViewController;
    }
    
    return vc;
}

@end
