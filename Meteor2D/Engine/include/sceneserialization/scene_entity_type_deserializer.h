#pragma once
#include <entities/spatial.h>
#include <pugixml/pugixml.hpp>
#include <string>

namespace meteor {
	/**
	 * @brief Base class for Scene Enity Derserializers
	*/
	class MSceneEntityTypeDeserializer : public MEntity {
	public:
		MSceneEntityTypeDeserializer() {};
		virtual MSpatialEntity* deserialize(pugi::xml_node* node) = 0;
	protected:
		void parseSpatialData(pugi::xml_node* node, MSpatialEntity* entity);
	private:
		const std::string LOCAL_POS_ATTRIB = "localPosition";
		const std::string LOCAL_ROT_ATTRIB = "localRotation";
		const std::string LOCAL_SCALE_ATTRIB = "localScale";
		const std::string NAME_ATTRIB = "name";
	};

}