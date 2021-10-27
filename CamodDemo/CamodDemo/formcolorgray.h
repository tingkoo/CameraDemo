#ifndef FORMCOLORGRAY_H
#define FORMCOLORGRAY_H

#include <QWidget>

namespace Ui {
class FormColorGray;
}

class FormColorGray : public QWidget
{
    Q_OBJECT
public:
    explicit FormColorGray(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormColorGray *ui;
};

#endif // FORMCOLORGRAY_H
