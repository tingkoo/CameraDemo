#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pCon_clicked()
{

    QString theAdd = ui->theIp->text();

    //needs to check if is a valid ip

    theServer = new DUPServer(this, theAdd);

    serverStatus = theServer->serverIsLive();
    if(!serverStatus){

    }else{
        qDebug() << "Active server on:" <<  theServer->getInfo();
    }

}

void MainWindow::on_pClose_clicked()
{
    if(theServer || serverStatus){
        qDebug() << "going to ds";
        theServer->killServer();
        delete theServer;

    }


}

void MainWindow::on_pSend_clicked()
{
    QImage test("/dd/d.jpg");
    theServer->currentFrame(test);
}
