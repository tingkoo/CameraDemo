
// rzapi.h

#ifndef _RZAPI_H
#define _RZAPI_H

#include "DataType.h"

#ifndef _LIB
	#ifdef RZSDK_EXPORTS
	#define RZ_API extern "C" __declspec(dllexport) int WINAPI
	#else
	#define RZ_API extern "C" __declspec(dllimport) int WINAPI
	#endif
#else
	#ifdef RZSDK_EXPORTS
	#define RZ_API extern "C" int WINAPI
	#else
	#define RZ_API extern "C" int WINAPI
	#endif
#endif


 /*==============================================================
	函数:	初始化设备，返回摄像头句柄，用于其它函数的调用
	功能:
 
	参数:	pFilterName		保留
			pIndex			摄像头序号
			pCapInfo		初始化摄像头参数   
	说明:   必须要给pCapInfo->Buffer分配足够的内存空间，一般要分配比最大的采集空间要大一些
			推荐用MAXWIDTH*MAXHEIGHT+512，用于传递采集数据
  --------------------------------------------------------------*/
RZ_API 
RZ_Initialize(	IN  LPCTSTR			pFilterName,
				IN	OUT	int				*pIndex,	
				IN  CapInfoStruct	*pCapInfo,
				OUT HANDLE			*hCamera
				);	



/*==============================================================
	函数:	RZ_Uninitialize
	功能:	反初始化设备
	参数:   
	说明:   必须在程序退出时调用,用于释放内存分配空间
  --------------------------------------------------------------*/
RZ_API
RZ_Uninitialize( IN HANDLE hCamera );


/*==============================================================
	函数:	RZ_StartView
	功能:	打开预览窗口,并启动视频流
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_StartView( IN HANDLE	hCamera, 
			  IN LPCTSTR	lpszWindowName, 
			  IN DWORD		dwStyle, 
			  IN int		x, 
			  IN int		y, 
			  IN int		nWidth, 
			  IN int		nHeight, 
			  IN HWND		hwndParent, 
			  IN HMENU		nIDorHMenu
			  );



/*==============================================================
	函数:	RZ_StopView
	功能:	停止视频流
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_StopView( IN HANDLE  hCamera );


/*==============================================================
	函数:	RZ_SetCapInfo
	功能:	实时设置视频参数
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetCapInfo( IN HANDLE hCamera , IN CapInfoStruct  *pCapInfo );


/*==============================================================
	函数:	RZ_GetCapInfo
	功能:	获取实时视频参数
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetCapInfo( IN HANDLE hCamera , OUT CapInfoStruct  *pCapInfo );


/*==============================================================
	函数:	RZ_SetParam
	功能:	设置图像参数
	参数:   

	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetParamColor(IN HANDLE hCamera, COLOR_MODE  DLParam);
RZ_API
RZ_SetParamFlip(IN HANDLE hCamera, FLIP_MODE  DLParam);




/*==============================================================
	函数:	
	功能:	
	参数:   pfAWBCallback 指定AWB结束后的回调函数指针
			VOID (WINAPI *DL_AUTOCALLBACK )( DWORD dw1, LPVOID lpContext );
			lpParam1	是指向AWB结果的指针，通过lpParam1来获得AWB结果如下：
			ULONG   Result = dw1;				// 0xFF202020
			BYTE btRed		= ( BYTE )(Result);				// 0x20
			BYTE btGreen	= ( BYTE )( Result>>8 );		// 0x20
			BYTE btBlue		= ( BYTE )( Result>>16 );		// 0x20
			ULONG Exposure  = ( BYTE )( Result>>24 ) * 2;	// 255 * 2 = 510 ms
			
	说明:   
  --------------------------------------------------------------*/
RZ_API 
RZ_SetDoAWB( IN HANDLE hCamera, IN BOOL bAWB, IN BYTE btTarget,
			  IN DL_AUTOCALLBACK pfAWBCallback,	 IN LPVOID lpContext );

/*==============================================================
	函数:	RZ_SetDoAE
	功能:	开始自动曝光操作
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API 
RZ_SetDoAE( IN HANDLE hCamera, IN BOOL bAE, IN BYTE btTarget, 
			 IN DL_AUTOCALLBACK pfAECallback, IN LPVOID lpContext );


/*==============================================================
	函数:	RZ_GetFrameRate
	功能:	得到摄像头的当前帧率
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API 
RZ_GetFrameRate( IN HANDLE	hCamera, OUT float *pfFrameRate );


/*==============================================================
	函数:	RZ_GetRawFrame
	功能:	采集一帧原始数据到pCapInfo->Buffer中
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetRawFrame(IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo);


/*==============================================================
	函数:	RZ_GetRawFrameToBmp
	功能:	采集一帧原始数据到pCapInfo->Buffer中,并数据保存成8位BMP图片
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetRawFrameToBmp(IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, LPCTSTR  strFileName );


/*==============================================================
	函数:	RZ_GetRgbFrame
	功能:	采集一帧24bitRGB数据到pDest中，同时原始数据会保存在pCapInfo->Buffer中。
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrame(IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, BOOL bFlip=FALSE);


/*==============================================================
	函数:	RZ_GetRgbFrameToBmp
	功能:	采集一帧图像到文件，文件格式会根据CAMPARAM中的设定改变。
			如果设置bClearView,pDest中是经过优化的转换算法而得到24bit的结果，
			如果设置bBW,那么是转换为8bit的灰度图像数据
			如果设置UPDOWN则图像数据会做相应的垂直翻转。
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToBmp( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, IN BOOL SaveData=FALSE ); 


/*==============================================================
	函数:	RZ_GetRgbFrameToJpeg
	功能:	采集一帧图像到Jpeg文件，

	参数:   nQuality 为压缩质量 1 - 100
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToJpeg( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, int nQuality ); 


/*==============================================================
	函数:	RZ_SetContrastValue
	功能:	加入对比度调节功能
	参数:   fValue 范围 1 - 32
	说明:   
  --------------------------------------------------------------*/
