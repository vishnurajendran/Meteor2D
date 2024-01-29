#pragma once
#include <irrKlang.h>
#include <entities/entity.h>
#include <audio/audioplayable.h>

namespace meteor {

#ifndef AUDIOCLIP_H
#define AUDIOCLIP_H
	class MAudioPlayable;
	/**
	 * @brief AudioClip is the instance of a audio clip file, this class holds.
	 * This class holds basic information of the clip, and has methods to create playable
	 * instances.
	*/
	class MAudioClip : MEntity {
	public:
		/**
		 * @brief Constructor
		 * @param engine core audio engine instance.
		 * @param clipPath path to the clip in disk.
		*/
		MAudioClip(irrklang::ISoundEngine* engine, std::string clipPath);
		~MAudioClip();
		/**
		 * @brief Creates a playable instance of this clip, which can be used to
		 * play audio.
		 * @return AudioPlayable instance.
		*/
		MAudioPlayable* createPlayableInstance();
		std::string toString() override;
	private:
		/**
		 * @brief Creates a unique id for each playable instance.
		 * @return Id as a string.
		*/
		std::string getPlayableInstanceId();

		irrklang::ISoundEngine* engine = NULL;
		irrklang::ISoundSource* baseSrc = NULL;
		std::string clipPath = "";
		bool isReady = false;
		int instanceIdCounter = 0;
	};
#endif;
}
