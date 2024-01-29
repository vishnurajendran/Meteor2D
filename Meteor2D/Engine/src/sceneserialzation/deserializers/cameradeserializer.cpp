#pragma once
#include <camera/camera.h>
#include <sceneserialization/deserializers/cameradeserializer.h>

namespace meteor {

	const bool MCameraDerserializer::registered = []() {
		MSceneEntityTypeMap::registerDeserializer("mcamera", new MCameraDerserializer());
		return true;
	}();

	MSpatialEntity* MCameraDerserializer::deserialize(pugi::xml_node* node) {
		MSpatialEntity* entity = new MCamera();
		parseSpatialData(node, entity);
		return entity;
	}

}