#include <TestGame.h>

std::string TestGame::getName() {
	return "Test Game";
}

meteor::MAudioSource* src;
void TestGame::onStart() {
	meteor::MSceneManager::loadScene("test_scene.scml");
	auto scene = meteor::MSceneManager::getActiveScene();
	gameCamera = scene->find<meteor::MCamera>("gameCamera");
	scp = scene->find<meteor::MSpatialEntity>("scp");
	anim = scene->find<meteor::MAnimation>("link_player");
	src = scene->find<meteor::MAudioSource>("bg");
	mLog("Scene contents {}", scene->getRootSize());
}

void TestGame::onUpdate(float deltaTime) {
	auto rot = scp->getLocalRotation();
	rot += 100 * deltaTime;
	int x = 0;
	int y = 0;
	
	if (meteor::MInputManager::getKeyDown(meteor::EKeyCode::KEYCODE_ESCAPE)) {
		quit();
		return;
	}

	if (meteor::MInputManager::getKeyDown(meteor::EKeyCode::KEYCODE_SPACE)) {
		bool paused = src->isPaused();
		if (paused)
			src->play();
		else
			src->pause();
		return;
	}

	if (meteor::MInputManager::getKey(meteor::EKeyCode::KEYCODE_W)) {
		y = 1;
	}
	else if (meteor::MInputManager::getKey(meteor::EKeyCode::KEYCODE_S)) {
		y = -1;
	}
	else
		y = 0;

	if (meteor::MInputManager::getKey(meteor::EKeyCode::KEYCODE_A)) {
		x = -1;
	}
	else if (meteor::MInputManager::getKey(meteor::EKeyCode::KEYCODE_D)) {
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
	pos += meteor::SVector2::make(x, y) * 150 * deltaTime;
	scp->setLocalPosition(pos);
}

void TestGame::onQuit() {
	meteor::MSceneManager::closeActiveScene();
}

meteor::MApplication* getApp() {
	return new TestGame();
}