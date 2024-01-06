#pragma once
#pragma once
#include <string>
#include <scenemanagement/scene.h>

namespace meteor {
	class SceneManager {
	public:
		static void initialise();
		static bool loadEmptyScene();
		static bool loadScene(std::string path);
		static bool closeActiveScene();
		static void updateScene(float deltaTime);
		inline static Scene* getActiveScene() { return activeScene; }
	private:
		static Scene* activeScene;
	};
}