RZ_API 
RZ_SetContrastValue( IN HANDLE hCamera, IN int fValue);


/*==============================================================
	函数:	RZ_GetContrastValue
	功能:	获取对比度
	参数:   fValue 返回对比度
	说明:   
  --------------------------------------------------------------*/
RZ_API 
RZ_GetContrastValue( IN HANDLE hCamera, OUT int *fValue);


/*==============================================================
	函数:	RZ_CaptureToAvi
	功能:	AVI录影
	参数:   bStart = TRUE 启动录影 FALSE 停止录影
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_CaptureToAvi( IN HANDLE hCamera, BOOL bStart, LPCTSTR  strFileName );


/*==============================================================
	函数:	RZ_GetTrigger
	功能:	启动外触发模式,用于采集图像
	参数:   ImageType： 指定保存图像的类型，目前仅支持BMP和JPG两种格式
	        pFilterNameStart 文件名设置，以所输入的文件名为文件名的开头之后按顺序加数字标号排列
	                         若输入为空，则按系统时间命名
		    JpegCompressibility 若所选图像保存方式为JPEG格式，该参数给定其压缩比率有效范围1~100
	说明:   每接到一个触发信号就采集一帧图像
	        仅支持低速摄像头，对于RZ-F系列不提供该功能
  --------------------------------------------------------------*/
RZ_API
RZ_GetTrigger( IN HANDLE hCamera, BOOL bStart, 
			   IN  RZIMAGETYPR ImageType, 
			   IN  LPCTSTR	pFileNameStart,
			   IN  int JpegCompressibility=50);

/*==============================================================
	函数:	RZ_SetScrollOffset
	功能:	设置视频窗口滚动偏移
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API 
RZ_SetScrollOffset(IN HANDLE hCamera,int Xoffset, int Yoffset);


/*==============================================================
	函数:	RZ_SetVideoSize
	功能:	设置视频尺寸
	参数:   
	说明:   调用前最好将水平和垂直滚动偏移清0
  --------------------------------------------------------------*/
RZ_API 
RZ_SetVideoSize(IN HANDLE hCamera,int nWidth, int nHeight);



/*==============================================================
	函数:	RZ_GetTotalDeviceNum
	功能:	获得被已安装的设备数目
	参数:   
	说明:   在多设备时使用
  --------------------------------------------------------------*/
RZ_API
RZ_GetTotalDeviceNum(IN HANDLE hCamera, int * pNum);



/*==============================================================
	函数:	RZ_GetDeviceID
	功能:	获得hCamera所指定设备的序号
	参数:   
	说明:   在多设备时使用
  --------------------------------------------------------------*/
RZ_API
RZ_GetDeviceID(IN HANDLE hCamera, IN USHORT * pDeviceID);



/*==============================================================
	函数:	RZ_SetFrameCallBack
	功能:	设置帧回调函数
	参数:   FrameCB 帧回调函数
			lpContext 设备上下文
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetFrameCallBack(IN HANDLE hCamera, IN DL_FRAMECALLBACK FrameCB, LPVOID lpContext);


/*==============================================================
	函数:	RZ_SetDeviceEvent
	功能:	设置设备消息回调函数
	参数:   FrameCB 帧回调函数
			lpContext 设备上下文
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetDeviceEvent(IN HANDLE hCamera, IN DL_AUTOCALLBACK Event, LPVOID lpContext);


/*==============================================================
	函数:	RZ_GetFriendlyName
	功能:	获取设备友好名
	参数:   pName 返回设备友好名
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetFriendlyName(IN HANDLE hCamera, OUT TCHAR * pName);


/*==============================================================
	函数:	RZ_SetClearView
	功能:	设置清晰视频
	参数:   bOn 是否开启清晰视频
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetClearView(IN HANDLE hCamera, IN BOOL bOn);


/*==============================================================
	函数:	RZ_GetClearViewState
	功能:	是否开启清晰视频
	参数:   bOn 如果开启清晰视频,返回TRUE
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetClearViewState(IN HANDLE hCamera, OUT BOOL &bOn);


/*==============================================================
	函数:	RZ_GetDeviceType
	功能:	获得相机类型
	参数:   CamType 返回相机类型
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetDeviceType(IN HANDLE hCamera, OUT RZCAMERA *CamType);


/*==============================================================
	函数:	RZ_SetIO
	功能:	设置IO控制位
	参数:   Data
	说明:   
			引脚顺序
			(2)		(4)		(6)		(8)		(10)
			[1]		(3)		(5)		(7)		(9)	

				data数据 
	data位:		BIT7    BIT6	BIT5	BIT4	BIT3	BIT2	BIT1	BIT0
	对应引脚													[1]		(4)
  --------------------------------------------------------------*/
RZ_API
RZ_SetIO(IN HANDLE hCamera,IN BYTE Data);


/*==============================================================
	函数:	RZ_GetIO
	功能:	获得IO控制位
	参数:   Data 返回IO控制位
	说明:   
				引脚顺序
				(2)		(4)		(6)		(8)		(10)
				[1]		(3)		(5)		(7)		(9)	

				data数据
	data位:		BIT7    BIT6	BIT5	BIT4	BIT3	BIT2	BIT1	BIT0
	对应引脚									(7)		(8)		(5)		(6)
  --------------------------------------------------------------*/
RZ_API
RZ_GetIO(IN HANDLE hCamera, IN OUT BYTE *pData);


/*==============================================================
	函数:	RZ_GetSerialNumber
	功能:	获得序列号
	参数:   data 返回序列号
	说明:   调用函数之前,用户需要为pData申请16字节的内存;
  --------------------------------------------------------------*/
RZ_API
RZ_GetSerialNumber(IN HANDLE hCamera, IN BYTE *pData);


/*==============================================================
	函数:	RZ_PixelCalibration
	功能:	开启坏点校正
	参数:   
	说明:   结果会自动保存到 RZMOS.bpt 文件
  --------------------------------------------------------------*/
RZ_API
RZ_PixelCalibration(IN HANDLE hCamera);


