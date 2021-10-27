#include "formhistogram.h"
#include "ui_formhistogram.h"

FormHistogram::FormHistogram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHistogram)
{
    ui->setupUi(this);
}
