#include "formcameralist.h"
#include "ui_formcameralist.h"

FormCameraList::FormCameraList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCameraList)
{
    ui->setupUi(this);
}
