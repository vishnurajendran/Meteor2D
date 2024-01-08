#pragma once
#include <memory>
#include <functional>
#include <map>
#include <string>
#include <sceneserialization/scene_entity_type_deserializer.h>

namespace meteor {
	/**
	 * @brief A Class that maintains mapping between Xml node types and their respective Deserializers.
	*/
	class SceneEntityTypeMap : public Entity {
	public:
		static void registerDeserializer(std::string type, SceneEntityTypeDeserializer* deserializer);
		static SceneEntityTypeDeserializer* getDeserializer(std::string type);
		static size_t getMapSize() { return getMapping().size(); }
	private:
		static std::map<std::string, SceneEntityTypeDeserializer*>& getMapping();
	};
}