#pragma once
#include <meteorutils/logging.h>
#include <2d/texrendercmd.h>
#include <meteorutils/transformhelper.h>
#include <camera/camerastack.h>
#include <camera/camera.h>

namespace meteor {
	TexRenderCmd::TexRenderCmd(RenderLayer layer, uint8_t sortingOrder) : RenderCommand(layer, sortingOrder) {
		texture = NULL;
	}

	void TexRenderCmd::render() {
		
		if (!CameraStack::hasActiveCamera())
			return;
		
		if (!isValid())
			return;

		Camera* cam = CameraStack::getActiveCamera();
		SDL_FRect tRect;
		SDL_Rect src;
		//subtract the positions, by half of x and y, to center the sprite.
		Vector2 size = texture->getSize();
		size.x *= scale.x;
		size.y *= scale.y;

		float pivotedSizeX = size.x * pivot.x;
		float pivotedSizeY = size.y - (size.y * pivot.y);

		tRect.x = (targetRect.position.x - pivotedSizeX) - cam->getPosition().x;
		tRect.y = (targetRect.position.y + pivotedSizeY) - cam->getPosition().y;
		tRect.w = (targetRect.size.x * scale.x);
		tRect.h = (targetRect.size.y * scale.y);
		transformRectInternalToScreen(tRect);

		if (useSrcRect) {
			src.x = srcRect.position.x;
			src.y = srcRect.position.y;
			src.w = srcRect.size.x;
			src.h = srcRect.size.y;

			SDL_RenderCopyF(renderCore, texture->getCoreTexture(), &src, &tRect);
		}
		else
			SDL_RenderCopyF(renderCore, texture->getCoreTexture(), NULL, &tRect);
	}

	bool TexRenderCmd::isValid() {
		if (renderCore == NULL) {
			mError("Renderer Core not available, this request will not be fullfilled");
			return false;
		}

		if (texture == NULL) {
			mError("Core texture not available, this request will not be fullfilled");
			return false;
		}

		return true;
	}
}
