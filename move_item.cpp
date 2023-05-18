#include "move_item.h"
#include "MyWidget.h"

MoveItem::MoveItem(QObject* parent) :
    QObject(parent), QGraphicsItem()
{
    setFlags(ItemIsSelectable | ItemIsMovable);
}


MoveItem::MoveItem(QWidget* parentWidget, QGraphicsItem* parent) :
    QGraphicsItem(parent),
    m_parentWidget(parentWidget)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
}


MoveItem::~MoveItem()
{

}


QRectF MoveItem::boundingRect() const
{
    return QRectF (-30, -30, 60, 60);
}


void MoveItem::setColor(QColor color)
{
    m_color = color;
    update(); // перерисовываем виджет
}


const QColor& MoveItem::getColor() const
{
        return m_color;
}


void MoveItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(m_color);
    painter->drawRect(-30,-30,60,60);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos() + m_shiftMouseCoords));
    emit itemMoved();
}


void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (QApplication::mouseButtons() == Qt::LeftButton)
    {
        emit itemSelected(this);
    }


    if (QApplication::mouseButtons() == Qt::RightButton)
    {
        emit selectionChanged("Что-то");
    }

    if (QApplication::mouseButtons() == Qt::MiddleButton)
    {
        this->deleteLater();
    }

    QGraphicsItem::mousePressEvent(event);

    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    m_shiftMouseCoords = this->pos() - mapToScene(event->pos());
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}


void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}


void MoveItem::mouseDoubleCLickEvent(QGraphicsSceneMouseEvent* event)
{
    return;
}
