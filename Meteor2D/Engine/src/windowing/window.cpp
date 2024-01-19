#pragma once
#include <Windowing/window.h>
#include <meteorutils/logging.h>
#include <global/sdlcores.h>

namespace meteor {
	Window::Window(WindowProperties properties) {
		SDL_Point screenCentre;
		screenCentre.x = properties.width / 2;
		screenCentre.y = properties.height / 2;

		backgroundColor = properties.backgroundColor;
		auto windowFlag = properties.fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

		mLog("Creating Window");
		window = SDL_CreateWindow(properties.name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, properties.width, properties.height, windowFlag);
		if (window == NULL) {
			mError("Cannot create window! SDL Error: {}", SDL_GetError());
			return;
		}
		mLog("Setting up renderer");
		quit = false;

		auto rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE;
		if (properties.vsync) {
			rendererFlags = rendererFlags | SDL_RENDERER_PRESENTVSYNC;
		}

		sdlRenderer = SDL_CreateRenderer(window, -1, rendererFlags);

		SdlCores::setActiveRenderer(sdlRenderer);
		SdlCores::setScreenCentre(screenCentre);

		SDL_SetRenderDrawColor(sdlRenderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
		if (sdlRenderer == NULL)
		{
			mError("Renderer could not be created! SDL Error: {}", SDL_GetError());
			return;
		}
		renderQueue = RenderQueue::getQueue();
		renderer = new Renderer(renderQueue, sdlRenderer);
		mLog("Meteor Window ready");
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
		render();
	}

	void Window::render() {
		renderer->renderAll();
		SDL_RenderPresent(sdlRenderer);
	}

	void Window::setLogicalResolution(size_t width, size_t height) {
		renderer->setLogicalSize(width, height);
	}

	void Window::delay(int delay) {
		SDL_Delay(delay);
	}
}