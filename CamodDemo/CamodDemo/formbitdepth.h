#ifndef FORMBITDEPTH_H
#define FORMBITDEPTH_H

#include <QWidget>

namespace Ui {
class FormBitDepth;
}

class FormBitDepth : public QWidget
{
    Q_OBJECT
public:
    explicit FormBitDepth(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::FormBitDepth *ui;
};

#endif // FORMBITDEPTH_H
