#include "camdemo.h"
#include "ui_camdemo.h"

CamDemo::CamDemo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamDemo)
{
    ui->setupUi(this);

    m_nControl = 0;
        m_nIO = 0;
        m_bWCF = FALSE;
        m_bTriggerMode = FALSE;
        m_nCT = 0;
        m_nEx = 0;
        m_nGainAll = 0;
        m_nB = 0;
        m_nG = 0;
        m_nR = 0;
        m_nOx = 0;
        m_nOy = 0;
        m_bCross = FALSE;
        m_bCompressor = FALSE;
        m_bHDR = FALSE;
        m_bLightAvg = FALSE;
        m_nTime = 0;
        m_bAllWR = FALSE;
        m_nCount_Get = 0;
        m_nCount_Set = 0;
        m_strData_Get = _T("");
        m_strData_Set = _T("");
        m_nIndex_Get = 0;
        m_nIndex_Set = 0;
        m_nCustomIO = 0;
        m_nTrigger_Source = 0;
        m_lTrigger_Source_Time = 0;
        m_bAELiving = FALSE;
        m_nHBlank = 0;
        m_nVBlank = 0;
        m_bZoom = FALSE;
        m_nExTime = 0;
        m_strSerialNumber = _T("");
        m_nW = 0;
        m_nH = 0;
        //}}AFX_DATA_INIT
        // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
        m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
        m_pCamera = NULL;
        m_bCLOSE = FALSE;
        m_CapThread = CDemoDlg::Thread_Capture;
        m_bPlay = FALSE;
}

CamDemo::~CamDemo()
{
    delete ui;
}

void CamDemo::on_videoStartBtn_clicked()
{
    if (m_bPlay)
        {
            OnVideoStop();
        }
        m_bPlay = TRUE;
        if(m_pCamera)
        {
            HWND hwnd = GetDlgItem(IDC_VIDEO)->m_hWnd;
            m_pCamera->SetNewHWDN(hwnd);
            m_pCamera->StartView();

            SetTimer(1,100,NULL);
        }
}

void CamDemo::on_videoStopBtn_clicked()
{
    if(m_pCamera)
        {
            m_pCamera->StopView();
            this->Invalidate();
            KillTimer(1);
        }
}

void CamDemo::on_recordStartBtn_clicked()
{
    SYSTEMTIME time;
    GetLocalTime( &time );
    unsigned short m_nYear		=   time.wYear;
    unsigned short m_nMonth		=   time.wMonth;
    unsigned short m_nDay		=   time.wDay;
    unsigned short m_nHour		=   time.wHour;
    unsigned short m_nMinute	=   time.wMinute;
    unsigned short m_nSecond	=   time.wSecond;
    unsigned short miSec		=	time.wMilliseconds;

    CString strname;
    strname.Format(_T("Video_%4d%02d%02d%02d%02d%02d%04d.avi"),m_nYear,m_nMonth,m_nDay,m_nHour,m_nMinute,m_nSecond,miSec);

    if(m_pCamera)
        m_pCamera->Capture2AVI(TRUE,LPCTSTR(strname));
}

void CamDemo::on_recordStopBtn_clicked()
{
    if(m_pCamera)
            m_pCamera->Capture2AVI(FALSE,_T(""));
}
