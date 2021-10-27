#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
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
    m_strData_Get = "";
    m_strData_Set = "";
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
    m_strSerialNumber = "";
    m_nW = 0;
    m_nH = 0;
    m_bFastMode = FALSE;
    m_bCLOSE = FALSE;
    m_bPlay = FALSE;
    m_nAfStartLoc = 40;
    m_nAfStepLen = 4;
    m_nAfEndLoc = 400;
    m_nAfCurrentLoc = 0;
    m_nAfDirection = 0;
    m_nAfRangeHS = 1408;
    m_nAfRangeHL = 256;
    m_nAfRangeVL = 256;
    m_nAfRangeVS = 896;

    initButtons();

    foreach (QToolButton *b, buttons)
    {
        connect(b, SIGNAL(clicked(bool)), this, SLOT(pageChange()));
    }
    HWND hWnd = (HWND)ui->label->winId();
    m_pCamera = new Camera(hWnd, 1);

    int n = 0;
    for(n = 0; n < m_pCamera->m_nResCount; n++)
    {
        ui->resolutionBox->addItem(QString::fromUtf16(reinterpret_cast<const unsigned short *>(m_pCamera->m_lpszResolution[n].lpszDesc)));
    }
    ui->resolutionBox->setCurrentIndex(0);

//    ui->DNLabel->setText(QString::fromWCharArray(m_pCamera->m_strFriendlyName));
//    if (m_pCamera)
//        ui->snLabel->setText(m_pCamera->GetSerialNumber());

    ui->flipModeBox->addItem("NATURAL");
    ui->flipModeBox->addItem("H-Flip");
    ui->flipModeBox->addItem("V-Flip");
    ui->flipModeBox->addItem("ROTATE90");
    ui->flipModeBox->addItem("ROTATE180");
    ui->flipModeBox->addItem("ROTATE270");

//    ui->spinBox->setRange(0, m_pCamera->m_lpszResolution[0].width - m_pCamera->m_lpszResolution[0].width);
    ui->spinBox->setValue(max(m_nOx, 0));
//    ui->spinBox_2->setRange(0, m_pCamera->m_lpszResolution[0].height - m_pCamera->m_lpszResolution[0].height);
    ui->spinBox_2->setValue(max(m_nOy, 0));
    ui->spinBox_3->setValue(max(m_nR, 0));
    ui->spinBox_4->setValue(max(m_nG, 0));
    ui->spinBox_5->setValue(max(m_nB, 0));
    ui->spinBox_6->setValue(max(m_nCT, 0));
    if ((RZ_COLOR_TYPE)RZ_GRAY == m_pCamera->m_CamColorType)
    {
        ui->spinBox_3->setEnabled(FALSE);
        ui->spinBox_4->setEnabled(FALSE);
        ui->spinBox_5->setEnabled(FALSE);
    }

    ui->spinBox_11->setRange(1, 500000);
    ui->spinBox_11->setValue(max(m_nEx, 0));

    ui->ThresholdBox->clear();
    ui->ThresholdBox->addItem("Regular");
    ui->ThresholdBox->addItem("Inverted");
    ui->ThresholdBox->addItem("Bilateral");

    ui->RoiBox->clear();
    ui->RoiBox->addItem("None");
    ui->RoiBox->addItem("Draw Mask");
    ui->RoiBox->addItem("From File");
    ui->RoiBox->addItem("Auto");

    ui->spinBox_15->setRange(0, 999);
    ui->spinBox_16->setRange(0, 999);
    ui->spinBox_17->setRange(0, 999);
    ui->spinBox_15->setValue(m_nAfStartLoc);
    ui->spinBox_16->setValue(m_nAfEndLoc);
    ui->spinBox_17->setValue(m_nAfStepLen);
    ui->spinBox_18->setValue(m_nAfStepLen);
    ui->radioForward->setChecked(true);
    ui->currentLabel->setText("0");

    UpdateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_pCamera)
        delete m_pCamera;
}

