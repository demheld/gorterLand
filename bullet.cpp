#include "bullet.h"


//Konstruktor eines bullets
Bullet::Bullet(qreal dirx, qreal diry,int gorterposx, int gorterposy)
    : m_Speed(7.0)
    , m_DirX(dirx)
    , m_DirY(diry)
{
    setRect(-10.0,-10.0,20.0,20.0);
    setPos(gorterposx,gorterposy);
    QRadialGradient rGrad( 0.0, 0.0, 20.0, 0.0, 0.0);
    rGrad.setColorAt(0.0, QColor(0,0,255));
    rGrad.setColorAt(0.7, QColor(200,100,20));
    rGrad.setColorAt(1.0, QColor(255,0,0,0));
    setBrush(QBrush(rGrad) );
    setPen(QPen(Qt::NoPen));
}

//Destruktor des bullets
Bullet::~Bullet()
{
}

/*Hier überschreibt man die Methode type, damit die Maus eine Item ID bekommt die fix ist
Falls man das in einem Enum definieren will Doku zu type lesen von QGraphicsitem*/
int Bullet::type() const
{
    // Enable the use of qgraphicsitem_cast with this item.
    return BULLETGRAPHICSID;
}



//Die Advance Funktion wird vom timer aufgerufen
void Bullet::advance(int step)
{
    setPos(x()+m_Speed*m_DirX, y()+m_Speed*m_DirY);
//    if (!scene()->collidingItems(this).isEmpty()) delete this;  //Das funktioniert nur halb; es kollidiert mit dem Gorter und wird dann gelöscht
}
