#pragma once
#include <meteorutils/vector2d.h>

namespace meteor {
	/**
	 * @brief A struct representing rectangle
	*/
	struct Rect {
	public:
		Rect() {
			position.x = position.y = 0;
			size.x = size.y = 1;
		}

		Rect(Vector2 position, Vector2 size) {
			this->position = position;
			this->size = size;
		}

		Vector2 position;
		Vector2 size;
	};
}