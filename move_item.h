#ifndef MOVE_ITEM_H
#define MOVE_ITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QApplication>


class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    MoveItem(QObject* parent = 0);
    ~MoveItem();


private:
    QPointF m_shiftMouseCoords;

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);


};

#endif // MOVE_ITEM_H
