#pragma once
#include <meteorutils/rect.h>
#include <global/sdlcores.h>
#include <SDL.h>

void transformRectInternalToScreen(SDL_Rect&);
void transformRectInternalToScreen(SDL_Rect& rect){
	auto origin = SdlCores::getScreenCentre();
	rect.x = origin.x + rect.x;
	rect.y = origin.y - rect.y;
}