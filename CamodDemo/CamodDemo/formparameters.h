#ifndef FORMPARAMETERS_H
#define FORMPARAMETERS_H

#include <QWidget>

namespace Ui {
class FormParameters;
}

class FormParameters : public QWidget
{
    Q_OBJECT
public:
    explicit FormParameters(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormParameters *ui;
};

#endif // FORMPARAMETERS_H
