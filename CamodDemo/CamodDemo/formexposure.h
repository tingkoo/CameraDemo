#ifndef FORMEXPOSURE_H
#define FORMEXPOSURE_H

#include <QWidget>

namespace Ui {
class FormExposure;
}

class FormExposure : public QWidget
{
    Q_OBJECT
public:
    explicit FormExposure(QWidget *parent = nullptr);

signals:

public slots:
private:
    Ui::FormExposure *ui;
};

#endif // FORMEXPOSURE_H
