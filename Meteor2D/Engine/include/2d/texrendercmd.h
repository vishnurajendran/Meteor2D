#pragma once
#include <SDL.h>
#include <meteorutils/rect.h>
#include <2d/texture.h>
#include <rendering/rendercommand.h>

namespace meteor {
	/**
	 * @brief This a RenderCommand that draws an image on to the screen
	*/
	class MTexRenderCmd : public MRenderCommand {
	public:
		/**
		 * @brief Constructor.
		 * @param layer layer for rendering
		 * @param sortingOrder sorting order within the layer
		*/
		MTexRenderCmd(ERenderLayer layer, uint8_t sortingOrder);
		/**
		 * @brief Bind a texture to draw.
		 * @param tex Texture reference
		*/
		void bindTexture(MTexture* tex);
		/**
		 * @brief Update the Rect for rendering.
		*/
		inline void updateRect(SRect rect) { targetRect = rect; }
		/**
		 * @brief Update the Rect for image. 
			Src Rect is the rect used for rendering specific parts of the texture
		 * @param rect Src Rect.
		*/
		inline void updateSrcRect(SRect rect) { this->srcRect = rect; }
		/**
		 * @brief Update the scale of image during render
		 * @param scale Vector2 defining scale
		*/
		inline void updateScale(SVector2 scale) { this->scale = scale; }
		/**
		 * @brief Update the pivot of image during render
		 * @param pivot Normalized Vector2 defining pivot
		*/
		inline void updatePivot(SVector2 pivot) { this->pivot = pivot; }
		/**
		 * @brief Update rotation of the img during render
		 * @param rotation 
		*/
		inline void updateRotation(float rotation) { this->rotation = rotation; }
		/**
		 * @brief Set to true if a part of the texture needs to be rendererd.
		 * @param useSrcRect 
		*/
		inline void useSourceRect(bool useSrcRect) { this->useSrcRect = useSrcRect; }
		/**
		 * @brief Renders the image to screen.
		*/
		void render() override;
		/**
		 * @return true if rendercommand is valid. 
		*/
		bool isValid() override;
	private:
		MTexture* textureTempBuffer = NULL;
		MTexture* texture;
		SRect targetRect;
		SRect srcRect;
		SVector2 scale;
		SVector2 pivot;
		float rotation;
		bool useSrcRect;
		bool lockedForRender;

		void swap();
	};
}