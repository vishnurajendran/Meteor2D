#pragma once
#include <assetmanagement/assetmanager.h>
#include <2d/animation.h>

namespace meteor {

	MAnimation::MAnimation(std::string mapFile, int fps, ERenderLayer layer, uint8_t sortingOrder) {
		this->animationMap = MAssetManager::getInstance()->getAnimationMap(mapFile);
		this->currAnimSheet = animationMap->getDefault();
		this->fps = fps;
		pivot = SVector2::make(0.5f, 0.5f);
		cmd = new MTexRenderCmd(layer, sortingOrder);
		cmd->useSourceRect(true);

		//bind default texture
		if(currAnimSheet != NULL)
			cmd->bindTexture(currAnimSheet == NULL ? NULL : currAnimSheet->getTexture());
	}

	void MAnimation::setFPS(int fps) {
		this->fps = fps;
	}

	void MAnimation::stop() {
		isPlaying = false;
	}

	void MAnimation::resume() {
		isPlaying = true;
	}

	void MAnimation::play(std::string name, bool looped=true) {
		//if in same anim, we ignore
		if (currAnim == name)
			return;

		this->currAnim = name;
		this->isLooping = looped;
		this->isPlaying = true;
		changeRequested = true;
	}

	void MAnimation::tryChangeAnimParams() {
		if (!changeRequested)
			return;

		changeRequested = false;
		currAnimSheet = animationMap->getAnim(currAnim);
		cmd->bindTexture(currAnimSheet == NULL ? NULL : currAnimSheet->getTexture());
		isPlaying = true;
		index = 0;
		animTime = 0;
		spriteSrcRect = currAnimSheet->sample(index, isLooping);
	}

	void MAnimation::onUpdate(float deltaTime) {
		//animation changes has a 1-frame delay, to avoid animation flickering.
		tryChangeAnimParams();
		MSpatialEntity::onUpdate(deltaTime);
		cmd->updateRotation(rotation);
		cmd->updateScale(localScale);
		cmd->updatePivot(pivot);
		updateAnimation(deltaTime);
	}

	void MAnimation::updateAnimation(float deltaTime) {
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

	void MAnimation::submitFrameRenderRequest() {
		updateRect();
		MRenderQueue::getQueue()->submit(cmd);
	}

	void MAnimation::updateRect() {
		SRect myRect;
		myRect.position = position;
		myRect.size = SVector2(spriteSrcRect.size.x, spriteSrcRect.size.y);
		cmd->updateSrcRect(spriteSrcRect);
		cmd->updateRect(myRect);
	}
};