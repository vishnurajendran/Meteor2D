#pragma once
#include <meteorutils/logging.h>
#include <entities/spatial.h>
#include <2d/texture.h>
#include <2d/texrendercmd.h>

class Sprite2D : public SpatialEntity {
public:
	Sprite2D(Texture* texture, RenderLayer layer, uint8_t sortingOrder);
	void onUpdate(float deltaTime) override;
	void onExit() override;
private:
	Vector2 texSize;
	Texture* texture = NULL;
	TexRenderCmd* cmd = NULL;
};