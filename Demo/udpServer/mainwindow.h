#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dupserver.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pCon_clicked();

    void on_pClose_clicked();

    void on_pSend_clicked();

private:
    Ui::MainWindow *ui;

    DUPServer *theServer;

    bool serverStatus = false;

};

#endif // MAINWINDOW_H
