#pragma once
#include <SDL.h>

namespace meteor {
	class SdlCores {
	public:
		static void setScreenCentre(SDL_Point point);
		static void setActiveRenderer(SDL_Renderer* renderer);
		static SDL_Renderer* getActiveRenderer();
		static SDL_Point getScreenCentre();
	private:
		static SDL_Point screenCentre;
		static SDL_Renderer* activeRenderer;
	};
}