#include<meteorutils/time.h>

uint64_t Time::timeNow = SDL_GetPerformanceCounter();
uint64_t Time::timeLast = 0;
double Time::deltaTime = 0;

void Time::updateTime() {
	timeLast = timeNow;
	timeNow = SDL_GetPerformanceCounter();
	deltaTime = ((double)((timeNow - timeLast) * 1000 / (double)SDL_GetPerformanceFrequency())) * 0.001f;
}