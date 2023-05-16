#ifndef MOVE_ITEM_H
#define MOVE_ITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QApplication>
#include <QWidget>
#include <QColor>
#include <QVector>


class MoveItem : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
    MoveItem(QObject* parent = 0);
    MoveItem(QWidget* parentWidget, QGraphicsItem* parent);
    ~MoveItem();

    void setColor(QColor color);
    const QColor& getColor() const;

private:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void mouseDoubleCLickEvent(QGraphicsSceneMouseEvent* event);

signals:
    void selectionChanged(const QString& value);
    void itemMoved();

private:
    QWidget* m_parentWidget;
    QPointF m_shiftMouseCoords;

    QColor m_color;
    QString m_name;
};

#endif // MOVE_ITEM_H
