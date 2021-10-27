
// datatype.h

#ifndef DATATYPE_H
#define DATATYPE_H

#include <windows.h>
/*===========================================================*\
	AE/AWB回调函数	dw1			返回AE/AWB之后的参数, 
					dw2			返回AE/AWB之后的参数, 
					lpContext	在设置帧回调函数时传递的上下文

2011-04-12 该回调函数格式兼用作设备移除与插入消息的回调
dw1 表示设备插入或移除  0，移除;1，插入
dw2 表示设备的句柄,强制转换
\*=========================================================//*/
typedef VOID (WINAPI *DL_AUTOCALLBACK )( DWORD dw1, DWORD dw2, LPVOID lpContext );

/*===========================================================*\
	帧回调函数	lpParam指向帧数据的指针, 
				lpPoint 保留, 
				lpContext在设置帧回调函数时传递的上下文
\*=========================================================//*/
typedef VOID (WINAPI *DL_FRAMECALLBACK)( LPVOID lpParam1, LPVOID lpPoint, LPVOID lpContext );

/*-------------------------------------------------------------
	返回值定义
  *===========================================================*/
#define		ResSuccess					0x0000		// 返回成功
#define		ResNullHandleErr			0x0001		// 无效句柄
#define		ResNullPointerErr			0x0002		// 指针为空
#define		ResFileOpenErr				0x0003		// 文件创建/打开失败
#define		ResNoDeviceErr				0x0004		// 没有可用设备
#define		ResInvalidParameterErr		0x0005		// 内存分配不足
#define		ResOutOfMemoryErr			0x0006		// 没有开启预览
#define		ResNoPreviewRunningErr		0x0007		// 预览没有开启
#define		ResOSVersionErr				0x0008
#define		ResUsbNotAvailableErr		0x0009
#define		ResNotSupportedErr			0x000a
#define		ResNoSerialString			0x000b
#define		ResVerificationErr			0x000c
#define		ResTimeoutErr	            0x000d
#define		ResScaleModeErr				0x000f
#define		ResUnknownErr				0x00ff

#define		ResDisplayWndExist			0x0011		// 应该关闭预览窗口
#define		ResAllocated				0x0012		// 内存已经分配
#define		ResAllocateFail				0x0013		// 内存分配失败
#define		ResReadError				0x0014      // USB读取失败
#define		ResWriteError				0x0015		// USB命令发出失败
#define		ResUsbOpen					0x0016      // USB端口已经打开
#define     ResCreateStreamErr			0x0017		// 创建avi流失败
#define     ResSetStreamFormatErr		0x0018		// 设置AVI流格式失败
#define		ResGetDCErr					0x0019		// 窗口句柄不正确
#define		ResGetFrameErr				0x0020		// 获取图片不正确


typedef struct _tagDLVIDEORECT
{
    int     Left;		// 相对于父窗口的水平偏移
    int     Top;		// 相对于父窗口的垂直偏移
    int     Width;		// 视频窗口宽度
    int     Height;		// 视频窗口高度
}DLVIDEORECT, *PDLVIDEORECT;

/*-------------------------------------------------------------
    摄像头相关参数结构
  *===========================================================*/
struct CapInfoStruct
{
    UCHAR	*Buffer;		// 用户分配，用于返回8bit原始数据
    ULONG	Height;			// 采集高度
    ULONG	Width;			// 采集宽度
    ULONG	OffsetX;		// 水平偏移,	CCD相机禁用
    ULONG	OffsetY;		// 垂直偏移,	CCD相机禁用
    ULONG	Exposure;		// 曝光值 1-500MS
    UCHAR	Gain[3];		// Gain[0]整体增益 1-63. Gain[1],Gain[2]保留
    UCHAR	Control;		// 控制位
    UCHAR	InternalUse;	// 用户不要对此字节进行操作
    UCHAR	ColorOff[3];	// 用户从外面不要改变此数组的值
    USHORT  nMaxAeExp;
    USHORT  nSharpen;
    UCHAR	Reserved[1];	// 保留位
};

