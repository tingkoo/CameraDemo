#ifndef RZAPI_H
#define RZAPI_H

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
    ��? ?:	��? ???��?����?����???��????��?���??�����̡�??��??��? ?????����
    ��???:

    ��? ?:	pFilterName		��???
            pIndex			��????��??�ҡ�
            pCapInfo		��? ???��????�ơ�   ? ?
    ??��?:   ��???��?��?pCapInfo->Buffer�ơ¡֡�??��????????��?��?����?��?��?�ơ¡֡��???????�ܡ�???��?�롰???��???
            ????����MAXWIDTH*MAXHEIGHT+512?�����̡�?????�ܡ�?? ???
  --------------------------------------------------------------*/
RZ_API
RZ_Initialize(	IN  LPCTSTR			pFilterName,
                IN	OUT	int				*pIndex,
                IN  CapInfoStruct	*pCapInfo,
                OUT HANDLE			*hCamera
                );



/*==============================================================
    ��? ?:	RZ_Uninitialize
    ��???:	��?��? ???��?����
    ��? ?:
    ??��?:   ��???��?��?????��? ��??����,���̡�? ?�ơ�????�ơ¡֡�?��?��
  --------------------------------------------------------------*/
RZ_API
RZ_Uninitialize( IN HANDLE hCamera );


/*==============================================================
    ��? ?:	RZ_StartView
    ��???:	????����???��??,��????? ��????
    ��? ?:
    ??��?:
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
    ��? ?:	RZ_StopView
    ��???:	??�¦� ��????
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_StopView( IN HANDLE  hCamera );


/*==============================================================
    ��? ?:	RZ_SetCapInfo
    ��???:	 ? ����?�¡� ��??��? ?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetCapInfo( IN HANDLE hCamera , IN CapInfoStruct  *pCapInfo );


/*==============================================================
    ��? ?:	RZ_GetCapInfo
    ��???:	???�� ? �� ��??��? ?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetCapInfo( IN HANDLE hCamera , OUT CapInfoStruct  *pCapInfo );



/*==============================================================
    ��? ?:	RZ_SetParam
    ��???:	��?�¡�????��? ?
    ��? ?:

    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetParamColor(IN HANDLE hCamera, COLOR_MODE  DLParam);
RZ_API
RZ_SetParamFlip(IN HANDLE hCamera, FLIP_MODE  DLParam);




/*==============================================================
    ��? ?:
    ��???:
    ��? ?:   pfAWBCallback �¡�??AWB���� ?��???????��? ?�¡ǡ�?
            VOID (WINAPI *DL_AUTOCALLBACK )( DWORD dw1, LPVOID lpContext );
            lpParam1	 ?�¡�??AWB������???�¡ǡ�??��??��?lpParam1?????��AWB������??????��
            ULONG   Result = dw1;				// 0xFF202020
            BYTE btRed		= ( BYTE )(Result);				// 0x20
            BYTE btGreen	= ( BYTE )( Result>>8 );		// 0x20
            BYTE btBlue		= ( BYTE )( Result>>16 );		// 0x20
            ULONG Exposure  = ( BYTE )( Result>>24 ) * 2;	// 255 * 2 = 510 ms

    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetDoAWB( IN HANDLE hCamera, IN BOOL bAWB, IN BYTE btTarget,
              IN DL_AUTOCALLBACK pfAWBCallback,	 IN LPVOID lpContext );

/*==============================================================
    ��? ?:	RZ_SetDoAE
    ��???:	?? ??��????��?��???
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetDoAE( IN HANDLE hCamera, IN BOOL bAE, IN BYTE btTarget,
             IN DL_AUTOCALLBACK pfAECallback, IN LPVOID lpContext );


/*==============================================================
    ��? ?:	RZ_GetFrameRate
    ��???:	?��?����????��???��?�ޡ¡�?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetFrameRate( IN HANDLE	hCamera, OUT float *pfFrameRate );


/*==============================================================
    ��? ?:	RZ_GetRawFrame
    ��???:	�ܡ�??��?�¡㡮�� ? ????��pCapInfo->Buffer��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetRawFrame(IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo);


/*==============================================================
    ��? ?:	RZ_GetRawFrameToBmp
    ��???:	�ܡ�??��?�¡㡮�� ? ????��pCapInfo->Buffer��?,��? ???��???�ݡ�8??BMP???��
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetRawFrameToBmp(IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, LPCTSTR  strFileName );


/*==============================================================
    ��? ?:	RZ_GetRgbFrame
    ��???:	�ܡ�??��?�¡�24bitRGB ????��pDest��??��?�� ������ ? ????����???��?pCapInfo->Buffer��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrame(IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, BOOL bFlip=FALSE);


/*==============================================================
    ��? ?:	RZ_GetRgbFrameToBmp
    ��???:	�ܡ�??��?�¡�?????��?????��????��? ��?����???CAMPARAM��???��???��?�����?
            ??��?��?�¡�bClearView,pDest��? ??�٦�?����??????????��????��?��24bit??������??��
            ??��?��?�¡�bBW,??��? ???????8bit???��?????? ???
            ??��?��?�¡�UPDOWN��????? ????��????��????�С¡��ơ�??��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToBmp( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, IN BOOL SaveData=FALSE );


/*==============================================================
    ��? ?:	RZ_GetRgbFrameToJpeg
    ��???:	�ܡ�??��?�¡�?????��Jpeg?????��

    ��? ?:   nQuality ??����??�� ?? 1 - 100
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToJpeg( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, int nQuality );


/*==============================================================
    ��? ?:	RZ_SetContrastValue
    ��???:	?��???����?????��?��???
    ��? ?:   fValue ��??? 1 - 32
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetContrastValue( IN HANDLE hCamera, IN int fValue);


/*==============================================================
    ��? ?:	RZ_GetContrastValue
    ��???:	???��?����???
    ��? ?:   fValue ��????����???
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetContrastValue( IN HANDLE hCamera, OUT int *fValue);


/*==============================================================
    ��? ?:	RZ_CaptureToAvi
    ��???:	AVI??����
    ��? ?:   bStart = TRUE ??????���� FALSE ??�¦�??����
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_CaptureToAvi( IN HANDLE hCamera, BOOL bStart, LPCTSTR  strFileName );


/*==============================================================
    ��? ?:	RZ_GetTrigger
    ��???:	????????��??? ��,���̡�?�ܡ�??????
    ��? ?:   ImageType?�� �¡�??��??????????????��???�ަ�?��?�ݡ�BMP��?JPG?���¡¡�? ��
            pFilterNameStart ????��?��?�¡�?������?? ��????????��???????��??????�ơ�?��?��??��???�� ??�¡�?�ҡ֡֡�??
                             ?? ��?????��?����?��????�� ��?���?��?
            JpegCompressibility ????����????��???�Ʀ� ��??JPEG��? ��?���ǡ̡�? ?��????�롪��??��?? ��???��???1~100
    ??��?:   ��?����?����?��???��??�֡ҡ�??�ܡ�??��?�¡�????
            ��?��?�ݡ�????��????��?��?����?RZ-F????��??����?�ǡ̦�???
  --------------------------------------------------------------*/
