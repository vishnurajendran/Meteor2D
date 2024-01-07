#pragma once
#include <SDL.h>

namespace meteor {
	/**
	 * @brief This class handles time function.
	*/
	class Time {
	public:
		/**
		 * @brief updates internal timer
		*/
		static void updateTime();

		/**
		 * @brief returns the time between last and last-to-last frame.
		*/
		static double getDeltaTime() { return deltaTime; }

		static int getFrameTime() {
			return SDL_GetTicks() - currFrameTime;
		}
	private:
		static uint64_t timeNow;
		static uint64_t timeLast;
		static double deltaTime;

		static uint64_t currFrameTime;
	};

}