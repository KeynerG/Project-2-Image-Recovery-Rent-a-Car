#include "EdgeItem.h"

EdgeItem::EdgeItem(QGraphicsItem *parent) {
    setRect(20,20,5,5);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor("#004040"));
    setBrush(brush);
}
EdgeItem::~EdgeItem(){
    delete this;
}