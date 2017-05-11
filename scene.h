#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "mouse.h"
#include "gorter.h"



class Scene : public QGraphicsScene
{
Q_OBJECT

public:
    Scene();
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    virtual void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    virtual void keyPressEvent(QKeyEvent *keyevent);
    virtual void keyReleaseEvent(QKeyEvent *keyevent);

public slots:
    void fire();
    void advance();


public:
    Mouse *mouse;
    Gorter *gorter;


private:
    QTimer *m_FireTimer;
    QPointF m_FireTarget;

    int mousetargetnumber = 3;
    int mouseactualnumber;
};







#endif // SCENE_H

