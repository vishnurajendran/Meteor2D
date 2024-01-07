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
		//if in same anim, we ignore
		if (currAnim == name)
			return;

		this->currAnim = name;
		this->isLooping = looped;
		this->isPlaying = true;
		changeRequested = true;
	}

	void Animation::tryChangeAnimParams() {
		if (!changeRequested)
			return;

		changeRequested = false;
		index = 0;
		animTime = 0;
		currAnimSheet = animationMap->getAnim(currAnim);
		cmd->bindTexture(currAnimSheet == NULL ? NULL : currAnimSheet->getTexture());
		isPlaying = true;
	}

	void Animation::onUpdate(float deltaTime) {
		//animation changes has a 1-frame delay, to avoid animation flickering.
		tryChangeAnimParams();
		SpatialEntity::onUpdate(deltaTime);
		cmd->updateRotation(rotation);
		cmd->updateScale(localScale);
		cmd->updatePivot(pivot);


		updateAnimation(deltaTime);
	}

	void Animation::updateAnimation(float deltaTime) {
		if (currAnimSheet == NULL) {
			return;
		}

		if (!isPlaying && renderOnce) {
			renderOnce = false;
			spriteSrcRect = currAnimSheet->sample(index, isLooping);
			submitFrameRenderRequest();
			return;
		}

		// update animations
		if (isPlaying) {
			animTime += deltaTime;
			if (animTime > (1.0f / fps)) {
				animTime = 0;
				spriteSrcRect = currAnimSheet->sample(index, isLooping);
			}
		}

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