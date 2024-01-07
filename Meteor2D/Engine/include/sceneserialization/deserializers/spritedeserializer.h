#pragma once
#pragma once
#include <sceneserialization/scene_entity_type_deserializer.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {
	/**
	 * @brief Desrializer for Sprite2D
	*/
	class SpriteDeserializer : SceneEntityTypeDeserializer {
	public:
		virtual SpatialEntity* deserialize(pugi::xml_node* node) override;
	private:
		const std::string SPRITE_SRC = "src";
		const std::string LAYER_SRC = "layer";
		const std::string SORTINGORDER_SRC = "sortingOrder";
		static const bool registered;
	};
}