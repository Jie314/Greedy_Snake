#pragma once

#include <QObject>
#include <QTimer>

class QGraphicsScene;
class QKeyEvent;
class Snake;
class Food;
class Wall;

class GameController : public QObject
{
	Q_OBJECT

public:
	GameController(QGraphicsScene *scene, QObject *parent);
	~GameController();
	void snakeAteFood(Snake *snake, Food *food);
	void snakeHitWall(Snake *snake, Wall *wall);
	void snakeAteItself(Snake *snake);
public slots:
	void pause();
	void resume();
	void gameOver();
protected:
	bool eventFilter(QObject *object, QEvent *event);

private:
	void handleKeyPressed(QKeyEvent *event);
	void addNewFood();

	void addWall();

	QTimer timer;
	QGraphicsScene *scene;

	Snake *snake;
	Wall *wall1;
	Wall *wall2;
};
