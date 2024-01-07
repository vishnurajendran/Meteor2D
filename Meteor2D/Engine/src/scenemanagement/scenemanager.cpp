#pragma once
#include <meteorutils/logging.h>
#include <assetmanagement/assetmanager.h>
#include <scenemanagement/scenemanager.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {
	Scene* SceneManager::activeScene = NULL;

	void SceneManager::initialise() {
	}

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

		loadEmptyScene();
		pugi::xml_document* doc = AssetManager::getInstance()->getSceneDefinition(path);
		return activeScene->tryParse(doc);
	}

	void SceneManager::updateScene(float deltaTime) {
		if (activeScene == NULL)
			return;

		activeScene->onUpdate(deltaTime);
	}
}