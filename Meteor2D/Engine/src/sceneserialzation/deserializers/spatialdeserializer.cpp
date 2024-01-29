#include <sceneserialization/deserializers/spatialdeserializer.h>

namespace meteor {

	const bool MSpatialDeserializer::registered = []() {
		MSceneEntityTypeMap::registerDeserializer("mspatial", new MSpatialDeserializer()); 
		return true;
	}();

	MSpatialEntity* MSpatialDeserializer::deserialize(pugi::xml_node* node) {
		MSpatialEntity* entity = new MSpatialEntity();
		parseSpatialData(node, entity);
		return entity;
	}

}