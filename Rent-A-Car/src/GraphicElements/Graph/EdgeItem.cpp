#include "EdgeItem.h"

EdgeItem::EdgeItem(complex<double> originPos, complex<double> destinyPos, const string &ID, int weight,
                   QGraphicsItem *parent) {
    setPos(0, 0);
    this->id = ID;
    //Defines form
    auto *path = new QPainterPath(QPointF(originPos.real() + 15, originPos.imag() + 15));
    path->lineTo(destinyPos.real() + 15, destinyPos.imag() + 15);
    QPen pen;
    pen.setColor("#00ffff");
    setPen(pen);
    setPath(*path);


    auto *label = new QLabel();
    label->setText(QString::fromStdString(to_string(weight)));
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background:transparent; font:10px; font:bold; color:'white';");
    auto *labelContainer = new QGraphicsProxyWidget(this);
    labelContainer->setWidget(label);
    labelContainer->setPos((path->boundingRect().center().x()),
                           (path->boundingRect().center().y() - label->height()) - 2);
}

EdgeItem::~EdgeItem() {
    delete this;
}

const string &EdgeItem::getId() const {
    return id;
}

void EdgeItem::setId(const string &id) {
    EdgeItem::id = id;
}
