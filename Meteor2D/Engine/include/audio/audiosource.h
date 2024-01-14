#pragma once
#include <audio/audioplayable.h>
#include <entities/spatial.h>

namespace meteor {
	class AudioSource : public SpatialEntity {
	public:
		AudioSource(std::string clipPath, bool loop,bool autoStart);
		void onExit() override;
		void play();
		bool isPaused();
		void pause();
		void stop();
		bool isLooped();
		void setIsLooped(bool loop);
		float getVolume();
		void setVolume(float volume);
		float getPlaybackSpeed();
		void setPlaybackSpeed(float playbackSpeed);
	private:
		AudioPlayable* playable = NULL;
	};
}
