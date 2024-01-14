#pragma once
#include <string>
#include <irrKlang.h>
#include <audio/audioclip.h>

namespace meteor {
	class AudioEngine : public Entity {
	public:
		static bool Initialise();
		static AudioClip* getClip(std::string clipPath);
		static void cleanup();
	private:
		static irrklang::ISoundEngine* engine;
	};
}