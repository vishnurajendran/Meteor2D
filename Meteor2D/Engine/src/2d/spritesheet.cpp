#pragma once
#include <assetmanagement/assetmanager.h>
#include <2d/spritesheet.h>
#include <algorithm>

namespace meteor {

	SpriteSheet::SpriteSheet(std::string tex, std::vector<Rect> rects) {
		this->spriteTex = AssetManager::getInstance()->getTexture(tex);
		this->spriteRects = rects;
	}

	Texture* SpriteSheet::getTexture() {
		return spriteTex;
	}

	Rect SpriteSheet::sample(int& index, bool looping) {
		index = std::clamp(index,0, (int)spriteRects.size() - 1);
		Rect rectToUse = spriteRects[index];
		if (looping) {
			index = (index + 1) % spriteRects.size();
		}
		else
			index = std::clamp(index + 1, 0, (int)spriteRects.size() - 1);

		return spriteRects[index];
	}

}