RZ_API
RZ_GetTrigger( IN HANDLE hCamera, BOOL bStart,
               IN  RZIMAGETYPR ImageType,
               IN  LPCTSTR	pFileNameStart,
               IN  int JpegCompressibility=50);

/*==============================================================
    ��? ?:	RZ_SetScrollOffset
    ��???:	��?�¡� ��???��??��?????��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetScrollOffset(IN HANDLE hCamera,int Xoffset, int Yoffset);


/*==============================================================
    ��? ?:	RZ_SetVideoSize
    ��???:	��?�¡� ��??��???
    ��? ?:
    ??��?:   ??����?��??�ҡ̦�????����??�С¡���?????��???0
  --------------------------------------------------------------*/
RZ_API
RZ_SetVideoSize(IN HANDLE hCamera,int nWidth, int nHeight);



/*==============================================================
    ��? ?:	RZ_GetTotalDeviceNum
    ��???:	???�̡�?�����ޡ�?��??��?���� ???
    ��? ?:
    ??��?:   ��???��?���� �� �С���
  --------------------------------------------------------------*/
RZ_API
RZ_GetTotalDeviceNum(IN HANDLE hCamera, int * pNum);



/*==============================================================
    ��? ?:	RZ_GetDeviceID
    ��???:	???��hCamera??�¡�??��?����????�ҡ�
    ��? ?:
    ??��?:   ��???��?���� �� �С���
  --------------------------------------------------------------*/
RZ_API
RZ_GetDeviceID(IN HANDLE hCamera, IN USHORT * pDeviceID);



