#pragma once
#include <iostream>
#include <meteorutils/color.h>
#include <SDL.h>
#include <rendering/renderqueue.h>
#include <rendering/renderer.h>

class Window {
public:
	Window(size_t height, size_t width, bool fullscreen, Color* background);
	void update();
	void pollEvents();
	void clear();
	bool hasQuit();
	void close();
private:
	SDL_Window* window;
	SDL_Renderer* sdlRenderer;
	SDL_Event windowEvent;
	Color* backgroundColor;
	RenderQueue* renderQueue;
	Renderer* renderer;
	bool quit;
	void render();
};