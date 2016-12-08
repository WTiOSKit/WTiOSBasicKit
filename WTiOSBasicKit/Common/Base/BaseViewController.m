//
//  BaseViewController.m
//  QQing
//
//  Created by 李杰 on 4/27/15.
//
//

#import "BaseViewController.h"
#import "Masonry.h"

@interface BaseViewController ()

@property (copy,nonatomic) UIColor* originNavBarColor;
@property (copy,nonatomic) UIColor* originNavTitleColor;
@property (assign,nonatomic) BOOL hasPreferNavBarColor;
@property (assign,nonatomic) BOOL hasPreferNavTitleColor;

@property (strong,nonatomic) WritingLoadingView* loadingViewWithoutbackground;

@end

@implementation BaseViewController

#pragma mark - Life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [BaseConfiguration adapterAppTeacher:^{
        [self setNavLeftItemWithImage:@"icon_top_back" target:self action:@selector(didClickOnBackButton)];
    } appStudent:^{
        NSString* backIconName;
        switch ([self preferNavBarBackButtonStyle]) {
            case NavBarBackButtonStyleWhite: {
                backIconName = @"ic_top_back_white";
                break;
            default:
                backIconName = @"ic_top_back";
            }
        }
        [self setNavLeftItemWithImage:backIconName target:self action:@selector(didClickOnBackButton)];
    } appAssistant:^{
        [self setNavLeftItemWithImage:@"icon_top_back" target:self action:@selector(didClickOnBackButton)];
    }];
    
    if ([self respondsToSelector:@selector(edgesForExtendedLayout)]) {
        self.edgesForExtendedLayout = UIRectEdgeNone;
    }
    
    self.view.backgroundColor = [UIColor bgGray000Color];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    UIColor* preferNavBarColor = [self preferNavBarBackgroundColor];
    if (preferNavBarColor) {
        self.hasPreferNavBarColor = YES;
        self.originNavBarColor = self.navBarColor;
        self.navBarColor = preferNavBarColor;
    }
    
    UIColor* preferNavBarNormalTitleColor = [self preferNavBarNormalTitleColor];
    if (preferNavBarNormalTitleColor) {
        self.hasPreferNavTitleColor = YES;
        self.originNavTitleColor = self.navTitleColor;
        self.navTitleColor = preferNavBarNormalTitleColor;
        self.navLeftItemNormalTitleColor = preferNavBarNormalTitleColor;
        self.navRightItemNormalTitleColor = preferNavBarNormalTitleColor;
    }
    
    UIColor* preferNavItemHighlightedTitleColor = [self preferNavBarHighlightedTitleColor];
    if (preferNavItemHighlightedTitleColor) {
        self.navItemHighlightedTitleColor = preferNavItemHighlightedTitleColor;
    }
    
    //隐藏导航栏底部黑线
    if ([self preferHideBlackLineUnderNavBar]) {
        [self hideBlackLineUnderNavBar];
    }
    
    self.loadingViewWithoutbackground.center = self.view.center;
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    //解决手势返回失效的问题
    if (self.navigationController.viewControllers.count > 1) {
        if([self preferPopGestureRecognizerForbidden]){
            self.navigationController.interactivePopGestureRecognizer.delegate = nil;
            self.navigationController.interactivePopGestureRecognizer.enabled = NO;
        }else{
            self.navigationController.interactivePopGestureRecognizer.delegate = (id)self;
            self.navigationController.interactivePopGestureRecognizer.enabled = YES;
        }
    }else{
        self.navigationController.interactivePopGestureRecognizer.delegate = nil;
        self.navigationController.interactivePopGestureRecognizer.enabled = NO;
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    if (self.hasPreferNavBarColor) {
        self.navBarColor = self.originNavBarColor;
    }
    if (self.hasPreferNavTitleColor) {
        self.navTitleColor = self.originNavTitleColor;
        self.navLeftItemNormalTitleColor = self.originNavTitleColor;
        self.navRightItemNormalTitleColor = self.originNavTitleColor;
    }
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
    //恢复导航栏底部黑线
    if ([self preferHideBlackLineUnderNavBar]) {
        [self showBlackLineUnderNavBar];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)bindViewModel:(id)vm {
    // do nothing
}

- (void)didClickOnBackButton {
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)dealloc {
    DDLogDebug(@"%@-------------------------dealloc", [self class]);
}

#pragma mark - Play with view model: overrided if needed

- (instancetype)initWithViewModel:(id)viewModel {
    return [super init];
}

#pragma mark - Views operations

- (void)initializeViews {
    // Do nothing...
}

#pragma mark - Virtual methods

- (void)applyViewConstraints {
    // Do nothing...
}

- (void)updateVCviewsConstraints {
    
}

- (void)updateViewConstraints {
    [super updateViewConstraints];
}

#pragma mark - NavigationBar style

- (UIColor *)preferNavBarBackgroundColor{
    return nil;
}

- (UIColor *)preferNavBarNormalTitleColor{
    return nil;
}

- (UIColor *)preferNavBarHighlightedTitleColor {
    return nil;
}

- (BOOL)preferHideBlackLineUnderNavBar{
    return NO;
}

- (NavBarBackButtonStyle)preferNavBarBackButtonStyle{
    return NavBarBackButtonStyleNormal;
}

- (BOOL)preferPopGestureRecognizerForbidden {
    return NO;
}

#pragma mark - 屏幕旋转相关

- (BOOL)shouldAutorotate {
    return NO;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

#pragma mark - Status style

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleDefault;
}

#pragma mark - Navigation

- (void)pushVC:(UIViewController *)vc animate:(BOOL)animate {
    [self.navigationController pushViewController:vc animated:animate];
}

- (void)pushVC:(UIViewController *)vc {
    [self pushVC:vc animate:YES];
}

- (void)popVCAnimate:(BOOL)animate {
    [self.navigationController popViewControllerAnimated:animate];
}

- (void)popVC {
    [self popVCAnimate:YES];
}

- (void)popToVC:(UIViewController *)vc animate:(BOOL)animate {
    [self.navigationController popToViewController:vc animated:animate];
}

- (void)popToVC:(UIViewController *)vc {
    [self popToVC:vc animate:YES];
}

- (void)popToRootAnimate:(BOOL)animate {
    [self.navigationController popToRootViewControllerAnimated:animate];
}

- (void)popToRoot {
    [self popToRootAnimate:YES];
}

#pragma mark - Utility

- (BOOL)isVisibleEx {
    return (self.isViewLoaded && self.view.window);
}

- (void)showLoadingIndicator {
    [self.loadingViewWithoutbackground bringToFront];
    self.loadingViewWithoutbackground.hidden = NO;
    [self.loadingViewWithoutbackground showLoadingViewWithText:@"加载中..."];
}

- (void)hideLoadingIndicator {
    [self.loadingViewWithoutbackground hideLoadingView];
    self.loadingViewWithoutbackground.hidden = YES;
}

-(void)hideBlackLineUnderNavBar {
    // 为了隐藏navigationbar底部的黑线
    if ([self.navigationController.navigationBar respondsToSelector:@selector( setBackgroundImage:forBarMetrics:)]){
        NSArray *list=self.navigationController.navigationBar.subviews;
        for (id obj in list) {
            if ([obj isKindOfClass:[UIImageView class]]) {
                UIImageView *imageView=(UIImageView *)obj;
                NSArray *list2=imageView.subviews;
                for (id obj2 in list2) {
                    if ([obj2 isKindOfClass:[UIImageView class]]) {
                        UIImageView *imageView2=(UIImageView *)obj2;
                        imageView2.hidden=YES;
                    }
                }
            }
        }
    }
}

-(void)showBlackLineUnderNavBar {
    // 为了恢复navigationbar底部的黑线
    if ([self.navigationController.navigationBar respondsToSelector:@selector( setBackgroundImage:forBarMetrics:)]){
        NSArray *list=self.navigationController.navigationBar.subviews;
        for (id obj in list) {
            if ([obj isKindOfClass:[UIImageView class]]) {
                UIImageView *imageView=(UIImageView *)obj;
                NSArray *list2=imageView.subviews;
                for (id obj2 in list2) {
                    if ([obj2 isKindOfClass:[UIImageView class]]) {
                        UIImageView *imageView2=(UIImageView *)obj2;
                        imageView2.hidden=NO;
                    }
                }
            }
        }
    }
}


- (UIView*)findViewWithTag:(NSInteger)tag {
    return [self findViewWithTag:tag inView:self.view];
}

- (UIView*)findViewWithTag:(NSInteger)tag inView:(UIView*)containerView {
    for (UIView* view in containerView.subviews) {
        if (view.tag == tag) {
            return view;
        } else {
            if (view.subviews.count > 0) {
                UIView* view1 = [self findViewWithTag:tag inView:view];
                if (view1) {
                    return view1;
                };
            }
        }
    }
    return nil;
}


#pragma mark - DataBinder

- (void)bindViewModel {
    QQLog(@"Warning: 该方法应该被覆盖！");
}

#pragma mark - Getter

-(WritingLoadingView*)loadingViewWithoutbackground{
    if (!_loadingViewWithoutbackground) {
        _loadingViewWithoutbackground = [[WritingLoadingView alloc] initOnlyAnimationFrameViewWithBackgound:NO];
        _loadingViewWithoutbackground.hidden = YES;
        [self.view addSubview:_loadingViewWithoutbackground];
        
        [_loadingViewWithoutbackground mas_makeConstraints:^(MASConstraintMaker *make) {
            make.edges.equalTo(self.view);
        }];
    }
    return _loadingViewWithoutbackground;
}

@end


