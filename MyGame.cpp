#include "MyGame.h"

MyGame::MyGame(QWidget *parent) : QMainWindow(parent) {
	GameH = GAME_HEIGHT;
	GameW = GAME_HEIGHT * GAME_ASPECT_RATIO;

	//set MainWindow size
	this->setFixedHeight(GameH);
	this->setFixedWidth(GameW);
	this->setWindowIcon(QIcon(":/MyGame/icon"));
	this->setWindowTitle("Snake vs Block");
	this->setStyleSheet("QMainWindow {background-color: rgb(22, 22, 22);}");

	//add all screens
	gameScreens = new QStackedWidget(this);
	gameScreens->addWidget(new MenuScreen());
	gameScreens->addWidget(new ClassicGameScreen(GameW,GameH));
	gameScreens->setCurrentIndex(1);

	//add gameScreens to the QMainWindow
	QHBoxLayout *layout = new QHBoxLayout;
	layout->setMargin(0);
	layout->addWidget(gameScreens);
	setCentralWidget(new QWidget);
	centralWidget()->setLayout(layout);

	//start gameLoop
	startGameLoop();
}

void MyGame::startGameLoop() {
	//start elapsedTimer
	gameElTimer = new QElapsedTimer();
	gameElTimer->start();

	//start gameTimer
	gameTimer = new QTimer(this);
	connect(gameTimer, SIGNAL(timeout()), this, SLOT(update()));
	gameTimer->setInterval(GAME_DELTA_TIME);
	gameTimer->start();
}

//slots
void MyGame::update() {
	lastUpdateTime = nowUpdateTime;
	nowUpdateTime = gameElTimer->elapsed();
	deltaTime = nowUpdateTime - lastUpdateTime;
	qDebug() << 1000/(deltaTime) << "fps";

	//run update method from active gameScreen
	static_cast<ClassicGameScreen*>(gameScreens->currentWidget())->update(deltaTime);
}
