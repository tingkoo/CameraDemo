#ifndef FORMFLUSYN_H
#define FORMFLUSYN_H

#include "formbase.h"

namespace Ui {
class FormFluSyn;
}

class FormFluSyn : public FormBase
{
    Q_OBJECT
public:
    explicit FormFluSyn(QWidget *parent = nullptr);

signals:

public slots:
private:
    Ui::FormFluSyn *ui;
};

#endif // FORMFLUSYN_H
