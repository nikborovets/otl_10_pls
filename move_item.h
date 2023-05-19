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
    QString get_name();
    void set_name(QString name);
    const QColor& getColor() const;

private:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

signals:
    void selectionChanged(MoveItem* item);
    void itemMoved();
    void itemSelected(MoveItem *item);


private:
    QWidget* m_parentWidget;
    QPointF m_shiftMouseCoords;

    QColor m_color;
    QString m_name;
};

#endif // MOVE_ITEM_H