void MainWindow::on_startReviewBtn_clicked()
{
    if (m_bPlay && m_pCamera)
    {
        m_pCamera->StopView();
        killTimer(timerId);
    }
    m_bPlay = TRUE;

    if (m_pCamera)
    {
        m_pCamera->StartView();
        timerId = startTimer(1000);
    }
}

void MainWindow::on_closeReviewBtn_clicked()
{
    if (m_pCamera)
    {
        m_pCamera->StopView();
        ui->label->clear();
        killTimer(timerId);
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (m_pCamera)
    {
        float fr = 0.0f;
        RZ_GetFrameRate(m_pCamera->m_hDevice, &fr);
        QString str = QString::number(fr, 'f', 3);
        ui->FRLabel->setText(str);
    }
}

void MainWindow::initButtons()
{
    buttons.append(ui->reviewBtn);
    buttons.append(ui->snapBtn);
    buttons.append(ui->toolButton_3);
    buttons.append(ui->toolButton_4);

    foreach (QToolButton *b, buttons) {
        connect(b, SIGNAL(clicked()), this, SLOT(changeButtonStatus()));
    }

    ui->reviewBtn->click();
}

void MainWindow::changeButtonStatus() {
    foreach (QToolButton *b, buttons) {
        b->setProperty("current", "false");
        b->setStyleSheet("");
    }
    QToolButton *source = qobject_cast<QToolButton *>(sender());
    source->setProperty("current", "true");
    source->setStyleSheet("");
}

void MainWindow::pageChange()
{
    QToolButton *s = qobject_cast<QToolButton *>(sender());
    ui->stackedWidget->setCurrentIndex(buttons.indexOf(s));
}

void MainWindow::on_startRecordBtn_clicked()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString str = "Video_";
    str += current_date_time.toString("yyyyMMddhhmmsszzz");
    str += ".avi";

    if (m_pCamera)
        m_pCamera->Capture2AVI(TRUE, (LPCTSTR)str.toStdString().c_str());
}

void MainWindow::on_stopRecordBtn_clicked()
{
    if (m_pCamera)
        m_pCamera->Capture2AVI(FALSE, L"");
}

void MainWindow::on_bmpBtn_clicked()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString str = "Shot_";
    str += current_date_time.toString("yyyyMMddhhmmsszzz");
    str += ".bmp";
//    qDebug("%s", qPrintable(str));
    if (m_pCamera)
        m_pCamera->Snap(IMG_TYPE_BMP, (LPCTSTR)str.toStdString().c_str());
}

void MainWindow::on_jpgBtn_clicked()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString str = "Shot_";
    str += current_date_time.toString("yyyyMMddhhmmsszzz");
    str += ".jpg";

    if (m_pCamera)
        m_pCamera->Snap(IMG_TYPE_JPG, (LPCTSTR)str.toStdString().c_str());
}

void MainWindow::on_ljpgBtn_clicked()
{
    if(!m_pCamera)
        return;

    CapInfoStruct* pCapInfo = m_pCamera->GetCapInfo();

    int w(pCapInfo->Width);
    int h(pCapInfo->Height);

    int ox(pCapInfo->OffsetX);
    int oy(pCapInfo->OffsetY);
    if (m_pCamera->GetCamType()!=RZCCD140C)
    {
        m_pCamera->SetParam(idOffsetX, 0);
    }

    m_pCamera->SetParam(idOffsetY, 0);

    if(w!=m_pCamera->m_lpszResolution[0].width || h!=m_pCamera->m_lpszResolution[0].height)
    {
        m_pCamera->SetParam(idResolution,
            m_pCamera->m_lpszResolution[0].width,
            m_pCamera->m_lpszResolution[0].height);
    }

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString str = "Large_";
    str += current_date_time.toString("yyyyMMddhhmmsszzz");
    str += ".jpg";

    if (m_pCamera)
        m_pCamera->Snap(IMG_TYPE_JPG, (LPCTSTR)str.toStdString().c_str());

    if(w!=m_pCamera->m_lpszResolution[0].width || h!=m_pCamera->m_lpszResolution[0].height)
        m_pCamera->SetParam(idResolution, w, h);

    if (m_pCamera->GetCamType()!=RZCCD140C)
    {
        m_pCamera->SetParam(idOffsetX, ox);
    }

    m_pCamera->SetParam(idOffsetY, oy);
}


