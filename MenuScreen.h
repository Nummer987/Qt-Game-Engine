#pragma once

#include <QWidget>
#include <QLabel>
#include <QDebug>

class MenuScreen : public QWidget
{
	Q_OBJECT

public:
	//constructor
	MenuScreen();
	~MenuScreen();

	//methods
	void update(float dt);

private:
	//vars
	float activeDeltaTime;
	QLabel *lbl;

};
