#include <meteorcore.h>
#include <constants.h>

	extern meteor::Application* getApp();

	int main(int argc, char* argv[]) {
		log("booting up meteor");
		if (!meteor::Texture::initialiseTextureLoader()) {
			error("un-recoverable error, closing meteor instance");
			return 0;
		}

		meteor::Application* app = getApp();
		meteor::Window* window = new meteor::Window(app->getName(), meteor::SCREEN_WIDTH, meteor::SCREEN_HEIGHT, false, meteor::Color::white());
		window->setLogicalResolution(meteor::LOGICAL_WIDTH, meteor::LOGICAL_HEIGHT);
		app->onStart();
		while (!window->hasQuit()) {
			window->clear();
			window->pollEvents();
			meteor::Time::updateTime();
			float deltaTime = meteor::Time::getDeltaTime();
			meteor::SceneManager::updateScene(deltaTime);
			app->onUpdate(deltaTime);
			window->update();
		}
		app->onQuit();
		delete app;
		log("Cleaning up...");
		window->close();
		delete window;
		return 0;
	}