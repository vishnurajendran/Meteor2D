#include <meteorcore.h>
#include <constants.h>
#include <pugixml/pugixml.hpp>

	extern meteor::Application* getApp();

	int main(int argc, char* argv[]) {
		mLog("booting up meteor");
		if (!meteor::Texture::initialiseTextureLoader()) {
			mError("un-recoverable error, closing meteor instance");
			return 0;
		}

		meteor::Application* app = getApp();
		meteor::WindowProperties properties(app->getName(),meteor::BG_COLOR);
		meteor::Window* window = new meteor::Window(properties);
		window->setLogicalResolution(meteor::LOGICAL_WIDTH, meteor::LOGICAL_HEIGHT);
		meteor::InputManager::initialise();
		meteor::SceneManager::initialise();
		app->onStart();
		float timer = 0;
		int targetFrameTime = 1000 / meteor::TARGET_FPS;
		while (!window->hasQuit()) {
			window->clear();
			window->pollEvents();
			meteor::Time::updateTime();
			float deltaTime = meteor::Time::getDeltaTime();
			int frameTime = meteor::Time::getFrameTime();
			meteor::SceneManager::updateScene(deltaTime);
			app->onUpdate(deltaTime);
			if (!meteor::CameraStack::hasActiveCamera())
				mWarn("No active camera found!, Entities may not be correctly rendererd to the screen");
			window->update();
			
			if (frameTime < targetFrameTime) {
				window->delay(targetFrameTime - frameTime);
			}
		}
		app->onQuit();
		delete app;
		mLog("Cleaning up...");
		window->close();
		delete window;
		return 0;
	}