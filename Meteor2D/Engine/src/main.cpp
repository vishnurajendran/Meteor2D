#include <meteorcore.h>
#include <constants.h>
#include <pugixml/pugixml.hpp>

#include <irrKlang.h>

extern meteor::MApplication* getApp();

int main(int argc, char* argv[]) {
	mLog("booting up meteor");
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		mError("Could not initialise SDL! SDL Error: {}", SDL_GetError());
		return 0;
	}

	if (!meteor::MTexture::initialiseTextureLoader()) {
		mError("un-recoverable error, closing meteor instance");
		return 0;
	}

	meteor::MApplication* app = getApp();
	meteor::SWindowProperties properties(app->getName(),meteor::BG_COLOR);
	meteor::MWindow* window = new meteor::MWindow(properties);
	window->setLogicalResolution(meteor::LOGICAL_WIDTH, meteor::LOGICAL_HEIGHT);
	meteor::MInputManager::initialise();
	meteor::MSceneManager::initialise();
	meteor::MAudioEngine::Initialise();

	app->onStart();
	float timer = 0;
	int targetFrameTime = 1000 / meteor::TARGET_FPS;
	while (!window->hasQuit() && !app->hasQuit()) {

		// update events
		meteor::MInputManager::update();

		// clear window
		window->clear();
		window->pollEvents();

		//update time
		meteor::MTime::updateTime();
		float deltaTime = meteor::MTime::getDeltaTime();
		int frameTime = meteor::MTime::getFrameTime();

		//update scene
		meteor::MSceneManager::update(deltaTime);

		//update app
		app->onUpdate(deltaTime);
		if (!meteor::MCameraStack::hasActiveCamera())
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
	meteor::MAssetManager::getInstance()->cleanup();

	mLog("Closing Audio Engine");
	meteor::MAudioEngine::cleanup();
	
	mLog("Closing Window..");
	window->close();
	delete window;
	mLog("meteor shutdown succesfull!");
	return 0;
}