#ifndef FORMFLIP_H
#define FORMFLIP_H

#include <QWidget>

namespace Ui {
class FormFlip;
}

class FormFlip : public QWidget
{
    Q_OBJECT
public:
    explicit FormFlip(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormFlip *ui;
};

#endif // FORMFLIP_H
