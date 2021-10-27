#include "formprop.h"
#include "ui_formprop.h"

FormProp::FormProp(QWidget *parent):
    FormBase(parent),
    ui(new Ui::FormProp)
{
    ui->setupUi(this);
}
