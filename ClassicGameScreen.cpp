#include "ClassicGameScreen.h"

ClassicGameScreen::ClassicGameScreen(int gWidth, int gHeight) {
	gameWidth = gWidth;
	gameHeight = gHeight;

	font1 = QFont();
	font1.setPixelSize(13);
	font2 = QFont();
	font2.setPixelSize(50);

	qDebug() << "ClassicGameScreen created";
}

void ClassicGameScreen::update(float dt) {
	activeDeltaTime = dt;

	//update game logic

	//render to screen
	this->repaint();
}

void ClassicGameScreen::paintEvent(QPaintEvent *e) { //renderer
	p = new QPainter(this);

	//display fps
	p->setPen(Qt::white);
	p->setFont(font1);
	p->drawText(1, 13, QString::number((int)(1000 / activeDeltaTime)));
}

ClassicGameScreen::~ClassicGameScreen() {
}
