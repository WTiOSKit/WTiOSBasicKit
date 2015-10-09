//
//  blocktype.h


#ifndef QQing_typedef_h
#define QQing_typedef_h

/*
 * Block 预定义
 */
typedef void(^Block)(void);
typedef void(^BlockBlock)(Block block);
typedef void(^BOOLBlock)(BOOL b);
typedef void(^ObjectBlock)(id obj);
typedef void(^ArrayBlock)(NSArray *array);
typedef void(^MutableArrayBlock)(NSMutableArray *array);
typedef void(^DictionaryBlock)(NSDictionary *dic);
typedef void(^ErrorBlock)(NSError *error);
typedef void(^IndexBlock)(NSInteger index);
typedef void(^ListItemBlock) (NSInteger index, id param);
typedef void(^FloatBlock)(CGFloat afloat);
typedef void(^StringBlock)(NSString *str);
typedef void(^ImageBlock)(UIImage *image);

typedef void(^CancelBlock)(id viewController);
typedef void(^FinishedBlock)(id viewController, id object);

typedef void(^SendRequestAndResendRequestBlock)(id sendBlock, id resendBlock);

/*
 * 结构定义
 */

/* Integer points. */

struct IntPoint {
    NSInteger x;
    NSInteger y;
};
typedef struct IntPoint IntPoint;

CG_INLINE IntPoint
IntPointMake(NSInteger x, NSInteger y)
{
    IntPoint ip;
    ip.x = x;
    ip.y = y;
    return ip;
}

/*
 * Pity! Duplicate with struct tm.
 */
struct QQDate {
    NSInteger week;
    
    NSInteger year;
    NSInteger month;
    NSInteger day;
    
    NSInteger hour;
    NSInteger minute;
    NSInteger second;
};
typedef struct QQDate QQDate;

CG_INLINE QQDate
QQDateMake(NSInteger week, NSInteger year, NSInteger month, NSInteger day,
           NSInteger hour, NSInteger minute, NSInteger second)
{
    QQDate date;
    date.week = week;
    date.year = year;
    date.month = month;
    date.day = day;
    date.hour = hour;
    date.minute = minute;
    date.second = second;
    return date;
}

// ================================= 枚举类型

typedef NS_ENUM(NSUInteger, UserType) {
    // 用户类型
    kUserTypeStudent        = 0,
    kUserTypeTeacher        = 1,
    kUserTypeAssistant      = 2,
};

typedef NS_ENUM(NSUInteger, TeacherType) {
    // 老师认证类型
    kTeacherTypeNoAuthentication   = 0,
    kTeacherTypeAuthentication     = 1,
    kTeacherTypeUnlimited          = 2,
};

typedef NS_ENUM(NSUInteger, GenderType) {
    // 性别
    kGenderTypeWoman        = 0,
    kGenderTypeMan          = 1,
    kGenderTypeUnlimited    = 2,
};

typedef NS_ENUM(NSUInteger, LessonSiteMaskType) {
    // 上课场地类型，用于智能匹配，掩码
    kSiteMaskTypeTeacher      = 1,
    kSiteMaskTypeStudent      = 2,
    kSiteMaskTypeThirdPart    = 4,
};

typedef NS_ENUM(NSUInteger, LessonSiteType) {
    // 上课场地类型，正常下单!!!!! 与h5匹配！！！！！
    kLessonSiteTypeTeacher      = 0, // 老师上门、学生家
    kLessonSiteTypeStudent      = 1, // 学生上门、老师家
    kLessonSiteTypeThirdPart    = 2, // 协商场地
    
    kLessonSiteTypeInvalid      = 13, // 无效
};

typedef NS_ENUM(NSUInteger, TimeType) {
    // 课程的时间类型
    kTimeTypeMorning            = 0,
    kTimeTypeNoon               = 1,
    kTimeTypeEvening            = 2,
};

typedef NS_ENUM(NSUInteger, PaymentType) {
    /*
     * 预支付
     */
    kPaymentTypePre,
};

typedef NS_ENUM(NSUInteger, CourseType) {
    /*
     * 试听课
     */
    kCourseTypeAudition,
    
    /*
     * 正式课
     */
    kCourseTypeFormal,
};
#define kCourseNumberAudition   2
#define kCourseNumberFormal     4

