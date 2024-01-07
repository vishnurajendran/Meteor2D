#pragma once
#include <meteorutils/rect.h>
#include <2d/texture.h>

namespace meteor {
	/**
	 * @brief This class holds the Rects within a texture that form an Animation
	*/
	class SpriteSheet {
	public:
		/**
		 * @brief Constructor
		 * @param texturePath Path to texture.
		 * @param rects List of rects that form the animation.
		*/
		SpriteSheet(std::string texturePath, std::vector<Rect> rects);
		/**
		 * @brief Gets the Texture for this sprite-sheet.
		 * @return Ptr to Texture instance
		*/
		Texture* getTexture();
		/**
		 * @brief Sample the sprite-sheet for a animation frame rect
		 * @param index integer directly mapping to frame number.
		 * @param loop boolean flag to loop over the frames.
		 * @return Rect for a specific animation frame.
		*/
		Rect sample(int& index, bool loop);
	private:
		Texture* spriteTex;
		std::vector<Rect> spriteRects;
	};
}
