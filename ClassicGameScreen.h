#pragma once

#include <qwidget.h>
#include <QDebug>
#include <QPainter>
#include <MyGame.h>

class ClassicGameScreen : public QWidget
{
	Q_OBJECT

public:
	//constructors
	ClassicGameScreen(int gWidth, int gHeight);
	~ClassicGameScreen();

	//methods
	void update(float dt);

private:
	//vars
	float activeDeltaTime;
	QPainter *p;
	int gameWidth, gameHeight;
	QFont font1, font2;

	//methods
	void paintEvent(QPaintEvent *e); //called when this->repaint() is called

};
