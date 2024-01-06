#pragma once
#include <entities/spatial.h>
#include <pugixml/pugixml.hpp>
#include <string>

namespace meteor {

	class SceneEntityTypeDeserializer {
	public:
		SceneEntityTypeDeserializer() {};
		virtual SpatialEntity* deserialize(pugi::xml_node node) = 0;
	};

}