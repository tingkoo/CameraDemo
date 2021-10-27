#ifndef FORMWHITEBALANCE_H
#define FORMWHITEBALANCE_H

#include <QWidget>

namespace Ui {
class FormWhiteBalance;
}

class FormWhiteBalance : public QWidget
{
    Q_OBJECT
public:
    explicit FormWhiteBalance(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormWhiteBalance *ui;
};

#endif // FORMWHITEBALANCE_H
