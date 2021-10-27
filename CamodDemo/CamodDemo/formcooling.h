#ifndef FORMCOOLING_H
#define FORMCOOLING_H

#include <QWidget>

namespace Ui {
class FormCooling;
}

class FormCooling : public QWidget
{
    Q_OBJECT
public:
    explicit FormCooling(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormCooling *ui;
};

#endif // FORMCOOLING_H