/*==============================================================
    ��? ?:	RZ_SetFrameCallBack
    ��???:	��?�¡̡¡�????��? ?
    ��? ?:   FrameCB �¡�????��? ?
            lpContext ��?���ǡ�?????
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetFrameCallBack(IN HANDLE hCamera, IN DL_FRAMECALLBACK FrameCB, LPVOID lpContext);


/*==============================================================
    ��? ?:	RZ_SetDeviceEvent
    ��???:	��?�¡̡�?����????????��? ?
    ��? ?:   FrameCB �¡�????��? ?
            lpContext ��?���ǡ�?????
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetDeviceEvent(IN HANDLE hCamera, IN DL_AUTOCALLBACK Event, LPVOID lpContext);


/*==============================================================
    ��? ?:	RZ_GetFriendlyName
    ��???:	???�㡭?���ǡ����ҡ̡�?
    ��? ?:   pName ��???��?���ǡ����ҡ̡�?
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetFriendlyName(IN HANDLE hCamera, OUT TCHAR * pName);


/*==============================================================
    ��? ?:	RZ_SetClearView
    ��???:	��?�¡�???? ��??
    ��? ?:   bOn  ?��????????? ��??
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetClearView(IN HANDLE hCamera, IN BOOL bOn);


/*==============================================================
    ��? ?:	RZ_GetClearViewState
    ��???:	 ?��????????? ��??
    ��? ?:   bOn ??��????????? ��??,��???TRUE
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetClearViewState(IN HANDLE hCamera, OUT BOOL &bOn);


/*==============================================================
    ��? ?:	RZ_GetDeviceType
    ��???:	???��????????
    ��? ?:   CamType ��???????????
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetDeviceType(IN HANDLE hCamera, OUT RZCAMERA *CamType);


/*==============================================================
    ��? ?:	RZ_SetIO
    ��???:	��?�¡�IO??��???
    ��? ?:   Data
    ??��?:
            ��?����?��??
            (2)		(4)		(6)		(8)		(10)
            [1]		(3)		(5)		(7)		(9)

                data ???
    data??:		BIT7    BIT6	BIT5	BIT4	BIT3	BIT2	BIT1	BIT0
    ?����?��?����													[1]		(4)
  --------------------------------------------------------------*/
RZ_API
RZ_SetIO(IN HANDLE hCamera,IN BYTE Data);


/*==============================================================
    ��? ?:	RZ_GetIO
    ��???:	???��IO??��???
    ��? ?:   Data ��???IO??��???
    ??��?:
                ��?����?��??
                (2)		(4)		(6)		(8)		(10)
                [1]		(3)		(5)		(7)		(9)

                data ???
    data??:		BIT7    BIT6	BIT5	BIT4	BIT3	BIT2	BIT1	BIT0
    ?����?��?����									(7)		(8)		(5)		(6)
  --------------------------------------------------------------*/
RZ_API
RZ_GetIO(IN HANDLE hCamera, IN OUT BYTE *pData);


/*==============================================================
    ��? ?:	RZ_GetSerialNumber
    ��???:	???��????�ҡ�
    ��? ?:   data ��???????�ҡ�
    ??��?:   ??���̡�? ?��??��,����????��???pData��???16?�¦�???????;
  --------------------------------------------------------------*/
RZ_API
RZ_GetSerialNumber(IN HANDLE hCamera, IN BYTE *pData);


/*==============================================================
    ��? ?:	RZ_PixelCalibration
    ��???:	??????????��?
    ��? ?:
    ??��?:   ������??��?��??��????�� RZMOS.bpt ????
  --------------------------------------------------------------*/
RZ_API
RZ_PixelCalibration(IN HANDLE hCamera);


