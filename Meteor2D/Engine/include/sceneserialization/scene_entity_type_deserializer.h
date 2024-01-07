#pragma once
#include <entities/spatial.h>
#include <pugixml/pugixml.hpp>
#include <string>

namespace meteor {

	class SceneEntityTypeDeserializer {
	public:
		SceneEntityTypeDeserializer() {};
		virtual SpatialEntity* deserialize(pugi::xml_node* node) = 0;
	protected:
		void parseSpatialData(pugi::xml_node* node, SpatialEntity* entity);
	private:
		const std::string LOCAL_POS_ATTRIB = "localPosition";
		const std::string LOCAL_ROT_ATTRIB = "localRotation";
		const std::string LOCAL_SCALE_ATTRIB = "localScale";
		const std::string NAME_ATTRIB = "name";
	};

}