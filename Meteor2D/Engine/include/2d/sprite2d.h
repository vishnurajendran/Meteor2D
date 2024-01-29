#pragma once
#include <meteorutils/logging.h>
#include <entities/spatial.h>
#include <2d/texture.h>
#include <2d/texrendercmd.h>

namespace meteor {
	/**
	 * @brief This entity enables sprite rendering in meteor
	*/
	class MSprite2D : public MSpatialEntity {
	public:
		/**
		 * @brief constructor
		 * @param texPath Path to sprite image, relative path evaulated to resS\img\texPath
		 * @param layer Rendering layer
		 * @param sortingOrder Sorting order within the layer
		*/
		MSprite2D(std::string texPath, ERenderLayer layer, uint8_t sortingOrder);
		/**
		 * @brief constructor
		 * @param texture Texture reference for sprite
		 * @param layer Rendering layer
		 * @param sortingOrder Sorting order within the layer
		*/
		MSprite2D(MTexture* texture, ERenderLayer layer, uint8_t sortingOrder);
		void onUpdate(float deltaTime) override;
		void onExit() override;
		/**
		 * @brief Set the pivot of the sprite
		 * @param normVal Normalised vector2
		*/
		void setPivot(SVector2 normVal) { pivot = normVal; };
		/**
		 * @brief Get the pivot of the sprite
		 * @return Normalised Vector2
		*/
		inline SVector2 getPivot() { return pivot; }
	private:
		SVector2 texSize;
		SVector2 pivot;
		MTexture* texture = NULL;
		MTexRenderCmd* cmd = NULL;
	};
}