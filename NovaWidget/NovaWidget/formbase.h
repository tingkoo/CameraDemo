#ifndef FORMBASE_H
#define FORMBASE_H

#include <QWidget>

class FormBase : public QWidget
{
    Q_OBJECT
public:
    explicit FormBase(QWidget *parent = nullptr);
    int indexId;

signals:

public slots:
};

#endif // FORMBASE_H
