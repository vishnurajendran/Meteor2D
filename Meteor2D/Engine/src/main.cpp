#include <meteorcore.h>
#include <constants.h>

extern Application* getApp();

int main(int argc, char* argv[]) {
	log("booting up meteor");
	if (!Texture::initialiseTextureLoader()) {
		error("un-recoverable error, closing meteor instance");
		return 0;
	}

	Application* app = getApp();
	Window* window = new Window(app->getName(),SCREEN_WIDTH, SCREEN_HEIGHT, false, Color::black());
	window->setLogicalResolution(LOGICAL_WIDTH, LOGICAL_HEIGHT);
	app->onStart();
	while (!window->hasQuit()) {
		window->clear();
		window->pollEvents();
		Time::updateTime();
		float deltaTime = Time::getDeltaTime();
		SceneManager::updateScene(deltaTime);
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