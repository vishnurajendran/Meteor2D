#pragma once
#include <SDL.h>
#include <meteorutils/rect.h>
#include <2d/texture.h>
#include <rendering/rendercommand.h>

namespace meteor {
	class TexRenderCmd : public RenderCommand {
	public:
		TexRenderCmd(RenderLayer layer, uint8_t sortingOrder);
		inline void bindTexture(Texture* tex) { this->texture = tex; }
		inline void updateRect(Rect rect) { targetRect = rect; }
		inline void updateSrcRect(Rect rect) { this->srcRect = rect; }
		inline void updateScale(Vector2 scale) { this->scale = scale; }
		inline void updatePivot(Vector2 pivot) { this->pivot = pivot; }
		inline void updateRotation(float rotation) { this->rotation = rotation; }
		inline void useSourceRect(bool useSrcRect) { this->useSrcRect = useSrcRect; }
		void render() override;
		bool isValid() override;
	private:
		Texture* texture;
		Rect targetRect;
		Rect srcRect;
		Vector2 scale;
		Vector2 pivot;
		float rotation;
		bool useSrcRect;
	};
}