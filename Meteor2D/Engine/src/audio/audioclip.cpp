#pragma once
#include <meteorutils/logging.h>
#include <audio/audioclip.h>

namespace meteor {

	std::string MAudioClip::toString() {
		return "AudioClip ( " + clipPath + " )";
	}

	MAudioClip::MAudioClip(irrklang::ISoundEngine* engine, std::string clipPath) {
		this->clipPath = clipPath;
		this->engine = engine;
		this->baseSrc = engine->addSoundSourceFromFile(clipPath.c_str());
		if (!this->baseSrc) {
			mError("Could not load clip");
			return;
		}
		isReady = true;
	}

	MAudioClip::~MAudioClip() {
		if (!isReady)
			return;
		if(baseSrc)
			baseSrc->drop();

		baseSrc = NULL;
		engine = NULL;
	}

	MAudioPlayable* MAudioClip::createPlayableInstance() {
		if (!isReady)
			return NULL;
		
		irrklang::ISoundSource* srcAlias = engine->addSoundSourceAlias(baseSrc, getPlayableInstanceId().c_str());
		if (!srcAlias) {
			mError("Could not create a playable for AudioClip {}", clipPath);
			return NULL;
		}
		MAudioPlayable* playable = new MAudioPlayable(engine, srcAlias);
		return playable;
	}

	std::string MAudioClip::getPlayableInstanceId() {
		return  "Playable_" + std::to_string((int)baseSrc) + "_" + std::to_string(instanceIdCounter++);
	}
}