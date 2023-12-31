#pragma once
#include <meteorutils/rect.h>
#include <entities/spatial.h>

namespace meteor {
	class Camera : public SpatialEntity {
	public:
		~Camera();
		Camera() : Camera(Vector2::make(0, 0), 0) {};
		Camera(Vector2 position, uint8_t sortingOrder);
		inline void setActive(bool active) { active = active; }
		bool isInsideBounds(Vector2 position);
		inline bool isActive() { return active; }
		inline uint8_t getSortingOrder() { return sortingOrder; }
	private:
		Vector2 boundsCentre;
		uint8_t sortingOrder;
		bool active;
	};
}
