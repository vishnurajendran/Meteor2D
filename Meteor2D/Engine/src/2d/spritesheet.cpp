#pragma once
#include <assetmanagement/assetmanager.h>
#include <2d/spritesheet.h>
#include <algorithm>

namespace meteor {

	MSpriteSheet::MSpriteSheet(std::string tex, std::vector<SRect> rects) {
		this->spriteTex = MAssetManager::getInstance()->getTexture(tex);
		this->spriteRects = rects;
	}

	MTexture* MSpriteSheet::getTexture() {
		return spriteTex;
	}

	SRect MSpriteSheet::sample(int& index, bool looping) {
		index = std::clamp(index,0, (int)spriteRects.size() - 1);
		SRect rectToUse = spriteRects[index];
		if (looping) {
			index = (index + 1) % spriteRects.size();
		}
		else
			index = std::clamp(index + 1, 0, (int)spriteRects.size() - 1);

		return spriteRects[index];
	}

}