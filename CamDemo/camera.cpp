#include "camera.h"

static TagResolution lpszResolution900[] =
{
    {L"3488 * 2560",3488,2560},
    {L"1744 * 1280",1744,1280},
    {L"872 * 640",872,640},
};

static TagResolution lpszResolution500P_New[] =
{
    {L"2592 * 1944",2592,1944},
    {L"2560 * 1944",2560,1944},
    {L"2048 * 1536",2048,1536},
    {L"1280 * 972",1280,972},
    {L"640 * 480",640,480},
};

static TagResolution lpszResolution500P[] =
{
    {L"2560 * 1944",2560,1944},
    {L"1280 * 972",1280,972},
    {L"640 * 486",640,486},
};
static TagResolution lpszResolution500[] =
{
    {L"2592 * 1944",2592,1944},
    {L"2560 * 800",2560,800},
    {L"2048 * 1536",2048,1536},
    {L"1600 * 1200",1600,1200},
    {L"1280 * 1024",1280,1024},
    {L"1280 * 400",1280,400},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};
static TagResolution lpszResolution500Super[] =
{
    {L"2592 * 2048",2592,2048},
    {L"2592 * 1944",2560,1944},
    {L"2048 * 1536",2048,1536},
    {L"1600 * 1200",1600,1200},
    {L"1280 * 1024",1280,1024},
    {L"1280 * 400",1280,400},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};

static TagResolution lpszResolution300[] =
{
    {L"2048 * 1536",2048,1536},
    {L"1600 * 1200",1600,1200},
    {L"1280 * 1024",1280,1024},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};

static TagResolution lpszResolution200[] =
{
    {L"1600 * 1200",1600,1200},
    {L"1280 * 1024",1280,1024},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};
static TagResolution lpszResolution200Super[] =
{
    {L"1920 * 1200",1920,1200},
    {L"1600 * 1200",1600,1200},
    {L"1280 * 1024",1280,1024},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};
static TagResolution lpszResolutionDft[] =
{
    {L"1280 * 1024",1280,1024},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};
static TagResolution lpszResolution50[] =
{

    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};
static TagResolution lpszResolution30[] =
{
    {L"640 * 480",640,480},
};
static TagResolution lpszResolution120[] =
{
    {L"1280 * 960",1280,960},
    {L"1280 * 720",1280,720},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};
static TagResolution lpszResolution1400[] =
{
    {L"4608 * 3288",4608,3288},
    {L"3488 * 2560",3488,2560},
    {L"2592 * 1944",2592,1944},
    {L"2048 * 1536",2048,1536},
    {L"1600 * 1200",1600,1200},
    {L"1280 * 1024",1280,1024},
    {L"1024 * 768",1024,768},
//	{L"800 * 600",800,600},
// 	{L"640 * 480",640,480},
};
static TagResolution lpszResolution1000[] =
{
    {L"3840 * 2748",3840,2748},
    {L"3488 * 2560",3488,2560},
    {L"2592 * 1944",2592,1944},
    {L"2048 * 1536",2048,1536},
    {L"1600 * 1200",1600,1200},
    {L"1280 * 1024",1280,1024},
    {L"1024 * 768",1024,768},
    {L"800 * 600",800,600},
    {L"640 * 480",640,480},
};
static TagResolution lpszResolution1200[] =
{
    {L"4000 * 3000",4000,3000},
    {L"2000 * 1500",2000,1500},
};
static TagResolution lpszResolution600[] =
{
    {L"3072 * 2048",3072,2048},
};
static TagResolution lpszResolution36M[] =
{
    {L"752 * 480",752,480},
};
static TagResolution lpszResolution140[] =
{
    {L"1360 * 1024",1360,1024}
};

VOID CALLBACK FrameCallback( LPVOID pData, LPVOID lpReserve, LPVOID lpContext )
{
    //帧回调函数,请尽快返回.
    qDebug("%s", "--- frame callback --- \n");
    Camera * pCamera = (Camera *)lpContext;
    pCamera->DrawCrossLine(PBYTE(pData));
};

VOID CALLBACK AECallBack(DWORD dw1, DWORD dw2, LPVOID lpContext)
{
    //(::AfxGetMainWnd())->PostMessage(XX_MSG_FINISH_AE,dw1,dw2);
//    ((CWnd *)lpContext)->SendMessage(XX_MSG_FINISH_AE,dw1,dw2);
};

VOID CALLBACK AWBCallBack(DWORD dw1, DWORD dw2, LPVOID lpContext)
{
    //(::AfxGetMainWnd())->PostMessage(XX_MSG_FINISH_AWB,dw1,dw2);
//    ((CWnd *)lpContext)->SendMessage(XX_MSG_FINISH_AWB,dw1,dw2);
};

