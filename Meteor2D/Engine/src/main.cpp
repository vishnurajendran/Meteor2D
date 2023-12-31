#include <meteorcore.h>
#include <constants.h>

	extern meteor::Application* getApp();

	int main(int argc, char* argv[]) {
		mLog("booting up meteor");
		if (!meteor::Texture::initialiseTextureLoader()) {
			mError("un-recoverable error, closing meteor instance");
			return 0;
		}

		meteor::Application* app = getApp();
		meteor::WindowProperties properties(app->getName(),meteor::Color::black());
		meteor::Window* window = new meteor::Window(properties);
		window->setLogicalResolution(meteor::LOGICAL_WIDTH, meteor::LOGICAL_HEIGHT);
		app->onStart();
		while (!window->hasQuit()) {
			window->clear();
			window->pollEvents();
			meteor::Time::updateTime();
			float deltaTime = meteor::Time::getDeltaTime();
			meteor::SceneManager::updateScene(deltaTime);
			app->onUpdate(deltaTime);
			if (!meteor::CameraStack::hasActiveCamera())
				mWarn("No active camera found!, Entities may not be correctly rendererd to the screen");
			window->update();
		}
		app->onQuit();
		delete app;
		mLog("Cleaning up...");
		window->close();
		delete window;
		return 0;
	}