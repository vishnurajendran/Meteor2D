#include <meteorcore.h>
#include <constants.h>
#include <pugixml/pugixml.hpp>

#include <irrKlang.h>

extern meteor::Application* getApp();

int main(int argc, char* argv[]) {
	mLog("booting up meteor");
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		mError("Could not initialise SDL! SDL Error: {}", SDL_GetError());
		return 0;
	}

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
	meteor::AudioEngine::Initialise();

	app->onStart();
	float timer = 0;
	int targetFrameTime = 1000 / meteor::TARGET_FPS;
	while (!window->hasQuit() && !app->hasQuit()) {

		// update events
		meteor::InputManager::update();

		// clear window
		window->clear();
		window->pollEvents();

		//update time
		meteor::Time::updateTime();
		float deltaTime = meteor::Time::getDeltaTime();
		int frameTime = meteor::Time::getFrameTime();

		//update scene
		meteor::SceneManager::update(deltaTime);

		//update app
		app->onUpdate(deltaTime);
		if (!meteor::CameraStack::hasActiveCamera())
			mWarn("No active camera found!, Entities may not be correctly rendererd to the screen");
		window->update();
		
		//delay frame to reach target framerate
		if (frameTime < targetFrameTime) {
			window->delay(targetFrameTime - frameTime);
		}
	}

	mLog("Quiting Application...");
	app->onQuit();
	delete app;

	mLog("Cleaning Asset References");
	meteor::AssetManager::getInstance()->cleanup();

	mLog("Closing Audio Engine");
	meteor::AudioEngine::cleanup();
	
	mLog("Closing Window..");
	window->close();
	delete window;
	mLog("meteor shutdown succesfull!");
	return 0;
}