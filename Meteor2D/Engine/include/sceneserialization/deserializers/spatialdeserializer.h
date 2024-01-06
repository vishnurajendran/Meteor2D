#pragma once
#include <sceneserialization/scene_entity_type_deserializer.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {
	class SpatialDeserializer : SceneEntityTypeDeserializer {
	public:
		SpatialEntity* deserialize(pugi::xml_node node) override;
	private:
		static const bool registered;
	};
}