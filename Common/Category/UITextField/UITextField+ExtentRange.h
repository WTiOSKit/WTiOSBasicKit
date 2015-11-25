//
//  UITextField+ExtentRange.h


#import <UIKit/UIKit.h>

@interface UITextField (ExtentRange)

- (NSRange)selectedRange;
- (void)setSelectedRange:(NSRange)range;

@end