/*==============================================================
    ��? ?:	RZ_SetShowAutoMark
    ��???:	��?�¡�AE/AWB ��????������?��???�Ʀ�??��?��? ?��??�� ?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetShowAutoMark(IN HANDLE hCamera, IN BOOL bShow);



/*==============================================================
    ��? ?:	RZ_SetShowVideo
    ��???:	��? �С���RZ_StartView?? ?�ܡ�??��?��?,��?�¡� ?��??�� ?????
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetShowVideo(IN HANDLE hCamera, IN BOOL bShow);


/*==============================================================
    ��? ?:	RZ_SelectAviCompressor
    ��???:	���㡮????? �С���??����????,��???��?fccHandler��???
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SelectAviCompressor(IN HANDLE hCamera, OUT DWORD *fccHandler);


/*==============================================================
    ��? ?:	RZ_SetAviCompressor
    ��???:	 �С���fccHandler�¡�������?�¡�???? �С���??����????
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetAviCompressor(IN HANDLE hCamera, IN DWORD fccHandler);


/*==============================================================
    ��? ?:	RZ_SetGainR
    ��???:	��?�¡̡�?��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetGainR(IN HANDLE hCamera, IN int nIdxR);


/*==============================================================
    ��? ?:	RZ_SetGainG
    ��???:	��?�¡�??��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetGainG(IN HANDLE hCamera, IN int nIdxG);


/*==============================================================
    ��? ?:	RZ_SetGainB
    ��???:	��?�¡�??��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetGainB(IN HANDLE hCamera, IN int nIdxB);


/*==============================================================
    ��? ?:	RZ_GetGainR
    ��???:	???���?��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetGainR(IN HANDLE hCamera, OUT int* pIndexR);


/*==============================================================
    ��? ?:	RZ_GetGainB
    ��???:	???��??��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetGainB(IN HANDLE hCamera, OUT int* pIndexB);


/*==============================================================
    ��? ?:	RZ_GetGainG
    ��???:	???��??��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetGainG(IN HANDLE hCamera, OUT int* pIndexG);


/*==============================================================
    ��? ?:	RZ_GetDeviceColorType
    ��???:	��????��?��??????��?��????��????,�� ��???��?��?��?
    ��? ?:
    ??��?:
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


/*==============================================================
��? ?:	RZ_SetAELevel
��???:	��?�¡�?��????��???????��?
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetAELevel(IN HANDLE hCamera, IN RZ_AE_LEVEL AELevel);

/*==============================================================
��? ?:	RZ_SetOffCenter
��???:	��?�¡̡�?�ܡ�???? ��???����??�� ?
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetOffCenter(IN HANDLE hCamera, IN BOOL bCenter);


/*==============================================================
��? ?:	RZ_GetOffCenter
��???:	???��?��?�� ?��? ??����??�� ?
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetOffCenter(IN HANDLE hCamera, OUT BOOL *bCenter);

/*==============================================================
��? ?:	RZ_ErasureStripe
��???:	??��???????��??��130W��???
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_ErasureStripe(IN HANDLE hCamera);

/*==============================================================
��? ?:	RZ_ApplyErasure
��???:	????????????��??��130W��???
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_ApplyErasure(IN HANDLE hCamera, IN BOOL bOn);

/*==============================================================
��? ?:	RZ_SetGamma
��???:	��?�¡�Gamma��?
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetGamma(IN HANDLE hCamera, IN int _nGammaIdx);

/*==============================================================
��? ?:	RZ_SetGamma
��???:	???��Gamma��?
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetGamma(IN HANDLE hCamera, OUT int *_nGammaIdx);

/*==============================================================
��? ?:	RZ_SetTriggerMode
��???:	??????��?����??��?�ܡ�???? ��
��? ?:   bEnable?��TRUE?��??????��?�ܡ�???? ��??FALSE,��?����??��?�ܡ�???? ��
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetTriggerMode(IN HANDLE hCamera, IN BOOL bEnable);


/*==============================================================
��? ?:	RZ_SoftTrigger
��???:	????��?�ܡ�??????
��? ?:
??��?:   ??��?��?����????IO ���???��???��????������?����?��?����RZ_SetTriggerMode????
        ??��?�ܡ�???? ����?
--------------------------------------------------------------*/
RZ_API
RZ_SoftTrigger(IN HANDLE hCamera);


/*==============================================================
��? ?:	RZ_VideoPause
��???:	��??? ��??
��? ?:
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_VideoPause(IN HANDLE hCamera, IN BOOL bPause);


/*==============================================================
    ��? ?:	RZ_GetRgbFrameToBmpZoom
    ��???:	�ܡ�??��?�¡�?????��bmp?????����??????????????��???��?�ޡ�?????�ơ¡�?? �ݡ�????��?��?��?
    ��? ?:
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToBmpZoom( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, IN BOOL SaveData=FALSE );


/*==============================================================
    ��? ?:	RZ_GetRgbFrameToJpegZoom
    ��???:	�ܡ�??��?�¡�?????��Jpeg?????����??????????????��???��?�ޡ�?????�ơ¡�?? �ݡ�????��?��?��?

    ��? ?:   nQuality ??����??�� ?? 1 - 100
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetRgbFrameToJpegZoom( IN HANDLE hCamera, IN struct CapInfoStruct *pCapInfo, OUT BYTE* pDest, LPCTSTR  strFileName, int nQuality );

/*==============================================================
��? ?:	RZ_SetHDR
��???:	????????��????����?????��?
��? ?:
        bEnable:		��? ? ?��?????��????����?????��? ?,FALSE?��,��?����;TURE?��????.
??��?:	2011-4-19 �ǡ̡Ʀ���????�ަ�??����?RZ36M��?RZ-F500CF��?RZ-F900CF��???
--------------------------------------------------------------*/
RZ_API
RZ_SetHDR(IN HANDLE hCamera, IN BOOL bEnable);


/*================================================================
��? ??��	RZ_EEProm_Set
��????��	��?�¡̡�??? ????��40��??�¦�??������
��? ??��	pData?? ???
??��??��	???�ަ�??��RZ-F300CF��???
================================================================*/
RZ_API
RZ_EEProm_Set(IN HANDLE hCamera, IN BYTE *pData);

