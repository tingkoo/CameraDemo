#ifndef QSPECIALBTN_H
#define QSPECIALBTN_H

#include <QPushButton>
#include <QTreeWidgetItem>

class QSpecialBtn : public QPushButton
{
    Q_OBJECT
public:
    QSpecialBtn(const QString &pText, QWidget* pParent, QTreeWidgetItem *pItem);

private slots:
    void BtnPressed();
private:
    QTreeWidgetItem *qItem;
};

#endif // QSPECIALBTN_H
