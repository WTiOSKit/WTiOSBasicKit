//
//  NSString+Size.h


#import <Foundation/Foundation.h>

@interface NSString (Size)

- (CGSize)textSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size lineBreakMode:(NSLineBreakMode)lineBreakMode;

//文字的行数
- (int)textLineNumWithFont:(UIFont *)font constrainedToSize:(CGSize)size;

//文字放在一行时的宽高
- (CGSize)textSizeForOneLineWithFont:(UIFont *)font;

@end