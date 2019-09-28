#include "Greedy_Snake.h"
#include <QGraphicsView>
#include <QTimer>
#include "constants.h"
#include "gamecontroller.h"


Greedy_Snake::Greedy_Snake(QWidget *parent)
	: QMainWindow(parent),
	scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene, this)),
	game(new GameController(scene, this))
{
	ui.setupUi(this);
	setCentralWidget(view);
	resize(600, 600);

	initScene();
	initSceneBackground();

	QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

Greedy_Snake::~Greedy_Snake()
{
}

void Greedy_Snake::initScene()
{
	scene->setSceneRect(-100, -100, 200, 200);
}

void Greedy_Snake::initSceneBackground()
{
	QPixmap bg(TILE_SIZE, TILE_SIZE);
	QPainter p(&bg);
	p.setBrush(QBrush(Qt::gray));
	p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

	view->setBackgroundBrush(QBrush(bg));
}

void Greedy_Snake::adjustViewSize()
{
	view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

