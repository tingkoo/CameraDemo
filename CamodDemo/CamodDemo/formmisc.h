#ifndef FORMMISC_H
#define FORMMISC_H

#include <QWidget>

namespace Ui {
class FormMisc;
}

class FormMisc : public QWidget
{
    Q_OBJECT
public:
    explicit FormMisc(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormMisc *ui;
};

#endif // FORMMISC_H
