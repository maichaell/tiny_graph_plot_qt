#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    //format.setVersion(4,6);

    //format.setDepthBufferSize(24);
    //format.setStencilBufferSize(8);
    //format.setVersion(4, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    MainWindow w;
    w.show();
    return a.exec();
}
