#ifndef RENT_A_CAR_EDGEITEM_H
#define RENT_A_CAR_EDGEITEM_H

#include <QObject>
#include <QGraphicsPathItem>
#include <QBrush>
#include <string>
#include <complex>
#include <QPen>
#include <QLabel>
#include <QGraphicsProxyWidget>

using namespace std;

class EdgeItem: public QObject, public QGraphicsPathItem{
Q_OBJECT
public:
    EdgeItem(complex<double> originPos, complex<double> destinyPos, const string& id, int weight, QGraphicsItem *parent = nullptr);

    ~EdgeItem() override;
};


#endif //RENT_A_CAR_EDGEITEM_H
