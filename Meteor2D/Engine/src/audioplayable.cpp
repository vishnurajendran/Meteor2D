#pragma once
#include <meteorutils/logging.h>
#include <audio/audioplayable.h>

namespace meteor {

	AudioPlayable::AudioPlayable(irrklang::ISoundEngine* engine, irrklang::ISoundSource* soundSrc) {
		this->soundSrc = soundSrc;
		this->engine = engine;
	}

	AudioPlayable::~AudioPlayable() {
		if (playableRef) {
			pause();
			playableRef->drop();
		}

		if (soundSrc)
			soundSrc->drop();
	}

	void AudioPlayable::prepare() {
		playableRef = engine->play2D(soundSrc, false, true, true, false);
		if (!playableRef) {
			mError("Preparing playable failed!");
			currState = AudioPlayableState::PLAYABLE_ERR;
			return;
		}

		currState = AudioPlayableState::PLAYABLE_STOPPED;
	}

	void AudioPlayable::play() {
		if (!playableRef)
			return;

		currState = AudioPlayableState::PLAYABLE_PLAYING;
		playableRef->setIsPaused(false);
	}

	void AudioPlayable::pause() {
		if (!playableRef)
			return;

		currState = AudioPlayableState::PLAYABLE_STOPPED;
		playableRef->setIsPaused(true);
	}

	void AudioPlayable::reset() {
		if (!playableRef)
			return;
		playableRef->setPlayPosition(0);
	}

	bool AudioPlayable::isLooped() {
		if (!playableRef)
			return false;
		return playableRef->isLooped();
	}

	void AudioPlayable::setIsLooped(bool loop) {
		if (!playableRef)
			return;
		playableRef->setIsLooped(loop);
	}

	void AudioPlayable::setVolume(float volume) {
		if (!soundSrc)
			return;
		volume = (volume < 0 ? 0 : ((volume > 1) ? 1 : volume));
		soundSrc->setDefaultVolume(volume);
	}

	float AudioPlayable::getVolume() {
		if (!soundSrc)
			return -1;
		return soundSrc->getDefaultVolume();
	}

	long AudioPlayable::getLength() {
		if (!soundSrc)
			return -1;
		return soundSrc->getPlayLength();
	}

	bool AudioPlayable::isPaused() {
		if (!playableRef)
			return false;
		playableRef->getIsPaused();
	}

	float AudioPlayable::getPlaybackSpeed() {
		if (!playableRef)
			return 0;
		
		return playableRef->getPlaybackSpeed();
	}

	void AudioPlayable::setPlaybackSpeed(float playbackSpeed) {
		if (!playableRef)
			return;
		playableRef->setPlaybackSpeed(playbackSpeed);
	}
}