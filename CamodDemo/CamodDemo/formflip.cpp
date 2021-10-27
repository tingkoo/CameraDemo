#include "formflip.h"
#include "ui_formflip.h"

FormFlip::FormFlip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFlip)
{
    ui->setupUi(this);
}
