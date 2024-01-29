#pragma once
#include <meteorutils/logging.h>
#include <audio/audioplayable.h>

namespace meteor {

	MAudioPlayable::MAudioPlayable(irrklang::ISoundEngine* engine, irrklang::ISoundSource* soundSrc) {
		this->soundSrc = soundSrc;
		this->engine = engine;
	}

	MAudioPlayable::~MAudioPlayable() {
		if (playableRef) {
			pause();
			playableRef->drop();
		}

		if (soundSrc)
			soundSrc->drop();
	}

	void MAudioPlayable::prepare() {
		playableRef = engine->play2D(soundSrc, false, true, true, false);
		if (!playableRef) {
			mError("Preparing playable failed!");
			currState = EAudioPlayableState::PLAYABLE_ERR;
			return;
		}

		currState = EAudioPlayableState::PLAYABLE_STOPPED;
	}

	void MAudioPlayable::play() {
		if (!playableRef)
			return;

		currState = EAudioPlayableState::PLAYABLE_PLAYING;
		playableRef->setIsPaused(false);
	}

	void MAudioPlayable::pause() {
		if (!playableRef)
			return;

		currState = EAudioPlayableState::PLAYABLE_STOPPED;
		playableRef->setIsPaused(true);
	}

	void MAudioPlayable::reset() {
		if (!playableRef)
			return;
		playableRef->setPlayPosition(0);
	}

	bool MAudioPlayable::isLooped() {
		if (!playableRef)
			return false;
		return playableRef->isLooped();
	}

	void MAudioPlayable::setIsLooped(bool loop) {
		if (!playableRef)
			return;
		playableRef->setIsLooped(loop);
	}

	void MAudioPlayable::setVolume(float volume) {
		if (!soundSrc)
			return;
		volume = (volume < 0 ? 0 : ((volume > 1) ? 1 : volume));
		playableRef->setVolume(volume);
	}

	float MAudioPlayable::getVolume() {
		if (!soundSrc)
			return -1;
		return playableRef->getVolume();
	}

	long MAudioPlayable::getLength() {
		if (!soundSrc)
			return -1;
		return soundSrc->getPlayLength();
	}

	bool MAudioPlayable::isPaused() {
		if (!playableRef)
			return false;
		playableRef->getIsPaused();
	}

	float MAudioPlayable::getPlaybackSpeed() {
		if (!playableRef)
			return 0;
		
		return playableRef->getPlaybackSpeed();
	}

	void MAudioPlayable::setPlaybackSpeed(float playbackSpeed) {
		if (!playableRef)
			return;
		playableRef->setPlaybackSpeed(playbackSpeed);
	}
}