/*================================================================
��? ??��	RZ_EEProm_Get
???��	???���??? ????��40��??�¦�??������
��? ??��	pData?? ???
??��??��	???�ަ�??��RZ-F300CF��???
================================================================*/
RZ_API
RZ_EEProm_Get(IN HANDLE hCamera, IN BYTE *pData);
/*================================================================
��? ??��	RZ_EEProm_SetByte
��????��	��?�¡̦�?????�¡̦�??????��?? ????��40��??�¦�??������
��? ??��	nIndex???? ??�¦�? ?
        nCount?? ??????��
        pData?? ???
??��??��	nIndex???���?��?????0-39?��nCount???���?��?????1-40?��nIndex+nCount<=40
        ???�ަ�??��RZ-F300CF��???
================================================================*/
RZ_API
RZ_EEProm_SetByte(IN HANDLE hCamera, IN int nIndex, IN int nCount, IN BYTE *pData);
/*================================================================
��? ??��	RZ_EEProm_GetByte
��????��
��? ??��	nIndex???? ??�¦�? ?
        nCount?? ??????��
        pData?? ???
??��??��	nIndex???���?��?????0-39?��nCount???���?��?????1-40?��nIndex+nCount<=40
        ???�ަ�??��RZ-F300CF��???
================================================================*/
RZ_API
RZ_EEProm_GetByte(IN HANDLE hCamera, IN int nIndex, IN int nCount, OUT BYTE *pData);

/*==============================================================
    ��? ?:	RZ_SetTriggerDelayTime
    ��???:	��?�¡�??????��?���� ���ܡ�?? ��?��
    ��? ?:   hCamera:		?????���?
            nTime			���� �� ��?��?�� ?????��ms
    ??��?:   ???�ަ�??��RZ-F300CF?��RZ-F500CF��???
  --------------------------------------------------------------*/
RZ_API
RZ_SetTriggerDelayTime(IN HANDLE hCamera, IN LONG nTime);

/*==============================================================
    ��? ?:	RZ_SetCustomIO
    ��???:	��?�¡̡���???��??��?IO
    ��? ?:   hCamera:		?????���?
            data			0?????��?��1��????��
    ??��?:   ???�ަ�??��RZ-F300CF��???
  --------------------------------------------------------------*/
RZ_API
RZ_SetCustomIO(IN HANDLE hCamera,IN BYTE data);

/*==============================================================
    ��? ?:	RZ_SetTriggerSource
    ��???:	��?�¡�??????��?��? ��??
    ��? ?:   hCamera:		?????���?
            data			??��? ��??0��?1
    ??��?:   ???�ަ�??��RZ-F300CF��???
  --------------------------------------------------------------*/
RZ_API
RZ_SetTriggerSource(IN HANDLE hCamera,IN BYTE data);

/*==============================================================
    ��? ?:	RZ_SetTriggerSourceTime
    ��???:	��?�¡�??????��?��??���? ��?��
    ��? ?:   hCamera:		?????���?
            nTime			���� �� ��?��?�� ?????��ms
    ??��?:   ???�ަ�??��RZ-F300CF��???
  --------------------------------------------------------------*/
RZ_API
RZ_SetTriggerSourceTime(IN HANDLE hCamera, IN LONG nTime);


/*==============================================================
    ��? ?:	RZ_SetHBlank
    ��???:	��?�¡�???????���?
    ��? ?:   hCamera:		?????���?
            nHBlank
    ??��?:   F300CF(142-1023),F130CF(9-1023),130(19-2000,?��??800)
  --------------------------------------------------------------*/
RZ_API
RZ_SetHBlank(IN HANDLE hCamera, IN int nHBlank);

