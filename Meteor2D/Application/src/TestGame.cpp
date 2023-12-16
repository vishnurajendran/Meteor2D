#include <TestGame.h>
#include <meteor.h>

std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	logNoFormat("game started");
}

void TestGame::onUpdate(float deltaTime) {
	logNoFormat("game updating");
}

void TestGame::onQuit() {
	logNoFormat("game quit");
}

Application* getApp() {
	return new TestGame();
}