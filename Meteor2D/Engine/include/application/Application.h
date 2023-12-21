#pragma once
#include <string>
#include <rendering/renderqueue.h>
class Application {
public:
	virtual std::string getName()=0;
	virtual void onStart()=0;
	virtual void onUpdate(float deltaTime)=0;
	virtual void onQuit()=0;
private:
	RenderQueue* renderQueue;
};