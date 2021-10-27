#ifndef FORMDARKFIELD_H
#define FORMDARKFIELD_H

#include <QWidget>

namespace Ui {
class FormDarkField;
}

class FormDarkField : public QWidget
{
    Q_OBJECT
public:
    explicit FormDarkField(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormDarkField *ui;
};

#endif // FORMDARKFIELD_H
