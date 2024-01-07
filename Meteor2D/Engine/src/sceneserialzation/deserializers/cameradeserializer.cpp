#pragma once
#include <camera/camera.h>
#include <sceneserialization/deserializers/cameradeserializer.h>

namespace meteor {

	const bool CameraDerserializer::registered = []() {
		SceneEntityTypeMap::registerDeserializer("camera", new CameraDerserializer());
		return true;
	}();

	SpatialEntity* CameraDerserializer::deserialize(pugi::xml_node* node) {
		SpatialEntity* entity = new Camera();
		parseSpatialData(node, entity);
		return entity;
	}

}