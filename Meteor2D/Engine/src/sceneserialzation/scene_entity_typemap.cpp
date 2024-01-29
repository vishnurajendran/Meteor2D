#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {

	std::map<std::string, MSceneEntityTypeDeserializer*>& MSceneEntityTypeMap::getMapping() {
		static std::map<std::string, MSceneEntityTypeDeserializer*> mapping;
		return mapping;
	}

	void MSceneEntityTypeMap::registerDeserializer(std::string type, MSceneEntityTypeDeserializer* deserializer) {
		auto& mapping = getMapping();
		mapping[type] = deserializer;
	}

	MSceneEntityTypeDeserializer* MSceneEntityTypeMap::getDeserializer(std::string type) {
		auto& mapping = getMapping();
		if (mapping.contains(type)) {	
			return mapping[type];
		}
		return NULL;
	}

}