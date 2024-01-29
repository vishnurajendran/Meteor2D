#include<meteorutils/time.h>

namespace meteor {
	uint64_t MTime::timeNow = SDL_GetPerformanceCounter();
	uint64_t MTime::currFrameTime = 0;
	uint64_t MTime::timeLast = 0;
	double MTime::deltaTime = 0;
	float MTime::timeScale = 1;

	void MTime::updateTime() {
		currFrameTime = SDL_GetTicks();
		timeLast = timeNow;
		timeNow = SDL_GetPerformanceCounter();
		deltaTime = ((double)((timeNow - timeLast) * 1000 / (double)SDL_GetPerformanceFrequency())) * 0.001f * timeScale;
	}
}