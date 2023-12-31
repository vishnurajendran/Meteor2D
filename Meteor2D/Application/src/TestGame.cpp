#include <TestGame.h>


std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	meteor::SceneManager::loadEmptyScene();
	gameCamera = new meteor::Camera();	
	meteor::Animation* anim = new meteor::Animation("link.animap", 12,meteor::RenderLayer::World, 1);
	anim->setLocalPosition(1500, 540);
	anim->play("walk", true);
}

void TestGame::onUpdate(float deltaTime) {

}

void TestGame::onQuit() {
	meteor::SceneManager::closeActiveScene();
}

meteor::Application* getApp() {
	return new TestGame();
}