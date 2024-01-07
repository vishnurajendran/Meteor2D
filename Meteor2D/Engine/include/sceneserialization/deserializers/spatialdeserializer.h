#pragma once
#include <sceneserialization/scene_entity_type_deserializer.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {
	/**
	 * @brief Deserializer for SpatialEntity
	*/
	class SpatialDeserializer : SceneEntityTypeDeserializer {
	public:
		virtual SpatialEntity* deserialize(pugi::xml_node* node) override;
	private:
		static const bool registered;
	};
}