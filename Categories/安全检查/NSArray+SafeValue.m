//
//  NSArray+SafeValue.m


#import "NSArray+SafeValue.h"
#import "NSObject+SafeValueWithJSON.h"
#import "NSArray+ObjectAtIndexWithBoundsCheck.h"

@implementation NSArray (SafeValue)

- (NSString *)safeStringAtIndex:(NSUInteger)index {
    return [[self objectAtIndexIfIndexInBounds:index] safeString];
}

- (NSNumber *)safeNumberAtIndex:(NSUInteger)index {
    return [[self objectAtIndexIfIndexInBounds:index] safeNumber];
    
}

- (NSArray *)safeArrayAtIndex:(NSUInteger)index {
    return [[self objectAtIndexIfIndexInBounds:index] safeArray];
}

- (NSDictionary *)safeDictionaryAtIndex:(NSUInteger)index {
    return [[self objectAtIndexIfIndexInBounds:index] safeDictionary];
}

@end
