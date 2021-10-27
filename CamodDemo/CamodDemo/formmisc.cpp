#include "formmisc.h"
#include "ui_formmisc.h"

FormMisc::FormMisc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMisc)
{
    ui->setupUi(this);
}
