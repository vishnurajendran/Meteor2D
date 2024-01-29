#pragma once
#include <2d/sprite2d.h>
#include <assetmanagement/assetmanager.h>

namespace meteor {

	MSprite2D::MSprite2D(std::string texPath, ERenderLayer targetLayer, uint8_t sortingOrder) : MSprite2D(MAssetManager::getInstance()->getTexture(texPath), targetLayer, sortingOrder) {
	}

	MSprite2D::MSprite2D(MTexture* texture, ERenderLayer targetLayer, uint8_t sortingOrder) {
		if (texture == NULL)
			return;

		cmd = new MTexRenderCmd(targetLayer, sortingOrder);
		cmd->bindTexture(texture);
		texSize = texture->getSize();
		pivot = SVector2::make(0.5f,0.5f);
	}

	void MSprite2D::onUpdate(float deltaTime) {
		MSpatialEntity::onUpdate(deltaTime);
		if (cmd == NULL)
			return;
		SRect rect;
		rect.position = position;
		rect.size.x = texSize.x;
		rect.size.y = texSize.y;
		cmd->updateRotation(rotation);
		cmd->updateRect(rect);
		cmd->updateScale(localScale);
		cmd->updatePivot(pivot);
		MRenderQueue::getQueue()->submit(cmd);
	}

	void MSprite2D::onExit() {
		if (cmd != NULL)
			delete cmd;
	}
}