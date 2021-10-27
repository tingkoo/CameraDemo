#ifndef CAMDEMO_H
#define CAMDEMO_H

typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned long DWORD;

#include <QDialog>

namespace Ui {
class CamDemo;
}

class CamDemo : public QDialog
{
    Q_OBJECT

public:
    explicit CamDemo(QWidget *parent = 0);
    ~CamDemo();
    void FinishAWB(DWORD dw1, DWORD dw2);
    void FinishAE(DWORD dw1, DWORD dw2);
    void UpdateUI();
//        CDemoDlg(CWnd* pParent = NULL);	// standard constructor
    BOOL m_bCLOSE;
    BOOL m_bPlay;
//        LPTHREAD_START_ROUTINE m_CapThread;
//        static DWORD WINAPI Thread_Capture(LPVOID lpParameter );
    enum { IDD = IDD_DEMO_DIALOG };
    BYTE	m_nControl;
    BYTE	m_nIO;
    BOOL	m_bWCF;
    BOOL	m_bTriggerMode;
    int		m_nCT;
    int		m_nEx;
    int		m_nGainAll;
    int		m_nB;
    int		m_nG;
    int		m_nR;
    int		m_nOx;
    int		m_nOy;
    BOOL	m_bCross;
    BOOL	m_bCompressor;
    BOOL	m_bHDR;
    BOOL	m_bLightAvg;
    long	m_nTime;
    BOOL	m_bAllWR;
    int		m_nCount_Get;
    int		m_nCount_Set;
//    CString	m_strData_Get;
//    CString	m_strData_Set;
    int		m_nIndex_Get;
    int		m_nIndex_Set;
    BYTE	m_nCustomIO;
    BYTE	m_nTrigger_Source;
    long	m_lTrigger_Source_Time;
    BOOL	m_bAELiving;
    int		m_nHBlank;
    int		m_nVBlank;
    BOOL	m_bZoom;
    int		m_nExTime;
//    CString	m_strSerialNumber;
    int		m_nW;
    int		m_nH;

private slots:
    void on_videoStartBtn_clicked();

    void on_videoStopBtn_clicked();

    void on_recordStartBtn_clicked();

    void on_recordStopBtn_clicked();

private:
    Ui::CamDemo *ui;
};

#endif // CAMDEMO_H
