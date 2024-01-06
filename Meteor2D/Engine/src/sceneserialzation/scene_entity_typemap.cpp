#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {

	std::map<std::string, SceneEntityTypeDeserializer*>& SceneEntityTypeMap::getMapping() {
		static std::map<std::string, SceneEntityTypeDeserializer*> mapping;
		return mapping;
	}

	void SceneEntityTypeMap::registerDeserializer(std::string type, SceneEntityTypeDeserializer* deserializer) {
		auto& mapping = getMapping();
		mapping[type] = deserializer;
	}

	SceneEntityTypeDeserializer* SceneEntityTypeMap::getDeserializer(std::string type) {
		auto& mapping = getMapping();
		if (mapping.contains(type)) {	
			return mapping[type];
		}
		return NULL;
	}

}