#pragma once
#include <meteorutils/logging.h>
#include <entities/spatial.h>
#include <2d/texture.h>
#include <2d/texrendercmd.h>

namespace meteor {
	/**
	 * @brief This entity enables sprite rendering in meteor
	*/
	class Sprite2D : public SpatialEntity {
	public:
		/**
		 * @brief constructor
		 * @param texPath Path to sprite image, relative path evaulated to resS\img\texPath
		 * @param layer Rendering layer
		 * @param sortingOrder Sorting order within the layer
		*/
		Sprite2D(std::string texPath, RenderLayer layer, uint8_t sortingOrder);
		/**
		 * @brief constructor
		 * @param texture Texture reference for sprite
		 * @param layer Rendering layer
		 * @param sortingOrder Sorting order within the layer
		*/
		Sprite2D(Texture* texture, RenderLayer layer, uint8_t sortingOrder);
		void onUpdate(float deltaTime) override;
		void onExit() override;
		/**
		 * @brief Set the pivot of the sprite
		 * @param normVal Normalised vector2
		*/
		void setPivot(Vector2 normVal) { pivot = normVal; };
		/**
		 * @brief Get the pivot of the sprite
		 * @return Normalised Vector2
		*/
		inline Vector2 getPivot() { return pivot; }
	private:
		Vector2 texSize;
		Vector2 pivot;
		Texture* texture = NULL;
		TexRenderCmd* cmd = NULL;
	};
}