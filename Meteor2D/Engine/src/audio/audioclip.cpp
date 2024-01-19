#pragma once
#include <meteorutils/logging.h>
#include <audio/audioclip.h>

namespace meteor {

	std::string AudioClip::toString() {
		return "AudioClip ( " + clipPath + " )";
	}

	AudioClip::AudioClip(irrklang::ISoundEngine* engine, std::string clipPath) {
		this->clipPath = clipPath;
		this->engine = engine;
		this->baseSrc = engine->addSoundSourceFromFile(clipPath.c_str());
		if (!this->baseSrc) {
			mError("Could not load clip");
			return;
		}
		isReady = true;
	}

	AudioClip::~AudioClip() {
		if (!isReady)
			return;
		if(baseSrc)
			baseSrc->drop();

		baseSrc = NULL;
		engine = NULL;
	}

	AudioPlayable* AudioClip::createPlayableInstance() {
		if (!isReady)
			return NULL;
		
		irrklang::ISoundSource* srcAlias = engine->addSoundSourceAlias(baseSrc, getPlayableInstanceId().c_str());
		if (!srcAlias) {
			mError("Could not create a playable for AudioClip {}", clipPath);
			return NULL;
		}
		AudioPlayable* playable = new AudioPlayable(engine, srcAlias);
		return playable;
	}

	std::string AudioClip::getPlayableInstanceId() {
		return  "Playable_" + std::to_string((int)baseSrc) + "_" + std::to_string(instanceIdCounter++);
	}
}