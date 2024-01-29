#pragma once
#include <2d/sprite2d.h>
#include <sceneserialization/deserializers/spritedeserializer.h>

namespace meteor {

	const bool MSpriteDeserializer::registered = []() {
		MSceneEntityTypeMap::registerDeserializer("msprite", new MSpriteDeserializer());
		return true;
	}();

	MSpatialEntity* MSpriteDeserializer::deserialize(pugi::xml_node* node) {

		if (!node->attribute(SPRITE_SRC.c_str())) {
			return NULL;
		}

		int sortingOrder = 0;
		if (node->attribute(SORTINGORDER_SRC.c_str())) {
			sortingOrder = std::stoi(node->attribute(SORTINGORDER_SRC.c_str()).value());
		}

		int layer = 0;
		if (node->attribute(LAYER_SRC.c_str())) {
			sortingOrder = std::stoi(node->attribute(LAYER_SRC.c_str()).value());
		}

		auto src = node->attribute(SPRITE_SRC.c_str()).value();
		auto sprite = new MSprite2D(src, (ERenderLayer)layer, sortingOrder);
		if (sprite == NULL)
			return NULL;

		parseSpatialData(node, sprite);
		return sprite;
	}
}