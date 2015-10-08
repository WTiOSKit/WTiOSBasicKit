//
//  NSData+EncDec.m
//  QQing
//
//  Created by 李杰 on 5/19/15.
//
//
#import <CommonCrypto/CommonDigest.h>
#import "NSData+EncDec.h"

@implementation NSData (EncDec)

#define CHAR64(c) (index_64[(unsigned char)(c)])

#define BASE64_GETC (length > 0 ? (length--, bytes++, (unsigned int)(bytes[-1])) : (unsigned int)EOF)
#define BASE64_PUTC(c) [buffer appendBytes: &c length: 1]

static char basis_64[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static inline void output64Chunk( int c1, int c2, int c3, int pads, NSMutableData * buffer )
{
    char pad = '=';
    BASE64_PUTC(basis_64[c1 >> 2]);
    BASE64_PUTC(basis_64[((c1 & 0x3) << 4) | ((c2 & 0xF0) >> 4)]);
    
    switch ( pads )
    {
        case 2:
            BASE64_PUTC(pad);
            BASE64_PUTC(pad);
            break;
            
        case 1:
            BASE64_PUTC(basis_64[((c2 & 0xF) << 2) | ((c3 & 0xC0) >> 6)]);
            BASE64_PUTC(pad);
            break;
            
        default:
        case 0:
            BASE64_PUTC(basis_64[((c2 & 0xF) << 2) | ((c3 & 0xC0) >> 6)]);
            BASE64_PUTC(basis_64[c3 & 0x3F]);
            break;
    }
}


- (NSString *)string {
    return [[NSString alloc] initWithData:self encoding:NSStringEncodingConversionAllowLossy];
}

- (NSData *)MD5 {
    unsigned char md5Result[CC_MD5_DIGEST_LENGTH + 1];
    CC_MD5( [self bytes], (CC_LONG)[self length], md5Result );
    
    NSMutableData * retData = [NSMutableData new];
    if ( nil == retData )
        return nil;
    
    [retData appendBytes:md5Result length:CC_MD5_DIGEST_LENGTH];
    return retData;
}

- (NSString *)MD5String {
    NSData * value = [self MD5];
    if ( value ) {
        char			tmp[16];
        unsigned char *	hex = (unsigned char *)malloc( 2048 + 1 );
        unsigned char *	bytes = (unsigned char *)[value bytes];
        unsigned long	length = [value length];
        
        hex[0] = '\0';
        
        for ( unsigned long i = 0; i < length; ++i ) {
            sprintf( tmp, "%02X", bytes[i] );
            strcat( (char *)hex, tmp );
        }
        
        NSString * result = [NSString stringWithUTF8String:(const char *)hex];
        free( hex );
        return result;
    } else {
        return nil;
    }
}

- (NSData *)Base64 {
    NSMutableData * buffer = [NSMutableData data];
    const unsigned char * bytes;
    NSUInteger length;
    unsigned int c1, c2, c3;
    
    bytes = [self bytes];
    length = [self length];
    
    while ( (c1 = BASE64_GETC) != (unsigned int)EOF )
    {
        c2 = BASE64_GETC;
        if ( c2 == (unsigned int)EOF )
        {
            output64Chunk( c1, 0, 0, 2, buffer );
        }
        else
        {
            c3 = BASE64_GETC;
            if ( c3 == (unsigned int)EOF )
                output64Chunk( c1, c2, 0, 1, buffer );
            else
                output64Chunk( c1, c2, c3, 0, buffer );
        }
    }
    
    return buffer;
}

- (NSString *)Base64String {
    return [[NSString alloc] initWithData:[self Base64] encoding:NSASCIIStringEncoding];
}

@end
