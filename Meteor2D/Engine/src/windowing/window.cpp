#pragma once
#include <Windowing/window.h>
#include <meteorutils/logging.h>
#include <global/sdlcores.h>

namespace meteor {
	MWindow::MWindow(SWindowProperties properties) {
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

		MSdlCores::setActiveRenderer(sdlRenderer);
		MSdlCores::setScreenCentre(screenCentre);

		SDL_SetRenderDrawColor(sdlRenderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
		if (sdlRenderer == NULL)
		{
			mError("Renderer could not be created! SDL Error: {}", SDL_GetError());
			return;
		}
		renderQueue = MRenderQueue::getQueue();
		renderer = new MRenderer(renderQueue, sdlRenderer);
		mLog("Meteor Window ready");
	}

	MRenderQueue* MWindow::getRenderQueue() {
		return renderQueue;
	}

	bool MWindow::hasQuit() {
		return quit;
	}

	void MWindow::close() {

		if (MSdlCores::getActiveRenderer() == sdlRenderer)
			MSdlCores::setActiveRenderer(NULL);

		delete renderer;
		delete renderQueue;

		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void MWindow::clear() {
		SDL_RenderClear(sdlRenderer);
	}

	void MWindow::pollEvents() {
		if (SDL_PollEvent(&windowEvent)) {
			if (windowEvent.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	void MWindow::update() {
		render();
	}

	void MWindow::render() {
		renderer->renderAll();
		SDL_RenderPresent(sdlRenderer);
	}

	void MWindow::setLogicalResolution(size_t width, size_t height) {
		renderer->setLogicalSize(width, height);
	}

	void MWindow::delay(int delay) {
		SDL_Delay(delay);
	}
}