#pragma once
#include <2d/sprite2d.h>
#include <assetmanagement/assetmanager.h>

namespace meteor {

	Sprite2D::Sprite2D(std::string texPath, RenderLayer targetLayer, uint8_t sortingOrder) : Sprite2D(AssetManager::getInstance()->getTexture(texPath), targetLayer, sortingOrder) {
	}

	Sprite2D::Sprite2D(Texture* texture, RenderLayer targetLayer, uint8_t sortingOrder) {
		if (texture == NULL)
			return;

		cmd = new TexRenderCmd(targetLayer, sortingOrder);
		cmd->bindTexture(texture);
		texSize = texture->getSize();
		pivot = Vector2::make(0.5f,0.5f);
	}

	void Sprite2D::onUpdate(float deltaTime) {
		SpatialEntity::onUpdate(deltaTime);
		if (cmd == NULL)
			return;
		Rect rect;
		rect.position = position;
		rect.size.x = texSize.x;
		rect.size.y = texSize.y;
		cmd->updateRotation(rotation);
		cmd->updateRect(rect);
		cmd->updateScale(localScale);
		cmd->updatePivot(pivot);
		RenderQueue::getQueue()->submit(cmd);
	}

	void Sprite2D::onExit() {
		if (cmd != NULL)
			delete cmd;
	}
}