/*-------------------------------------------------------------
    AF功能相关参数结构
byAfState:   电机驱动状态说明
  0：   无效状态  若当前处于自动对焦状态时，发送该值强制结束自动对焦操作。
     1：   扫描状态  开启该状态后，用户需要指定扫描起始位置，扫描结束位置及扫描的步长值
           扫描状态流程如下：
           （1） 控制电机运转到用户指定的起始位置处
           （2） 从起始位置处，按照用户指定的步长值，控制电机步进，直到扫描结束位置处。 该状态下，帧率将减小为实际帧率的三分之一
           （3） 到结束位置后，控制电机回退到扫描过程中最清晰的位置处。
     2：   步进状态 该状态控制电机按照用户指定的方向和步长转动电机一次
     4：   定位移动状态  移动电机到指定的位置处 有效范围0~750，每一步对应长度0.02mm
     8：   开启一次自动对焦操作。
     16:   单次自动对焦操作
     其它：保留

 byAfDirection:		仅在步进状态下有效，控制电机在步进状态下的转动方向
 usAfScanStartLoc:  仅在扫描操作状态下有效。设置扫描操作的起始位置
 usAfScanEndLoc:    扫描操作下，设置扫描操作的结束位置
                    定位移动状态下，设置定位操作目标位置
 byAfScanStep:      扫描状态或步进状态下，设置扫描操作的步进长度  有效范围[1，31]
                    其它状态下，该参数无效，由系统按照最快速度驱动电机转动。
  *===========================================================*/
typedef struct AutoFocusParam_St
{
    UCHAR    byAfState;			//
    UCHAR    byAfDirection;
    USHORT   usAfScanStartLoc;
    USHORT   usAfScanEndLoc;
    UCHAR    byAfScanStep;
    UCHAR 	 Reserved[4];
}*P_AUTOFOCUS_ST;//*/



/*-------------------------------------------------------------
    AF功能对焦区域设置
  *===========================================================*/
typedef struct AutoFocusRange_St
{
    USHORT   usAfRangeHS;	//对焦区域水平起始点
    USHORT   usAfRangeHL;	//对焦区域水平方向上的范围大小
    USHORT   usAfRangeVS;	//对焦区域垂直起始点
    USHORT   usAfRangeVL;	//对焦区域垂直方向上的范围大小
    UCHAR 	 Reserved[4];
}*P_AUTOFOCUS_RANGE_ST;//*/

//CapInfoStruct m_tCamerParam;
/*-----------------------------------------------------------
    Control 控制位说明
    BIT7       BIT6      BIT5     BIT4     BIT3     BIT2     BIT1     BIT0
    用户IO	触发源使能								HDR    	 触发	  裁剪/缩放
    0低电平   0										 0		 0			0裁剪
    1高电平	  1										 1开启	 1 触发采集	1缩放
  ===========================================================*/


/*-------------------------------------------------------------
    颜色模式
  *===========================================================*/
enum	COLOR_MODE {
                    COLOR_RGB24,
                    COLOR_RGB24_CLEAR,
                    COLOR_BW24,
                    COLOR_GRAY,
                    COLOR_RAWDATA,
                    COLOR_Microscope	//颜色校正模式(显微镜模式)
                };


/*-------------------------------------------------------------
    翻转模式 目前仅对RGB24,BW24有效
  *===========================================================*/
enum	FLIP_MODE {
                    FLIP_NATURAL,		// 正常显示
                    FLIP_LEFTRIGHT,	    // 左右翻转
                    FLIP_UPDOWN,			// 上下翻转
                    FLIP_ROTATE180,		// 旋转180
                    FLIP_ROTATE90,
                    FLIP_ROTATE270
                };

enum	RZIMAGETYPR {
                        BMP,		// 保存图像格式设置
                        JPEG,	    //
                    };

