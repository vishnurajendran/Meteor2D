#include <TestGame.h>

std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	meteor::SceneManager::loadEmptyScene();
	gameCamera = new meteor::Camera();	
	anim = new meteor::Animation("link.anim", 12,meteor::RenderLayer::World, 1);
	anim->setLocalPosition(960, 1200);
	anim->play("walk", true);
	
	meteor::Animation* anim2 = new meteor::Animation("link.anim", 12, meteor::RenderLayer::World, 0);
	anim2->setLocalPosition(960, 540);
	anim2->play("walk", true);
}

void TestGame::onUpdate(float deltaTime) {
	auto pos = anim->getLocalPosition();
	auto newPos = meteor::Vector2::make(pos.x, pos.y - (50 * deltaTime));
	anim->setLocalPosition(newPos);
}

void TestGame::onQuit() {
	meteor::SceneManager::closeActiveScene();
}

meteor::Application* getApp() {
	return new TestGame();
}