#include <sceneserialization/scene_entity_type_deserializer.h>

namespace meteor {
	void MSceneEntityTypeDeserializer::parseSpatialData(pugi::xml_node* node, MSpatialEntity* entity) {
		SVector2 localPosition(0, 0);
		SVector2 localScale(1, 1);
		float localRotation = 0;

		if (node->attribute(NAME_ATTRIB.c_str())) {
			entity->setName(node->attribute(NAME_ATTRIB.c_str()).value());
		}

		if (node->attribute(LOCAL_POS_ATTRIB.c_str())) {
			SVector2::parse(node->attribute(LOCAL_POS_ATTRIB.c_str()).value(), localPosition);
		}

		if (node->attribute(LOCAL_ROT_ATTRIB.c_str())) {
			localRotation = std::stof(node->attribute(LOCAL_ROT_ATTRIB.c_str()).value());
		}

		if (node->attribute(LOCAL_SCALE_ATTRIB.c_str())) {
			SVector2::parse(node->attribute(LOCAL_SCALE_ATTRIB.c_str()).value(), localScale);
		}

		entity->setLocalPosition(localPosition);
		entity->setLocalRotation(localRotation);
		entity->setLocalScale(localScale);
	}
}