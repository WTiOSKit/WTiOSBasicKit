//
//  BaseViewController.h
//  QQing
//
//  Created by 李杰 on 4/27/15.
//
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, NavBarBackButtonStyle) {
    NavBarBackButtonStyleNormal,  //正常主题色的返回按钮
    NavBarBackButtonStyleWhite,   //白色
};

#pragma mark -

/**
 * Implemented by sub-classes of BaseViewController.
 */
@protocol ReactiveViewProtocol <NSObject>

@optional

- (void)bindViewModel;

- (void)bindViewModel:(id)vm;

@end

#pragma mark -

@interface BaseViewController : UIViewController <ReactiveViewProtocol>

@property (nonatomic, assign) NSInteger serviceState;

#pragma mark - Play with view model: overrided if needed

- (instancetype)initWithViewModel:(id)viewModel;

#pragma mark - Views operations: overrided if needed

- (void)initializeViews;

#pragma mark - Virtual method: Need to be overrided

/**
 *  Make constraints by code! Masonry is suggest.
 
 *  Call it at viewDidLoad 's end.
 */
- (void)applyViewConstraints;

/**
 *  Update Xib's constraints when needed.
 
 *  Call it where needed.
 */
- (void)updateVCviewsConstraints;

/**
 *  Just override api's method here.
 */
- (void)updateViewConstraints;

#pragma mark - NavigationBar style

// 修改当前导航栏背景色
- (UIColor *)preferNavBarBackgroundColor;

// 修改当前导航栏标题、左右按钮Normal状态标题颜色
- (UIColor *)preferNavBarNormalTitleColor;

// 修改左右按钮Highlighted标题颜色
- (UIColor *)preferNavBarHighlightedTitleColor;

// 是否隐藏导航栏底部黑线，默认为NO
- (BOOL)preferHideBlackLineUnderNavBar;

// 是否禁止右滑手势返回,默认为NO
- (BOOL)preferPopGestureRecognizerForbidden;

// 修改返回按钮的样式
- (NavBarBackButtonStyle)preferNavBarBackButtonStyle;

#pragma mark - Navigation

- (void)pushVC:(UIViewController *)vc animate:(BOOL)animate;

- (void)pushVC:(UIViewController *)vc;

- (void)popVCAnimate:(BOOL)animate;

- (void)popVC;

- (void)popToVC:(UIViewController *)vc animate:(BOOL)animate;

- (void)popToVC:(UIViewController *)vc;

- (void)popToRootAnimate:(BOOL)animate;

- (void)popToRoot;

#pragma mark - Override methods

- (void)didClickOnBackButton;

#pragma mark - Utility

- (BOOL)isVisibleEx;

//显示不阻塞UI的加载动画
- (void)showLoadingIndicator;
- (void)hideLoadingIndicator;

//隐藏导航栏底部黑线，建议willAppear里隐藏，didDisappear里显示
- (void)hideBlackLineUnderNavBar;
- (void)showBlackLineUnderNavBar;

//找到特定tag的view
- (UIView*)findViewWithTag:(NSInteger)tag;

@end
