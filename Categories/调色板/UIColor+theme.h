//
//  UIColor+theme.h


#import <UIKit/UIKit.h>

@interface UIColor (theme)

#pragma mark - 颜色规范

// For example  [UIColor colorWithRed:50.0/255.0 green:50.0/255.0 blue:50.0/255.0 alpha:100]

/**
 *  UI，系统色，即主题色，themeXXXColor
 */

+ (UIColor *)mainOrangeColor;
+ (UIColor *)lightOrangeColor;
+ (UIColor *)paleOrangeColor;

// ===============================================
// 全局用色：灰色系

// Use 000, just because one '0', is too short.
// ===============================================
+ (UIColor *)gray000Color;
+ (UIColor *)gray001Color;
+ (UIColor *)gray002Color;
+ (UIColor *)gray003Color;
+ (UIColor *)gray004Color;
+ (UIColor *)gray005Color;
+ (UIColor *)gray006Color;

// ===============================================
// 全局用色：主题色、辅助色

// st：家长端
// te：老师端

// Notice: 可能不同的端对同一种颜色，色值定义不同
// ===============================================

+ (UIColor *)stGreenColor;
+ (UIColor *)stOrangeColor;
+ (UIColor *)stBlueColor;
+ (UIColor *)stYellowColor;
+ (UIColor *)stRedColor;

+ (UIColor *)teGreenColor;
+ (UIColor *)teOrangeColor;
+ (UIColor *)teBlueColor;
+ (UIColor *)teYellowColor;
+ (UIColor *)teRedColor;

+ (UIColor *)themeGrayColor;    // 系统、主题 灰色

+ (UIColor *)themePinkColor;    // 系统、主题 粉红
+ (UIColor *)themePurpleColor;  // 系统、主题 紫色

+ (UIColor *)themeRedColor;

+ (UIColor *)themeGreenColor;   // 系统、主题 绿色
+ (UIColor *)themeGreenTwoColor;
+ (UIColor *)themeGreenColorWithAlpha:(CGFloat)alpha;

+ (UIColor *)themeBlueColor;    // 系统、主题 蓝色
+ (UIColor *)themeBlueColorWithAlpha:(CGFloat)alpha;

// ===============================================
// 背景用色
// ===============================================

+ (UIColor *)bgGray000Color;
+ (UIColor *)bgGray001Color;
+ (UIColor *)bgGray002Color;
+ (UIColor *)bgGreenColor;

//背景灰
+ (UIColor *)webViewNavigationBarBackgroundColor;
+ (UIColor *)backGroundGrayColor;

// ===============================================
// 分割线用色
// ===============================================

+ (UIColor *)lineGray000Color;
+ (UIColor *)lineGray001Color;

// ===============================================
// 文字用色
// 暂时不区分 端
// ===============================================

+ (UIColor *)fontGray000Color;
+ (UIColor *)fontGray001Color;
+ (UIColor *)fontGray002Color;
+ (UIColor *)fontBlackColor; // title
+ (UIColor *)fontGreenColor;
+ (UIColor *)fontOrangeColor;
+ (UIColor *)fontBlueColor;

/**
 * 字体灰 1-4 颜色递减
 */
+ (UIColor *)fontGray_one_Color;
+ (UIColor *)fontGray_two_Color;
+ (UIColor *)fontGray_three_Color;
+ (UIColor *)fontGray_four_Color;

// 导航栏颜色风格
+ (UIColor *)navigationBarTintColor;

+ (UIColor *)textDarkGreenColor;

+ (UIColor *)courseEdColor;
+ (UIColor *)courseIngColor;
+ (UIColor *)courseWillColor;
+ (UIColor *)courseWaitColor;
+ (UIColor *)courseDealingColor;

#pragma mark - 颜色预定义

/**
 * 单选上课时间 颜色
 */
+ (UIColor *)sscourseCellContentColor;
+ (UIColor *)sscourseCellBorderColor;
+ (UIColor *)sscourseNewCellBorderColor;
/**
 * 自定义view，按下态等
 */
+ (UIColor *)colorOnTouched;
+ (UIColor *)colorOnSelected;

/**
 * 授课时间课程表 颜色表
 */
+ (UIColor *)schePurpleColor;
+ (UIColor *)schePurpleColorWithAlpha:(CGFloat)alpha;

/**
 *  黄色：奖学券
 */
+ (UIColor *)yellowColor_1;

/**
 * 课程详情底部按钮栏背景色
 */
+ (UIColor *)courseDetailBottomBarColor;
/**
 * 
 */

@end
