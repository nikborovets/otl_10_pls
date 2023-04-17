#include "move_item.h"
#include "MyWidget.h"

MoveItem::MoveItem(QObject* parent) :
    QObject(parent), QGraphicsItem()
{
    setFlag(ItemIsSelectable);
}

MoveItem::MoveItem(QWidget* parentWidget, QGraphicsItem* parent) :
    QGraphicsItem(parent),
    m_parentWidget(parentWidget)
{
    setFlag(ItemIsSelectable);
}


MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF (-30, -30, 60, 60);
}

void MoveItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::gray);
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
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        MyWidget *widget = new MyWidget();
        widget->setWindowTitle("My Widget");
        widget->resize(200, 200);
        widget->show();
    }


    if (QApplication::mouseButtons() == Qt::RightButton)
    {
        this->deleteLater();
    }


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
