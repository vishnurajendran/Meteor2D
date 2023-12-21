#include <TestGame.h>


std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	SceneManager::loadEmptyScene();
	SpatialEntity* p = new SpatialEntity();
	p->setLocalPosition(10, 20);
	SpatialEntity* c = new SpatialEntity(p);
	c->setLocalPosition(5, 1);
	sprite = new Sprite2D(AssetManager::getInstance()->getTexture("chars\\link.png"), RenderLayer::World, 0);
}

void TestGame::onUpdate(float deltaTime) {
	auto pos = sprite->getLocalPosition();
	//pos.y += 50 * deltaTime;
	sprite->setLocalPosition(pos);
}

void TestGame::onQuit() {
	SceneManager::closeActiveScene();
}

Application* getApp() {
	return new TestGame();
}