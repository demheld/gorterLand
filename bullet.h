#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <math.h>

#define BULLETGRAPHICSID (65536+2)


//Etwas mit dem Destruktor müsste noch gemacht werden

class Bullet : public QGraphicsEllipseItem
{
public:
    Bullet(qreal dirx, qreal diry, int gorterposx, int gorterposy);
    ~Bullet();


protected:
    void advance(int step);
    int  type() const;

public:
//    int  myQGraphicsItemID = 65536+2;

private:
    QBrush m_Brush;
    qreal m_Speed;
    qreal m_DirX;
    qreal m_DirY;
};

#endif // BULLET_H



