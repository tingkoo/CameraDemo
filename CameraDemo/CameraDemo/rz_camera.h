#ifndef RZ_CAMERA_H
#define RZ_CAMERA_H

typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef void *HANDLE;

#include "demodata.h"
#include "datatype.h"
#include <QObject>

class CRZ_Camera : public QObject
{
public:
    static	int		s_nCameraCount;	//
    int				m_nDevIndex;
    HANDLE			m_hDevice;
    TCHAR			m_strFriendlyName[255];//char
    int				m_nContrast;
    RZCAMERA		m_CamType;
    RZ_COLOR_TYPE	m_CamColorType;
    COLOR_MODE		m_nColorMode;
    FLIP_MODE		m_nFlipMode;
public:
    int				m_nResCount;		//分辨率个数
    TagResolution *	m_lpszResolution;	//所支持的分辨率
    int				m_nR, m_nG, m_nB;
    int				m_nHBlank,m_nVBlank;
    int				m_nSharp;
protected:
//	HWND			m_hWnd;	//显示窗口的句柄

    BYTE			*m_pRawData;
    BYTE			*m_pRgbData;
    BYTE			*m_pSnapBuffer;
    BYTE			*m_buffercache;

    CapInfoStruct	m_CapInfo;
    DWORD			m_dwCompressor;

//	int				m_nContrast;

    BOOL			m_bPlay;		//
    BOOL			m_bCrossline;	//
    BOOL			m_bTrigger;		//外触发状态，采集外触发图片
    BOOL			m_bTriggerMode;	//外触发模式，只显示外触发时的数据
    BOOL			m_bstretch;		//视频拉伸
    BOOL			m_bCompressor;


    int	m_Xoff, m_Yoff;


public:
/*    void PixelCalibration();
    void EnableCompressor(BOOL bOn);
    void SelectComprossor();
    void SetTriggerMode(BOOL bOn);
    void SetTriggerStatus(BOOL bOn, LPCTSTR lpPath);
//	void CAM_Initialize(HWND hWnd=NULL, int nIdx=1);
    LPCTSTR GetFrameRate(float &fr);
    BOOL IsPlaying();
    BOOL IsVideoStretch();
    HANDLE GetDeviceHandle() const;
    BOOL IsShowCorssLine();
    void DrawCrossLine(BYTE * pData);
    void EnableCrossline(BOOL bOn);
    void VideoAutoSize(BOOL bChange=FALSE);
    void SetDoAWB(BOOL bAWB, LPVOID lpContext);
    void SetDoAE(BOOL bAE, LPVOID lpContext);
    void Snap(ENUM_IMAGE_TYPE type, LPCTSTR lpszPath);
    BOOL Capture2AVI(BOOL bStart, LPCTSTR lpszPath);
    void SetVideoSize(long width, long height);
    void SetParam(ENUM_Param type, long value, long value2=-1);
    CapInfoStruct * GetCapInfo();
    void SetScrollOffset(int H=-1, int V=-1);*/
//    CSize GetVideoSize();
    BOOL StopView();
    BOOL StartView();
    void Play(BOOL bPlay);
//    CRZ_Camera(HWND hWnd, int nIdx=1);
    CRZ_Camera();
    virtual ~CRZ_Camera();
/*    void softTrigger();
    void SetHDR(BOOL bEnable);
    RZCAMERA GetCamType(){return m_CamType;};
    void EnableLightAvg(BOOL bOn);
    void ResetLightAvgTable();
    void SetTriggerDelayTime(LONG Time);
    void EEProm_Set(BYTE *pData);
    void EEProm_Get(BYTE *pData);
    void EEProm_SetByte(int nIndex, int nCount, BYTE *pData);
    void EEProm_GetByte(int nIndex, int nCount, BYTE *pData);
    void SetCustomIO(BYTE data);
    void SetTriggerSource(BYTE data);
    void SetTriggerSourceTime(LONG Time);
    void SetAEParam(BOOL bAE,LPVOID lpContext);

    void SetHBlank(int nHBlank);
    void SetVBlank(int nVBlank);
    void SetZoom(BOOL b);

    void SetExpouseDelayTime(int nTime);

    CString GetSerialNumber();
    void SetNewHWDN(HWND hwnd);

protected:
//    DECLARE_DYNCREATE(CRZ_Camera);
// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CRZ_Camera)
    public:
    virtual void Serialize(CArchive& ar);
    //}}AFX_VIRTUAL
    */
};


#endif // RZ_CAMERA_H
