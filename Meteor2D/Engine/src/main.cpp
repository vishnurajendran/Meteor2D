#include <meteorcore.h>

const size_t SCREEN_WIDTH = 800;
const size_t SCREEN_HEIGHT = 600;

extern Application* getApp();

float getDeltaTime();

int main(int argc, char* argv[]) {
	logNoFormat("booting up meteor");
	Application* app = getApp();
	Window* window = new Window(app->getName(),SCREEN_WIDTH, SCREEN_HEIGHT, false, Color::black());
	app->setRenderQueue(window->getRenderQueue());
	app->onStart();
	while (!window->hasQuit()) {
		float time = getDeltaTime();
		window->clear();
		window->pollEvents();
		EntityManager::updateAll(time);
		app->onUpdate(time);
		window->update();
	}
	app->onQuit();
	delete app;
	logNoFormat("Cleaning up...");
	window->close();
	delete window;
	return 0;
}

//todo: replace later
float getDeltaTime() {
	return 0;
}