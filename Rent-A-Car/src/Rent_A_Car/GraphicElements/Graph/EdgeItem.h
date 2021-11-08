#ifndef RENT_A_CAR_EDGEITEM_H
#define RENT_A_CAR_EDGEITEM_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>

class EdgeItem: public QObject, public QGraphicsRectItem{
Q_OBJECT
public:

    EdgeItem(QGraphicsItem *parent = nullptr);

    ~EdgeItem() override;
};


#endif //RENT_A_CAR_EDGEITEM_H
