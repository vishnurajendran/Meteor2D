#include <sceneserialization/deserializers/spatialdeserializer.h>

namespace meteor {

	const bool SpatialDeserializer::registered = []() {
		SceneEntityTypeMap::registerDeserializer("spatial", new SpatialDeserializer()); 
		return true;
	}();

	SpatialEntity* SpatialDeserializer::deserialize(pugi::xml_node* node) {
		SpatialEntity* entity = new SpatialEntity();
		parseSpatialData(node, entity);
		return entity;
	}

}