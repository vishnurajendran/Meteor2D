#include <Windowing/window.h>
#include <meteorutils/logging.h>

Window::Window(std::string name, size_t width, size_t height, bool fullscreen, Color* background) {
	backgroundColor = background;
	SDL_WindowFlags windowFlag = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
	logNoFormat("Initialising SDL");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		errorFormat("Could not initialise SDL! SDL Error: {}",SDL_GetError());
		return;
	}
	logNoFormat("Creating Window");
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,windowFlag);
	if (window == NULL) {
		errorFormat("Cannot create window! SDL Error: {}",SDL_GetError());
		return;
	}
	logNoFormat("Setting up renderer");
	quit = false;
	sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(sdlRenderer, background->r, background->g, background->b, background->a);
	if (sdlRenderer == NULL)
	{
		errorFormat("Renderer could not be created! SDL Error: {}", SDL_GetError());
		return;
	}
	renderQueue = new RenderQueue();
	renderer = new Renderer(renderQueue, sdlRenderer);
	logNoFormat("Meteor Window ready");
}

RenderQueue* Window::getRenderQueue() {
	return renderQueue;
}

bool Window::hasQuit() {
	return quit;
}

void Window::close() {
	delete renderer;
	delete renderQueue;

	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::clear() {
	SDL_RenderClear(sdlRenderer);
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
	renderer->renderAll();
	SDL_RenderPresent(sdlRenderer);
}
