#pragma once
#include <meteorutils/logging.h>
#include <audio/audioengine.h>

namespace meteor {

	irrklang::ISoundEngine* MAudioEngine::engine = NULL;

	bool MAudioEngine::Initialise() {
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

	void MAudioEngine::cleanup() {
		if(engine)
			engine->drop();
		engine = NULL;
	}

	MAudioClip* MAudioEngine::getClip(std::string clipPath) {
		if (engine == NULL)
			return NULL;
		MAudioClip* clip = new MAudioClip(engine, clipPath);
		return clip;
	}
}