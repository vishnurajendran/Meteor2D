#pragma once
#include <meteorutils/rect.h>
#include <global/sdlcores.h>
#include <constants.h>
#include <SDL.h>

namespace meteor {
	void transformRectInternalToScreen(SDL_FRect& rect) {
		rect.y = LOGICAL_HEIGHT - rect.y;
	}
}