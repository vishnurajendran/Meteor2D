#include <TestGame.h>


std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	meteor::SceneManager::loadEmptyScene();
	meteor::SpatialEntity* p = new meteor::SpatialEntity();
	p->setLocalPosition(10, 20);
	meteor::SpatialEntity* c = new meteor::SpatialEntity(p);
	c->setLocalPosition(5, 1);
	sprite = new meteor::Sprite2D(meteor::AssetManager::getInstance()->getTexture("chars\\link.png"), meteor::RenderLayer::World, 1);
	/*Sprite2D* sp = new Sprite2D(AssetManager::getInstance()->getTexture("chars\\link.png"), RenderLayer::World, 0);
	sp->setLocalPosition(10, 10);*/
}

void TestGame::onUpdate(float deltaTime) {
	auto pos = sprite->getLocalPosition();
	auto scale = sprite->getLocalScale();
	pos.y += 50 * deltaTime;
	auto newScale = scale.x + (1 * deltaTime);
	scale.x = scale.y = newScale;
	//sprite->setLocalPosition(pos);
	sprite->setLocalScale(scale);
}

void TestGame::onQuit() {
	meteor::SceneManager::closeActiveScene();
}

meteor::Application* getApp() {
	return new TestGame();
}