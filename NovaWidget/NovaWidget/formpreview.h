#ifndef FORMPREVIEW_H
#define FORMPREVIEW_H

#include "formbase.h"

namespace Ui {
class FormPreview;
}

class FormPreview : public FormBase
{
    Q_OBJECT
public:
    explicit FormPreview(QWidget *parent = nullptr);

signals:

public slots:
private:
    Ui::FormPreview *ui;
};

#endif // FORMPREVIEW_H