VOID CALLBACK AFCallBack(DWORD dw1, DWORD dw2, LPVOID lpContext)
{
    //(::AfxGetMainWnd())->PostMessage(XX_MSG_FINISH_AWB,dw1,dw2);
//	((CWnd *)lpContext)->SendMessage(XX_MSG_FINISH_AF,dw1,dw2);
};

int Camera::s_nCameraCount = 0;

Camera::Camera()
{
    Initialize();
}

Camera::Camera(HWND hWnd, int nIdx)
{
    Initialize(hWnd, nIdx);
}

Camera::~Camera()
{
    if(m_bPlay)
        Play( FALSE );
    if( m_pRawData )
    {
        delete [] m_pRawData;
        m_pRawData = NULL;
    }

    if( m_pRgbData )
    {
        delete m_pRgbData;
        m_pRgbData = NULL;
    }

    if( m_pSnapBuffer )
    {
        delete m_pSnapBuffer;
        m_pSnapBuffer = NULL;
    }

    if( m_hDevice != NULL )
        RZ_Uninitialize( m_hDevice );

    if(m_lpszResolution)
        delete []m_lpszResolution;
}

void Camera::Play(BOOL bPlay)
{
    if( m_hDevice == NULL )     return;
    m_bPlay = bPlay;

    RECT    rect;
    rect.left = 0;
    rect.top = 0;
//    ::GetClientRect(m_hWnd, &rect);
    rect.right = rect.left + this->m_CapInfo.Width;
    rect.bottom = rect.top + this->m_CapInfo.Height;


    if( m_bPlay )
    {
        RZ_SetFrameCallBack(m_hDevice,FrameCallback,LPVOID(this));
        RZ_StartView( m_hDevice, L"Digital Lab", WS_CHILD | WS_VISIBLE,
            0, 0, rect.right, rect.bottom, m_hWnd, NULL );
    }
    else
    {
        RZ_StopView( m_hDevice );
    }
}

BOOL Camera::StartView()
{
    if (m_hDevice == NULL)  return FALSE;
    if (m_bPlay)            return FALSE;
    Play(TRUE);
    VideoAutoSize();
    return TRUE;
}

BOOL Camera::StopView()
{
    if (m_hDevice == NULL)  return FALSE;
    if (!m_bPlay)           return FALSE;
    Play(FALSE);
    return TRUE;
}

QSizeF Camera::GetVideoSize()
{
    return QSizeF(m_CapInfo.Width, m_CapInfo.Height);
}

CapInfoStruct* Camera::GetCapInfo()
{
    return &m_CapInfo;
}

BOOL Camera::IsShowCorssLine()
{
    return m_bCrossline;
}

BOOL Camera::IsVideoStretch()
{
    return m_bstretch;
}

BOOL Camera::IsPlaying()
{
    return m_bPlay;
}

HANDLE Camera::GetDeviceHandle() const
{
    return m_hDevice;
}

QString Camera::GetFrameRate(float &fr)
{
    QString strRet = "";
    if (RZ_GetFrameRate(m_hDevice, &fr) == 0)
        strRet = QString("%.2f").arg(fr);
    return strRet;
}

void Camera::softTrigger()
{
    RZ_SoftTrigger(m_hDevice);
}

void Camera::SetHDR(BOOL bHDR)
{
    RZ_SetHDR(m_hDevice,bHDR);
}

void Camera::EnableLightAvg(BOOL bOn)
{
    RZ_EnableLightAvg(m_hDevice,bOn);
}

void Camera::ResetLightAvgTable()
{
    RZ_ResetLightAvgTable(m_hDevice);
}

void Camera::SetTriggerDelayTime(LONG Time)
{
    if (m_CamType == RZ36M)
    {
        RZ_SetTriggerCheckSignalTime(m_hDevice,(USHORT)Time);
    }
    else
        RZ_SetTriggerDelayTime(m_hDevice,Time);
}

void Camera::EEProm_Set(BYTE *pData)
{
    RZ_EEProm_Set(m_hDevice,pData);
}

void Camera::EEProm_Get(BYTE *pData)
{
    RZ_EEProm_Get(m_hDevice,pData);
}

void Camera::EEProm_SetByte(int nIndex, int nCount, BYTE *pData)
{
    RZ_EEProm_SetByte(m_hDevice,nIndex,nCount,pData);
}

void Camera::EEProm_GetByte(int nIndex, int nCount, BYTE *pData)
{
    RZ_EEProm_GetByte(m_hDevice,nIndex,nCount,pData);
}

