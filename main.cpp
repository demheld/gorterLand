#include <QApplication>
#include "scene.h"
#include <QTimer>
#include <QGraphicsView>
#include <QScreen>





int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    a.setOverrideCursor(Qt::BlankCursor);

    //get the screen size for fullscreen
    QScreen *srn = QApplication::screens().at(0);
    QSize screensize = srn->size();

    Scene scene;
    scene.setSceneRect(0.0, 0.0, screensize.width()-10, screensize.height()-10);
    scene.setBackgroundBrush(Qt::black);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer->start(50);



    QGraphicsView window(&scene);
    window.showFullScreen();
    return a.exec();
}
