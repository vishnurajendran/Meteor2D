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

	void TexRenderCmd::bindTexture(Texture* tex) {
		if (lockedForRender)
			this->textureTempBuffer = tex;
		else
			this->texture = tex;
	}

	void TexRenderCmd::render() {
		
		if (!CameraStack::hasActiveCamera())
			return;
		
		if (!isValid())
			return;

		lockedForRender = true;
		Camera* cam = CameraStack::getActiveCamera();
		SDL_FRect tRect;
		SDL_Rect src;
		//subtract the positions, by half of x and y, to center the sprite.
		Vector2 size = targetRect.size;
		size.x *= scale.x;
		size.y *= scale.y;

		float pivotedSizeX = size.x * pivot.x;
		float pivotedSizeY = size.y - (size.y * pivot.y);
		SDL_FPoint sdlPivot(pivotedSizeX, pivotedSizeY);

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
			SDL_RenderCopyExF(renderCore, texture->getCoreTexture(), &src, &tRect, rotation, &sdlPivot, SDL_FLIP_NONE);
		}
		else
			SDL_RenderCopyExF(renderCore, texture->getCoreTexture(), NULL, &tRect, rotation, &sdlPivot, SDL_FLIP_NONE);
		lockedForRender = false;
		swap();
	}

	void TexRenderCmd::swap() {
		if (textureTempBuffer != NULL) {
			texture = textureTempBuffer;
			textureTempBuffer = NULL;
		}
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
