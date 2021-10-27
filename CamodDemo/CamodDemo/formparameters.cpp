#include "formparameters.h"
#include "ui_formparameters.h"

FormParameters::FormParameters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormParameters)
{
    ui->setupUi(this);
}
