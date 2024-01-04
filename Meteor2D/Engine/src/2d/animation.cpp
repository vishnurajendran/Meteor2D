#pragma once
#include <assetmanagement/assetmanager.h>
#include <2d/animation.h>

namespace meteor {

	Animation::Animation(std::string mapFile, int fps, RenderLayer layer, uint8_t sortingOrder) {
		this->animationMap = AssetManager::getInstance()->getAnimationMap(mapFile);
		this->currAnimSheet = animationMap->getDefault();
		this->fps = fps;
		pivot = Vector2::make(0.5f, 0.5f);
		cmd = new TexRenderCmd(layer, sortingOrder);
		cmd->useSourceRect(true);

		//bind default texture
		if(currAnimSheet != NULL)
			cmd->bindTexture(currAnimSheet == NULL ? NULL : currAnimSheet->getTexture());
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

	void Animation::play(std::string name, bool looped=true) {
		this->isLooping = looped;

		//reset animation rect index.
		index = 0;

		currAnimSheet = animationMap->getAnim(name);
		cmd->bindTexture(currAnimSheet == NULL ? NULL : currAnimSheet->getTexture());
		isPlaying = true;
	}

	void Animation::onUpdate(float deltaTime) {
		SpatialEntity::onUpdate(deltaTime);
		updateAnimation(deltaTime);
	}

	void Animation::updateAnimation(float deltaTime) {
		
		cmd->updateRotation(rotation);
		cmd->updateScale(localScale);
		cmd->updatePivot(pivot);
		
		if (currAnimSheet == NULL)
			return;

		if (!isPlaying && renderOnce) {
			renderOnce = false;
			spriteSrcRect = currAnimSheet->sample(index, isLooping);
			submitFrameRenderRequest();
			return;
		}

		// update animations
		animTime += deltaTime;
		if (animTime < (1.0f / fps)) {
			submitFrameRenderRequest();
			return;
		}
		
		//reset timer
		animTime = 0;

		if (isPlaying)
			spriteSrcRect = currAnimSheet->sample(index, isLooping);

		submitFrameRenderRequest();
	}

	void Animation::submitFrameRenderRequest() {
		updateRect();
		RenderQueue::getQueue()->submit(cmd);
	}

	void Animation::updateRect() {
		Rect myRect;
		myRect.position = position;
		myRect.size.x = spriteSrcRect.size.x;
		myRect.size.y = spriteSrcRect.size.y;
		cmd->updateSrcRect(spriteSrcRect);
		cmd->updateRect(myRect);
	}
};