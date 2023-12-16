#pragma once
#include<rendering/renderqueue.h>
#include<SDL.h>

class Renderer {
public:
	Renderer(RenderQueue* queue, SDL_Renderer* rendererCore);
	void renderAll();
private:
	void render(RenderCommand* cmd);
	SDL_Renderer* renderCore;
	RenderQueue* queue;
};