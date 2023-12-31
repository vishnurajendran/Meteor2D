#pragma once
#include <meteorutils/logging.h>
#include <entities/spatial.h>
#include <2d/texture.h>
#include <2d/texrendercmd.h>

namespace meteor {
	class Sprite2D : public SpatialEntity {
	public:
		Sprite2D(Texture* texture, RenderLayer layer, uint8_t sortingOrder);
		void onUpdate(float deltaTime) override;
		void onExit() override;
		void setPivot(Vector2 normVal) { pivot = normVal; };
		inline Vector2 getPivot() { return pivot; }
	private:
		Vector2 texSize;
		Vector2 pivot;
		Texture* texture = NULL;
		TexRenderCmd* cmd = NULL;
	};
}