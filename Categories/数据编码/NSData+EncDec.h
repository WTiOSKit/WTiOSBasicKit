//
//  NSData+EncDec.h
//  QQing
//
//  Created by 李杰 on 5/19/15.
//
//

#import <Foundation/Foundation.h>

@interface NSData (EncDec)

@property (nonatomic, readonly) NSString *	string;

@property (nonatomic, readonly) NSData *	MD5;
@property (nonatomic, readonly) NSString *	MD5String;

@property (nonatomic, readonly) NSData *    Base64;
@property (nonatomic, readonly) NSString *  Base64String;

@end