typedef NS_ENUM(NSInteger, CourseStatusType) { // 课程订单状态
    /*
     * 订单等待老师确认
     */
    kCourseStatusTypeWaitingConfirmation            = 0,
    /*
     * 订单双方确认，等待付款
     */
    kCourseStatusTypeWaitingPayment                 = 1,
    /**
     * 付款成功未上课
     */
    kCourseStatusTypePaymentSuccess                 = 2,
    /**
     * 开始上课
     */
    kCourseStatusTypeClassesBegin                   = 3,
    /**
     * 课程结束 等待评价
     */
    kCourseStatusTypeClassesEndEvaluated            = 4,
    /**
     * 评价完成
     */
    kCourseStatusTypeHaveEvaluated                  = 5,
    /**
     * 打款完成
     */
    kCourseStatusTypePlayMoneyComplete              = 6,
    /**
     * 课程冻结
     */
    kCourseStatusTypeFrozen                         = 7,
    /**
     * 课程取消成功
     */
    kCourseStatusTypeCancellationSuccess            = 8,
};

typedef NS_ENUM(NSUInteger, MainTabMenuIndex) {
    kMainTabMenuIndexSchedule           = 0,
    kMainTabMenuIndexSearchTeacher      = 1,
    kMainTabMenuIndexProfile            = 2,
};

/**
 *  FA:
 
 *  api中用的类型 用api开头命名
 */
typedef NS_ENUM(NSUInteger, ApiEntranceType) {
    // 入口方式
    kEntranceTypeFuzzyLookup    = 0, // 智能匹配
    kEntranceTypeExactMatching  = 1, // 手机号查找
    kEntranceTypeRepeatOrder    = 2, // 续课订单（老师端）
    kEntranceTypeFindAttention  = 3, // 通过关注
    kEntranceTypeFindFromIcon   = 4, // 点击老师头像下单
    
    // 4.3.0 新需求，不用于api
    kEntranceTypeFuzzyLookupHelp= 5, // 如果填入api中createType，用kEntranceTypeFuzzyLookup
    kEntranceTypeFuzzyTutorial  = 6, // 立即体验
};

typedef NS_ENUM(NSUInteger, FuzzyMatchEntranceType) {
    //智能匹配入口方式
    kFuzzyMatchEntranceTypeExperience,    //立即体验
    kFuzzyMatchEntranceTypeSearchTeacher, //找老师
};

typedef NS_ENUM(NSUInteger, FuzzyMatchStatus) {
    //智能匹配状态
    kFuzzyMatchStatusMatchNotStart,                 //匹配未开始
    kFuzzyMatchStatusMatchStart,                    //开始匹配
    kFuzzyMatchStatusConigFetched,                  //配置文件获取成功
    kFuzzyMatchStatusConigFetchFailed,              //配置文件获取失败
    kFuzzyMatchStatusForeTimeOverAndTeacherEnough,  //前置时间到且响应老师数满足
    kFuzzyMatchStatusForeTimeOverAndTeacherNotEnough,   //前置时间到且响应老师数不足
    kFuzzyMatchStatusCountDownOver,                 //总倒计时结束
};

typedef NS_ENUM(NSUInteger, OrderTipType) {
    // 订单状态类型
    kOrderTipType,
    kOrderTipTypeComplete,
};

typedef NS_ENUM(NSUInteger, TeacherTimeType) {
    kTeacherTimeTypeTime, // 预设时间
    kTeacherTimeTypeLeave, // 请假时间
    kTeacherTimeTypeOrderCourse, // 课程时间
};

typedef NS_ENUM(NSUInteger, TeacherCertificationStatus) {
    //老师认证状态
    kTeacherCertificationStatusSuccess = 2,
    kTeacherCertificationStatusFail    = 3,
    kTeacherCertificationStatusAuthing = 1,
    kTeacherCertificationStatusNoAuth  = 0,
};

/**
 * 用户类型
 * @author db
 *
 */
typedef NS_ENUM(NSUInteger, StautsType) {
    // 身份
    KMESSAGE_STUDENT        = 0, // 学生
    KMESSAGE_TEACHER        = 1, // 老师
    KMESSAGE_ASSISTANT      = 2, // 助教
};

