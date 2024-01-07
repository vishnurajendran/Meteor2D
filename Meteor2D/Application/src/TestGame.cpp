#include <TestGame.h>

std::string TestGame::getName() {
	return "Test Game";
}

void TestGame::onStart() {
	meteor::SceneManager::loadScene("test_scene.scml");
	auto scene = meteor::SceneManager::getActiveScene();
	gameCamera = scene->find<meteor::Camera>("gameCamera");
	scp = scene->find<meteor::SpatialEntity>("scp");
	anim = scene->find<meteor::Animation>("link_player");
	mLog("Scene contents {}", scene->getRootSize());
}

void TestGame::onUpdate(float deltaTime) {
	auto rot = scp->getLocalRotation();
	rot += 100 * deltaTime;
	int x = 0;
	int y = 0;
	
	if (meteor::InputManager::getKeyDown(meteor::KeyCode::KEYCODE_ESCAPE)) {
		quit();
		return;
	}

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