void MainWindow::on_hdrBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        m_pCamera->SetHDR(m_bHDR);
    else
        m_pCamera->SetHDR(!m_bHDR);
}


void MainWindow::on_flipModeBox_currentIndexChanged(int index)
{
    if (!m_pCamera)
        return;
    ui->label->clear();
    m_pCamera->SetParam(idFlipMode, long(index), 0);
}


void MainWindow::UpdateUI()
{
    if(!m_pCamera)
        return;

    m_nCT = m_pCamera->m_nContrast;
    m_nEx = m_pCamera->GetCapInfo()->Exposure;
    m_nGainAll = m_pCamera->GetCapInfo()->Gain[0];
    m_nB = m_pCamera->m_nB;
    m_nG = m_pCamera->m_nG;
    m_nR = m_pCamera->m_nR;
    m_nOx = 0;
    m_nOy = 0;


    m_nHBlank = m_pCamera->m_nHBlank;
    m_nVBlank = m_pCamera->m_nVBlank;

    if (m_pCamera->m_CamColorType == RZ_GRAY)
    {
        ui->colorModeBox->clear();
        ui->colorModeBox->addItem("BW24");
        ui->colorModeBox->addItem("GRAY");
        ui->colorModeBox->addItem("RAWDATA");
        ui->colorModeBox->setCurrentIndex(0);
    }
    else
    {
        ui->hdrBox->setEnabled(TRUE);
    }
    switch(m_pCamera->GetCamType())
    {
    case MicroUH600C:
        {
            m_bAELiving = TRUE;
            m_bHDR = TRUE;
            m_nGainAll = m_pCamera->m_nG;
            m_nB = m_pCamera->m_nB;
            m_nR = m_pCamera->m_nR;
            int nColorMode = m_pCamera->m_nColorMode;
            if (nColorMode==1)
            {
                nColorMode=0;
            }
            else
                nColorMode=1;

            ui->colorModeBox->clear();
            ui->colorModeBox->addItem("YUV");
            ui->colorModeBox->addItem("RAWDATA");

            ui->settingBtn->setEnabled(FALSE);
            ui->spinBox->setEnabled(FALSE);
            ui->spinBox_2->setEnabled(FALSE);
            ui->spinBox_4->setEnabled(FALSE);
            ui->spinBox_10->setEnabled(FALSE);

            ui->spinBox_3->setRange(1, 511);
            ui->spinBox_3->setValue(max(m_nR, 0));
            ui->spinBox_4->setRange(1, 511);
            ui->spinBox_4->setValue(128);
            ui->spinBox_5->setRange(1, 511);
            ui->spinBox_5->setValue(max(m_nB, 0));

            ui->spinBox_6->setRange(1, 63);
            ui->spinBox_6->setValue(max(m_nCT, 0));

            ui->spinBox_7->setRange(1, 1957);
            ui->spinBox_7->setValue(max(m_nGainAll, 1));

            ui->spinBox_8->setRange(1, 16);
            ui->spinBox_8->setValue(8);

            ui->spinBox_9->setEnabled(TRUE);
            ui->spinBox_9->setRange(40, 220);
            ui->spinBox_9->setValue(max(m_nHBlank, 90));

            ui->spinBox_11->setValue(10008);

            connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(spinbox3_setting()));
            connect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(spinbox4_setting()));
            connect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(spinbox5_setting()));
            connect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(spinbox6_setting()));
            connect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(spinbox7_setting()));
            connect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(spinbox8_setting()));
            connect(ui->spinBox_9, SIGNAL(valueChanged(int)), this, SLOT(spinbox9_setting()));
            connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(spinbox11_setting()));
            connect(ui->spinBox_15, SIGNAL(valueChanged(int)), this, SLOT(spinbox15_setting()));
            connect(ui->spinBox_16, SIGNAL(valueChanged(int)), this, SLOT(spinbox16_setting()));
            connect(ui->AFBox, SIGNAL(stateChanged(int)), this, SLOT(AFBoxStateChanged(int)));
        }
        break;

    }
}


