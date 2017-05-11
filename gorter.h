#ifndef GORTER_H
#define GORTER_H


#include <QGraphicsItem>
#include <QMouseEvent>



class Gorter : public QGraphicsItem
{
//Funktionen
public:
    Gorter();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;



    QCursor getPosition();
    void changeDirectionByKey(void);
    void keyControl(int whichkey, bool pressed);

public slots:
    void moveGorter(void);



protected:
    void advance(int step) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event);  //Nein nicht hier weil das ja eine QGraphicsItem Klasse ist
    void mousePressEvent(QMouseEvent *event);


//Variablen
public:
    bool        f_changeDirectionByKey;
    int         whichkey;
    int         runningvelocity = 3;    //grusig hier
    int         rotspeed = 4;

private:
    qreal       angle;
    qreal       speed;
    qreal       mouseEyeDirection;
    QColor      color;

    bool        key_up_pressed;
    bool        key_down_pressed;
    bool        key_left_pressed;
    bool        key_right_pressed;

};

#endif // GORTER_H















