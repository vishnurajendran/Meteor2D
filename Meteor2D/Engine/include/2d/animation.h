#pragma once
#include <string>
#include <entities/spatial.h>
#include <2d/animationmap.h>
#include <2d/spritesheet.h>
#include <2d/texrendercmd.h>

namespace meteor {
	/**
	 * @brief Animation entity provides sprite - sheet based animation system to meteor
	*/
	class Animation : public SpatialEntity {
	public:
		/**
		 * @brief Constructor for Animation
		 * @param mapFile relative path to the .anim file, will evaluate to resS\anim\<mapFile>
		 * @param fps the frame-rate of the animation playback.
		 * @param layer layer for rendering
		 * @param sortingOrder sorting order in render layer.
		*/
		Animation(std::string mapFile, int fps, RenderLayer layer, uint8_t sortingOrder);
		void onUpdate(float deltaTime) override;

		/**
		 * @brief set the frame-rate of the fps playback
		 * @param fps 
		*/
		void setFPS(int fps);
		/**
		 * @brief Plays a specific animation
		 * @param name animation clip name
		 * @param looped set to true if the animation needs to be looping
		*/
		void play(std::string name, bool looped);
		/**
		 * @brief Resumes a stopped animation.
		*/
		void resume();
		/**
		 * @brief Stops animation playback.
		*/
		void stop();
	private:
		std::string currAnim;
		int index = 0;
		bool isPlaying = false;
		bool isLooping = false;
		bool renderOnce = true;
		bool changeRequested=false;
		int fps=30;
		float animTime;
		AnimationMap* animationMap;
		SpriteSheet* currAnimSheet;
		TexRenderCmd* cmd;
		Vector2 pivot;
		Rect spriteSrcRect;
		void tryChangeAnimParams();
		void updateAnimation(float deltaTime);
		void submitFrameRenderRequest();
		void updateRect();
	};
}
