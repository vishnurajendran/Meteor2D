#pragma once
#include <string>
#include <rendering/renderqueue.h>

namespace meteor {
	/**
	 * @brief Application acts as the entry-point to the game.
	*/
	class Application {
	public:
		/**
		 * @brief Gets name of application.
		 * @return Name of application as string.
		*/
		virtual std::string getName() = 0;
		/**
		 * @brief Invoked when application starts
		*/
		virtual void onStart() = 0;
		/**
		 * @brief Invoked once per frame.
		 * @param deltaTime time difference last and last-to-last frame.
		*/
		virtual void onUpdate(float deltaTime) = 0;
		/**
		 * @brief Invoked when application quits.
		*/
		virtual void onQuit() = 0;
		/**
		 * @return true if application has exited. 
		*/
		inline bool hasQuit() { return quitApplication; }
		/**
		 * @brief Quits the application.
		*/
		inline void quit() { this->quitApplication = true; }
	private:
		RenderQueue* renderQueue;
		bool quitApplication;
	};
}