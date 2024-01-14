#pragma once
#include <irrKlang.h>
#include <entities/entity.h>
#include <audio/audioplaystate.h>

namespace meteor {
#ifndef AUDIOPLAYABLE_H
#define AUDIOPLAYABLE_H
	class AudioClip;
	class AudioPlayable : Entity {
	public:
		~AudioPlayable();
		long getLength();
		void prepare();
		void play();
		void pause();
		void reset();
		bool isLooped();
		void setIsLooped(bool loop);
		float getVolume();
		void setVolume(float volume);
		bool isPaused();
		float getPlaybackSpeed();
		void setPlaybackSpeed(float val);
	private:
		AudioPlayable(irrklang::ISoundEngine* engine, irrklang::ISoundSource* soundSrc);
		
		irrklang::ISound* playableRef=NULL;
		irrklang::ISoundSource* soundSrc=NULL;
		irrklang::ISoundEngine* engine=NULL;
		AudioPlayableState currState = AudioPlayableState::PLAYABLE_INIT;

		friend class AudioClip;
	};
#endif
}