void Camera::SetCustomIO(BYTE data)
{
    RZ_SetCustomIO(m_hDevice,data);
}

void Camera::SetTriggerSource(BYTE data)
{
    RZ_SetTriggerSource(m_hDevice,data);
}

void Camera::SetTriggerSourceTime(LONG Time)
{
    RZ_SetTriggerSourceTime(m_hDevice,Time);
}

void Camera::SetHBlank(int nHBlank)
{
    if ((m_CamType==MicroUH1200C) || (m_CamType==MicroUH600C))
    {
        RZ_SetAELight(m_hDevice,nHBlank);
    }
    else
    {
        RZ_SetHBlank(m_hDevice,nHBlank);
    }
}

void Camera::SetVBlank(int nVBlank)
{
    RZ_SetVBlank(m_hDevice,nVBlank);
}

void Camera::SetZoom(BOOL b)
{
    if(b)
    {
        m_CapInfo.Control |=0x01;
    }
    else
    {
        m_CapInfo.Control &=0xFE;
    }
    RZ_SetCapInfo( m_hDevice, &m_CapInfo );
}

void Camera::SetExpouseDelayTime(int nTime)
{
    RZ_SetExpouseDelayTime(m_hDevice,nTime);
}

void Camera::SetNewHWDN(HWND hwnd)
{
    m_hWnd = hwnd;
}

void Camera::SetFastCapMode(BOOL b)
{
    RZ_CapFastMode(m_hDevice,b);
    if(b)
    RZ_GetRgbFrame(m_hDevice,&m_CapInfo,m_pRgbData,FALSE);
}

int Camera::GetBuffer()
{
    int i =RZ_GetRgbFrame(m_hDevice,&m_CapInfo,m_pRgbData,FALSE);
    return i;
}

void Camera::DrawCrossLine(BYTE *pData)
{
    if(!m_bCrossline)
        return;

    int actual_w,actual_h;
    if (m_nFlipMode==FLIP_ROTATE90||m_nFlipMode==FLIP_ROTATE270)
    {
        actual_w=m_CapInfo.Height;
        actual_h=m_CapInfo.Width;
    }
    else
    {
        actual_w=m_CapInfo.Width;
        actual_h=m_CapInfo.Height;
    }

    int nBytesOfPixel;
    if(m_nColorMode==COLOR_RGB24 || m_nColorMode==COLOR_BW24 || m_nColorMode==COLOR_RGB24_CLEAR ||m_nColorMode ==COLOR_Microscope)
        nBytesOfPixel = 3;
    else
        nBytesOfPixel = 1;


    BYTE *pLine = pData + 	actual_w * nBytesOfPixel * (actual_h / 2);

    if(m_nColorMode==COLOR_RGB24 || m_nColorMode==COLOR_BW24 || m_nColorMode==COLOR_RGB24_CLEAR||m_nColorMode ==COLOR_Microscope)
    {
        for( int i=0; i<actual_w; i++ )
        {
            *( pLine + nBytesOfPixel * i ) = 0;
            *( pLine + nBytesOfPixel * i + 1 ) = 0;
            *( pLine + nBytesOfPixel * i + 2 ) = 255;
        }
        for( int j = 0; j<actual_h; j++)
        {
            BYTE *pLine = pData + actual_w * nBytesOfPixel * j;
            *( pLine + ( actual_w/2 ) * nBytesOfPixel ) = 0;
            *( pLine + ( actual_w/2 ) * nBytesOfPixel + 1 ) = 0;
            *( pLine + ( actual_w/2 ) * nBytesOfPixel + 2 ) = 255;
        }
    }
    else
    {
        for( int i=0; i<actual_w; i++ )
        {
            *( pLine + nBytesOfPixel * i + 0 ) = 255;
        }
        for( int j = 0; j<actual_h; j++)
        {
            BYTE *pLine = pData + actual_w * nBytesOfPixel * j;
            *( pLine + ( actual_w/2 ) * nBytesOfPixel + 0 ) = 255;
        }
    }
}

void Camera::EnableCrossline(BOOL bOn)
{
    m_bCrossline=bOn;
}

void Camera::SetScrollOffset(int H, int V)
{
    if (H != -1)
        m_Xoff = H;
    if (V != -1)
        m_Yoff = V;

    if (!m_bPlay) return;
    RZ_SetScrollOffset(m_hDevice, m_Xoff, m_Yoff);
}

void Camera::SetVideoSize(long width, long height)
{
    RZ_SetVideoSize(m_hDevice, width, height);
}

