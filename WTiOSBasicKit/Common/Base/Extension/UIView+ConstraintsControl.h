//
//  UIView+ConstraintsControl.h
//  QQing
//
//  Created by 李杰 on 7/31/15.
//
//

#import <UIKit/UIKit.h>

@interface UIView (ConstraintsControl)

/**
 *  Make constraints by code! Masonry is suggest.
 
 *  Call it at subViews created.
 */
- (void)applyConstraints;

@end
