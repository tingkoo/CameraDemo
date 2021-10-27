#ifndef FORMCAMERALIST_H
#define FORMCAMERALIST_H

#include <QWidget>

namespace Ui {
class FormCameraList;
}

class FormCameraList : public QWidget
{
    Q_OBJECT
public:
    explicit FormCameraList(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormCameraList *ui;
};

#endif // FORMCAMERALIST_H
