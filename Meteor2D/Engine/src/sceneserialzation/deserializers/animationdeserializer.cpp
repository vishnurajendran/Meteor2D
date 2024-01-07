#pragma once
#include <2d/animation.h>
#include <sceneserialization/deserializers/animationdeserializer.h>

namespace meteor {

	const bool AnimationDeserializer::registered = []() {
		SceneEntityTypeMap::registerDeserializer("animation", new AnimationDeserializer());
		return true;
	}();

	SpatialEntity* AnimationDeserializer::deserialize(pugi::xml_node* node) {
		
		if (!node->attribute(ANIM_SRC.c_str())) {
			return NULL;
		}

		int fps = 12;
		if (node->attribute(FPS_SRC.c_str())) {
			fps = std::stoi(node->attribute(FPS_SRC.c_str()).value());
		}

		int sortingOrder = 0;
		if (node->attribute(SORTINGORDER_SRC.c_str())) {
			sortingOrder = std::stoi(node->attribute(SORTINGORDER_SRC.c_str()).value());
		}

		int layer = 0;
		if (node->attribute(LAYER_SRC.c_str())) {
			layer = std::stoi(node->attribute(LAYER_SRC.c_str()).value());
		}

		auto src = node->attribute(ANIM_SRC.c_str()).value();
		auto anim = new Animation(src, fps, (RenderLayer)layer, sortingOrder);
		if (anim == NULL)
			return NULL;

		parseSpatialData(node, anim);
		return anim;
	}
}