#include <TestGame.h>

std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	meteor::SceneManager::loadEmptyScene();
	gameCamera = new meteor::Camera();
	scp = new meteor::SpatialEntity();
	scp->setLocalPosition(meteor::Vector2(960, 540));
	anim = new meteor::Animation("link.anim", 12,meteor::RenderLayer::World, 1);
	//anim->setLocalPosition(250, 0);
	scp->setChild(anim);
	anim->play("walk", true);
}

void TestGame::onUpdate(float deltaTime) {
	auto rot = scp->getLocalRotation();
	rot += 100 * deltaTime;
	scp->setLocalRotation(rot);
	//anim->setLocalPosition(newPos);
}

void TestGame::onQuit() {
	meteor::SceneManager::closeActiveScene();
}

meteor::Application* getApp() {
	return new TestGame();
}