/*==============================================================
	函数:	RZ_SetShowAutoMark
	功能:	设置AE/AWB时图像右上角的方形标志是否显示
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetShowAutoMark(IN HANDLE hCamera, IN BOOL bShow);



/*==============================================================
	函数:	RZ_SetShowVideo
	功能:	在使用RZ_StartView开始采集之后,设置是否显示图像
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetShowVideo(IN HANDLE hCamera, IN BOOL bShow);


/*==============================================================
	函数:	RZ_SelectAviCompressor
	功能:	选择录像使用的压缩器,并通过fccHandler返回
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SelectAviCompressor(IN HANDLE hCamera, OUT DWORD *fccHandler);


/*==============================================================
	函数:	RZ_SetAviCompressor
	功能:	使用fccHandler直接设置录像使用的压缩器
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetAviCompressor(IN HANDLE hCamera, IN DWORD fccHandler);


/*==============================================================
	函数:	RZ_SetGainR
	功能:	设置红增益
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetGainR(IN HANDLE hCamera, IN int nIdxR);


/*==============================================================
	函数:	RZ_SetGainG
	功能:	设置绿增益
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetGainG(IN HANDLE hCamera, IN int nIdxG);


/*==============================================================
	函数:	RZ_SetGainB
	功能:	设置蓝增益
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetGainB(IN HANDLE hCamera, IN int nIdxB);


/*==============================================================
	函数:	RZ_GetGainR
	功能:	获取红增益
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetGainR(IN HANDLE hCamera, OUT int* pIndexR);


/*==============================================================
	函数:	RZ_GetGainB
	功能:	获取蓝增益
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetGainB(IN HANDLE hCamera, OUT int* pIndexB);


/*==============================================================
	函数:	RZ_GetGainG
	功能:	获取绿增益
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetGainG(IN HANDLE hCamera, OUT int* pIndexG);


/*==============================================================
	函数:	RZ_GetDeviceColorType
	功能:	判断当前相机的感光芯片类型,彩色或者黑白
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetDeviceColorType(IN HANDLE hCamera, OUT RZ_COLOR_TYPE *ColorType);


RZ_API
RZ_SetColorAdjust(IN HANDLE hCamera, COLOR_ADJUST_TYPE type);


RZ_API
RZ_GetColorAdjust(IN HANDLE hCamera, COLOR_ADJUST_TYPE *type);


RZ_API
RZ_ResetLightAvgTable(IN HANDLE hCamera);


RZ_API
RZ_EnableLightAvg(IN HANDLE hCamera, BOOL bOn);


RZ_API
RZ_SetSourceFormat(IN HANDLE hCamera, DWORD dwType);
//===============
// Internal use
RZ_API
RZ_SetEC(IN HANDLE hCamera,BYTE *pData);
RZ_API
RZ_GetEC(IN HANDLE hCamera, BYTE *pData);

/*==============================================================
函数:	RZ_SetAELevel
功能:	设置自动曝光亮度效果
参数:   
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_SetAELevel(IN HANDLE hCamera, IN RZ_AE_LEVEL AELevel);

/*==============================================================
函数:	RZ_SetOffCenter
功能:	设置在裁剪模式下居中显示
参数:   
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_SetOffCenter(IN HANDLE hCamera, IN BOOL bCenter);


/*==============================================================
函数:	RZ_GetOffCenter
功能:	获得当前是否是居中显示
参数:   
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_GetOffCenter(IN HANDLE hCamera, OUT BOOL *bCenter);

/*==============================================================
函数:	RZ_ErasureStripe
功能:	去除条纹算法，130W有效
参数:   
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_ErasureStripe(IN HANDLE hCamera);

/*==============================================================
函数:	RZ_ApplyErasure
功能:	开启去条纹算法，130W有效
参数:   
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_ApplyErasure(IN HANDLE hCamera, IN BOOL bOn);

/*==============================================================
函数:	RZ_SetGamma
功能:	设置Gamma值
参数:   
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_SetGamma(IN HANDLE hCamera, IN int _nGammaIdx);

/*==============================================================
函数:	RZ_SetGamma
功能:	获取Gamma值
参数:   
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_GetGamma(IN HANDLE hCamera, OUT int *_nGammaIdx);

/*==============================================================
函数:	RZ_SetTriggerMode
功能:	开启或关闭触发采集模式
参数:   bEnable，TRUE，开启触发采集模式；FALSE,关闭触发采集模式
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_SetTriggerMode(IN HANDLE hCamera, IN BOOL bEnable);


/*==============================================================
函数:	RZ_SoftTrigger
功能:	软触发采集图像
参数:  
说明:   需要将硬件的IO输出端和触发端连接，并应用RZ_SetTriggerMode开启
		触发采集模式。
--------------------------------------------------------------*/
RZ_API
RZ_SoftTrigger(IN HANDLE hCamera);


/*==============================================================
函数:	RZ_VideoPause
功能:	暂停视频
参数:  
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_VideoPause(IN HANDLE hCamera, IN BOOL bPause);


/*==============================================================
	函数:	RZ_GetRgbFrameToBmpZoom
	功能:	采集一帧图像到bmp文件，保存的图像的大小为当前设定的分辨率长宽的各一半
	参数:   
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToBmpZoom( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, IN BOOL SaveData=FALSE ); 


/*==============================================================
	函数:	RZ_GetRgbFrameToJpegZoom
	功能:	采集一帧图像到Jpeg文件，保存的图像的大小为当前设定的分辨率长宽的各一半

	参数:   nQuality 为压缩质量 1 - 100
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToJpegZoom( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, int nQuality ); 

/*==============================================================
函数:	RZ_SetHDR
功能:	开启相机高动态范围效果
参数: 
		bEnable:		标识是否开启高动态范围的参数,FALSE，,关闭;TURE，开启.
说明:	2011-4-19 该方法目前仅对于RZ36M、RZ-F500CF、RZ-F900CF有效
--------------------------------------------------------------*/
RZ_API
RZ_SetHDR(IN HANDLE hCamera, IN BOOL bEnable);


