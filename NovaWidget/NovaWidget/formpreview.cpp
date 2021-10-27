#include "formpreview.h"
#include "ui_formpreview.h"

FormPreview::FormPreview(QWidget *parent) :
    FormBase(parent),
    ui(new Ui::FormPreview)
{
    ui->setupUi(this);
}
