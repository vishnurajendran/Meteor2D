#pragma once
#include <algorithm>
#include <audio/audiosource.h>
#include <sceneserialization/deserializers/audiosourcedeserializer.h>

namespace meteor {

	const bool AudioSourceDeserializer::registered = []() {
		SceneEntityTypeMap::registerDeserializer("audiosource", new AudioSourceDeserializer());
		return true;
	}();

	std::string toLower(std::string str) {
		std::string s = str;
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
		return s;
	}

	SpatialEntity* AudioSourceDeserializer::deserialize(pugi::xml_node* node) {

		if (!node->attribute(AUDIO_SRC.c_str())) {
			return NULL;
		}

		float volume = 1;
		if (node->attribute(AUDIO_VOL.c_str())) {
			volume = std::stof(node->attribute(AUDIO_VOL.c_str()).value());
		}

		float playbackSpeed = 1;
		if (node->attribute(AUDIO_PLAYBACK_SPEED.c_str())) {
			playbackSpeed = std::stof(node->attribute(AUDIO_PLAYBACK_SPEED.c_str()).value());
		}

		bool loop = false;
		if (node->attribute(AUDIO_LOOP.c_str())) {
			auto str = toLower(node->attribute(AUDIO_LOOP.c_str()).value());
			loop = str == "true" ? true : false;
		}

		bool autoPlay = false;
		if (node->attribute(AUDIO_AUTOPLAY.c_str())) {
			auto str = toLower(node->attribute(AUDIO_AUTOPLAY.c_str()).value());
			autoPlay = str == "true" ? true : false;
		}

		auto src = node->attribute(AUDIO_SRC.c_str()).value();
		auto audioSource = new AudioSource(src, loop, autoPlay);
		audioSource->setIsLooped(loop);
		audioSource->setPlaybackSpeed(playbackSpeed);
		audioSource->setVolume(volume);

		parseSpatialData(node, audioSource);
		return audioSource;
	}
}