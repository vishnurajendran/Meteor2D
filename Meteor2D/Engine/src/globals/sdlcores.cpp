#include<global/sdlcores.h>

namespace meteor {
	SDL_Renderer* MSdlCores::activeRenderer = NULL;
	SDL_Point MSdlCores::screenCentre;

	void MSdlCores::setActiveRenderer(SDL_Renderer* renderer) {
		activeRenderer = renderer;
	}

	void MSdlCores::setScreenCentre(SDL_Point point) {
		screenCentre = point;
	}

	SDL_Renderer* MSdlCores::getActiveRenderer() {
		return activeRenderer;
	}

	SDL_Point MSdlCores::getScreenCentre() {
		return screenCentre;
	}
}