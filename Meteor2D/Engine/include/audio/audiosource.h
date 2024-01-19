#pragma once
#include <audio/audioplayable.h>
#include <entities/spatial.h>

namespace meteor {
	/**
	 * @brief This class represents an audio source in the game world.
	*/
	class AudioSource : public SpatialEntity {
	public:
		/**
		 * @brief Construnctor
		 * @param clipPath path to clip
		 * @param loop loop status of the clip
		 * @param autoStart start playing automatically
		*/
		AudioSource(std::string clipPath, bool loop,bool autoStart);
		void onExit() override;
		/**
		 * @brief Plays audio clip
		*/
		void play();
		/**
		 * @return get playback pause status. 
		*/
		bool isPaused();
		/**
		 * @brief Pause playback.
		*/
		void pause();
		/**
		 * @brief Pause playback and reset to the begining.
		*/
		void stop();
		/**
		 * @return Loop status of playback. 
		*/
		bool isLooped();
		/**
		 * @brief Set playback loop status.
		 * @param Loop new loop status boolean.
		*/
		void setIsLooped(bool loop);
		/**
		 * @return Current playback volume level. 
		*/
		float getVolume();
		/**
		 * @brief Set volume level of playback.
		 * @param volume value between 0 and 1.
		*/
		void setVolume(float volume);
		/**
		 * @return Playback speed. 
		*/
		float getPlaybackSpeed();
		/**
		 * @brief Set playback speed.
		 * @param playbackSpeed new playback speed value.
		*/
		void setPlaybackSpeed(float playbackSpeed);
	private:
		AudioPlayable* playable = NULL;
	};
}
