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

class EdgeItem : public QObject, public QGraphicsPathItem {
Q_OBJECT
private:
    string id;
public:
    EdgeItem(complex<double> originPos, complex<double> destinyPos, const string &id, int weight,
             QGraphicsItem *parent = nullptr);

    ~EdgeItem() override;

    const string &getId() const;

    void setId(const string &id);
};


#endif //RENT_A_CAR_EDGEITEM_H
