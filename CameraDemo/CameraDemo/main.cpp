#include "camdemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CamDemo w;
    w.show();

    return a.exec();
}
