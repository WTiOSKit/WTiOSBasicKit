//
//  BaseNavigationController.h
//  QQingCommon
//
//  Created by fallen.ink on 10/15/15.
//  Copyright (c) 2015 QQingiOSTeam. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BaseNavigationController : UINavigationController

#pragma mark - 

- (UIViewController *)childViewControllerForStatusBarStyle;

@end
