#include "camod.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/imgs/recs/SplashScreen.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();

    Camod w;
    w.show();

    splash.finish(&w);
    return a.exec();
}
