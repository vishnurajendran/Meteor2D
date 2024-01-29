#pragma once
#include <entities/entity.h>
#include<rendering/renderqueue.h>
#include<SDL.h>

namespace meteor {
	/**
	 * @brief Renderer handles all render related tasks in meteor.
	 * Renderer uses the render-queue to render each command in-order.
	*/
	class MRenderer : public MEntity {
	public:
		MRenderer(MRenderQueue* queue, SDL_Renderer* rendererCore);
		void setLogicalSize(size_t width, size_t height);
		void renderAll();
	private:
		void render(MRenderCommand* cmd);
		SDL_Renderer* renderCore;
		MRenderQueue* queue;
	};
}