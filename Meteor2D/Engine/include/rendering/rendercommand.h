#pragma once
#include <rendering/renderlayer.h>
#include<SDL.h>

class RenderCommand {
protected:
	SDL_Renderer* renderCore = NULL;
public:
	RenderCommand(RenderLayer layer, uint8_t sortingOrder) { this->layer = layer; this->sortingOrder = sortingOrder; }
	inline RenderLayer getLayer() { return layer; }
	inline uint8_t getSortingOrder() { return sortingOrder; }
	inline void setRenderCore(SDL_Renderer* rendererCore) { this->renderCore = rendererCore; }
	virtual void render() {};
	virtual bool isValid() { return true; }
private:
	uint8_t sortingOrder;
	RenderLayer layer;
};