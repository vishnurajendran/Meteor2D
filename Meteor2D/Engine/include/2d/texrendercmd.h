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
		inline void updateScale(Vector2 scale) { this->scale = scale; }
		void render() override;
		bool isValid() override;
	private:
		Texture* texture;
		Rect targetRect;
		Vector2 scale;
	};
}