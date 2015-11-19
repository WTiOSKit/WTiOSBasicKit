//
//  NSData+EncDec.h


#import <Foundation/Foundation.h>

@interface NSData (EncDec)

@property (nonatomic, readonly) NSString *	string;

@property (nonatomic, readonly) NSData *	MD5;
@property (nonatomic, readonly) NSString *	MD5String;

@property (nonatomic, readonly) NSData *    Base64;
@property (nonatomic, readonly) NSString *  Base64String;

@end
