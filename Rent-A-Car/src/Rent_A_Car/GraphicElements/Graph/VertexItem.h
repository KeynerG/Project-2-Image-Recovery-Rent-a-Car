#ifndef RENT_A_CAR_VERTEXITEM_H
#define RENT_A_CAR_VERTEXITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>

class VertexItem: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    VertexItem(std::string ID = "", QGraphicsItem *parent = nullptr);

    ~VertexItem() override;
private:
    std::string identifier;
};


#endif //RENT_A_CAR_VERTEXITEM_H
