#pragma once
#include <irrKlang.h>
#include <entities/entity.h>
#include <audio/audioplaystate.h>

namespace meteor {
#ifndef AUDIOPLAYABLE_H
#define AUDIOPLAYABLE_H
	class MAudioClip;
	/**
	 * @brief This class is the Playable instance of AudioClip.
	 * Provides various playback functions.
	*/
	class MAudioPlayable : MEntity {
	public:
		~MAudioPlayable();
		/**
		 * @brief Get length of the clip in milliseconds.
		 * @return long representing the length of the clip.
		*/
		long getLength();
		/**
		 * @brief Prepares the instance for playback, needed before playaback can be done.
		*/
		void prepare();
		/**
		 * @brief Plays the audio clip.
		*/
		void play();
		/**
		 * @brief Pauses audio playback.
		*/
		void pause();
		/**
		 * @brief Resets current position in playback to the begining of the clip.
		*/
		void reset();
		/**
		 * @return true if playback is looped. 
		*/
		bool isLooped();
		/**
		 * @brief Set loop status of the playback.
		 * @param loop bool representating new loop status of playback.
		*/
		void setIsLooped(bool loop);
		/**
		 * @return Volume of playback between 0 and 1 
		*/
		float getVolume();
		/**
		 * @brief Set volume level of the playback.
		 * @param volume float between 0 and 1, representating new volume level.
		*/
		void setVolume(float volume);
		/**
		 * @return true if playaback is paused. 
		*/
		bool isPaused();
		/**
		 * @return speed of playback. 
		*/
		float getPlaybackSpeed();
		/**
		 * @brief Set playback speed.
		 * @param val new playback speed.
		*/
		void setPlaybackSpeed(float val);
	private:
		/**
		 * @brief Constructor for initialisation.
		 * @param engine core audio engine.
		 * @param soundSrc core audio source.
		*/
		MAudioPlayable(irrklang::ISoundEngine* engine, irrklang::ISoundSource* soundSrc);
		
		irrklang::ISound* playableRef=NULL;
		irrklang::ISoundSource* soundSrc=NULL;
		irrklang::ISoundEngine* engine=NULL;
		EAudioPlayableState currState = EAudioPlayableState::PLAYABLE_INIT;

		friend class MAudioClip;
	};
#endif
}
