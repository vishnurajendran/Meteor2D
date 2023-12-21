#include <meteorutils/logging.h>
#include <2d/texrendercmd.h>
#include <meteorutils/transformhelper.h>


TexRenderCmd::TexRenderCmd(RenderLayer layer, uint8_t sortingOrder) : RenderCommand(layer, sortingOrder) {
	texture = NULL;
}

void TexRenderCmd::render() {
	if (!isValid())
		return;

	

	SDL_Rect tRect;
	//subtract the positions, by half of x and y, to center the sprite.
	Vector2 size = texture->getSize();
	size.x *= scale.x;
	size.y *= scale.y;

	tRect.x = targetRect.position.x - (size.x / 2);
	tRect.y = targetRect.position.y + (size.y / 2);
	tRect.w = (targetRect.size.x * scale.x);
	tRect.h = (targetRect.size.y * scale.y);
	transformRectInternalToScreen(tRect);
	SDL_RenderCopy(renderCore, texture->getCoreTexture(), NULL, &tRect);
}

bool TexRenderCmd::isValid() {
	if (renderCore == NULL) {
		error("Renderer Core not available, this request will not be fullfilled");
		return false;
	}

	if (texture == NULL) {
		error("Core texture not available, this request will not be fullfilled");
		return false;
	}

	return true;
}
