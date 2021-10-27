#ifndef FORMCOLORADJUST_H
#define FORMCOLORADJUST_H

#include <QWidget>

namespace Ui {
class FormColorAdjust;
}

class FormColorAdjust : public QWidget
{
    Q_OBJECT
public:
    explicit FormColorAdjust(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormColorAdjust *ui;
};

#endif // FORMCOLORADJUST_H
