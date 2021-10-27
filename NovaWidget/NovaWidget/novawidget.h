#ifndef NOVAWIDGET_H
#define NOVAWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QListWidget>
#include <QStackedWidget>
#include "formpreview.h"
#include "formflusyn.h"
#include "formprop.h"

namespace Ui {
class NovaWidget;
}

class NovaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NovaWidget(QWidget *parent = 0);
    ~NovaWidget();
    QHBoxLayout *mainLayout;
    QListWidget *list;
//    QTabWidget *tab;
    QStackedWidget *stack;
    FormPreview *formPreview;
    FormFluSyn *formFluSyn;
    FormProp *formProp;
    QListWidgetItem *previewListBtn;
    QListWidgetItem *flusynListBtn;
    QListWidgetItem *d25ListBtn;
    QListWidgetItem *propListBtn;

private:
    Ui::NovaWidget *ui;
    QPushButton *previewBtn;
    QPushButton *flusynBtn;
    QPushButton *d25Btn;
    QPushButton *propBtn;
public slots:
    void on_previewBtn_clicked();
    void on_flusynBtn_clicked();
    void on_propBtn_clicked();
};

#endif // NOVAWIDGET_H
