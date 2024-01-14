#pragma once
#include <meteorutils/logging.h>
#include <audio/audioengine.h>

namespace meteor {

	irrklang::ISoundEngine* AudioEngine::engine = NULL;

	bool AudioEngine::Initialise() {
		if (engine != NULL)
		{
			mWarn("Audio Core is already intialised");
			return false;
		}

		engine = irrklang::createIrrKlangDevice();
		engine->grab();
		if (!engine) {
			mError("Audio Core failed to initialise");
			return false;
		}
		
		mLog("Audio Core initialised");
		return true;
	}

	void AudioEngine::cleanup() {
		if(engine)
			engine->drop();
		engine = NULL;
	}

	AudioClip* AudioEngine::getClip(std::string clipPath) {
		AudioClip* clip = new AudioClip(engine, clipPath);
		return clip;
	}
}