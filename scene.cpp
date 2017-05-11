#include "scene.h"

#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <math.h>
#include <QDebug>
#include "gorter.h"






Scene::Scene()
    : QGraphicsScene()
{
    mouse = new Mouse;              //Konstruiert eine Maus
    addItem(mouse);                 //Fügt die Maus hinzu
    gorter = new Gorter;
    addItem(gorter);


    // the fire timer has the responsability to create bullets
    // it will be started when needed : when mouse is pressed
    m_FireTimer= new QTimer();
    QObject::connect(m_FireTimer, SIGNAL(timeout()), this, SLOT(fire()));
}

void Scene::mousePressEvent ( QGraphicsSceneMouseEvent *mouseEvent )
{
    m_FireTarget = mouseEvent->scenePos();
    m_FireTimer->start(100);
    QGraphicsScene::mousePressEvent(mouseEvent);    //Hier wird der Event weitergeleitet an QGraphicsscene

    qDebug() << QString::number(m_FireTarget.x());
    qDebug() << QString::number(m_FireTarget.y());
}

void Scene::mouseMoveEvent ( QGraphicsSceneMouseEvent *mouseEvent )
{
    m_FireTarget = mouseEvent->scenePos();
    QGraphicsScene::mouseMoveEvent(mouseEvent);

//    qDebug() << QString::number(m_FireTarget.x());
//    qDebug() << QString::number(m_FireTarget.y());
}

void Scene::mouseReleaseEvent ( QGraphicsSceneMouseEvent *mouseEvent )
{
    m_FireTimer->stop();
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void Scene::keyPressEvent(QKeyEvent *keyevent)
//Die Idee hier ist wenn ein Knopf (asdw) gedrückt wird wird das bewegungsflag gesetzt und der Event mitgesendet.
//Im gorter.cpp wird dann geschaut was damit gemacht werden soll
{

    gorter->keyControl(keyevent->key(),true);      //übergebe welcher Knopf und dass gedrückt
    QGraphicsScene::keyPressEvent(keyevent);
}

void Scene::keyReleaseEvent(QKeyEvent *keyevent)
{
    gorter->keyControl(keyevent->key(),false);
    QGraphicsScene::keyReleaseEvent(keyevent);
}


void Scene::fire()
// creates a fire bullet
// the bullet will move in the direction of the mouse cursor
// the trajectory is sligthly perturbated by a random small angle
{
/*    qreal dirx = m_FireTarget.x()-200.0;
    qreal diry = m_FireTarget.y()-200.0;
    qreal length = sqrt(dirx*dirx+diry*diry);
    if (length!=0)
    {
        // normalized direction vector
        qreal invLength= 1.0/length;
        dirx *= invLength;
        diry *= invLength;

        // creating an angle perturbation of +/- 3°
        qreal alphaPerturbation = static_cast<qreal>(qrand()%6-3) * M_PI / 180.0;
        qreal xPerturbation = cos(alphaPerturbation);
        qreal yPerturbation = sin(alphaPerturbation);
        // cos(a+b)=...
        dirx = dirx*xPerturbation - diry*yPerturbation;
        // sin(a+b)=...
        diry = diry*xPerturbation + dirx*yPerturbation;
*/

        qreal dirx = -sin((2*3.1415/360)*gorter->rotation());
        qreal diry = cos((2*3.1415/360)*gorter->rotation());

        Bullet *bullet = new Bullet(dirx, diry,gorter->pos().x(),gorter->pos().y());
        addItem(bullet);
    /*}*/

}


void Scene::advance()
{

    mouseactualnumber = 0;
    // we first remove the items out of the sceneRect
    for (int i=0; i<items().count(); ++i)
    {
        QGraphicsItem * item = items().at(i);
        qreal x= item->x();
        qreal y= item->y();
        qreal sx=sceneRect().width();
        qreal sy= sceneRect().height();

        //Das muss vor dem Löschen des Items sein, sonst versucht die Methode auf ein gelöschtes Item zuzugreifen.
        if (item->type() == MOUSEGRAPHICSID)
        {
            mouseactualnumber = mouseactualnumber +1;       //zähle wieviele Mäuse in Betrieb sind
            Mouse * newitem= dynamic_cast<Mouse *>(item);   //Dieser dynamic cast braucht man, damit man auf die Mouse Methode Mouse::deleteMouse() zugreifen kann
            newitem->deleteMouse();
        }

        if ( (x < 0.0) || (y < 0.0) || (x > sx) || (y > sy))
        {
            removeItem(item);
            delete item;
        }

      }

    //Neue Mäuse wenn es nicht genügend mehr hat
    if(mouseactualnumber<=mousetargetnumber)
    {
        Mouse *mouseli = new Mouse;
        addItem(mouseli);
    }

    QGraphicsScene::advance();
}











