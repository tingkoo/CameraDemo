#ifndef FORMPROP_H
#define FORMPROP_H

#include "formbase.h"

namespace Ui {
class FormProp;
}

class FormProp : public FormBase
{
    Q_OBJECT
public:
    explicit FormProp(QWidget *parent = nullptr);
private:
    Ui::FormProp *ui;
};

#endif // FORMPROP_H
