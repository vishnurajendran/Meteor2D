#include <2d/sprite2d.h>

namespace meteor {
	Sprite2D::Sprite2D(Texture* texture, RenderLayer targetLayer, uint8_t sortingOrder) {
		if (texture == NULL)
			return;

		cmd = new TexRenderCmd(targetLayer, sortingOrder);
		cmd->bindTexture(texture);
		texSize = texture->getSize();
	}

	void Sprite2D::onUpdate(float deltaTime) {
		SpatialEntity::onUpdate(deltaTime);
		if (cmd == NULL)
			return;
		Rect rect;
		rect.position = position;
		rect.size.x = texSize.x;
		rect.size.y = texSize.y;
		cmd->updateRect(rect);
		cmd->updateScale(localScale);
		RenderQueue::getQueue()->submit(cmd);
	}

	void Sprite2D::onExit() {
		if (cmd != NULL)
			delete cmd;
	}
}