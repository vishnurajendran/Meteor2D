#include <TestGame.h>
#include <meteor.h>

std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	logNoFormat("game started");
	logNoFormat("Opening empty scene");
	SceneManager::loadEmptyScene();
	SpatialEntity* p = new SpatialEntity();
	p->setLocalPosition(10, 20);
	SpatialEntity* c = new SpatialEntity(p);
	c->setLocalPosition(5, 1);
	logFormat("Scene Size: {}", SceneManager::getActiveScene()->getRootSize());
	logFormat("p: {} {}", p->getPosition().x, p->getPosition().y);
	logFormat("c: {} {}", c->getPosition().x, c->getPosition().y);
}

void TestGame::onUpdate(float deltaTime) {
	//logNoFormat("game updating");
}

void TestGame::onQuit() {
	SceneManager::closeActiveScene();
	logNoFormat("game quit");
}

Application* getApp() {
	return new TestGame();
}