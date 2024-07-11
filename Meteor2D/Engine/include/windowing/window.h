#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <entities/entity.h>
#include <meteorutils/color.h>
#include <meteorutils/vector2d.h>
#include <rendering/renderqueue.h>
#include <rendering/renderer.h>
#include <windowing/windowproperties.h>

namespace meteor {
	/**
	 * @brief This class is responsible for opening a Window target for
	 * rendering
	*/
	class MWindow : public MEntity {
	public:
		MWindow(SWindowProperties properties);
		void update();
		void pollEvents();
		void clear();
		bool hasQuit();
		void close();
		void setLogicalResolution(size_t width, size_t height);
		inline SVector2 getLogicalResolution() { return resolution; }
		MRenderQueue* getRenderQueue();
		void delay(int delay);
	private:
		SVector2 resolution;
		SWindowProperties properties;
		SDL_Window* window;
		SDL_Renderer* sdlRenderer;
		SDL_Event windowEvent;
		SColor backgroundColor;
		MRenderQueue* renderQueue;
		MRenderer* renderer;
		bool quit;
		void render();
	};
}