/*================================================================
函数：	RZ_EEProm_Set
功能：	设置保存数据，40个字节可用
参数：	pData为数据
说明：	目前仅对RZ-F300CF有效
================================================================*/
RZ_API
RZ_EEProm_Set(IN HANDLE hCamera, IN BYTE *pData);

/*================================================================
函数：	RZ_EEProm_Get
能：	获取保存数据，40个字节可用
参数：	pData为数据
说明：	目前仅对RZ-F300CF有效
================================================================*/
RZ_API
RZ_EEProm_Get(IN HANDLE hCamera, IN BYTE *pData);
/*================================================================
函数：	RZ_EEProm_SetByte
功能：	设置固定位置固定大小的数据，40个字节可用
参数：	nIndex为开始字节数
		nCount为数据大小
		pData为数据
说明：	nIndex的取值范围为0-39，nCount的取值范围为1-40，nIndex+nCount<=40
		目前仅对RZ-F300CF有效
================================================================*/
RZ_API
RZ_EEProm_SetByte(IN HANDLE hCamera, IN int nIndex, IN int nCount, IN BYTE *pData);
/*================================================================
函数：	RZ_EEProm_GetByte
功能：	
参数：	nIndex为开始字节数
		nCount为数据大小
		pData为数据
说明：	nIndex的取值范围为0-39，nCount的取值范围为1-40，nIndex+nCount<=40
		目前仅对RZ-F300CF有效
================================================================*/
RZ_API
RZ_EEProm_GetByte(IN HANDLE hCamera, IN int nIndex, IN int nCount, OUT BYTE *pData);

/*==============================================================
	函数:	RZ_SetTriggerDelayTime
	功能:	设置相机触发延时采集时间
	参数:   hCamera:		相机句柄
			nTime			延时时间， 单位：ms
	说明:   目前仅对RZ-F300CF，RZ-F500CF有效
  --------------------------------------------------------------*/
RZ_API
RZ_SetTriggerDelayTime(IN HANDLE hCamera, IN LONG nTime);
//////////////////////////////////////////////////////////////////////////
//inner 内部调试，不对外开放
/*==============================================================
	函数:	RZ_Write_Register
	功能:	设置寄存器
	参数:   hCamera:		相机句柄
			ADDR			寄存器地址
			Value			寄存器值
	说明:   目前仅支持设置1个寄存器，并仅支持130W相机
  --------------------------------------------------------------*/
RZ_API
RZ_Write_Register(IN HANDLE hCamera,IN USHORT * ADDR,IN  USHORT * Value,IN  UINT nCount=1);
///////////////////////////////////////////////////////////////////////////

/*==============================================================
	函数:	RZ_SetCustomIO
	功能:	设置用户自定义IO
	参数:   hCamera:		相机句柄
			data			0低电平，1高电平
	说明:   目前仅对RZ-F300CF有效
  --------------------------------------------------------------*/
RZ_API
RZ_SetCustomIO(IN HANDLE hCamera,IN BYTE data);

/*==============================================================
	函数:	RZ_SetTriggerSource
	功能:	设置相机触发源使能
	参数:   hCamera:		相机句柄
			data			控制使能0、1
	说明:   目前仅对RZ-F300CF有效
  --------------------------------------------------------------*/
RZ_API
RZ_SetTriggerSource(IN HANDLE hCamera,IN BYTE data);

/*==============================================================
	函数:	RZ_SetTriggerSourceTime
	功能:	设置相机触发源间隔时间
	参数:   hCamera:		相机句柄
			nTime			延时时间， 单位：ms
	说明:   目前仅对RZ-F300CF有效
  --------------------------------------------------------------*/
RZ_API
RZ_SetTriggerSourceTime(IN HANDLE hCamera, IN LONG nTime);


/*==============================================================
	函数:	RZ_SetHBlank
	功能:	设置相机行间隔
	参数:   hCamera:		相机句柄
			nHBlank			
	说明:   F300CF(142-1023),F130CF(9-1023),130(19-2000,默认800)
  --------------------------------------------------------------*/
RZ_API
RZ_SetHBlank(IN HANDLE hCamera, IN int nHBlank);

/*==============================================================
	函数:	RZ_SetTriggerSourceTime
	功能:	设置相机帧间隔
	参数:   hCamera:		相机句柄
			nVBlank			F300CF,F130CF(25-1023)130(19-2000,默认25)
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetVBlank(IN HANDLE hCamera, IN int nVBlank);

/*==============================================================
	函数:	RZ_AEParam
	功能:	设置自动曝光参数，可以开启实时自动曝光
	参数:   hCamera:		相机句柄
			bLiving:		是否开启实时自动曝光
			AELevel:		曝光等级
			pfAECallback:	曝光回调函数
			lpContext
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_AEParam(IN HANDLE hCamera, IN BOOL bLiving, IN RZ_AE_LEVEL AELevel,
		   IN DL_AUTOCALLBACK pfAECallback, IN LPVOID lpContext);
/*==============================================================
	函数:	RZ_SetSpeedMode
	功能:	设置相机帧速模式
	参数:   hCamera:		相机句柄
			nSpeedMode			帧速设置
	说明:  目前仅支持130w 
  --------------------------------------------------------------*/
