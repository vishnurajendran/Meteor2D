#pragma once
#include <Windowing/window.h>
#include <meteorutils/logging.h>
#include <global/sdlcores.h>

namespace meteor {
	Window::Window(std::string name, size_t width, size_t height, bool fullscreen, Color* background) {
		SDL_Point screenCentre;
		screenCentre.x = width / 2;
		screenCentre.y = height / 2;

		backgroundColor = background;
		SDL_WindowFlags windowFlag = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
		log("Initialising SDL");
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			error("Could not initialise SDL! SDL Error: {}", SDL_GetError());
			return;
		}
		log("Creating Window");
		window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlag);
		if (window == NULL) {
			error("Cannot create window! SDL Error: {}", SDL_GetError());
			return;
		}
		log("Setting up renderer");
		quit = false;
		sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		SdlCores::setActiveRenderer(sdlRenderer);
		SdlCores::setScreenCentre(screenCentre);

		SDL_SetRenderDrawColor(sdlRenderer, background->r, background->g, background->b, background->a);
		if (sdlRenderer == NULL)
		{
			error("Renderer could not be created! SDL Error: {}", SDL_GetError());
			return;
		}
		renderQueue = RenderQueue::getQueue();
		renderer = new Renderer(renderQueue, sdlRenderer);
		log("Meteor Window ready");
	}

	RenderQueue* Window::getRenderQueue() {
		return renderQueue;
	}

	bool Window::hasQuit() {
		return quit;
	}

	void Window::close() {

		if (SdlCores::getActiveRenderer() == sdlRenderer)
			SdlCores::setActiveRenderer(NULL);

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

	void Window::setLogicalResolution(size_t width, size_t height) {
		renderer->setLogicalSize(width, height);
	}
}