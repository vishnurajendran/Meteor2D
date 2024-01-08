#pragma once
#pragma once
#include <string>
#include <scenemanagement/scene.h>

namespace meteor {
	/**
	 * @brief Manages Scene loads and unloads.
	*/
	class SceneManager : public Entity {
	public:
		/**
		 * @brief Initialises the SceneManager.
		*/
		static void initialise();
		/**
		 * @brief Loads an empty scene
		*/
		static bool loadEmptyScene();
		/**
		 * @brief Loads a scene from an scene definition file
		*/
		static bool loadScene(std::string path);
		/**
		 * @brief Closes the current active scene
		*/
		static bool closeActiveScene();
		/**
		 * @brief Updates current active scene.
		*/
		static void update(float deltaTime);
		/**
		 * @brief Returns current active scene. 
		*/
		inline static Scene* getActiveScene() { return activeScene; }
	private:
		static Scene* activeScene;
	};
}