void Camera::SetParam(ENUM_Param type, long value, long value2)
{
    switch(type)
    {
    case idResolution:
        m_CapInfo.Width = value;
        m_CapInfo.Height= value2;
        break;
    case idContrast:
        m_nContrast = value;
        RZ_SetContrastValue(m_hDevice,value);
        return;
    case idExposure:
        m_CapInfo.Exposure=value;
        break;
    case idGain_All:

        if (m_CamType == RZ130SC_YUV)
        {
            m_nSharp = (int)value;
            RZ_SetSharpness(m_hDevice, (int)value);
            return;
        }
        else if (m_CamType==RZF1400CF)
        {
            m_CapInfo.Gain[0]=(BYTE)value&0x7F;
            m_CapInfo.Gain[1]=(BYTE)(value>>7);
        }
        else if ((m_CamType == MicroUH1200C) || (m_CamType == MicroUH600C))
        {
            m_nG = value;
            RZ_SetGainAll(m_hDevice,m_nG);
            return;
        }
        else
        {
            m_CapInfo.Gain[0]=(BYTE)value;

        }
        break;
    case idGain_R:
        if (m_CamType == RZ130SC_YUV)
        {
            m_CapInfo.Gain[0]=(BYTE)value;
            break;
        }
        else
        {
            RZ_SetGainR(m_hDevice, value);
            return;
        }
    case idGain_G:
        if (m_CamType == RZ130SC_YUV)
        {
            m_CapInfo.Gain[1]=(BYTE)value;
            break;
        }
        else
        {
            RZ_SetGainG(m_hDevice, value);
            return;
        }
    case idGain_B:
        if (m_CamType == RZ130SC_YUV)
        {
            m_CapInfo.Gain[2]=(BYTE)value;
            break;
        }
        else
        {
            RZ_SetGainB(m_hDevice, value);
            return;
        }
    case idOffsetX:
        m_CapInfo.OffsetX=value;
        break;
    case idOffsetY:
        m_CapInfo.OffsetY=value;
        break;
    case idControl:
        m_CapInfo.Control=(BYTE)value;
        break;
    case idFlipMode:
        m_nFlipMode = FLIP_MODE(value);
        RZ_SetParamFlip(m_hDevice, FLIP_MODE(value));
        VideoAutoSize();
        return;
    case idColorMode:
        m_nColorMode = COLOR_MODE(value);
        RZ_SetParamColor(m_hDevice, COLOR_MODE(value));
        return;
    case idSharp:
        m_nSharp = (int)value;
        RZ_SetSharpness(m_hDevice, (int)value);
        return;
    case idSta:
        m_nSta = (int)value;
        RZ_SetSaturation(m_hDevice,m_nSta);
        return;
    default:
        return;
    }
    RZ_SetCapInfo(m_hDevice,&m_CapInfo);
    RZ_GetCapInfo(m_hDevice,&m_CapInfo);
}

void Camera::PixelCalibration()
{
    RZ_PixelCalibration(m_hDevice);
}

void Camera::EnableCompressor(BOOL bOn)
{
    if(bOn)
    {
        RZ_SetAviCompressor(m_hDevice, m_dwCompressor);
    }
    else
    {
        RZ_SetAviCompressor(m_hDevice, 0);
    }
    m_bCompressor = bOn;
}

void Camera::SelectComprossor()
{
    DWORD dwCode = 0;
    if(RZ_SelectAviCompressor(m_hDevice, &dwCode)==0)
    {
        m_dwCompressor = dwCode;
    }

    EnableCompressor(m_bCompressor);
}

void Camera::SetDoAE(BOOL bAE, LPVOID lpContext)
{
    RZ_SetDoAE( m_hDevice, bAE, 0,
             AECallBack, lpContext );
}

void Camera::SetDoAWB(BOOL bAWB, LPVOID lpContext)
{
    RZ_SetDoAWB( m_hDevice, bAWB, 0,
             AWBCallBack, lpContext );
}

void Camera::SetAEParam(BOOL bAE,LPVOID lpContext)
{
    if ((m_CamType==MicroUH1200C) || (m_CamType==MicroUH600C))
    {
        RZ_SetDoAE( m_hDevice, bAE, 0,
            AECallBack, this );
    }
    else
    {
        RZ_AEParam(m_hDevice,bAE,RZ_AE_LEVEL_NORMAL,AECallBack,lpContext);
    }

//	RZ_AEParam(m_hDevice,bAE,RZ_AE_LEVEL_NORMAL,AECallBack,lpContext);
}

void Camera::SetTriggerMode(BOOL bOn)
{
    RZ_SetTriggerMode(m_hDevice, bOn);
    m_bTriggerMode = bOn;
}

