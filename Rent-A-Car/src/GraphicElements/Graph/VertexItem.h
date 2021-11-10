#ifndef RENT_A_CAR_VERTEXITEM_H
#define RENT_A_CAR_VERTEXITEM_H

#include <iostream>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <complex>
#include <QPen>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QLabel>

using namespace std;

class VertexItem : public QObject, public QGraphicsEllipseItem {
Q_OBJECT
private:
    string identifier;
public:
    explicit VertexItem(string ID = "", complex<int> pos = (0, 0), QGraphicsItem *parent = nullptr);

    ~VertexItem() override;

    const string &getIdentifier() const;

    void setIdentifier(const string &identifier);
};


#endif //RENT_A_CAR_VERTEXITEM_H
