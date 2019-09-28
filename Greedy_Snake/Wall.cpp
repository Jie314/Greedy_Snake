#include "Wall.h"
#include <QPainter>
#include "constants.h"


Wall::Wall(qreal x, qreal y)
{
	setPos(x, y);
	setData(GD_Type, GO_Wall);
}


Wall::~Wall()
{
}

QRectF Wall::boundingRect() const
{
	return QRectF(-2*TILE_SIZE, -2*TILE_SIZE,
		TILE_SIZE * 4, TILE_SIZE * 4);
}

void Wall::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->save();

	painter->setRenderHint(QPainter::Antialiasing);
	painter->fillPath(shape(), Qt::blue);
	painter->restore();
}

QPainterPath Wall::shape() const
{
	QPainterPath p;
	p.addRect(QRectF(-0.95*TILE_SIZE, -0.95*TILE_SIZE,TILE_SIZE * 1.9, TILE_SIZE * 1.9));
	return p;
}
