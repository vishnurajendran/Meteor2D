#pragma once
#pragma once
#include <string>
#include <scenemanagement/scene.h>
class SceneManager {
public:
	static bool loadEmptyScene();
	static bool loadScene(std::string path);
	static bool closeActiveScene();
	static void updateScene(float deltaTime);
	inline static Scene* getActiveScene() { return activeScene; }
private:
	static Scene* activeScene;
};