/////////////////////////////////不对外开放
RZ_API
RZ_SetSpeedMode(IN HANDLE hCamera, IN RZ_SPEED_MODE nSpeedMode);
/////////////////////////////////
///////////////////////////////////////////////////////////////
//支持gonganbu2011-06-10
/*==============================================================
函数:	RZ_GetNewCalibrationRawFrame
功能:	根据原始校准图像生成新的校准图像
		功能是根据新设置的的增益和对比度，
		由原始校准图像生成新的校准图像，新的校准图像仍为原始数据格式（8位）。

参数:   hCamera,[IN]相机句柄
		lHeight_In，[IN]数据采集高度；
        lWidth_In，[IN]数据采集宽度；
		iColourType_In,[IN]标识当前传入的原始数据采集的是黑白或者彩色图像（未使用）
		iRawDateType_In，[IN] 标识传入原始数据阵列的排列格式（未使用）
        cTotalGain_In，[IN]转换前图像数据的亮度（未使用）
        iContrastValue_In，[IN]转换前图像数据的对比度（未使用）
		pRawFrame_In，[IN]需转换图像的数据的指针
		cNewTotalGain_In，[IN]转换后图像数据的亮度（1-63）
		iNewContrastValue_In，[IN]转换后图像数据的对比度（1-32）
		pRawFrame_Out，[OUT]转换后图像的数据的指针
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_GetNewCalibrationRawFrame(IN HANDLE hCamera,
			IN ULONG lHeight_In,		
			IN ULONG lWidth_In,			
			IN int	 iColourType_In,	
			IN int  iRawDateType_In,	
			IN UCHAR cTotalGain_In,		
			IN int iContrastValue_In,	
			IN UCHAR *pRawFrame_In,		
			IN UCHAR cNewTotalGain_In,	
			IN int iNewContrastValue_In,
			OUT UCHAR *pRawFrame_Out	
			);

/*==============================================================
函数:	RZ_RawFrameToRgb
功能:	由原始数据生成bmp图像数据（BGR顺序排列）

参数:   hCamera,[IN]相机句柄
		lHeight_In，[IN] 数据采集高度；
        lWidth_In，[IN]数据采集宽度；
		iColourType_In,[IN]标识当前传入的原始数据采集的是黑白或者彩色图像（未使用）
		iRawDateType_In，[IN] 标识传入原始数据阵列的排列格式（未使用）
        pRawFrame_In，[IN]原始数据的指针
        pRgbData_Out，[OUT]输出的RGB图像的数据区指针
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_RawFrameToRgb(IN HANDLE hCamera,
			IN ULONG lHeight_In,		
			IN ULONG lWidth_In,			
			IN int	 iColourType_In,	
			IN int  iRawDateType_In,	
			IN UCHAR *pRawFrame_In,		
			OUT UCHAR *pRgbData_Out		
		);

/*==============================================================
函数:	RZ_SetLight
功能:	调节输出图像的亮度值

参数:   hCamera,[IN]相机句柄
		cTotalGain_In，[IN]图像亮度值


说明:   
--------------------------------------------------------------*/
RZ_API
RZ_SetLight(IN HANDLE hCamera, IN UCHAR cTotalGain_In);


/*==============================================================
函数:	RZ_GetLight
功能:	获得输出图像的当前亮度值
参数:   hCamera,[IN]相机句柄
		cTotalGain_Out，[OUT]返回图像的当前亮度值
说明:   
--------------------------------------------------------------*/
RZ_API
RZ_GetLight(IN HANDLE hCamera, OUT UCHAR * cTotalGain_Out);

/*==============================================================
函数:	RZ_WriteDataToDevice
功能:	将数据保存到相机设备中（数据长度40字节）

参数:   hCamera,[IN]相机句柄
		bData_In，[IN]写入到设备的数据指针
        iOffSet_In,[IN]写入数据的首位置偏移量（单位：BYTE）
        iNum_In,[IN]写入数据的长度（单位：BYTE）
说明:   1.0.0.1版本暂未实现
		1.0.0.2版本实现
--------------------------------------------------------------*/
RZ_API
RZ_WriteDataToDevice(IN HANDLE hCamera, IN BYTE *bData_In, 
			IN int iOffSet_In,
			IN int iNum_In);

/*==============================================================
函数:	RZ_ReadDataFromDevice
功能:	读取保存在相机设备中的数据（数据长度40字节）

参数:   hCamera,[IN]相机句柄
		bData_Out，[OUT]输出的数据的指针
		iOffSet_In,[IN]读取数据的首位置的偏移量（单位：BYTE）
        iNum_In,[IN]读取的数据的长度（单位：BYTE）
说明:   1.0.0.1版本暂未实现
		1.0.0.2版本实现
--------------------------------------------------------------*/
RZ_API
RZ_ReadDataFromDevice(IN HANDLE hCamera, IN BYTE *bData_In, 
			IN int iOffSet_In,
			IN int iNum_In);

/*==============================================================
函数:	RZ_DeviceIoControl
功能:	控制小灯的方法，前3字节(24bit)的数对应下层的IO 输出控制，每一bit控制一个LED
		1字节用于控制24V通断：0，表示关；1，表示开
参数:   hCamera,[IN]相机句柄
		bIoData_In，[IN]用于控制设备IO输出的数据（24bit + 8bit）4字节
说明:   1.0.0.1版本暂未实现
		1.0.0.2版本实现
--------------------------------------------------------------*/

RZ_API
RZ_DeviceIoControl(IN HANDLE hCamera, IN BYTE *bIoData_In);

/*==============================================================
函数:	RZ_MCResolutionShow
功能:	设置是否应用自定义的裁剪分辨率显示预览
参数:   hCamera,		[IN]相机句柄
		nEnable:		表示是否开启.TRUE,开启;FALSE,关闭.
		
说明:	在开启了裁剪分辨率显示后,预览图像窗口
		的图像数据长宽改为显示原始图像数据中指定的位置的图像.
--------------------------------------------------------------*/
RZ_API
RZ_MCResolutionShow(IN HANDLE hCamera, IN BOOL nEnable);

/*==============================================================
函数:	RZ_IsMCResolutionShow
功能:	获取是否开启了裁剪分辨率显示
参数:	hCamera,		[IN]相机句柄.
		nEnable:		返回值表示是否开启.TRUE,开启;FALSE,关闭.
		
说明:	
--------------------------------------------------------------*/
RZ_API
RZ_IsMCResolutionShow(IN HANDLE hCamera, OUT BOOL *nEnable);