/*==============================================================
    ��? ?:	RZ_SetTriggerSourceTime
    ��???:	��?�¡�????�¡�?���?
    ��? ?:   hCamera:		?????���?
            nVBlank			F300CF,F130CF(25-1023)130(19-2000,?��??25)
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_SetVBlank(IN HANDLE hCamera, IN int nVBlank);

/*==============================================================
    ��? ?:	RZ_AEParam
    ��???:	��?�¡�?��????��?��? ??��?������???? ? ��?��????��?
    ��? ?:   hCamera:		?????���?
            bLiving:		 ?��????? ? ��?��????��?
            AELevel:		??��?????
            pfAECallback:	??��?????��? ?
            lpContext
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_AEParam(IN HANDLE hCamera, IN BOOL bLiving, IN RZ_AE_LEVEL AELevel,
           IN DL_AUTOCALLBACK pfAECallback, IN LPVOID lpContext);

/*==============================================================
��? ?:	RZ_GetNewCalibrationRawFrame
��???:	��???���� ?????????��?�ݡ�????????????
        ��??? ?��?????��?�¡�????��?��?��??����????��
        �������� ?????????��?�ݡ�?????????????��?????????????��??���� ? ???��? ��??8????��?

��? ?:   hCamera,[IN]?????���?
        lHeight_In?��[IN] ???�ܡ�??��?????
        lWidth_In?��[IN] ???�ܡ�????????
        iColourType_In,[IN]��? ??��?��??????���� ? ???�ܡ�???? ?��?��???��?�� ��????????? �С���??
        iRawDateType_In?��[IN] ��? ?????���� ? ???��?????�֡�??��? ��???? �С���??
        cTotalGain_In?��[IN]?????��???? ????????????? �С���??
        iContrastValue_In?��[IN]?????��???? ??????����??????? �С���??
        pRawFrame_In?��[IN]???????????? ?????�¡ǡ�?
        cNewTotalGain_In?��[IN]????��????? ???????????1-63??
        iNewContrastValue_In?��[IN]????��????? ??????����?????1-32??
        pRawFrame_Out?��[OUT]????��??????? ?????�¡ǡ�?
??��?:
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
��? ?:	RZ_RawFrameToRgb
��???:	�������� ? ???��?�ݡ�bmp???? ?????BGR?��??�֡�????

��? ?:   hCamera,[IN]?????���?
        lHeight_In?��[IN]  ???�ܡ�??��?????
        lWidth_In?��[IN] ???�ܡ�????????
        iColourType_In,[IN]��? ??��?��??????���� ? ???�ܡ�???? ?��?��???��?�� ��????????? �С���??
        iRawDateType_In?��[IN] ��? ?????���� ? ???��?????�֡�??��? ��???? �С���??
        pRawFrame_In?��[IN]���� ? ?????�¡ǡ�?
        pRgbData_Out?��[OUT] ���???RGB?????? ?????�¡ǡ�?
??��?:
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
��? ?:	RZ_SetLight
��???:	??��? ���???????????��?

��? ?:   hCamera,[IN]?????���?
        cTotalGain_In?��[IN]????????��?


??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetLight(IN HANDLE hCamera, IN UCHAR cTotalGain_In);


/*==============================================================
��? ?:	RZ_GetLight
��???:	???�� ���????????��?��????��?
��? ?:   hCamera,[IN]?????���?
        cTotalGain_Out?��[OUT]��??????????��?��????��?
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetLight(IN HANDLE hCamera, OUT UCHAR * cTotalGain_Out);

/*==============================================================
��? ?:	RZ_WriteDataToDevice
��???:	��? ???��????��????��?���ǡ�??? ???�ݡ�??40?�¦�???

��? ?:   hCamera,[IN]?????���?
        bData_In?��[IN]?????����?����?? ???�¡ǡ�?
        iOffSet_In,[IN]???? ????? ???�¡�??��??????????��BYTE??
        iNum_In,[IN]???? ?????�ݡ�?????????��BYTE??
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_WriteDataToDevice(IN HANDLE hCamera, IN BYTE *bData_In,
            IN int iOffSet_In,
            IN int iNum_In);

/*==============================================================
��? ?:	RZ_ReadDataFromDevice
��???:	???���???��?????��?���ǡ�??? ????? ???�ݡ�??40?�¦�???

��? ?:   hCamera,[IN]?????���?
        bData_Out?��[OUT] ���??? ?????�¡ǡ�?
        iOffSet_In,[IN]???�� ????? ???�¡�????��??????????��BYTE??
        iNum_In,[IN]???��?? ?????�ݡ�?????????��BYTE??
??��?:
--------------------------------------------------------------*/
RZ_API
RZ_ReadDataFromDevice(IN HANDLE hCamera, IN BYTE *bData_In,
            IN int iOffSet_In,
            IN int iNum_In);

/*==============================================================
��? ?:	RZ_DeviceIoControl
��???:	??��??��????�Ʀ���??��?��3?�¦�?(24bit)?? ??����???��???IO  ���???��??����?��?bit??��?��?��?LED
        1?�¦�?���̡�???��?24V?????��0?����? ?��???1?����? ???
��? ?:   hCamera,[IN]?????���?
        bIoData_In?��[IN]���̡�???��?��?����IO ���??? ?????24bit + 8bit??4?�¦�?
??��?:
--------------------------------------------------------------*/

RZ_API
RZ_DeviceIoControl(IN HANDLE hCamera, IN BYTE *bIoData_In);

