#include <Windowing/window.h>

Window::Window(size_t width, size_t height,bool fullscreen, Color* background) {
	backgroundColor = background;
	SDL_WindowFlags windowFlag = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialise SDL " << SDL_GetError() << std::endl;
		return;
	}
	window = SDL_CreateWindow("Meteor2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,windowFlag);
	if (window == NULL) {
		std::cout << "Cannot create window" << SDL_GetError() << std::endl;
		return;
	}
	surface = SDL_GetWindowSurface(window);
	quit = false;
}

bool Window::hasQuit() {
	return quit;
}

void Window::close() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::clear() {
	SDL_FillRect(surface, NULL,SDL_MapRGBA(surface->format,backgroundColor->r, backgroundColor->g, backgroundColor->b, backgroundColor->a));
}

void Window::pollEvents() {
	if (SDL_PollEvent(&windowEvent)) {
		if (windowEvent.type == SDL_QUIT) {
			quit = true;
		}
	}
}

void Window::update() {
	clear();
	render();
}

void Window::render() {
	//todo: add render code here.
}
