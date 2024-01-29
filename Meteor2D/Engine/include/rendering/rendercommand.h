#pragma once
#include <entities/entity.h>
#include <rendering/renderlayer.h>
#include<SDL.h>

namespace meteor {
	/**
	 * @brief RenderCommand are responsible for rendering visuals to the screen.
	*/
	class MRenderCommand : public MEntity {
	protected:
		SDL_Renderer* renderCore = NULL;
	public:
		MRenderCommand(ERenderLayer layer, uint8_t sortingOrder) { this->layer = layer; this->sortingOrder = sortingOrder; }
		inline ERenderLayer getLayer() { return layer; }
		inline uint8_t getSortingOrder() { return sortingOrder; }
		inline void setRenderCore(SDL_Renderer* rendererCore) { this->renderCore = rendererCore; }
		virtual void render() {};
		virtual bool isValid() { return true; }
	private:
		uint8_t sortingOrder;
		ERenderLayer layer;
	};
}