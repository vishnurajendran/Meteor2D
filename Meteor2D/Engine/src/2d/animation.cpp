#pragma once
#include <assetmanagement/assetmanager.h>
#include <2d/animation.h>

namespace meteor {

	Animation::Animation(std::string mapFile, int fps, RenderLayer layer, uint8_t sortingOrder) {
		this->animationMap = AssetManager::getInstance()->getAnimationMap(mapFile);
		this->fps = fps;
		pivot = Vector2::make(0.5f, 0.5f);
		cmd = new TexRenderCmd(layer, sortingOrder);
	}

	void Animation::setFPS(int fps) {
		this->fps = fps;
	}

	void Animation::stop() {
		isPlaying = false;
	}

	void Animation::resume() {
		isPlaying = true;
	}

	void Animation::play(std::string name, bool looped) {
		this->isLooping = looped;
		currAnimSheet = animationMap->getAnim(name);
		cmd->useSourceRect(true);
		cmd->bindTexture(currAnimSheet == NULL ? NULL : currAnimSheet->getTexture());
		isPlaying = true;
	}

	void Animation::onUpdate(float deltaTime) {
		SpatialEntity::onUpdate(deltaTime);
		updateAnimation(deltaTime);
	}

	void Animation::updateAnimation(float deltaTime) {
		// exit conditions
		if (!isPlaying)
			return;
		if (currAnimSheet == NULL)
			return;

		cmd->updateScale(localScale);
		cmd->updatePivot(pivot);

		// update animations
		animTime += deltaTime;
		if (animTime < (1.0f / fps)) {
			RenderQueue::getQueue()->submit(cmd);
			return;
		}
		
		//reset timer
		animTime = 0;

		Rect src = currAnimSheet->getNext(isLooping);
		Rect myRect;

		myRect.position = position;
		myRect.size.x = src.size.x;
		myRect.size.y = src.size.y;

		cmd->updateSrcRect(src);
		cmd->updateRect(myRect);
		RenderQueue::getQueue()->submit(cmd);
	}
};