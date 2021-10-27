#ifndef FORMFRAMERATE_H
#define FORMFRAMERATE_H

#include <QWidget>

namespace Ui {
class FormFrameRate;
}

class FormFrameRate : public QWidget
{
    Q_OBJECT
public:
    explicit FormFrameRate(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormFrameRate *ui;
};

#endif // FORMFRAMERATE_H
