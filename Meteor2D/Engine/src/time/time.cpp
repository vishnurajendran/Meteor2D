#include<meteorutils/time.h>

namespace meteor {
	uint64_t Time::timeNow = SDL_GetPerformanceCounter();
	uint64_t Time::currFrameTime = 0;
	uint64_t Time::timeLast = 0;
	double Time::deltaTime = 0;
	float Time::timeScale = 1;

	void Time::updateTime() {
		currFrameTime = SDL_GetTicks();
		timeLast = timeNow;
		timeNow = SDL_GetPerformanceCounter();
		deltaTime = ((double)((timeNow - timeLast) * 1000 / (double)SDL_GetPerformanceFrequency())) * 0.001f * timeScale;
	}
}