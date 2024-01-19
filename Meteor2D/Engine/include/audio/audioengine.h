#pragma once
#include <string>
#include <irrKlang.h>
#include <audio/audioclip.h>

namespace meteor {
	/**
	 * @brief AudioEngine wraps the core audio-engine.
	 * Contains helper method to load AudioClip from instance.
	*/
	class AudioEngine : public Entity {
	public:
		/**
		 * @brief Initialise the engine.
		 * @return true if successful, else false.
		*/
		static bool Initialise();
		/**
		 * @brief Load a clip from disk
		 * @param clipPath path in disk to audio clip file.
		 * @return AudioClip instance.
		*/
		static AudioClip* getClip(std::string clipPath);
		/**
		 * @brief Performs cleanup of the audio engine.
		*/
		static void cleanup();
	private:
		static irrklang::ISoundEngine* engine;
	};
}