/*==============================================================
函数:	RZ_SetMCResolution
功能:	设置裁剪分辨率显示的相关参数
参数:   hCamera,		[IN]相机句柄.
		nOffX:			设置裁剪分辨率相对于当前相机采集到的图像左下角的X偏移.
		nOffY:			设置裁剪分辨率相对于当前相机采集到的图像左下角的Y偏移.
		nWidth:			设置裁剪分辨率的宽.
		nHeight			设置裁剪分辨率的高.
		
说明:	在应用设置分辨率函数设置当前的分辨率或者更改颜色模式后,裁剪分辨率的偏移会恢复为0,
		大小会设置为与当前设置的分辨率一样.
		在设置时请确保设置数据的合法性:nOffX+nWidth <= (当前相机设置的分辨率的宽),
		nOffY+nHeight <= (当前相机设置的分辨率的高),
		nWidth与nHeight尽量设置为4的整数倍.
		坐标原点与在回调函数中取得的图像数据的坐标原点保持一致,在图像的左下角.
--------------------------------------------------------------*/
RZ_API
RZ_SetMCResolution(IN HANDLE hCamera, IN int nOffX, IN int nOffY, IN int nWidth, IN int nHeight);
/*==============================================================
函数:	RZ_GetMCResolution
功能:	获取裁剪分辨率显示的相关参数
参数:   hCamera,		[IN]相机句柄.
		nOffX:			获取裁剪分辨率相对于当前相机采集到的图像左上角的X偏移.
		nOffY:			获取裁剪分辨率相对于当前相机采集到的图像左上角的Y偏移.
		nWidth:			获取裁剪分辨率的宽.
		nHeight			获取裁剪分辨率的高.
		
说明:	
--------------------------------------------------------------*/
RZ_API
RZ_GetMCResolution(IN HANDLE hCamera, OUT int *nOffX, OUT int *nOffY, OUT int *nWidth, OUT int *nHeight);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*==============================================================
函数:	RZ_SetExpouseDelayTime
功能:	设置曝光延迟时间
参数:   hCamera,		[IN]相机句柄.
		nTime			[IN]曝光延迟时间，取值范围0-2047
		
说明:	支持RZ130CF，RZ300CF，RZ36M，RZ500CF
--------------------------------------------------------------*/
RZ_API
RZ_SetExpouseDelayTime(IN HANDLE hCamera, IN int nTime);

/*==============================================================
函数:	RZ_SetGolbalGain
功能:	设置全局增益
参数:   hCamera,		[IN]相机句柄.
		nGain			[IN]全局增益，取值范围8-96
		
说明:	支持RZ130CF，RZ300CF，RZ500CF
--------------------------------------------------------------*/
RZ_API
RZ_SetGolbalGain(IN HANDLE hCamera, IN int nGain);

//内部使用，不对外开放
/*==============================================================
函数:	RZ_SetSensorRdMode
功能:	设置感光芯片读出模式
参数:   hCamera,		[IN]相机句柄.
		nSnapshot		[IN]感光芯片读出模式，取值范围
		
说明:	支持RZ130CF，RZ300CF，RZ36M，RZ500CF
--------------------------------------------------------------*/
RZ_API
RZ_SetSensorRdMode(IN HANDLE hCamera, IN int nSnapshot);
/*==============================================================
函数:	RZ_SetExpouseUnit
功能:	设置曝光单位，默认为行数
参数:   hCamera,		[IN]相机句柄.
		nUnit			[IN]曝光单位，0为行数，1为曝光时间
		
说明:	支持RZ-F130MF，RZ-F300CF
--------------------------------------------------------------*/
RZ_API
RZ_SetExpouseUnit(IN HANDLE hCamera, IN int nUnit);
/*==============================================================
函数:	RZ_SetZoomMode
功能:	设置缩放模式
参数:   hCamera,		[IN]相机句柄.
		ZoomMode		[IN]缩放模式
		
说明:	
--------------------------------------------------------------*/
RZ_API
RZ_SetZoomMode(IN HANDLE hCamera, IN RZ_ZOOM_MODE ZoomMode);
/*==============================================================
	函数:	RZ_FrameToImage
	功能:	将传入内存中的数据保存为图像
	参数:   strFileName:      保存图片的名称
			pImageData:       保存图像的内存数据的指针
			_ulWidth：        图像宽度
			_ulHeight：       图像高度
			nColor：          颜色位数 （8或24）
			ImgType：         图片类型
	说明:  nColor参数需要根据图像数据的具体格式来设置8位灰度图
		   或24位RGB图像。
		   所支持的图片类型参见RZIMAGETYPR定义
--------------------------------------------------------------*/
RZ_API
RZ_FrameToImage(IN LPCTSTR strFileName, IN LPVOID pImageData, IN ULONG _ulWidth, IN ULONG _ulHeight, IN ULONG nColor, IN RZIMAGETYPR ImgType);


/*==============================================================
函数:	RZ_SetDoAWBInRegion
功能:	区域自动白平衡
参数:   hCamera,		[IN]相机句柄.
		
		
说明:	
--------------------------------------------------------------*/
RZ_API 
RZ_SetDoAWBInRegion( IN HANDLE hCamera, IN BOOL bAWB, IN BYTE btTarget,	IN DL_AUTOCALLBACK pfAWBCallback, IN LPVOID lpContext, IN long _Sx, IN long _Sy, IN long _Ex, IN long _Ey);
/*==============================================================
函数:	RZ_SetDoAEInRegion
功能:	区域自动曝光
参数:   hCamera,		[IN]相机句柄.
		
		
说明:	
--------------------------------------------------------------*/
RZ_API 
RZ_SetDoAEInRegion( IN HANDLE hCamera, IN BOOL bAWB, IN BYTE btTarget,
				   IN DL_AUTOCALLBACK pfAECallback,	IN LPVOID lpContext, 
				   IN long _Sx, IN long _Sy, IN long _Ex, IN long _Ey);
