#ifndef FORMCAPRESOLUTION_H
#define FORMCAPRESOLUTION_H

#include <QWidget>

namespace Ui {
class FormCapResolution;
}

class FormCapResolution : public QWidget
{
    Q_OBJECT
public:
    explicit FormCapResolution(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormCapResolution *ui;
};

#endif // FORMCAPRESOLUTION_H
