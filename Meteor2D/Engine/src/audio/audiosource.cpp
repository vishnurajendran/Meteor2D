#pragma once
#include <meteorutils/logging.h>
#include <scenemanagement/scenemanager.h>
#include <assetmanagement/assetmanager.h>
#include <audio/audiosource.h>

namespace meteor {
	MAudioSource::MAudioSource(std::string clipPath, bool loop = false, bool autoStart = true) {
		auto clip = MAssetManager::getInstance()->getAudioClip(clipPath);
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

	void MAudioSource::onExit() {
		if (playable == NULL) {
			return;
		}

		delete playable;
	}

	void MAudioSource::play() {
		if (playable == NULL)
			return;
		playable->play();
	}

	void MAudioSource::pause() {
		if (playable == NULL)
			return;
		playable->pause();
	}

	void MAudioSource::stop() {
		if (playable == NULL)
			return;
		playable->pause();
		playable->reset();
	}

	bool MAudioSource::isPaused() {
		if (playable == NULL)
			return false;
		return playable->isPaused();
	}

	bool MAudioSource::isLooped() {
		if (playable == NULL)
			return false;
		return playable->isLooped();
	}

	void MAudioSource::setIsLooped(bool loop) {
		if (playable == NULL)
			return;
		playable->setIsLooped(loop);
	}

	float MAudioSource::getVolume() {
		if (playable == NULL)
			return -1;
		return playable->getVolume();
	}

	void MAudioSource::setVolume(float volume) {
		if (playable == NULL)
			return;
		playable->setVolume(volume);
	}

	float MAudioSource::getPlaybackSpeed() {
		if (playable == NULL)
			return 0;
		return playable->getPlaybackSpeed();
	}

	void MAudioSource::setPlaybackSpeed(float playbackSpeed) {
		if (playable == NULL)
			return;
		playable->setPlaybackSpeed(playbackSpeed);
	}
}