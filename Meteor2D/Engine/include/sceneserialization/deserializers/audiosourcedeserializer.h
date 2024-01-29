#pragma once
#include <sceneserialization/deserializers/spatialdeserializer.h>

namespace meteor {
	/**
	 * @brief Deserializer for AudioSource
	*/
	class MAudioSourceDeserializer : MSceneEntityTypeDeserializer {
	public:
		MSpatialEntity* deserialize(pugi::xml_node* node) override;
	private:
		const std::string AUDIO_SRC = "src";
		const std::string AUDIO_VOL = "volume";
		const std::string AUDIO_PLAYBACK_SPEED = "playbackSpeed";
		const std::string AUDIO_LOOP = "loop";
		const std::string AUDIO_AUTOPLAY = "autoPlay";
		static const bool registered;
	};
}