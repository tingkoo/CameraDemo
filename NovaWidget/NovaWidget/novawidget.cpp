#include "novawidget.h"
#include "ui_novawidget.h"
#include <QPixmap>

NovaWidget::NovaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NovaWidget)
{
    ui->setupUi(this);

    //mainLayout
//    QPixmap previewIcon(tr(":/icons/res/previewIcon.png"));
//    QSize s = previewBtn->size();
//    QPixmap flusynIcon(tr(":/icons/res/flusynIcon.png"));
//    QPixmap d25Icon(tr(":/icons/res/d25Icon.png"));
//    QPixmap propIcon(tr(":/icons/res/propIcon.png"));
    list = new QListWidget(this);
//    tab = new QTabWidget(this);
    stack = new QStackedWidget(this);
    mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(5);
    mainLayout->setMargin(5);
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack, 0, Qt::AlignHCenter);

    previewListBtn = new QListWidgetItem();
    flusynListBtn = new QListWidgetItem();
    propListBtn = new QListWidgetItem();
//    d25ListBtn = new QListWidgetItem();

    formPreview = new FormPreview();
    formFluSyn = new FormFluSyn();
    formProp = new FormProp();

    previewBtn  = new QPushButton();
    flusynBtn   = new QPushButton();
    propBtn     = new QPushButton();
//    tab->insertTab(0, previewBtn, tr("预览"));
//    tab->insertTab(1, flusynBtn, tr("荧光合成"));
//    tab->insertTab(2, propBtn, tr("属性"));
    list->insertItem(0, previewListBtn);
    list->insertItem(1, flusynListBtn);
    list->insertItem(2, propListBtn);
    list->insertItem(2, d25ListBtn);
    list->setItemWidget(previewListBtn,     previewBtn  = new QPushButton());
    list->setItemWidget(flusynListBtn,      flusynBtn   = new QPushButton());
    list->setItemWidget(propListBtn,        propBtn     = new QPushButton());
    list->setItemWidget(d25ListBtn,         d25Btn      = new QPushButton());

//    previewBtn->setStyleSheet("border-image:url(:/icons/res/previewIcon.png)");
//    flusynBtn->setStyleSheet("border-image:url:/icons/res/previewIcon.png)");
//    propBtn->setStyleSheet("border-image:url:/icons/res/previewIcon.png)");
//    previewBtn->setFixedSize(78, 78);
//    flusynBtn->setFixedSize(78, 78);
//    propBtn->setFixedSize(78, 78);

    stack->addWidget(formPreview);
    formPreview->indexId = 0;
    stack->addWidget(formFluSyn);
    formFluSyn->indexId = 1;
    stack->addWidget(formProp);
    formProp->indexId = 2;

    connect(previewBtn, SIGNAL(clicked(bool)), this, SLOT(on_previewBtn_clicked()));
    connect(flusynBtn, SIGNAL(clicked(bool)), this, SLOT(on_flusynBtn_clicked()));
    connect(propBtn, SIGNAL(clicked(bool)), this, SLOT(on_propBtn_clicked()));
}

NovaWidget::~NovaWidget()
{
    delete ui;
}

void NovaWidget::on_previewBtn_clicked()
{
    stack->setCurrentIndex(formPreview->indexId);
}

void NovaWidget::on_flusynBtn_clicked()
{
    stack->setCurrentIndex(formFluSyn->indexId);
}

void NovaWidget::on_propBtn_clicked()
{
    stack->setCurrentIndex(formProp->indexId);
}
