#ifndef FORMSAMPLING_H
#define FORMSAMPLING_H

#include <QWidget>

namespace Ui {
class FormSampling;
}

class FormSampling : public QWidget
{
    Q_OBJECT
public:
    explicit FormSampling(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormSampling *ui;
};

#endif // FORMSAMPLING_H