/*==============================================================
��? ?:	RZ_MCResolutionShow
��???:	��?�¡� ?��?��?����?��??��???�ܡ�??�ơ¡�?? ?�� ?����??
��? ?:   hCamera,		[IN]?????���?
        nEnable:		��? ? ?��?????.TRUE,????;FALSE,��?����.

??��?:	��???????�ܡ�??�ơ¡�?? ?�� ?��?,����???????��??
        ?????? ???�ݡ�??��????�� ?���� ????? ???��?�¡�??????�¡�??????.
--------------------------------------------------------------*/
RZ_API
RZ_MCResolutionShow(IN HANDLE hCamera, IN BOOL nEnable);

/*==============================================================
��? ?:	RZ_IsMCResolutionShow
��???:	???�� ?��???????�ܡ�??�ơ¡�?? ?�� ?
��? ?:	hCamera,		[IN]?????���?.
        nEnable:		��???��?��? ? ?��?????.TRUE,????;FALSE,��?����.

??��?:
--------------------------------------------------------------*/
RZ_API
RZ_IsMCResolutionShow(IN HANDLE hCamera, OUT BOOL *nEnable);

/*==============================================================
��? ?:	RZ_SetMCResolution
��???:	��?�¡̡ܡ�??�ơ¡�?? ?�� ?????��?��? ?
��? ?:   hCamera,		[IN]?????���?.
        nOffX:			��?�¡̡ܡ�??�ơ¡�?? ???����??��?��????�ܡ�???��??????????��???X??��?.
        nOffY:			��?�¡̡ܡ�??�ơ¡�?? ???����??��?��????�ܡ�???��??????????��???Y??��?.
        nWidth:			��?�¡̡ܡ�??�ơ¡�?? ????.
        nHeight			��?�¡̡ܡ�??�ơ¡�?? ??��?.

??��?:	��?��?���̡�?�¡̡ơ¡�?? ��? ?��?�¡�?��?��??�ơ¡�?? ??��?��?��?������??? ����?,�ܡ�??�ơ¡�?? ????��??��?�¡�???0,
        ???��?����?�¡�??��??��?�ޡ�?�¡�??�ơ¡�?? ��?��?.
        ��?��?�¡� ��???�ơ�?��?�¡� ?????��?��??��:nOffX+nWidth <= (?��?��????��?�¡�??�ơ¡�?? ????),
        nOffY+nHeight <= (?��?��????��?�¡�??�ơ¡�?? ??��?),
        nWidth��?nHeight?��??��?�¡�??4??��? ?��?.
        ??��?����??��?��?????��? ?��??��?��?????? ???????��?����??��?�ݡ¡�?��?,��???????????��?.
--------------------------------------------------------------*/
RZ_API
RZ_SetMCResolution(IN HANDLE hCamera, IN int nOffX, IN int nOffY, IN int nWidth, IN int nHeight);

/*==============================================================
��? ?:	RZ_GetMCResolution
��???:	???��ܡ�??�ơ¡�?? ?�� ?????��?��? ?
��? ?:   hCamera,		[IN]?????���?.
        nOffX:			???��ܡ�??�ơ¡�?? ???����??��?��????�ܡ�???��????????��?��???X??��?.
        nOffY:			???��ܡ�??�ơ¡�?? ???����??��?��????�ܡ�???��????????��?��???Y??��?.
        nWidth:			???��ܡ�??�ơ¡�?? ????.
        nHeight			???��ܡ�??�ơ¡�?? ??��?.

??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetMCResolution(IN HANDLE hCamera, OUT int *nOffX, OUT int *nOffY, OUT int *nWidth, OUT int *nHeight);

/*==============================================================
��? ?:	RZ_SetExpouseDelayTime
��???:	��?�¡�??��?������? ��?��
��? ?:   hCamera,		[IN]?????���?.
        nTime			[IN]??��?������? ��?��?��?���?��???0-2047

??��?:	��?�ݡ�RZ130CF?��RZ300CF?��RZ36M?��RZ500CF
--------------------------------------------------------------*/
RZ_API
RZ_SetExpouseDelayTime(IN HANDLE hCamera, IN int nTime);

/*==============================================================
��? ?:	RZ_SetExpouseUnit
��???:	��?�¡�??��??????��?��?????? ?
��? ?:   hCamera,		[IN]?????���?.
        nUnit			[IN]??��??????��0???? ??��1????��? ��?��

??��?:	��?�ݡ�RZ-F130MF?��RZ-F300CF
--------------------------------------------------------------*/
RZ_API
RZ_SetExpouseUnit(IN HANDLE hCamera, IN int nUnit);
/*==============================================================
    ��? ?:	RZ_FrameToImage
    ��???:	��?????????��??? ???��?????????
    ��? ?:   strFileName:      ��??????��??��?��?
            pImageData:       ��????????????? ?????�¡ǡ�?
            _ulWidth?��        ????????
            _ulHeight?��       ????��???
            nColor?��          ������??? ? ??8??24??
            ImgType?��         ???��????
    ??��?:  nColor��? ???��?��??????? ?????????��? ��??��?�¡�8???��????
           ??24??RGB????��?
           ??��?�ݡ�?????��????��???RZIMAGETYPR??��?
--------------------------------------------------------------*/
RZ_API
RZ_FrameToImage(IN LPCTSTR strFileName, IN LPVOID pImageData, IN ULONG _ulWidth, IN ULONG _ulHeight, IN ULONG nColor, IN RZIMAGETYPR ImgType);

