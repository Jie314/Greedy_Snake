#pragma once
#include <QGraphicsItem>



class Wall :
	public QGraphicsItem
{
public:
	Wall(qreal x, qreal y);
	~Wall();

public:

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

	QPainterPath shape() const;
};

