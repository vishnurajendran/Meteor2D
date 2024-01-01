#pragma once
#include <string>
#include <entities/spatial.h>
#include <2d/animationmap.h>
#include <2d/spritesheet.h>
#include <2d/texrendercmd.h>

namespace meteor {
	class Animation : public SpatialEntity {
	public:
		Animation(std::string mapFile, int fps, RenderLayer layer, uint8_t sortingOrder);
		void onUpdate(float deltaTime) override;
		void setFPS(int fps);
		void play(std::string name, bool looped);
		void resume();
		void stop();
	private:
		bool isPlaying = false;
		bool isLooping = false;
		bool renderOnce = true;
		int fps=30;
		float animTime;
		AnimationMap* animationMap;
		SpriteSheet* currAnimSheet;
		TexRenderCmd* cmd;
		Vector2 pivot;
		Rect spriteSrcRect;
		void updateAnimation(float deltaTime);
		void submitFrameRenderRequest();
		void updateRect();
	};
}
