#pragma once
#include <meteorutils/rect.h>
#include <entities/spatial.h>

namespace meteor {
	/**
	 * @brief Camera entity uses provides camera like functionlity to
	 * manage world view.
	*/
	class MCamera : public MSpatialEntity {
	public:
		
		~MCamera();
		/**
		 * @brief default Constructor
		*/
		MCamera() : MCamera(SVector2::make(0, 0), 0) {};
		/**
		 * @brief Constructor
		 * @param position Position of Camera at position
		 * @param sortingOrder sorting Order of Camera within the CameraStack
		*/
		MCamera(SVector2 position, uint8_t sortingOrder);
		/**
		 * @brief Sets the Camera active status
		*/
		inline void setActive(bool active) { active = active; }
		/**
		 * @brief Checks if a provided position within camera bounds.
		 * @return 
		*/
		bool isInsideBounds(SVector2 position);
		/**
		 * @return true if Camera is active
		*/
		inline bool isActive() { return active; }
		/**
		 * @return Sorting order of Camera inside the CameraStack. 
		*/
		inline uint8_t getSortingOrder() { return sortingOrder; }
	private:
		SVector2 boundsCentre;
		uint8_t sortingOrder;
		bool active;
	};
}
