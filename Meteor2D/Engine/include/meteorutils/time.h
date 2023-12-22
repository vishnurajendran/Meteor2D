#pragma once
#include <SDL.h>

namespace meteor {

	class Time {
	public:
		/// <summary>
		/// updates the internal time keeper.
		/// </summary>
		static void updateTime();

		/// <summary>
		/// returns the time between this frame and the frame before.
		/// in seconds
		/// </summary>
		/// <returns></returns>
		static inline double getDeltaTime() { return deltaTime; }
	private:
		static uint64_t timeNow;
		static uint64_t timeLast;
		static double deltaTime;
	};

}