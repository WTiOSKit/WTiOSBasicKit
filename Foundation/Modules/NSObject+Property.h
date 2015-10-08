//
//  NSObject+Property.h
//  QQing
//
//  Created by 李杰 on 5/19/15.
//
//

#pragma mark -

#undef	AS_STATIC_PROPERTY
#define AS_STATIC_PROPERTY( __name ) \
@property (nonatomic, readonly) NSString * __name; \
+ (NSString *)__name;

#if __has_feature(objc_arc)

#undef	DEF_STATIC_PROPERTY
#define DEF_STATIC_PROPERTY( __name ) \
@dynamic __name; \
- (NSString *)__name \
{ \
return (NSString *)[[self class] __name]; \
} \
+ (NSString *)__name \
{ \
static NSString * __local = nil; \
if ( nil == __local ) \
{ \
__local = [NSString stringWithFormat:@"%s", #__name]; \
} \
return __local; \
}

#else

#undef	DEF_STATIC_PROPERTY
#define DEF_STATIC_PROPERTY( __name ) \
@dynamic __name; \
- (NSString *)__name \
{ \
return (NSString *)[[self class] __name]; \
} \
+ (NSString *)__name \
{ \
static NSString * __local = nil; \
if ( nil == __local ) \
{ \
__local = [[NSString stringWithFormat:@"%s", #__name] retain]; \
} \
return __local; \
}

#endif

#if __has_feature(objc_arc)

#undef	DEF_STATIC_PROPERTY2
#define DEF_STATIC_PROPERTY2( __name, __prefix ) \
@dynamic __name; \
- (NSString *)__name \
{ \
return (NSString *)[[self class] __name]; \
} \
+ (NSString *)__name \
{ \
static NSString * __local = nil; \
if ( nil == __local ) \
{ \
__local = [NSString stringWithFormat:@"%@.%s", __prefix, #__name]; \
} \
return __local; \
}

#else

#undef	DEF_STATIC_PROPERTY2
#define DEF_STATIC_PROPERTY2( __name, __prefix ) \
@dynamic __name; \
- (NSString *)__name \
{ \
return (NSString *)[[self class] __name]; \
} \
+ (NSString *)__name \
{ \
static NSString * __local = nil; \
if ( nil == __local ) \
{ \
__local = [[NSString stringWithFormat:@"%@.%s", __prefix, #__name] retain]; \
} \
return __local; \
}

#endif

#if __has_feature(objc_arc)

#undef	DEF_STATIC_PROPERTY3
#define DEF_STATIC_PROPERTY3( __name, __prefix, __prefix2 ) \
@dynamic __name; \
- (NSString *)__name \
{ \
return (NSString *)[[self class] __name]; \
} \
+ (NSString *)__name \
{ \
static NSString * __local = nil; \
if ( nil == __local ) \
{ \
__local = [NSString stringWithFormat:@"%@.%@.%s", __prefix, __prefix2, #__name]; \
} \
return __local; \
}

#else

#undef	DEF_STATIC_PROPERTY3
#define DEF_STATIC_PROPERTY3( __name, __prefix, __prefix2 ) \
@dynamic __name; \
- (NSString *)__name \
{ \
return (NSString *)[[self class] __name]; \
} \
+ (NSString *)__name \
{ \
static NSString * __local = nil; \
if ( nil == __local ) \
{ \
__local = [[NSString stringWithFormat:@"%@.%@.%s", __prefix, __prefix2, #__name] retain]; \
} \
return __local; \
}

#endif

#pragma mark -

#undef	AS_STATIC_PROPERTY_INT
#define AS_STATIC_PROPERTY_INT( __name ) \
@property (nonatomic, readonly) NSInteger __name; \
+ (NSInteger)__name;

#undef	DEF_STATIC_PROPERTY_INT
#define DEF_STATIC_PROPERTY_INT( __name, __value ) \
@dynamic __name; \
- (NSInteger)__name \
{ \
return (NSInteger)[[self class] __name]; \
} \
+ (NSInteger)__name \
{ \
return __value; \
}

#undef	AS_INT
#define AS_INT	AS_STATIC_PROPERTY_INT

#undef	DEF_INT
#define DEF_INT	DEF_STATIC_PROPERTY_INT

#pragma mark -

#undef	AS_STATIC_PROPERTY_STRING
#define AS_STATIC_PROPERTY_STRING( __name ) \
@property (nonatomic, readonly) NSString * __name; \
+ (NSString *)__name;

#undef	DEF_STATIC_PROPERTY_STRING
#define DEF_STATIC_PROPERTY_STRING( __name, __value ) \
@dynamic __name; \
- (NSString *)__name \
{ \
return [[self class] __name]; \
} \
+ (NSString *)__name \
{ \
return __value; \
}


#undef	TAG_STRING_FOR
#define TAG_STRING_FOR(COMMAND_ID) [NSString stringWithFormat:@"%d", COMMAND_ID]

//
#undef	AS_STRING
#define AS_STRING	AS_STATIC_PROPERTY_STRING

//
#undef	DEF_STRING
#define DEF_STRING	DEF_STATIC_PROPERTY_STRING

// Tag定义
#undef TAG_DEC // 声明
#define TAG_DEC( __name )       AS_STATIC_PROPERTY( __name )

#undef TAG_DEF // 定义
#define TAG_DEF( __name )       DEF_STATIC_PROPERTY3( __name, @"tag", [self description] )

#undef TAG_EQUAL
#define TAG_EQUAL( __tag1, __tag2 ) ([__tag1 isEqualToString:__tag2])

// event

#undef  EVENT_EQUAL
#define EVENT_EQUAL( __tag1, __tag2 ) ([(NSString *)__tag1 isEqualToString:(NSString *)__tag2])

// class

#undef  CLASS_EUQAL
#define CLASS_EUQAL(inst, target_class_type) [inst isKindOfClass:[target_class_type class]]

// Service定义
#undef	DEC_INSTANCE_PROPERTY_STRONG
#define DEC_INSTANCE_PROPERTY_STRONG( __type, __name ) \
@property (nonatomic, strong) __type * __name;

#undef	DEC_INSTANCE_PROPERTY_WEAK
#define DEC_INSTANCE_PROPERTY_WEAK( __type, __name ) \
@property (nonatomic, weak) __type * __name;

#undef  DEF_INSTANCE_PROPERTY
#define DEF_INSTANCE_PROPERTY( __type, __name ) \
- (__type *)__name { \
if (!_##__name) { \
    _##__name = [__type instance]; \
} \
\
return _##__name; \
}

#undef  DEC_INSTANCE_PROPERTY
#define DEC_INSTANCE_PROPERTY DEC_INSTANCE_PROPERTY_STRONG // default: strong

#undef  DEC_SERVICE_PROPERTY
#define DEC_SERVICE_PROPERTY DEC_INSTANCE_PROPERTY_WEAK

#undef  DEF_SERVICE_PROPERTY
#define DEF_SERVICE_PROPERTY DEF_INSTANCE_PROPERTY


