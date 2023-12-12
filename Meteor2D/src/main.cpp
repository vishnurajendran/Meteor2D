#include <meteor.h>

const size_t SCREEN_WIDTH = 800;
const size_t SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
	logNoFormat("booting up meteor");
	Window* window = new Window(SCREEN_WIDTH, SCREEN_HEIGHT, false, Color::black());
	while (!window->hasQuit()) {
		window->pollEvents();
		window->update();
	}
	window->close();
	return 0;
}