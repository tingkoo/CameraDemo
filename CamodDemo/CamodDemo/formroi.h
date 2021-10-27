#ifndef FORMROI_H
#define FORMROI_H

#include <QWidget>

namespace Ui {
class FormRoi;
}

class FormRoi : public QWidget
{
    Q_OBJECT
public:
    explicit FormRoi(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormRoi *ui;
};

#endif // FORMROI_H
