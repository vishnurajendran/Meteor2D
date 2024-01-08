#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <entities/entity.h>
#include <meteorutils/color.h>
#include <rendering/renderqueue.h>
#include <rendering/renderer.h>
#include <windowing/windowproperties.h>

namespace meteor {
	/**
	 * @brief This class is responsible for opening a Window target for
	 * rendering
	*/
	class Window : public Entity {
	public:
		Window(WindowProperties properties);
		void update();
		void pollEvents();
		void clear();
		bool hasQuit();
		void close();
		void setLogicalResolution(size_t width, size_t height);
		RenderQueue* getRenderQueue();
		void delay(int delay);
	private:
		SDL_Window* window;
		SDL_Renderer* sdlRenderer;
		SDL_Event windowEvent;
		Color backgroundColor;
		RenderQueue* renderQueue;
		Renderer* renderer;
		bool quit;
		void render();
	};
}