#include <scenemanagement/scenemanager.h>

Scene* SceneManager::activeScene = NULL;

bool SceneManager::closeActiveScene() {
	if (activeScene == NULL)
		return false;

	activeScene->onExit();
	activeScene = NULL;
	return true;
}

bool SceneManager::loadEmptyScene() {
	if (activeScene != NULL)
		closeActiveScene();
	activeScene = new Scene();
	return true;
}

bool SceneManager::loadScene(std::string path) {
	if (path.empty())
		return false;
	
	//todo add scene load logic here
	return loadEmptyScene();
}

void SceneManager::updateScene(float deltaTime) {
	if (activeScene == NULL)
		return;

	activeScene->onUpdate(deltaTime);
}