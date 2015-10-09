//
//  ArchiveRecord.h
//  QQing
//
//  Created by fallen.ink on 7/2/15.
//
//  Encode/Decode object(implement NSCoding/NSCopying proto) by NSKeyedArchiver/NSKeyedUnarchiver

#import <Foundation/Foundation.h>

@interface ArchiveRecord : NSObject

+ (void)saveObject:(id)codeable asFilename:(NSString *)fn;

+ (id)fetchWithFilename:(NSString *)fn;

+ (void)deleteWithFilename:(NSString *)fn;

@end