void MainWindow::on_colorModeBox_currentIndexChanged(int index)
{
    int n = ui->colorModeBox->currentIndex();

    if(!m_pCamera)
        return;
    if ((m_pCamera->m_CamType == MicroUH1200C) || (m_pCamera->m_CamType == MicroUH600C))
    {
        if (n==0)
        {
            n=1;
        }
        else
            n=4;
    }
    else if (m_pCamera->m_CamColorType==RZ_GRAY)
        n+=2;
    m_pCamera->SetParam(idColorMode, long(n), 0);
}

void MainWindow::spinbox3_setting()
{
    m_pCamera->SetParam(idGain_R, ui->spinBox_3->value());
}

void MainWindow::spinbox4_setting()
{
    m_pCamera->SetParam(idGain_G, ui->spinBox_4->value());
}

void MainWindow::spinbox5_setting()
{
    m_pCamera->SetParam(idGain_B, ui->spinBox_5->value());
}

void MainWindow::spinbox6_setting()
{
    m_pCamera->SetParam(idContrast, ui->spinBox_6->value());
}

void MainWindow::spinbox7_setting()
{
    m_pCamera->SetParam(idGain_All, ui->spinBox_7->value());
}

void MainWindow::spinbox8_setting()
{
    m_pCamera->SetParam(idSta, ui->spinBox_8->value());
}

void MainWindow::spinbox9_setting()
{
    m_pCamera->SetHBlank(ui->spinBox_9->value());
}

void MainWindow::on_spinBox_11_valueChanged(int arg1)
{
    m_pCamera->SetParam(idExposure, arg1);
}

void MainWindow::spinbox15_setting()
{
    AutoFocusParam_St  stAfParam;
    m_nAfStartLoc = ui->spinBox_15->value();
    m_nAfEndLoc = ui->spinBox_15->value();
    stAfParam.byAfState = 4;
    stAfParam.byAfDirection = (UCHAR)m_nAfDirection;
    stAfParam.usAfScanStartLoc = m_nAfStartLoc;
    stAfParam.usAfScanEndLoc   = m_nAfEndLoc;
    stAfParam.byAfScanStep  = (UCHAR)m_nAfStepLen;
    m_pCamera->SetAfParam(&stAfParam,(LPVOID)this);
//    ui->currentLabel->setText(QString::number(m_nAfEndLoc));
}

void MainWindow::spinbox16_setting()
{
    AutoFocusParam_St  stAfParam;
    m_nAfEndLoc = ui->spinBox_16->value();
    stAfParam.byAfState = 4;
    stAfParam.byAfDirection = (UCHAR)m_nAfDirection;
    stAfParam.usAfScanStartLoc = m_nAfStartLoc;
    stAfParam.usAfScanEndLoc   = m_nAfEndLoc;
    stAfParam.byAfScanStep  = (UCHAR)m_nAfStepLen;
    m_pCamera->SetAfParam(&stAfParam,(LPVOID)this);
//    ui->currentLabel->setText(QString::number(m_nAfEndLoc));
}


