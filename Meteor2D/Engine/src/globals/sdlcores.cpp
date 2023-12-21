#include<global/sdlcores.h>

SDL_Renderer* SdlCores::activeRenderer = NULL;
SDL_Point SdlCores::screenCentre;

void SdlCores::setActiveRenderer(SDL_Renderer* renderer) {
	activeRenderer = renderer;
}

void SdlCores::setScreenCentre(SDL_Point point) {
	screenCentre = point;
}

SDL_Renderer* SdlCores::getActiveRenderer() {
	return activeRenderer;
}

SDL_Point SdlCores::getScreenCentre() {
	return screenCentre;
}