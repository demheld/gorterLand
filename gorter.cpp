#include "gorter.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>
#include <QDebug>
#include <math.h>

#include <QCursor>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static const QPointF points[3] = {
    QPointF(-20.0, 0),
    QPointF(0, 50.0),
    QPointF(20, 0)
};


static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}


/*Das ist die gorter Klasse*/
Gorter::Gorter()
      : angle(0), speed(0), mouseEyeDirection(0), color(Qt::black)        /*Das sind die privaten variabeln, die beim konstruieren ohne zusatz genommen werden.*/
{
    setRotation(0);    //qrand() % (360 * 16));                                                                    /*Ist von Qgraphics*/
    setPos(200,200);
}

/*Noch nicht verstanden; ist hier zum debuggen*/
QRectF Gorter::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

/*Noch nicht verstanden; ist hier zum debuggen*/
QPainterPath Gorter::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}




void Gorter::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
//Den Gorter grafisch erstellen
{
/*    // Body
    painter->setBrush(Qt::red);
    painter->drawEllipse(-0, -0, 30, 30);

    // Eyes
    painter->setBrush(Qt::black);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

    // Nose
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(QRectF(-2, -22, 4, 4));

    // Pupils
    painter->drawEllipse(QRectF(-8.0 + mouseEyeDirection, -17, 4, 4));
    painter->drawEllipse(QRectF(4.0 + mouseEyeDirection, -17, 4, 4));

    // Ears
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);
*/
    painter->setBrush(Qt::red);
    painter->drawPolygon(points,4);
}


//! [4]
void Gorter::advance(int step)
{




     moveGorter();


}



void Gorter::moveGorter(void)
{
    //lateral
    if (key_left_pressed) setPos(mapToParent(runningvelocity,0));  //setRotation(rotation()-10);

    if (key_right_pressed) setPos(mapToParent(-runningvelocity,0));      //setRotation(rotation()+10);

    if (key_down_pressed) setPos(mapToParent(0, -runningvelocity));

    if (key_up_pressed) setPos(mapToParent(0, runningvelocity));

    //Rotation
    QPoint cursorpos = QCursor::pos();
    QCursor::setPos(500,500);
    setRotation(rotation()+(cursorpos.x()-500));

}

/*Diese Funktion wird von scene.cpp aufgerufen und aus dem keypressevent wird übergeben welcher
knopf gedrückt wurde bzw. losgelassen wurde. Man braucht so eine min Statemachine damit mehrere
Knöpfe gleichzeitig gedrückt werden können.*/
void Gorter::keyControl(int whichkey, bool pressed)
{
    switch (whichkey)
    {
        case(Qt::Key_A):
            key_left_pressed = pressed;
            break;
        case Qt::Key_D:
            key_right_pressed = pressed;
            break;
        case Qt::Key_W:
            key_up_pressed = pressed;
            break;
        case Qt::Key_S:
            key_down_pressed = pressed;
            break;
    }

}











