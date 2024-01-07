#pragma once
#include <string>
#include <rendering/renderqueue.h>

namespace meteor {
	class Application {
	public:
		virtual std::string getName() = 0;
		virtual void onStart() = 0;
		virtual void onUpdate(float deltaTime) = 0;
		virtual void onQuit() = 0;
		
		inline bool hasQuit() { return quitApplication; }
		inline void quit() { this->quitApplication = true; }
	private:
		RenderQueue* renderQueue;
		bool quitApplication;
	};
}