#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Greedy_Snake.h"

class QGraphicsScene;
class QGraphicsView;
class GameController;//Forward statement

class Greedy_Snake : public QMainWindow
{
	Q_OBJECT

public:
	Greedy_Snake(QWidget *parent = Q_NULLPTR);
	~Greedy_Snake();

private:
	Ui::Greedy_SnakeClass ui;

private slots:
	void adjustViewSize();

private:
	void initScene();
	void initSceneBackground();

	QGraphicsScene *scene;
	QGraphicsView *view;
	GameController *game;
};
