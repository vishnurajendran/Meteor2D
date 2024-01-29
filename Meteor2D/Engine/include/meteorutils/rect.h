#pragma once
#include <meteorutils/vector2d.h>

namespace meteor {
	/**
	 * @brief A struct representing rectangle
	*/
	struct SRect {
	public:
		SRect() {
			position.x = position.y = 0;
			size.x = size.y = 1;
		}

		SRect(SVector2 position, SVector2 size) {
			this->position = position;
			this->size = size;
		}

		SVector2 position;
		SVector2 size;
	};
}