void MainWindow::on_aelivingBox_stateChanged(int arg1)
{
    if (!m_pCamera)
        return;
    if (arg1 == Qt::Checked)
    {
        m_pCamera->SetAEParam(m_bAELiving, (LPVOID)this);
        ui->spinBox_11->setEnabled(false);
//        ui->spinBox_11->setValue(m_pCamera->GetCapInfo()->Exposure);
    }
    else
    {
        m_pCamera->SetAEParam(!m_bAELiving, (LPVOID)this);
        ui->spinBox_11->setEnabled(true);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    AutoFocusParam_St  stAfParam;
    stAfParam.byAfState = 1;
    stAfParam.byAfDirection = (UCHAR)m_nAfDirection;
    stAfParam.usAfScanStartLoc = m_nAfStartLoc;
    stAfParam.usAfScanEndLoc   = m_nAfEndLoc;
    stAfParam.byAfScanStep     = (UCHAR)m_nAfStepLen;
    m_pCamera->SetAfParam(&stAfParam,(LPVOID)this);
//    ui->currentLabel->setText(QString::number(m_nAfEndLoc));
}

void MainWindow::on_pushButton_7_clicked()
{
    AutoFocusParam_St  stAfParam;
    stAfParam.byAfState = 2;
    stAfParam.byAfDirection = (UCHAR)m_nAfDirection;
    stAfParam.usAfScanStartLoc = m_nAfStartLoc;
    stAfParam.usAfScanEndLoc   = m_nAfEndLoc;
    stAfParam.byAfScanStep     = (UCHAR)m_nAfStepLen;
    m_pCamera->SetAfParam(&stAfParam,(LPVOID)this);
}


void MainWindow::on_radioForward_clicked()
{
    m_nAfDirection = 0;
}

void MainWindow::on_radioBackward_clicked()
{
    m_nAfDirection = 1;
}


void MainWindow::on_spinBox_17_valueChanged(int arg1)
{
    m_nAfStepLen = arg1;
    ui->spinBox_18->setValue(arg1);
}

void MainWindow::on_spinBox_18_valueChanged(int arg1)
{
    m_nAfStepLen = arg1;
    ui->spinBox_17->setValue(arg1);
}

void MainWindow::on_spinBox_19_valueChanged(int arg1)
{
    AutoFocusParam_St  stAfParam;
    m_nAfEndLoc = ui->spinBox_19->value();
    stAfParam.byAfState = 4;
    stAfParam.byAfDirection = (UCHAR)m_nAfDirection;
    stAfParam.usAfScanStartLoc = m_nAfStartLoc;
    stAfParam.usAfScanEndLoc   = m_nAfEndLoc;
    stAfParam.byAfScanStep  = (UCHAR)m_nAfStepLen;
    m_pCamera->SetAfParam(&stAfParam,(LPVOID)this);
}

void MainWindow::AFBoxStateChanged(int state)
{
    AutoFocusParam_St  stAfParam;
    if (state == Qt::Checked)
    {
        stAfParam.byAfState = 8;
        ui->scanBox->setEnabled(false);
        ui->stepBox->setEnabled(false);
        ui->moveBox->setEnabled(false);
    }
    else if (state == Qt::Unchecked)
    {
        stAfParam.byAfState = 0;
        ui->scanBox->setEnabled(true);
        ui->stepBox->setEnabled(true);
        ui->moveBox->setEnabled(true);
    }
    stAfParam.byAfDirection = (UCHAR)m_nAfDirection;
    stAfParam.usAfScanStartLoc = m_nAfStartLoc;
    stAfParam.usAfScanEndLoc   = m_nAfEndLoc;
    stAfParam.byAfScanStep  = (UCHAR)m_nAfStepLen;
    m_pCamera->SetAfParam(&stAfParam,(LPVOID)this);
}

void MainWindow::on_pushButton_5_clicked()
{
    AutoFocusParam_St  stAfParam;
    m_nAfEndLoc = ui->spinBox_16->value();
    stAfParam.byAfState = 16;
    stAfParam.byAfDirection = (UCHAR)m_nAfDirection;
    stAfParam.usAfScanStartLoc = m_nAfStartLoc;
    stAfParam.usAfScanEndLoc   = m_nAfEndLoc;
    stAfParam.byAfScanStep  = (UCHAR)m_nAfStepLen;
    m_pCamera->SetAfParam(&stAfParam,(LPVOID)this);
}

void MainWindow::on_awbBox_clicked()
{
    if (m_pCamera && Qt::Checked)
        m_pCamera->SetDoAWB(TRUE, (LPVOID)this);
    else if (m_pCamera && Qt::Unchecked)
        m_pCamera->SetDoAWB(FALSE, (LPVOID)this);
}
