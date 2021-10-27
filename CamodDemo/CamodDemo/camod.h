#ifndef CAMOD_H
#define CAMOD_H

#include <QMainWindow>
#include <ui_camod.h>
#include <formbitdepth.h>
#include <formcameralist.h>
#include <formcapresolution.h>
#include <formcoloradjust.h>
#include <formcolorgray.h>
#include <formcooling.h>
#include <formdarkfield.h>
#include <formexposure.h>
#include <formflip.h>
#include <formframerate.h>
#include <formhistogram.h>
#include <formmisc.h>
#include <formparameters.h>
#include <formpowerfreq.h>
#include <formroi.h>
#include <formsampling.h>
#include <formwhitebalance.h>

class FormBitDepth;
class FormCameraList;
class FormCapResolution;
class FormColorAdjust;
class FormColorGray;
class FormCooling;
class FormDarkField;
class FormExposure;
class FormFlip;
class FormFrameRate;
class FormHistogram;
class FormMisc;
class FormParameters;
class FormPowerFreq;
class FormRoi;
class FormSampling;
class FormWhiteBalance;

class Camod : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camod(QWidget *parent = 0);
    ~Camod();

protected:
    void AddWidgetToGroup(QString title, QWidget *subWidget, bool expanded = false);

private:
    Ui::Camod *ui;
    FormBitDepth *fBitDepth;
    FormCameraList *fCameraList;
    FormCapResolution *fCapResolution;
    FormColorAdjust *fColorAdjust;
    FormColorGray *fColorGray;
    FormCooling *fCooling;
    FormDarkField *fDarkField;
    FormExposure *fExposure;
    FormFlip *fFlip;
    FormFrameRate *fFrameRate;
    FormHistogram *fHistogram;
    FormMisc *fMisc;
    FormParameters *fParameters;
    FormPowerFreq *fPowerFreq;
    FormRoi *fRoi;
    FormSampling *fSampling;
    FormWhiteBalance *fWhiteBalance;
};

#endif // CAMOD_H
