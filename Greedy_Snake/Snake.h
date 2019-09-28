#pragma once

#include <QGraphicsItem>

class GameController;

class Snake : public QGraphicsItem
{
	//Q_OBJECT

public:
	enum Direction {
		NoMove,
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown
	};

	Snake(GameController & controller);

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

	QPainterPath shape() const;
	void setMoveDirection(Direction direction);

protected:
	void advance(int step);

private:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void handleCollisions();

	QPointF        head;
	int            growing;
	int            speed;
	QList<QPointF> tail;
	int            tickCounter;
	Direction      moveDirection;
	GameController &controller;
};
