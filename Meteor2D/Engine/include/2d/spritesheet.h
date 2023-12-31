#pragma once
#include <meteorutils/rect.h>
#include <2d/texture.h>

namespace meteor {
	class SpriteSheet {
	public:
		SpriteSheet(std::string texturePath, std::vector<Rect> rects);
		Texture* getTexture();
		Rect getNext(bool loop);
		void reset();
	private:
		Texture* spriteTex;
		std::vector<Rect> spriteRects;
		int index=0;
	};
}
