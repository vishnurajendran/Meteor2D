#pragma once
#include <entities/entity.h>
#include <SDL.h>

namespace meteor {
	/**
	 * @brief This class handles time function.
	*/
	class MTime : public MEntity {
	public:
		/**
		 * @brief updates internal timer
		*/
		static void updateTime();

		/**
		 * @brief returns the time between last and last-to-last frame.
		*/
		static double getDeltaTime() { return deltaTime; }

		/**
		 * @return current frame time 
		*/
		static int getFrameTime() {
			return SDL_GetTicks() - currFrameTime;
		}

		/**
		 * @return time scale
		*/
		static float getTimeScale() { return timeScale; }

		/**
		 * @brief set time scale.
		 * @param val 
		*/
		static void setTimeScale(float val) { timeScale = val; }

	private:
		static uint64_t timeNow;
		static uint64_t timeLast;
		static double deltaTime;
		static float timeScale;
		static uint64_t currFrameTime;
	};

}