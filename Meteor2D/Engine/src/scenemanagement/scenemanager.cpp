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

		activeScene->onClose();
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
		if (path.empty()) {
			loadEmptyScene();
			return false;
		}

		loadEmptyScene();
		pugi::xml_document* doc = AssetManager::getInstance()->getSceneDefinition(path);
		if (activeScene->tryParse(doc))
			return true;

		mError("Failed loading scene from {}, loading empty scene as fallback", path);
		loadEmptyScene();
		return false;
	}

	void SceneManager::update(float deltaTime) {
		if (activeScene == NULL)
			return;

		activeScene->update(deltaTime);
	}
}