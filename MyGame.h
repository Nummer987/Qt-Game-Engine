#pragma once

#include <QtWidgets/QMainWindow>
#include <QStackedwidget>
#include <QHBoxLayout>
#include <MenuScreen.h>
#include <ClassicGameScreen.h>
#include <QTimer>
#include <QDebug>
#include <QElapsedtimer>
#define GAME_HEIGHT 768
#define GAME_ASPECT_RATIO 9/16
#define GAME_DELTA_TIME 16

class SnakeVsBlock : public QMainWindow
{
	Q_OBJECT

public:
	//constructor
	SnakeVsBlock(QWidget *parent = Q_NULLPTR);

private:
	//vars
	QStackedWidget *gameScreens;
	QTimer *gameTimer;
	QElapsedTimer *gameElTimer;
	qint64 lastUpdateTime, nowUpdateTime = 0;
	float deltaTime;
	int GameH;
	int GameW;

	//methods
	void startGameLoop();

private slots:
	//methods
	void update();
};