enum	RZCAMERA{	RZUNKOWN,		//相机类型
                    RZ130,
                    RZ300,
                    RZ130CF,
                    RZ200CF,
                    RZ300CF,
                    RZ500CF,
                    RZ900CF,
                    RZ500P,			//
                    RZ130C_1_3,
                    RZ36M,
                    RZ300C_FPGA,
                    RZ130C_FPGA,
                    RZ130M_FPGA,
                    RZ80C_SP16,
                    RZ130SC_YUV,
                    RZ120C_FPGA,
                    RZ300_LED,
                    RZTEST,
                    RZF1400CF,
                    RZF1000CF,
                    RZ50C,
                    RZCCD140C,
                    RZUL200MFG,
                    MicroUH1200C,
                    RZTRIGGER,
                    MicroUH600C,
                    SuperUH500,
                    MicroUH300C,
                    SuperUH130,
                    SuperUH200,
                    SuperUH50,
                    SuperUH30,
                    RZF120CF_NEW,//新版本在其上添加
                    RZU31400CII,
                    RZF1400CFII,
                    RZU3120C,
                    RZU3500C,
                    RZU31000C,
                    RZU31400C,
                    RZF300CF_NEW,
                    RZF130MF_NEW,
                    RZF500CF_NEW,
                    RZ500CFSMALL,
                    RZ50016,
                    RZ500_FPGA,
                    RZ500P_FPGA//给gonganbu特殊(这个型号是不暴露的对外显示（RZ500P），再加新型号加载这个上面)
                };

enum	RZ_COLOR_TYPE{
                    RZ_COLOR,
                    RZ_GRAY
                };


enum COLOR_ADJUST_TYPE {
                    COLOR_ADJUST_NO,	//
                    COLOR_ADJUST_COLD,	//冷色优先
                    COLOR_ADJUST_WARM	//暖色优先
                };

//自动曝光亮度效果设置
enum	RZ_AE_LEVEL
{
        RZ_AE_LEVEL_HIGH,	//更亮
        RZ_AE_LEVEL_NORMAL,	//正常
        RZ_AE_LEVEL_LOW		//更暗
};

typedef struct _tagResolution
{
    TCHAR * lpszDesc;
    int	width;
    int	height;
}TagResolution;

enum	RZ_SPEED_MODE
{
        RZ_SPEED_MODE_LOW,	//慢速
        RZ_SPEED_MODE_NORMAL,	//正常
        RZ_SPEED_MODE_HIGH		//快速
};
//缩放模式定义
enum RZ_ZOOM_MODE
{
    RZ_ZOOM_1_1 = 0, //不缩放，裁剪效果
    RZ_ZOOM_1_2 = 1, //行列各缩小一倍。如2048*1536图像缩小后，将变成1024*768的图像
    RZ_ZOOM_1_4 = 2,  //行列各缩小两倍。如2048*1536图像缩小后，将变成512*384的图像
    RZ_ZOOM_0_2 = 3,	//列bin 2x
    RZ_ZOOM_0_3 = 4		//行bin 3x
};

/*--------------------------------------------------------------
自动白平衡区域设置
    要求最小区域设置为64*64
===============================================================*/
typedef struct AWB_Range_ST
{
    USHORT	usAwbRange_XS;	//自动白平衡区域水平方向上的起始位置
    USHORT	usAwbRange_XL;	//自动白平衡区域水平方向上的宽度  取值范围大于等于64
    USHORT	usAwbRange_YS;	//自动白平衡区域垂直方向上的起始位置
    USHORT	usAwbRange_YL;	//自动白平衡区域垂直方向上的高度  取值范围大于等于64
    USHORT  rsvd[4];
}*P_AWB_RANGE_ST;

typedef enum		//
{
    idResolution,	//
    idContrast,		//
    idExposure,		//
    idGain_All,		//
    idGain_R,		//
    idGain_G,		//
    idGain_B,		//
    idOffsetX,		//
    idOffsetY,		//
    idControl,
    idImageType,	//
    idFlipMode,
    idColorMode,
    idSharp,
    idSta
}ENUM_Param;

typedef enum
{
    IMG_TYPE_BMP,
    IMG_TYPE_JPG,
    IMG_TYPE_PNG,
    IMG_TYPE_TIF
}ENUM_IMAGE_TYPE;

#endif
