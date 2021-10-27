#include "rz_camera.h"

static TagResolution lpszResolution900[] =
{
    {_T("3488 * 2560"),3488,2560},
    {_T("1744 * 1280"),1744,1280},
    {_T("872 * 640"),872,640},
};

static TagResolution lpszResolution500P_New[] =
{
    {_T("2592 * 1944"),2592,1944},
    {_T("2560 * 1944"),2560,1944},
    {_T("2048 * 1536"),2048,1536},
    {_T("1280 * 972"),1280,972},
    {_T("640 * 480"),640,480},
};

static TagResolution lpszResolution500P[] =
{
    {_T("2560 * 1944"),2560,1944},
    {_T("1280 * 972"),1280,972},
    {_T("640 * 486"),640,486},
};
static TagResolution lpszResolution500[] =
{
    {_T("2592 * 1944"),2592,1944},
    {_T("2560 * 800"),2560,800},
    {_T("2048 * 1536"),2048,1536},
    {_T("1600 * 1200"),1600,1200},
    {_T("1280 * 1024"),1280,1024},
    {_T("1280 * 400"),1280,400},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolution500Super[] =
{
    {_T("2592 * 2048"),2592,2048},
    {_T("2592 * 1944"),2560,1944},
    {_T("2048 * 1536"),2048,1536},
    {_T("1600 * 1200"),1600,1200},
    {_T("1280 * 1024"),1280,1024},
    {_T("1280 * 400"),1280,400},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};

static TagResolution lpszResolution300[] =
{
    {_T("2048 * 1536"),2048,1536},
    {_T("1600 * 1200"),1600,1200},
    {_T("1280 * 1024"),1280,1024},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};

static TagResolution lpszResolution200[] =
{
    {_T("1600 * 1200"),1600,1200},
    {_T("1280 * 1024"),1280,1024},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolution200Super[] =
{
    {_T("1920 * 1200"),1920,1200},
    {_T("1600 * 1200"),1600,1200},
    {_T("1280 * 1024"),1280,1024},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolutionDft[] =
{
    {_T("1280 * 1024"),1280,1024},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolution50[] =
{

    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolution30[] =
{
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolution120[] =
{
    {_T("1280 * 960"),1280,960},
    {_T("1280 * 720"),1280,720},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolution1400[] =
{
    {_T("4608 * 3288"),4608,3288},
    {_T("3488 * 2560"),3488,2560},
    {_T("2592 * 1944"),2592,1944},
    {_T("2048 * 1536"),2048,1536},
    {_T("1600 * 1200"),1600,1200},
    {_T("1280 * 1024"),1280,1024},
    {_T("1024 * 768"),1024,768},
    //	{_T("800 * 600"),800,600},
    // 	{_T("640 * 480"),640,480},
};
static TagResolution lpszResolution1000[] =
{
    {_T("3840 * 2748"),3840,2748},
    {_T("3488 * 2560"),3488,2560},
    {_T("2592 * 1944"),2592,1944},
    {_T("2048 * 1536"),2048,1536},
    {_T("1600 * 1200"),1600,1200},
    {_T("1280 * 1024"),1280,1024},
    {_T("1024 * 768"),1024,768},
    {_T("800 * 600"),800,600},
    {_T("640 * 480"),640,480},
};
static TagResolution lpszResolution1200[] =
{
    {_T("4000 * 3000"),4000,3000},
    {_T("2000 * 1500"),2000,1500},
};
static TagResolution lpszResolution600[] =
{
    {_T("3072 * 2048"),3072,2048},
};
static TagResolution lpszResolution36M[] =
{
    {_T("752 * 480"),752,480},
};
static TagResolution lpszResolution140[] =
{
    {_T("1360 * 1024"),1360,1024}
};


//===========================================================================
/////////////////////////////////////////////////////////////////////////////
// CRZ_Camera  实现
int	CRZ_Camera::s_nCameraCount = 0;

//IMPLEMENT_DYNCREATE(CRZ_Camera, CObject)

/*
CRZ_Camera::CRZ_Camera(HWND hWnd, int nIdx)
{
    CAM_Initialize(hWnd, nIdx);
}
*/

CRZ_Camera::CRZ_Camera()
{
    CAM_Initialize();
}

CRZ_Camera::~CRZ_Camera()
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

void CRZ_Camera::Play(BOOL bPlay)
{
    if( m_hDevice == NULL )     return;
    m_bPlay = bPlay;

    RECT    rect;
    ::GetClientRect(m_hWnd, &rect);
    rect.right = rect.left + this->m_CapInfo.Width;
    rect.bottom = rect.top + this->m_CapInfo.Height;

    if( m_bPlay )
    {
        RZ_SetFrameCallBack(m_hDevice,FrameCallback,LPVOID(this));
        RZ_StartView( m_hDevice, _T("Digital Lab"), WS_CHILD | WS_VISIBLE,
            0, 0, rect.right, rect.bottom, m_hWnd, NULL );
    }
    else
    {
        RZ_StopView( m_hDevice );
    }
}

BOOL CRZ_Camera::StartView()
{
    if( m_hDevice == NULL )    return false;
    if(m_bPlay)                return false;
    Play( true );
    VideoAutoSize();
    return TRUE;
}

BOOL CRZ_Camera::StopView()
{
    if( m_hDevice == NULL )    return false;
    if(!m_bPlay)               return false;
    // TODO: Add your control notification handler code here
    Play( false );
    return true;
}

void CRZ_Camera::CAM_Initialize(HWND hWnd, int nIdx)
{
    m_bCrossline = false;
    m_bstretch = true;
    m_bCompressor = false;
    m_dwCompressor = 0;
    m_nResCount =0;
    m_bTrigger = m_bTriggerMode = false;;

    m_hWnd = hWnd;

    m_bPlay=false;

    m_pRawData = NULL;
    m_pRgbData = NULL;
//	m_pRawData = ( BYTE* ) new BYTE [ 2048 * 1536 + 2048 ];
//	m_pRgbData = ( BYTE* ) new BYTE [ 2048 * 1536 * 3 +512];

    m_pSnapBuffer = NULL;
//	m_pSnapBuffer = ( BYTE* ) new BYTE [ 800 * 600 * 3 * 30 +2048];
    m_buffercache = m_pSnapBuffer;

    m_nColorMode = COLOR_RGB24;
    memset( &m_CapInfo, 0, sizeof( CapInfoStruct ) );
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
    ///////////////////////////////////////////////////////////////

    m_nDevIndex = -1;
    int    nIndex = nIdx;	//第1个设备
//	CRZSDK_DemoApp* pApp = (CRZSDK_DemoApp *)::AfxGetApp();
    DWORD x = RZ_Initialize(_T("RZ_DEMO"), &nIndex, &m_CapInfo, &m_hDevice );
    if( ResSuccess != x)//RZ_Initialize(_T("RZ_DEMO"), &nIndex, &m_CapInfo, &m_hDevice ) )
    {
        RZ_Uninitialize( m_hDevice );
        m_hDevice = NULL;
        ::MessageBox( NULL, _T("Initial Error"), _T("Demo"), 0 );
        return;
    }
    m_nDevIndex = nIndex;
    RZ_GetDeviceType(m_hDevice,&m_CamType);
    if (m_CamType!=RZ130SC_YUV)
    {
        RZ_SetExpouseUnit(m_hDevice,1);
        m_CapInfo.Exposure = 10000;
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

        m_nR = 260;
        m_nB = 264;
        m_nG = 1;
        RZ_SetGainR(m_hDevice, m_nR);
        //RZ_SetGainG(m_hDevice, m_nG);
        RZ_SetGainB(m_hDevice, m_nB);
    }


    RZ_SetCapInfo( m_hDevice, &m_CapInfo );
    RZ_SetParamColor(m_hDevice, COLOR_RGB24 );
    RZ_SetParamFlip(m_hDevice, FLIP_NATURAL );
    RZ_SetContrastValue(m_hDevice,m_nContrast);

    RZ_SetGainR(m_hDevice, m_nR);
    RZ_SetGainG(m_hDevice, m_nG);
    RZ_SetGainB(m_hDevice, m_nB);
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
