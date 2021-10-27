#include "qspecialbtn.h"
#include <QPixmap>

QSpecialBtn::QSpecialBtn(const QString &pText, QWidget* pParent, QTreeWidgetItem *pItem)
    : QPushButton(pText, pParent), qItem(pItem)
{
//    QPixmap iconBtn(tr(":/imgs/recs/imgBtn.png"));
//    setIcon(iconBtn);
//    setFixedSize(iconBtn.size());
    setStyleSheet("Text-align:left;background:#9370DB;color:white");
    connect(this, SIGNAL(pressed()), this, SLOT(BtnPressed()));
}

void QSpecialBtn::BtnPressed()
{
    qItem->setExpanded(!qItem->isExpanded());
}
