#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QDateTime>
#include <Windows.h>
#include "Camera.h"
#include "Camera/Include/RZAPI.H"

#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void FinishAWB(DWORD dw1, DWORD dw2);
    void FinishAE(DWORD dw1, DWORD dw2);
    void UpdateUI();
protected:
    Camera *m_pCamera;
    void timerEvent(QTimerEvent *event);
    int timerId;

private slots:
    void changeButtonStatus();
    void pageChange();
    void on_startReviewBtn_clicked();
    void on_closeReviewBtn_clicked();
    void on_startRecordBtn_clicked();
    void on_stopRecordBtn_clicked();
    void on_bmpBtn_clicked();
    void on_jpgBtn_clicked();
    void on_ljpgBtn_clicked();
    void on_hdrBox_stateChanged(int arg1);
    void on_aelivingBox_stateChanged(int arg1);
    void on_flipModeBox_currentIndexChanged(int index);
    void on_colorModeBox_currentIndexChanged(int index);

    void spinbox3_setting();
    void spinbox4_setting();
    void spinbox5_setting();
    void spinbox6_setting();
    void spinbox7_setting();
    void spinbox8_setting();
    void spinbox9_setting();
    void spinbox15_setting();
    void spinbox16_setting();



    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();


    void on_radioForward_clicked();

    void on_radioBackward_clicked();

    void on_spinBox_18_valueChanged(int arg1);

    void on_spinBox_19_valueChanged(int arg1);

    void AFBoxStateChanged(int state);

    void on_pushButton_5_clicked();

    void on_spinBox_17_valueChanged(int arg1);

    void on_spinBox_11_valueChanged(int arg1);

    void on_awbBox_clicked();

private:
    Ui::MainWindow *ui;
    QList<QToolButton *> buttons;
    void initButtons();

public:
    BOOL m_bCLOSE;
    BOOL m_bPlay;
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
    QString	m_strData_Get;
    QString	m_strData_Set;
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
    QString	m_strSerialNumber;
    int		m_nW;
    int		m_nH;
    BOOL	m_bFastMode;
    int     m_nAfDirection;
    int     m_nAfStartLoc;
    int     m_nAfEndLoc;
    int     m_nAfCurrentLoc;
    int     m_nAfStepLen;
    int		m_nAfRangeHS;
    int		m_nAfRangeHL;
    int		m_nAfRangeVL;
    int		m_nAfRangeVS;
    bool    ok;
};

#endif // MAINWINDOW_H
