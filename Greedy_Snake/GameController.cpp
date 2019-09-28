#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "gamecontroller.h"
#include "food.h"
#include "snake.h"
#include "Wall.h"

GameController::GameController(QGraphicsScene *scene, QObject *parent)
	: QObject(parent),
	scene(scene),
	snake(new Snake(*this))
{
	timer.start(1000 / 33);

	//Food *a1 = new Food(0, -50);
	//scene->addItem(a1);

	scene->addItem(snake);
	addWall();
	addNewFood();

	scene->installEventFilter(this);

	resume();
}

GameController::~GameController()
{
}

void GameController::pause()
{
	disconnect(&timer, SIGNAL(timeout()),
		scene, SLOT(advance()));
}

void GameController::resume()
{
	connect(&timer, SIGNAL(timeout()),
		scene, SLOT(advance()));
}

bool GameController::eventFilter(QObject *object, QEvent *event)
{
	if (event->type() == QEvent::KeyPress) {
		handleKeyPressed((QKeyEvent *)event);
		return true;
	}
	else {
		return QObject::eventFilter(object, event);
	}
}

void GameController::handleKeyPressed(QKeyEvent *event)
{
	switch (event->key()) {
	case Qt::Key_Left:
		snake->setMoveDirection(Snake::MoveLeft);
		break;
	case Qt::Key_Right:
		snake->setMoveDirection(Snake::MoveRight);
		break;
	case Qt::Key_Up:
		snake->setMoveDirection(Snake::MoveUp);
		break;
	case Qt::Key_Down:
		snake->setMoveDirection(Snake::MoveDown);
		break;
	}
}

void GameController::snakeAteFood(Snake *snake, Food *food)
{
	scene->removeItem(food);
	delete food;

	addNewFood();
}

void GameController::addNewFood()
{
	int x, y;

	do {
		x = ((int)(qrand() % 200)-100) / 10;
		y = ((int)(qrand() % 200)-100) / 10;

		x *= 10;
		y *= 10;
	} while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5)))|| wall1->shape().contains(wall1->mapFromScene(QPointF(x + 5, y + 5))) || wall2->shape().contains(wall2->mapFromScene(QPointF(x + 5, y + 5))));
	Food *food = new Food(x, y);
	scene->addItem(food);
}

void GameController::addWall()
{
	wall1 = new Wall(30,40);
	wall2 = new Wall(-30, -40);
	scene->addItem(wall1);
	scene->addItem(wall2);
}

void GameController::snakeAteItself(Snake *snake)
{
	QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::gameOver()
{
	scene->clear();
	//scene->removeItem(snake);
	//delete snake;
	snake = new Snake(*this);
	scene->addItem(snake);
	addWall();
	addNewFood();
}
