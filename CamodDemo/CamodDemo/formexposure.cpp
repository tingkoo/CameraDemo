#include "formexposure.h"
#include "ui_formexposure.h"

FormExposure::FormExposure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormExposure)
{
    ui->setupUi(this);
}