/*==============================================================
	函数:	RZ_SetSharpness
	功能:	设置清晰度
	参数:   nSharp:      清晰度数值0-7

	说明:  该方法仅支持RZ130SC_YUV型号相机
--------------------------------------------------------------*/
RZ_API
RZ_SetSharpness(IN HANDLE hCamera,int nSharp);
/*==============================================================
	函数:	RZ_GetSharpness
	功能:	获取清晰度
	参数:   fValue:      清晰度数值0-7

	说明:  该方法仅支持RZ130SC_YUV型号相机
--------------------------------------------------------------*/
RZ_API  
RZ_GetSharpness( IN HANDLE hCamera, OUT int *fValue);

RZ_API
RZ_UpdateDeviceProgram(IN HANDLE hCamera,IN BOOL bStart,IN LPCTSTR strUpdateFile);


/*==============================================================
	函数:	RZ_SetTriggerCheckSignalTime
	功能:	设置相机触发检测时间
	参数:   nTime:      相机检测时间，单位ms

	说明:  该方法仅支持RZ36M型号相机
--------------------------------------------------------------*/
RZ_API
RZ_SetTriggerCheckSignalTime(IN HANDLE hCamera, IN USHORT nTime);

/*==============================================================
	函数:	RZ_CapFastMode
	功能:	设置是否开启快速采集模式
	参数:   bStart:      开关设置

	说明:  该方法仅对支持软触发的相机有作用，并且在开启视频的条件下不起作用。
--------------------------------------------------------------*/
RZ_API
RZ_CapFastMode(IN HANDLE hCamera, IN BOOL bStart);
/*==============================================================
	函数:	RZ_SetCameraLED
	功能:	设置相机LED灯光
	参数:   nLED:      灯序号，0-3
			nLight:		灯亮度值，0-2号灯可调节0-127,3号灯仅可控制开关0为关1为开

	说明:  该方法需要硬件支持。
--------------------------------------------------------------*/
RZ_API
RZ_SetCameraLED(IN HANDLE hCamera, IN int nLED,IN int nLight);

RZ_API
RZ_SetClearPic(IN HANDLE hCamera);


RZ_API
RZ_EEProm_Set_Test(IN HANDLE hCamera, IN BYTE *pData);


RZ_API
RZ_EEProm_Get_Test(IN HANDLE hCamera, IN BYTE *pData);

RZ_API
RZ_SetSaturation(IN HANDLE hCamera, IN int nSaturation);

RZ_API
RZ_GetSaturation(IN HANDLE hCamera, IN int *nSaturation);


/*==============================================================
	函数:	RZ_SetEliminationBuffetingTime
	功能:	设置相机消抖时间
	参数:   hCamera:		相机句柄
			nTime			延时时间， 单位：ms
	说明:  
  --------------------------------------------------------------*/
RZ_API
RZ_SetEliminationBuffetingTime(IN HANDLE hCamera, IN LONG nTime);

/*==============================================================
	函数:	RZ_GetDeviceVertion
	功能:	获取相机硬件版本号
	参数:   hCamera:		相机句柄
			pData			版本信息，将返回8个字节的字符串
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetDeviceVertion(IN HANDLE hCamera, IN BYTE *pData);
/*==============================================================
	函数:	RZ_GetDeviceVertion
	功能:	获取相机驱动版本号
	参数:   hCamera:		相机句柄
			pData			版本信息，将返回8个字节的字符串
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_GetDriverVertion(IN HANDLE hCamera, IN BYTE *pData);
/*==============================================================
	函数:	RZ_SetHighLightMode
	功能:	设置高亮模式
	参数:   hCamera:		相机句柄
			b			开关
	说明:   仅130vga起作用
  --------------------------------------------------------------*/
RZ_API
RZ_SetHighLightMode(IN HANDLE hCamera, IN BOOL b);

/*==============================================================
	函数:	RZ_SetHardwareLight
	功能:	设置高亮模式
	参数:   hCamera:		相机句柄
			b			开关
	说明:   仅130vga起作用带帧存
  --------------------------------------------------------------*/
RZ_API
RZ_SetHardwareLight(IN HANDLE hCamera, IN BOOL b);
/*==============================================================
	函数:	RZ_SetHardwareFreeze
	功能:	设置冻结
	参数:   hCamera:		相机句柄
			b			开关
	说明:   仅130vga起作用带帧存
  --------------------------------------------------------------*/
RZ_API
RZ_SetHardwareFreeze(IN HANDLE hCamera, IN BOOL b);
/*==============================================================
	函数:	RZ_SetHardwareContrast
	功能:	设置硬件对比度
	参数:   hCamera:		相机句柄
			nContrast	    8-24
	说明:   仅130vga起作用带帧存
  --------------------------------------------------------------*/
RZ_API
RZ_SetHardwareContrast(IN HANDLE hCamera, IN int nContrast);
/*==============================================================
	函数:	RZ_SetCapNumPerFrame
	功能:	设置驱动内采集帧数
	参数:   hCamera:		相机句柄
			nNum	    默认1
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetCapNumPerFrame(IN HANDLE hCamera, IN int nNum);
/*==============================================================
	函数:	RZ_SetBinZoom
	功能:	设置软件bin模式
	参数:   hCamera:		相机句柄
			nNum	    1,2,3
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_SetBinZoom(IN HANDLE hCamera, IN int nNum);

RZ_API
RZ_SaveLightAVGTable(IN HANDLE hCamera, IN LPCTSTR strAVGFile);

RZ_API
RZ_LoadLightAVGTable(IN HANDLE hCamera, IN LPCTSTR strAVGFile);
RZ_API
RZ_SetLightAVGTopButton(IN HANDLE hCamera, IN int nTop,IN int nButton);

/*==============================================================
	函数:	RZ_UserDrawCallBack
	功能:	设置用户自定义绘制回调函数
	参数:   UserDrawCB 用户自定义绘制回调函数
			lpContext 设备上下文
	说明:   
  --------------------------------------------------------------*/
RZ_API
RZ_UserDrawCallBack(IN HANDLE hCamera, IN DL_FRAMECALLBACK UserDrawCB, LPVOID lpContext);
/*==============================================================
	函数:	RZ_SetAELightParam
	功能:	设置AE参数，合适亮度范围以及对应频率
	参数:   nLightMax 0-255  亮度范围最大值
			nLightMin 0-255  亮度范围最小值
			nFrequency 频率 单位 Hz  可以避免出现水波纹
			
	说明:   频率取0为不起作用，范围取0表示不起作用，最大值要大于最小值，两值差建议在20-25
  --------------------------------------------------------------*/