/**
 * 消息沟通系统　消息类型
 * @author db
 *
 */
typedef NS_ENUM(NSUInteger, MessageType) {
    /**
     * 文本信息
     */
    KMESSAGE_TEXT,
    /**
     * 语音信息
     */
    KMESSAGE_SOUND,
    /**
     * 表情信息
     */
    KMESSAGE_ICON,
    /**
     * 图片信息
     */
    KMESSAGE_IMAGE
    
};

/**
 * 课程操作类型
 */
typedef NS_ENUM(NSUInteger, CourseApplyType) {
    kCourseApplyTypeContinue    = 1, // 续单
    kCourseApplyTypeCancel      = 0, // 取消
};

/**
 *  课程评价类型
 */
typedef NS_ENUM(NSUInteger, CourseAppraiseType) {
    kCourseAppraiseTypeGood = 0,
    kCourseAppraiseTypeMiddle = 1,
    kCourseAppraiseTypeWorse = 2,
};


typedef NS_ENUM(NSUInteger, ApplyChangTime){
    
    /**
     * 拒绝
     */
    KAPPLY_NO,
    /**
     * 同意
     */
    KAPPLY_YES,
};


/**
 * 消息类型
 *
 * @author db
 *
 */
typedef NS_ENUM(NSUInteger,MessageSendType) {
    /**
     * 新消息
     */
    KNEW_MESSAGE,
    /**
     * 消息已经查看过了
     */
    KVIEW_MESSAGE
};

/**
 * 消息发送状态
 *
 * @author li
 *
 */
typedef NS_ENUM(NSUInteger,SendStateType){
    /**
     * 发送中
     */
    KTHE_SENDING,
    /**
     * 发送成功
     */
    KMSUCCESS,
    /**
     * 发送失败
     */
    KMFAILURE,
    /**
     * 消息不存在
     */
};


/**
 * 智能匹配失败，报告的状态
 */
typedef NS_ENUM (NSUInteger, SearchWaittingStatus){
    KSEARCH_SUCCEED = 0,
    
    /**
     *没有老师，弹窗选重新设置条件
     */
    KSEARCH_FAILED_NOTEACHER_RESET = 1,
    
    /**
     *倒计时无人接单，弹窗选修改条件
     */
    KSEARCH_FAILED_KNOTIME_RESET = 2,
    
    /**
     *用户取消，弹窗选修改条件
     */
    KSEARCH_FAILED_KUSER_CANCLE_RESET = 3,
    /**
     *没有老师，弹窗选联系咨询师；倒计时无人接单，弹窗选联系咨询师；用户取消，弹窗联系咨询师
     */
    KSEARCH_FAILED_KUSER_CANCLE_CONTACT = 4,
    /**
     *  老师列表的返回、下订单列表返回。
     */
    KSEARCH_FAILED_KUSER_CANCLE_TEACHER_LIST_ORDER = 5,
};

typedef NS_ENUM(NSUInteger, ProtocolType) {
    // 是否成功
    kError        = 0,
    KSuccess        = 1,
    
};

typedef NS_ENUM(NSUInteger, UploadStatus) {
    kUploadStatusNotStart   = 0,
    kUploadStatusUploading  = 1,
    kUploadStatusSuccess    = 2,
    kUploadStatusFailed     = 3,
};

typedef NS_ENUM(NSUInteger, AuditionType) {
    // 试听类型
    kAuditionOff                = 0,
    kAuditionOn                 = 1,
};

typedef NS_ENUM(NSUInteger, SortType) {
    /**
     * 智能排序
     */
    KINTELLIGENTSORT = 0,
    /**
     * 推荐
     */
    KRECOMMENDSORT = 1,
    /**
     * 离老师最近
     */
    KNEARTEACHERSORT =2,
    /**
     * 离我最近
     */
    KNEARMESORT = 3,
    
};

/**
 * 流程入口类型
 */
typedef NS_ENUM(NSUInteger, FlowEntranceType) {
    /**
     * 立即体验
     */
    kFlowEntranceTypeQuickTurial = 0,
};

#endif
