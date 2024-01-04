#include <TestGame.h>

std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	meteor::SceneManager::loadEmptyScene();
	gameCamera = new meteor::Camera();
	scp = new meteor::SpatialEntity();
	scp->setLocalPosition(meteor::Vector2(960, 540));

	auto bg = new meteor::Sprite2D("bg\\test.png", meteor::RenderLayer::World, 0);
	bg->setLocalScale(3, 3);

	anim = new meteor::Animation("link.anim", 12,meteor::RenderLayer::World, 1);
	scp->setChild(anim);
	auto scene = meteor::SceneManager::getActiveScene();
	mLog("Scene contents {}", scene->getRootSize());
}

void TestGame::onUpdate(float deltaTime) {
	auto rot = scp->getLocalRotation();
	rot += 100 * deltaTime;
	int x = 0;
	int y = 0;
	
	if (meteor::InputManager::getKey(meteor::KeyCode::KEYCODE_W)) {
		y = 1;
	}
	else if (meteor::InputManager::getKey(meteor::KeyCode::KEYCODE_S)) {
		y = -1;
	}
	else
		y = 0;

	if (meteor::InputManager::getKey(meteor::KeyCode::KEYCODE_A)) {
		x = -1;
	}
	else if (meteor::InputManager::getKey(meteor::KeyCode::KEYCODE_D)) {
		x = 1;
	}
	else
		x = 0;

	if (x != 0 || y != 0) {
		anim->play("walk", true);
	}
	else {
		anim->play("idle", true);
	}

	auto pos = scp->getLocalPosition();
	pos += meteor::Vector2::make(x, y) * 150 * deltaTime;
	scp->setLocalPosition(pos);
}

void TestGame::onQuit() {
	meteor::SceneManager::closeActiveScene();
}

meteor::Application* getApp() {
	return new TestGame();
}