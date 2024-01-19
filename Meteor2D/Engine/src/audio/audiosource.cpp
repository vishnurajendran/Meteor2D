#pragma once
#include <meteorutils/logging.h>
#include <scenemanagement/scenemanager.h>
#include <assetmanagement/assetmanager.h>
#include <audio/audiosource.h>

namespace meteor {
	AudioSource::AudioSource(std::string clipPath, bool loop = false, bool autoStart = true) {
		auto clip = AssetManager::getInstance()->getAudioClip(clipPath);
		if (clip == NULL)
		{
			mError("Audio source could not resolve, {} to a clip", clipPath);
			return;
		}
		playable = clip->createPlayableInstance();
		playable->prepare();
		setIsLooped(loop);
		if (autoStart)
			play();
	}

	void AudioSource::onExit() {
		if (playable == NULL) {
			return;
		}

		delete playable;
	}

	void AudioSource::play() {
		if (playable == NULL)
			return;
		playable->play();
	}

	void AudioSource::pause() {
		if (playable == NULL)
			return;
		playable->pause();
	}

	void AudioSource::stop() {
		if (playable == NULL)
			return;
		playable->pause();
		playable->reset();
	}

	bool AudioSource::isPaused() {
		if (playable == NULL)
			return false;
		return playable->isPaused();
	}

	bool AudioSource::isLooped() {
		if (playable == NULL)
			return false;
		return playable->isLooped();
	}

	void AudioSource::setIsLooped(bool loop) {
		if (playable == NULL)
			return;
		playable->setIsLooped(loop);
	}

	float AudioSource::getVolume() {
		if (playable == NULL)
			return -1;
		return playable->getVolume();
	}

	void AudioSource::setVolume(float volume) {
		if (playable == NULL)
			return;
		playable->setVolume(volume);
	}

	float AudioSource::getPlaybackSpeed() {
		if (playable == NULL)
			return 0;
		return playable->getPlaybackSpeed();
	}

	void AudioSource::setPlaybackSpeed(float playbackSpeed) {
		if (playable == NULL)
			return;
		playable->setPlaybackSpeed(playbackSpeed);
	}
}