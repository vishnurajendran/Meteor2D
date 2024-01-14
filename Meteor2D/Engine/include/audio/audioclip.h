#pragma once
#include <irrKlang.h>
#include <entities/entity.h>
#include <audio/audioplayable.h>

namespace meteor {

#ifndef AUDIOCLIP_H
#define AUDIOCLIP_H
	class AudioPlayable;
	class AudioClip : Entity {
	public:
		AudioClip(irrklang::ISoundEngine* engine, std::string clipPath);
		~AudioClip();
		AudioPlayable* createPlayableInstance();
		std::string toString() override;
	private:
		std::string getPlayableInstanceId();

		irrklang::ISoundEngine* engine = NULL;
		irrklang::ISoundSource* baseSrc = NULL;
		std::string clipPath = "";
		bool isReady = false;
		int instanceIdCounter = 0;
	};
#endif;
}
