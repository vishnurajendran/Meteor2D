#pragma once
#include <meteorutils/logging.h>
#include <scenemanagement/scenemanager.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {
	Scene* SceneManager::activeScene = NULL;

	void SceneManager::initialise() {
		mWarn("registered size {}", SceneEntityTypeMap::getMapSize());
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

		pugi::xml_node node;
		auto res = SceneEntityTypeMap::getDeserializer("animation")->deserialize(node);

		//todo add scene load logic here
		return loadEmptyScene();
	}

	void SceneManager::updateScene(float deltaTime) {
		if (activeScene == NULL)
			return;

		activeScene->onUpdate(deltaTime);
	}
}