#include <sceneserialization/deserializers/animationdeserializer.h>

namespace meteor {

	const bool AnimationDeserializer::registered = []() {
		SceneEntityTypeMap::registerDeserializer("animation", new AnimationDeserializer());
		return true;
	}();

	SpatialEntity* AnimationDeserializer::deserialize(pugi::xml_node node) {
		return NULL;
	}
}