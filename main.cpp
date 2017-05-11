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
//    QSize sizeasdf = QScreen::size();


    QScreen *srn = QApplication::screens().at(0);
     QSize sizeasdf = srn->size();
//    qreal dotsPerInch = (qreal)srn->logicalDotsPerInch();








    Scene scene;
//    scene.setSceneRect(0.0, 0.0, 12/*sizeasdf.width()*/, 12/*sizeasdf.height()*/);
        scene.setSceneRect(0.0, 0.0, sizeasdf.width()-10, sizeasdf.height()-100);
    scene.setBackgroundBrush(Qt::black);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer->start(50);



    QGraphicsView window(&scene);
    window.showFullScreen();
    return a.exec();
}