/*==============================================================
    ��? ?:	RZ_SetTriggerCheckSignalTime
    ��???:	��?�¡�??????��???��? ��?��
    ��? ?:   nTime:      ??????��? ��?��?��????ms

    ??��?:  �ǡ̡Ʀ���?��?��?�ݡ�RZ36M??�ҡ�????
--------------------------------------------------------------*/
RZ_API
RZ_SetTriggerCheckSignalTime(IN HANDLE hCamera, IN USHORT nTime);

/*==============================================================
    ��? ?:	RZ_SetCameraLED
    ��???:	��?�¡�????LED??��?
    ��? ?:   nLED:      ????�ҡ�?��0-3
        nLight:	   ??????��??��0-2�ҡ�???��??��?0??��?127????,3�ҡ�??��??��??��???��?1??��?0????

    ??��?:  �ǡ̡Ʀ���???��?����??��?�ݡ¡�?
--------------------------------------------------------------*/
RZ_API
RZ_SetCameraLED(IN HANDLE hCamera, IN int nLED,IN int nLight);
/*==============================================================
    ��? ?:	RZ_SetSaturation
    ��???:	???��Micro????????��???��?��?
    ��? ?:   nValue:    1-63 ,32

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetSaturation(IN HANDLE hCamera, IN int nSaturation);
/*==============================================================
    ��? ?:	RZ_GetSaturation
    ��???:	???���?��???
    ��? ?:   nSaturation:      ��?��??? ?��?1-16?��?��??8

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetSaturation(IN HANDLE hCamera, OUT int *nSaturation);
/*==============================================================
    ��? ?:	RZ_SetSharpness
    ��???:	��?�¡�??????
    ��? ?:   nSharp:      ?????? ?��?1-8

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetSharpness(IN HANDLE hCamera,int nSharp);
/*==============================================================
    ��? ?:	RZ_GetSharpness
    ��???:	???��??????
    ��? ?:   fValue:      ?????? ?��?1-8

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetSharpness( IN HANDLE hCamera, OUT int *fValue);

/*==============================================================
    ��? ?:	RZ_GetDeviceVertion
    ��???:	???��????����??��?��?�ҡ�
    ��? ?:   hCamera:		?????���?
            pData			��?��??��???����?��???8��??�¦�????�¡�???
    ??��?:
  --------------------------------------------------------------*/
RZ_API
RZ_GetDeviceVertion(IN HANDLE hCamera, IN BYTE *pData);
/*==============================================================
    ��? ?:	RZ_CapFastMode
    ��???:	��?�¡� ?��?????????�ܡ�???? ��
    ��? ?:   bStart:      ??��?��?�¡�

    ??��?:  �ǡ̡Ʀ���?��??����?�ݡ�????��???????��???����?����??����????? ��??????????��?????���̡�?
--------------------------------------------------------------*/
RZ_API
RZ_CapFastMode(IN HANDLE hCamera, IN BOOL bStart);
/*==============================================================
    ��? ?:	RZ_SetGainAll
    ��???:	��?�¡�Micro????????��???��?��?
    ��? ?:   nValue:   1-1957

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetGainAll(IN HANDLE hCamera, IN int nValue);
/*==============================================================
    ��? ?:	RZ_SetGainAll
    ��???:	��?�¡�Micro????????HDR
    ��? ?:   nValue:   0-1

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetHDRValue(IN HANDLE hCamera, IN int nValue);
/*==============================================================
    ��? ?:	RZ_GetAELight
    ��???:	???��AE??��?????��?
    ��? ?:   nValue:    50-220

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetAELight(IN HANDLE hCamera, OUT int *nLight);
/*==============================================================
    ��? ?:	RZ_SetAELight
    ��???:	��?�¡�AE??��?????��?
    ��? ?:   nValue:    50-220

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_SetAELight(IN HANDLE hCamera, IN int nLight);
/*==============================================================
    ��? ?:	RZ_GetGainAll
    ��???:	???��Micro????????��???��?��?
    ��? ?:   nValue:    1-1957

    ??��?:
--------------------------------------------------------------*/
RZ_API
RZ_GetGainAll(IN HANDLE hCamera, OUT int *nValue);

#endif // RZAPI_H
