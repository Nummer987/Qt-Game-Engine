#include "MenuScreen.h"

MenuScreen::MenuScreen() {
	lbl = new QLabel(this);
	lbl->setGeometry(100, 0, 100, 100);
	lbl->setText("MenuScreen");

	qDebug() << "MenuScreen created";
}

void MenuScreen::update(float dt) {
	activeDeltaTime = dt;
}

MenuScreen::~MenuScreen() {
}
