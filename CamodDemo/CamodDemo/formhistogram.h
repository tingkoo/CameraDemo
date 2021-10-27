#ifndef FORMHISTOGRAM_H
#define FORMHISTOGRAM_H

#include <QWidget>

namespace Ui {
class FormHistogram;
}

class FormHistogram : public QWidget
{
    Q_OBJECT
public:
    explicit FormHistogram(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormHistogram *ui;
};

#endif // FORMHISTOGRAM_H
