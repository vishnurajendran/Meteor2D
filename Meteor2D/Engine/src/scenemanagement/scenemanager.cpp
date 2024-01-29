#pragma once
#include <meteorutils/logging.h>
#include <assetmanagement/assetmanager.h>
#include <scenemanagement/scenemanager.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {
	MScene* MSceneManager::activeScene = NULL;

	void MSceneManager::initialise() {
	}

	bool MSceneManager::closeActiveScene() {
		if (activeScene == NULL)
			return false;


		activeScene->onClose();
		activeScene = NULL;
		return true;
	}

	bool MSceneManager::loadEmptyScene() {
		if (activeScene != NULL)
			closeActiveScene();
		activeScene = new MScene();
		return true;
	}

	bool MSceneManager::loadScene(std::string path) {
		if (path.empty()) {
			loadEmptyScene();
			return false;
		}

		loadEmptyScene();
		pugi::xml_document* doc = MAssetManager::getInstance()->getSceneDefinition(path);
		if (activeScene->tryParse(doc))
			return true;

		mError("Failed loading scene from {}, loading empty scene as fallback", path);
		loadEmptyScene();
		return false;
	}

	void MSceneManager::update(float deltaTime) {
		if (activeScene == NULL)
			return;

		activeScene->update(deltaTime);
	}
}