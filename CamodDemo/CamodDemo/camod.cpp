#include "camod.h"
#include "qspecialbtn.h"
#include <unistd.h>

Camod::Camod(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Camod)
{
    ui->setupUi(this);
    ui->treeWidget->clear();
    ui->dockWidget->setWidget(ui->treeWidget);

    AddWidgetToGroup(tr("Camera List"),                   fCameraList     = new FormCameraList(ui->treeWidget), true);
    AddWidgetToGroup(tr("Capture Resolution"),            fCapResolution  = new FormCapResolution(ui->treeWidget));
    AddWidgetToGroup(tr("Exposure"),                      fExposure       = new FormExposure(ui->treeWidget));
    AddWidgetToGroup(tr("White Balance"),                 fWhiteBalance   = new FormWhiteBalance(ui->treeWidget));
    AddWidgetToGroup(tr("Color Adjustment"),              fColorAdjust    = new FormColorAdjust(ui->treeWidget));
    AddWidgetToGroup(tr("Bit Depth"),                     fBitDepth       = new FormBitDepth(ui->treeWidget));
    AddWidgetToGroup(tr("Power Frequency (Anti-flicker)"), fPowerFreq     = new FormPowerFreq(ui->treeWidget));
    AddWidgetToGroup(tr("Color/Gray"),                    fColorGray      = new FormColorGray(ui->treeWidget));
    AddWidgetToGroup(tr("Frame Rate"),                    fFrameRate      = new FormFrameRate(ui->treeWidget));
    AddWidgetToGroup(tr("Sampling"),                      fSampling       = new FormSampling(ui->treeWidget));
    AddWidgetToGroup(tr("ROI"),                           fRoi            = new FormRoi(ui->treeWidget));
    AddWidgetToGroup(tr("Histogram"),                     fHistogram      = new FormHistogram(ui->treeWidget));
    AddWidgetToGroup(tr("Dark Field Correction"),         fDarkField      = new FormDarkField(ui->treeWidget));
    AddWidgetToGroup(tr("Cooling"),                       fCooling        = new FormCooling(ui->treeWidget));
    AddWidgetToGroup(tr("Misc"),                          fMisc           = new FormMisc(ui->treeWidget));
    AddWidgetToGroup(tr("Parameters"),                    fParameters     = new FormParameters(ui->treeWidget));
    sleep(2);
}

Camod::~Camod()
{
    delete ui;
}

void Camod::AddWidgetToGroup(QString title, QWidget *subWidget, bool expanded)
{
    QTreeWidgetItem *group = new QTreeWidgetItem();
    ui->treeWidget->addTopLevelItem(group);
    ui->treeWidget->setItemWidget(group, 0, new QSpecialBtn(title, ui->treeWidget, group));
    QTreeWidgetItem *child = new QTreeWidgetItem();
    child->setDisabled(true);
    group->addChild(child);
    ui->treeWidget->setItemWidget(child, 0, subWidget);

    group->setExpanded(expanded);
}
