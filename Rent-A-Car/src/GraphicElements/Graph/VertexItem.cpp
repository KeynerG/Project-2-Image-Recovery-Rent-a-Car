#include "VertexItem.h"

#include <utility>

VertexItem::VertexItem(string ID, complex<int> pos, QGraphicsItem *parent) : QGraphicsEllipseItem(parent), QObject() {
    this->identifier = std::move(ID);
    setRect(pos.real(), pos.imag(), 30, 30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor("#004040");
    setBrush(brush);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor("#00ffff");
    setPen(pen);


    auto *label = new QLabel();
    label->setText(QString::fromStdString(this->identifier));
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background:transparent; font:bold; color:'white'");
    auto *labelContainer = new QGraphicsProxyWidget(this);
    labelContainer->setWidget(label);
    //cout << "X: " << this->boundingRect().x() << "  Center x: " << this->boundingRect().center().x() << endl;
    labelContainer->setPos(this->boundingRect().center().x() - label->width() / 2,
                           this->boundingRect().center().y() - label->height() / 2);
}

VertexItem::~VertexItem() {
    delete this;
}

const string &VertexItem::getIdentifier() const {
    return identifier;
}

void VertexItem::setIdentifier(const string &identifier) {
    VertexItem::identifier = identifier;
}