RZ_API
RZ_SetAELightParam(IN HANDLE hCamera, IN int nLightMax, IN int nLightMin, IN int nFrequency);
RZ_API
RZ_SetBufToCamera(IN HANDLE hCamera, IN BYTE *pData);
RZ_API
RZ_PixelCalibrationHard(IN HANDLE hCamera);
//RZ_API
//RZ_SetBadPnt(IN HANDLE hCamera, IN BadPntStruct *pData);
RZ_API
RZ_SetBadPntValue(IN HANDLE hCamera, IN int nValue);
RZ_API
RZ_GetCameraName(int nIndex,OUT TCHAR * pName);
RZ_API
RZ_GetInitCameraCount();
RZ_API
RZ_SetGainAll(IN HANDLE hCamera, IN int nValue);
RZ_API
RZ_SetHDRValue(IN HANDLE hCamera, IN int nValue);

RZ_API
RZ_GetAELight(IN HANDLE hCamera, OUT int *nLight);
RZ_API
RZ_SetAELight(IN HANDLE hCamera, IN int nLight);
RZ_API
RZ_GetGainAll(IN HANDLE hCamera, OUT int *nValue);

RZ_API
RZ_GetRgbFrameNow(IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, BOOL bFlip);
RZ_API
RZ_GetIsMoved(IN HANDLE hCamera, OUT BOOL *b);
RZ_API
RZ_SetFps(IN HANDLE hCamera,IN DWORD fps);


/*==================================================================================
以下几个函数用来调节RGB颜色矫正系数  取值范围－256~512
-----------------------------------------------------------------------------------*/
RZ_API  RZ_SetRr( IN HANDLE hCamera, IN int nValue);
RZ_API  RZ_SetRg( IN HANDLE hCamera, IN int nValue);
RZ_API  RZ_SetGr( IN HANDLE hCamera, IN int nValue);
RZ_API  RZ_SetGg( IN HANDLE hCamera, IN int nValue);
RZ_API  RZ_SetBr( IN HANDLE hCamera, IN int nValue);
RZ_API  RZ_SetBg( IN HANDLE hCamera, IN int nValue);


/*==================================================================================
保存RGB颜色系数及黑电平值到INI文件中。
-----------------------------------------------------------------------------------*/
RZ_API  RZ_SaveParamToIni(IN HANDLE hCamera);


/*==================================================================================
	函数:	RZ_SetAF_Param
	功能:	设置自动对焦相关的功能参数
	参数:   AutoFocusParam_St:   对焦参数状态设置。详细结构体AutoFocusParam_St说明
				
			strFileName：		用户自定义的存储的图片的目录及名称头。比如用户可以定义文件名为“D:\\Img\myImg_”.则程
			                序会根据存储的图片的顺序，生成一系列文件名为myImg_1.bmp, myImg_2.bmp...的图片。
			usImgCount:			用户在扫描状态下要存储的图片的数量，若设置为0时，则跟据AutoFocusParam_St的值自动计算

            ImgType :存图类型
            bSave：是否存图 
	说明:   
  ---------------------------------------------------------------------------------*/
RZ_API  RZ_SetAF_Param(IN HANDLE hCamera, IN struct AutoFocusParam_St *pAfParam, LPCSTR strFileName, USHORT usImgCount, RZIMAGETYPR ImgType, BOOL bSave);


/*==================================================================================
	函数:	RZ_SetAF_Range
	功能:	设置自动对焦操作时对应的工作范围
	参数:   AutoFocusRange_St:  自动对焦参数范围设置，详见相关结构体说明

	说明:   
  ---------------------------------------------------------------------------------*/
RZ_API  RZ_SetAF_Range(IN HANDLE hCamera, IN struct AutoFocusRange_St *pAfRange);



/*==================================================================================
	函数:	RZ_SetMaxAE_Exposure
	功能:	设置自动曝光状态下，自动曝光
	参数:   AutoFocusRange_St:  自动对焦参数范围设置，详见相关结构体说明

	说明:   
  ---------------------------------------------------------------------------------*/
RZ_API  RZ_SetMaxAE_Exposure(IN HANDLE hCamera, IN unsigned int nValue);



/*==================================================================================
	函数:	RZ_SetAFCallBack
	功能:	设置AF反馈回调函数
	参数:   DL_AUTOCALLBACK AFCB 注册的回调函数
	        lpContext 上下文

			回调函数返回值说明
			dw1,表示当前状态 ，1表示自动扫描结束，2表示自动存图结束
			dw2,表示存图状态 ，当前存储图像数

	说明:   
  ---------------------------------------------------------------------------------*/

RZ_API  
RZ_SetAFCallBack(IN HANDLE hCamera, IN DL_AUTOCALLBACK AFCB, LPVOID lpContext);


/*==================================================================================
	函数:	RZ_GetFrameFromAF
	功能:	从指定自动扫描结果中获取图像内存数据
	参数:   
			nIndex，指定图片序号，从0开始
            pDest，图像数据，bgr排列，需要外界申请
            bFlip，图像是否需要上下翻转

	说明:   
  ---------------------------------------------------------------------------------*/
RZ_API  
RZ_GetFrameFromAF(IN HANDLE hCamera,IN int nIndex, OUT BYTE* pDest, BOOL bFlip=FALSE);


/*==================================================================================
	函数:	RZ_SetAWB_Range
	功能:	设置自动白平衡的计算区域
	参数:   
			pstAwbRange: 详见AWB_Range_ST结构体说明

	说明:   自动白平衡的区域设置应不小于64*64
  ---------------------------------------------------------------------------------*/
RZ_API  
RZ_SetAWB_Range(IN HANDLE hCamera,IN struct AWB_Range_ST *pstAwbRange);

#endif