#include "VertexItem.h"

VertexItem::VertexItem(std::string ID, QGraphicsItem *parent): QGraphicsEllipseItem(parent), QObject(){
    this->identifier = ID;
    setRect(20,20,5,5);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor("#004040"));
    setBrush(brush);
}

VertexItem::~VertexItem() noexcept {
    delete this;
}