void Camera::SetTriggerStatus(BOOL bOn, LPCTSTR lpPath)
{
    if(RZ_GetTrigger( m_hDevice, bOn, BMP, lpPath, 100)==0)
        m_bTrigger = bOn;
}

BOOL Camera::Capture2AVI(BOOL bStart, LPCTSTR lpszPath)
{
    RZ_CaptureToAvi(m_hDevice, bStart, lpszPath);
    return TRUE;
}

void Camera::Snap(ENUM_IMAGE_TYPE type, LPCTSTR lpszPath)
{
    QString strPath = QString::fromUtf16(reinterpret_cast<const unsigned short *>(lpszPath));
    switch(type)
    {
    case IMG_TYPE_BMP:
        strPath += ".bmp";
        RZ_GetRgbFrameToBmp(m_hDevice, &m_CapInfo, m_pRgbData, reinterpret_cast<const wchar_t *>(strPath.utf16()), TRUE);
        break;
    case IMG_TYPE_JPG:
        strPath += ".jpg";
        RZ_GetRgbFrameToJpeg(m_hDevice, &m_CapInfo, NULL, reinterpret_cast<const wchar_t *>(strPath.utf16()), 100);
        break;
    default:
        break;
    };
}

void Camera::VideoAutoSize(BOOL bChange)
{
    RECT rect = {0, 0, 611, 467};
//    GetClientRect(m_hWnd,&rect);
    if(bChange)	//切换拉伸模式
        m_bstretch = !m_bstretch;

    if(m_bstretch)
    {
        int w,h;
        w = rect.right - rect.left;
        h = rect.bottom - rect.top;

        int nW,nH,nX,nY;
        nW = m_CapInfo.Width;nH = m_CapInfo.Height;
        if (m_nFlipMode == FLIP_ROTATE90 ||m_nFlipMode==FLIP_ROTATE270)
        {
            nW = m_CapInfo.Height;
            nH = m_CapInfo.Width;
        }
        float ff = min(float(w)/nW,float(h)/nH);
        if (ff < 1.0f)
        {
            nW = nW * ff;
            nH = nH * ff;
        }
        nW = nW + nW%4;	nH = nH + nH%4;

        nX = w-nW > 0 ? (w-nW)/2 : 0;
        nY = h-nH > 0 ? (h-nH)/2 : 0;

        RZ_SetScrollOffset(m_hDevice, -nX, -nY);
        RZ_SetVideoSize(m_hDevice,nW,nH);
    }
    else
    {
        long lw=(long)m_CapInfo.Width; long lh=(long)m_CapInfo.Height;
        rect.left = (rect.right-rect.left-lw > 0) ?
            (int)((rect.right-rect.left-lw)/2) : rect.left ;
        rect.top = (rect.bottom-rect.top-lh > 0) ?
            (int)((rect.bottom-rect.top-lh)/2) : rect.top ;

        RZ_SetScrollOffset(m_hDevice, -rect.left, -rect.top);
        m_Xoff = -rect.left;
        m_Yoff = -rect.top;
        RZ_SetVideoSize(m_hDevice,lw,lh);

    }
}

