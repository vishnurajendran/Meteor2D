#pragma once

namespace meteor {
	struct Vector2 {
	public:
		float x = 0;
		float y = 0;
		
		static Vector2 make(float x, float y) {
			Vector2 v;
			v.x = x;
			v.y = y;
			return v;
		}
	};
}