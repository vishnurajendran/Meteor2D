#pragma once
#include <meteorutils/rect.h>
#include <2d/texture.h>

namespace meteor {
	/**
	 * @brief This class holds the Rects within a texture that form an Animation
	*/
	class MSpriteSheet : public MEntity {
	public:
		/**
		 * @brief Constructor
		 * @param texturePath Path to texture.
		 * @param rects List of rects that form the animation.
		*/
		MSpriteSheet(std::string texturePath, std::vector<SRect> rects);
		/**
		 * @brief Gets the Texture for this sprite-sheet.
		 * @return Ptr to Texture instance
		*/
		MTexture* getTexture();
		/**
		 * @brief Sample the sprite-sheet for a animation frame rect
		 * @param index integer directly mapping to frame number.
		 * @param loop boolean flag to loop over the frames.
		 * @return Rect for a specific animation frame.
		*/
		SRect sample(int& index, bool loop);
	private:
		MTexture* spriteTex;
		std::vector<SRect> spriteRects;
	};
}