void Camera::Initialize(HWND hWnd, int nIdx)
{
    m_nSta = 34;
    m_bCrossline = FALSE;
    m_bstretch = TRUE;
    m_bCompressor = FALSE;
    m_dwCompressor = 0;
    m_nResCount =0;
    m_bTrigger = m_bTriggerMode = FALSE;

    m_hWnd = hWnd;

    m_bPlay=FALSE;

    m_pRawData = NULL;
    m_pRgbData = NULL;
//	m_pRawData = ( BYTE* ) new BYTE [ 2048 * 1536 + 2048 ];
//	m_pRgbData = ( BYTE* ) new BYTE [ 2048 * 1536 * 3 +512];

    m_pSnapBuffer = NULL;
//	m_pSnapBuffer = ( BYTE* ) new BYTE [ 800 * 600 * 3 * 30 +2048];
    m_buffercache = m_pSnapBuffer;

    m_nColorMode = COLOR_RGB24;
    memset(&m_CapInfo, 0, sizeof( CapInfoStruct));
    m_CapInfo.Buffer = m_pRawData;
    m_CapInfo.Width		= 752;
    m_CapInfo.Height	= 480;
    m_CapInfo.Exposure = 100;
//	memset( m_CapInfo.Gain, 30, 3 );
    m_CapInfo.Gain[0] = 16;
    m_CapInfo.Gain[1] = 32;
    m_CapInfo.Gain[2] = 32;

    m_nR = m_nG = m_nB = 500;
    m_nContrast = 16;
    m_nFlipMode = FLIP_NATURAL;
    m_lpszResolution = NULL;
    m_CamColorType = RZ_COLOR;
    m_nHBlank = m_nVBlank = 0;
    memset(m_strFriendlyName, 0 , sizeof(TCHAR)*255);
    m_nSharp = 0;

    m_nDevIndex = -1;
    int    nIndex = nIdx;
//	CRZSDK_DemoApp* pApp = (CRZSDK_DemoApp *)::AfxGetApp();
    DWORD x = RZ_Initialize(L"RZ_DEMO", &nIndex, &m_CapInfo, &m_hDevice );
    if( ResSuccess != x)
    {
        RZ_Uninitialize( m_hDevice );
        m_hDevice = NULL;
//        ::MessageBox( NULL, L"Initial Error"), L"Demo"), 0 );
        return;
    }
    m_nDevIndex = nIndex;
    RZ_GetDeviceType(m_hDevice,&m_CamType);
    if (m_CamType!=RZ130SC_YUV)
    {
        RZ_SetExpouseUnit(m_hDevice,1);
        m_CapInfo.Exposure = 10000;
    }
    if (m_CamType==RZCCD140C)
    {
        m_CapInfo.OffsetX = 100;
    }
    if ((m_CamType == MicroUH1200C) || (m_CamType == MicroUH600C))
    {
        if(m_CamType == MicroUH1200C)
        {
            m_CapInfo.Width = 4000;
            m_CapInfo.Height = 3000;
        }
        else
        {
            m_CapInfo.Width = 3072;
            m_CapInfo.Height = 2048;
        }
        RZ_SetCapInfo( m_hDevice, &m_CapInfo );
        m_nColorMode = COLOR_RGB24_CLEAR;
        RZ_SetParamColor(m_hDevice, COLOR_RGB24_CLEAR );
        m_nContrast = 37;
        RZ_SetContrastValue(m_hDevice,m_nContrast);
        RZ_SetSaturation(m_hDevice,m_nSta);
        m_nR = 260;
        m_nB = 264;
        m_nG = 1;
        RZ_SetGainR(m_hDevice, m_nR);
        //RZ_SetGainG(m_hDevice, m_nG);
        RZ_SetGainB(m_hDevice, m_nB);
        RZ_SetGainAll(m_hDevice,m_nG);
        RZ_SetAELight(m_hDevice,90);
    }
    else
    {
        RZ_SetCapInfo( m_hDevice, &m_CapInfo );
        RZ_SetParamColor(m_hDevice, COLOR_RGB24 );

        RZ_SetContrastValue(m_hDevice,m_nContrast);

        RZ_SetGainR(m_hDevice, m_nR);
        RZ_SetGainG(m_hDevice, m_nG);
        RZ_SetGainB(m_hDevice, m_nB);

    }
    RZ_SetParamFlip(m_hDevice, FLIP_NATURAL );
    RZ_GetDeviceColorType(m_hDevice,&m_CamColorType);

    m_Xoff = m_Yoff = 0;

    RZ_GetTotalDeviceNum(m_hDevice, &s_nCameraCount);
    RZ_GetFriendlyName(m_hDevice, m_strFriendlyName);
    RZ_SetGamma(m_hDevice,16);
    RZ_SetColorAdjust(m_hDevice,COLOR_ADJUST_NO);

    //=================================================================
    //根据型号设置支持的分辨率
    switch(m_CamType)
    {
    case RZ500P:
        {
            m_nResCount = sizeof(lpszResolution500P_New)/sizeof(lpszResolution500P_New[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution500P_New,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 0;
        }
        break;
    case SuperUH500:
        {
            m_nResCount = sizeof(lpszResolution500Super)/sizeof(lpszResolution500Super[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution500Super,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 8;
        }
        break;
    case SuperUH200:
        {
            m_nResCount = sizeof(lpszResolution200Super)/sizeof(lpszResolution200Super[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution200Super,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 8;
        }
        break;
    case SuperUH130:
        {
            m_nResCount = sizeof(lpszResolutionDft)/sizeof(lpszResolutionDft[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolutionDft,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 8;
        }
        break;
    case SuperUH50:
        {
            m_nResCount = sizeof(lpszResolution50)/sizeof(lpszResolution50[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution50,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 8;
        }
        break;
    case SuperUH30:
        {
            m_nResCount = sizeof(lpszResolution30)/sizeof(lpszResolution30[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution30,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 8;
        }
        break;
    case RZ900CF:
        {
            m_nResCount = sizeof(lpszResolution900)/sizeof(lpszResolution900[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution900,sizeof(TagResolution)*m_nResCount);
            Sleep(50);
        }
        break;
    case RZ200CF:
        {
            m_nResCount = sizeof(lpszResolution200)/sizeof(lpszResolution200[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution200,sizeof(TagResolution)*m_nResCount);
        }
        break;
    case RZ500CF:
        {
            m_nResCount = sizeof(lpszResolution500)/sizeof(lpszResolution500[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution500,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 0;
        }
        break;
    case RZ300:
    case RZ300CF:
    case RZ300_LED:
        {
            m_nResCount = sizeof(lpszResolution300)/sizeof(lpszResolution300[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution300,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 142;
        }
        break;
    case RZ300C_FPGA:
        {
            m_nResCount = sizeof(lpszResolution300)/sizeof(lpszResolution300[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution300,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 142;
        }
        break;
    case RZ36M:
        {
            m_nResCount = sizeof(lpszResolution36M)/sizeof(lpszResolution36M[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution36M,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 45;
            m_nHBlank = 94;
        }
        break;
    case RZ130CF:
        {
            m_nResCount = sizeof(lpszResolutionDft)/sizeof(lpszResolutionDft[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolutionDft,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 25;
        }
        break;
    case RZ120C_FPGA:
        {
            m_nResCount = sizeof(lpszResolution120)/sizeof(lpszResolution120[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution120,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 0;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 60;
        }
        break;
    case RZCCD140C:
        {
            m_nResCount = sizeof(lpszResolution140)/sizeof(lpszResolution140[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution140,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 0;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 32;
        }
        break;
    case RZF1400CF:
        {
            m_nResCount = sizeof(lpszResolution1400)/sizeof(lpszResolution1400[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution1400,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 0;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 13;
            m_CapInfo.Gain[1] = 0;
        }
        break;
    case RZF1000CF:
        {
            m_nResCount = sizeof(lpszResolution1000)/sizeof(lpszResolution1000[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution1000,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 0;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 96;
            m_CapInfo.Gain[1] = 0;
        }
        break;
    case RZ130C_FPGA:
    case RZ130M_FPGA:
        {
            m_nResCount = sizeof(lpszResolutionDft)/sizeof(lpszResolutionDft[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolutionDft,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 25;
            m_nHBlank = 9;
        }
        break;
    case MicroUH1200C:
        {
            m_nResCount = sizeof(lpszResolution1200)/sizeof(lpszResolution1200[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution1200,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 0;
            m_nHBlank = 0;
            m_CapInfo.Gain[0] = 0;
            m_CapInfo.Gain[1] = 0;
        }
        break;
    case MicroUH600C:
        {
            m_nResCount = sizeof(lpszResolution600)/sizeof(lpszResolution600[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolution600,sizeof(TagResolution)*m_nResCount);
            m_nVBlank = 0;
            m_nVBlank = 0;
            m_CapInfo.Gain[0] = 0;
            m_CapInfo.Gain[1] = 0;
        }
        break;
    case RZ130:
    case RZ130SC_YUV:
    default:
        {
            m_nResCount = sizeof(lpszResolutionDft)/sizeof(lpszResolutionDft[0]);
            m_lpszResolution = new TagResolution[m_nResCount];
            memcpy(m_lpszResolution,lpszResolutionDft,sizeof(TagResolution)*m_nResCount);
        }
        break;
    }
    m_CapInfo.Width = m_lpszResolution[0].width;
    m_CapInfo.Height= m_lpszResolution[0].height;

    m_pRawData = ( BYTE* ) new BYTE [ m_lpszResolution[0].width * m_lpszResolution[0].height + m_lpszResolution[0].width ];
    m_pRgbData = ( BYTE* ) new BYTE [ m_lpszResolution[0].width * m_lpszResolution[0].height * 3 +m_lpszResolution[0].width];
    m_CapInfo.Buffer = m_pRawData;
    RZ_SetHBlank( m_hDevice,m_nHBlank);
    RZ_SetVBlank(m_hDevice,m_nVBlank);
    RZ_SetCapInfo(m_hDevice,&m_CapInfo);
    RZ_GetCapInfo(m_hDevice,&m_CapInfo);
    if (((int)m_CapInfo.Width!=m_lpszResolution[0].width) && m_CamType==RZ500P)
    {
        if(m_lpszResolution)
            delete []m_lpszResolution;
        m_lpszResolution = NULL;
        m_nResCount = sizeof(lpszResolution500P)/sizeof(lpszResolution500P[0]);
        m_lpszResolution = new TagResolution[m_nResCount];
        memcpy(m_lpszResolution,lpszResolution500P,sizeof(TagResolution)*m_nResCount);
    }
    if (m_CamType == RZ130SC_YUV)
    {
        RZ_SetSharpness(m_hDevice,m_nSharp);
    }
}

void Camera::SavePic(ENUM_IMAGE_TYPE type, LPCTSTR lpszPath)
{
    QString strPath = QString::fromUtf16(reinterpret_cast<const unsigned short *>(lpszPath));
    int color = m_nColorMode>2 ? 8:24;
    switch(type)
    {
    case IMG_TYPE_BMP:
        strPath += ".bmp";
        break;
    case IMG_TYPE_JPG:
        strPath += ".jpg";
        break;
    default:
        break;
    };
    RZ_FrameToImage(reinterpret_cast<const wchar_t *>(strPath.utf16()), m_pRgbData, m_CapInfo.Width,m_CapInfo.Height,color,(RZIMAGETYPR)type);
}

QString Camera::GetCameraVersion()
{
    BYTE pData[16];
    QString str;
    memset(&pData,0,sizeof(BYTE)*16);
    RZ_GetDeviceVertion(m_hDevice,pData);
    QByteArray temp((const char *)(pData), 16);
    str = temp.toHex();
    return str;
}

QString Camera::GetSerialNumber()
{
    BYTE pData[17];
    memset(&pData,0,sizeof(BYTE)*17);
    RZ_GetSerialNumber(m_hDevice,pData);
    QByteArray temp((const char *)(pData), 17);
    QString str;
    str = temp.toHex();
    return str;
}

void Camera::SetAfParam(AutoFocusParam_St *pstAfParam, LPVOID lpContext)
{
    QString strname;

    if (pstAfParam->byAfState == 1)
    {
        QString m_strPath = GetAppPath();
//        qDebug()<<m_strPath;
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString florname;
        florname= current_date_time.toString("yyyyMMddhhmmsszzz");
//        qDebug()<<florname;
        m_strPath.append("\\");
        m_strPath.append(florname);
//        qDebug()<<m_strPath;

        BOOL b = FolderExist(m_strPath.toStdString().c_str());
        if(!b)
        {
            CreateFolder(m_strPath.toStdString().c_str());
        }
        strname.append(m_strPath);
        strname.append("\\Shot_");
//        strname.sprintf("%s\\Shot_", m_strPath);

//        qDebug()<<strname;
    }
    RZ_SetAFCallBack(m_hDevice,AFCallBack,lpContext);
    RZ_SetAF_Param(m_hDevice, pstAfParam, strname.toStdString().c_str(),0,JPEG,TRUE);
}

BOOL Camera::FolderExist(QString strPath)
{
    WIN32_FIND_DATA wfd;
    BOOL bValue=FALSE;
    HANDLE hFind=::FindFirstFile(strPath.toStdWString().c_str(),&wfd);
    if( (hFind!=INVALID_HANDLE_VALUE) && (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )//文件找到
    {
        bValue = TRUE;
    }
    ::FindClose(hFind);
    return bValue;
}

BOOL Camera::CreateFolder(QString strPath)
{
    SECURITY_ATTRIBUTES attrib;
    attrib.bInheritHandle = FALSE;
    attrib.lpSecurityDescriptor = NULL;
    attrib.nLength = sizeof(SECURITY_ATTRIBUTES);
    return ::CreateDirectory(strPath.toStdWString().c_str(), &attrib);
    //  return ::CreateDirectory(strPath,NULL);
}

/*
QString Camera::GetAppPath()
{
    QString strAppPath; // 保存结果

    TCHAR szModuleFileName[MAX_PATH]; // 全路径名

    TCHAR drive[_MAX_DRIVE]; // 盘符名称，比如说C盘啊，D盘啊

    TCHAR dir[_MAX_DIR]; // 目录

    TCHAR fname[_MAX_FNAME]; // 进程名字

    TCHAR ext[_MAX_EXT]; //后缀，一般为exe或者是dll

    if (NULL == GetModuleFileName(NULL, szModuleFileName, MAX_PATH)) //获得当前进程的文件路径
        return L"";

    _tsplitpath( szModuleFileName, drive, dir, fname, ext ); //分割该路径，得到盘符，目录，文件名，后缀名

    strAppPath = drive;

    strAppPath += dir;


    return strAppPath;
}
*/

QString Camera::GetAppPath()
{
    QString strAppPath;

    strAppPath = QCoreApplication::applicationDirPath();
    return strAppPath;
}

void Camera::SetAfRange(AutoFocusRange_St *pstAfRange)
{
    RZ_SetAF_Range(m_hDevice, pstAfRange);
}
