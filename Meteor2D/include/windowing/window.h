#pragma once
#include <iostream>
#include <meteorutils/color.h>
#include <SDL.h>
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
	SDL_Surface* surface;
	Color* backgroundColor;
	SDL_Event windowEvent;
	bool quit;
	void render();
};