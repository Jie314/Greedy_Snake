#pragma once

#include <QGraphicsItem>

class Food : public QGraphicsItem
{
	//Q_OBJECT

public:
	Food(qreal x, qreal y);

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

	QPainterPath shape() const;
};
