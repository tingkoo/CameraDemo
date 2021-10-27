#ifndef FORMPOWERFREQ_H
#define FORMPOWERFREQ_H

#include <QWidget>

namespace Ui {
class FormPowerFreq;
}

class FormPowerFreq : public QWidget
{
    Q_OBJECT
public:
    explicit FormPowerFreq(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormPowerFreq *ui;
};

#endif // FORMPOWERFREQ_H
