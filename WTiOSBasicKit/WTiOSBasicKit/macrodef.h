//
//  def.h


#ifndef QQing_def_h
#define QQing_def_h

#undef  FA_EXTERN
#define FA_EXTERN    extern __attribute__((visibility ("default")))

/*!
 * @function Singleton GCD Macro
 */
#ifndef SINGLETON_GCD
#define SINGLETON_GCD(classname)                        \
\
+ (classname *)shared##classname {                      \
\
static dispatch_once_t pred;                        \
__strong static classname * shared##classname = nil;\
dispatch_once( &pred, ^{                            \
shared##classname = [[self alloc] init]; });    \
return shared##classname;                           \
}
#endif

#undef DEF_SINGLETON_GCD
#define DEF_SINGLETON_GCD SINGLETON_GCD

#undef DEC_SINGLETON
#define DEC_SINGLETON(classname) + (classname *)shared##classname;

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

//检查系统版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

//系统版本
#define SYSTEM_VERSION  [[UIDevice currentDevice].systemVersion doubleValue]

// Log
#if DEBUG
#define QQLog( s, ... ) NSLog( @"<%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
//#define NSLog(...)
#define QQLog( s, ... )
#endif

// RGB颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r, g, b, 1.0f)

// 通用异常定制
#define kExceptionName @"qqing exception"

#define kExceptionReasonNotImplemented  @"interface not implemented"
#define kExceptionReasonFunctionWrong   @"function incrrect"

#define __RAISE_NOT_IMPLEMENT_EXCEPTION [[NSException exceptionWithName:kExceptionName\
                                        reason:kExceptionReasonNotImplemented \
                                        userInfo:nil] raise]; // 接口未实现

#define __RAISE_NOT_FUNCTION_EXCEPTION  [[NSException exceptionWithName:kExceptionName\
                                        reason:kExceptionReasonFunctionWrong \
                                        userInfo:nil] raise]; // 功能点不对


// ReactiveCocoa 定制

/**
 *  非绑定的RAC宏定义
 *
 *  @desc   RAC宏的原理是做属性关联
 *
 *  @warn   请使用对类型！
 */
#define NON_BIND_RAC(target, prop, signal) {\
RACCompoundDisposable *disposable = [RACCompoundDisposable compoundDisposable];\
RACDisposable *subscriptionDisposable = [signal subscribeNext:^(id x) {\
target . prop = x ?: nil;\
} error:^(NSError *error) {\
[disposable dispose];\
} completed:^{\
[disposable dispose];\
}];\
[disposable addDisposable:subscriptionDisposable];\
}

// 转到字符串
#define STRING_PRICE_FROM_DOUBLE(value) ([NSString stringWithFormat:@"¥%.2lf", (double)value])
#define STRING_PRICE_PER_HOUR_FROM_DOUBLE(value) ([NSString stringWithFormat:@"¥%.2lf／小时", value])

#define STRING_PRICE_FROM_INTEGER(value) ([NSString stringWithFormat:@"¥%ld.00", (NSInteger)value])
#define STRING_PRICE_PER_HOUR_FROM_INTEGER(value)\
([NSString stringWithFormat:@"¥%zd.00／小时", (NSInteger)value])

#define STRING_HOUR_FROM_DOUBLE(value) ([NSString stringWithFormat:@"%.2lf 小时", (double)value])
#define STRING_HOUR_FROM_INTEGER(value) ([NSString stringWithFormat:@"%ld.00 小时", value])

// 仅仅是标记
#define ___INPUT  // Params input
#define ___OUTPUT // Params output
#define ___RESPONSE
#define ___REQUEST
#define ___(note)

// 默认目录
#define PATH_OF_APP_HOME    NSHomeDirectory()
#define PATH_OF_TEMP        NSTemporaryDirectory()
#define PATH_OF_DOCUMENT    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define PATH_OF_CACHE       [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]

// Package

#undef	DEC_PACKAGE
#define DEC_PACKAGE( __parentClass, __class, __propertyName ) \
@class __class; \
@interface __parentClass (__propertyName) \
@property (nonatomic, readonly) __class * __propertyName; \
@end

#undef	DEF_PACKAGE
#define DEF_PACKAGE( __parentClass, __class, __propertyName ) \
@implementation __parentClass (__propertyName) \
@dynamic __propertyName; \
- (__class *)__propertyName \
{ \
return [__class shared##__class]; \
} \
@end

// fixme: Should have domain\formatErrorDesc\filename\filelinenum
#undef ENC_ERROR
#define ENC_ERROR(pp_error, error_desc) {\
*pp_error = [NSError errorWithDomain:@"IngErrorDomain" code:-1L userInfo:\
[NSDictionary dictionaryWithObjectsAndKeys:\
error_desc, NSLocalizedDescriptionKey,\
NULL]];\
}

// 枚举、错误码：
// Notice: 最新的相关于文字提示的，ErrorDefinition
// Notice: 偏模块化的：property
#undef __enum_start
#define __enum_start(type, name) typedef NS_ENUM(type, name) {

#undef __enum_end
#define __enum_end };

/**
 *
 *  设备类型宏判断，提供给需要在不同机型的设备上的布局调整
 *
 */
#define QQIPHONE_4_4S               (([UIScreen width] == 320) && ([UIScreen height] == 480))
#define QQIPHONE_5_5C_5S            (([UIScreen width] == 320) && ([UIScreen height] == 568))
#define QQIPHONEBELOW_6             ([UIScreen width] == 320)
#define QQIPHONE_6                  ([UIScreen width] == 375)
#define QQIPHONE_6P                 ([UIScreen width] == 414)

#endif
