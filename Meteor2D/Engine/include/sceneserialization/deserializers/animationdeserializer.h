#pragma once
#include <sceneserialization/deserializers/spatialdeserializer.h>

namespace meteor {
	/**
	 * @brief Deserializer for Aniamtion
	*/
	class AnimationDeserializer : SceneEntityTypeDeserializer {
	public:
		SpatialEntity* deserialize(pugi::xml_node* node) override;
	private:
		const std::string ANIM_SRC = "src";
		const std::string FPS_SRC = "fps";
		const std::string LAYER_SRC = "layer";
		const std::string SORTINGORDER_SRC = "sortingOrder";
		static const bool registered;
	};
}