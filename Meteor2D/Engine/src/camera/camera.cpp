#pragma once
#include <constants.h>
#include <global/sdlcores.h>
#include <camera/camera.h>
#include <camera/camerastack.h>

namespace meteor {

	Camera::Camera(Vector2 localPosition, uint8_t soringOrder) : SpatialEntity(NULL) {
		this->localPosition = localPosition;
		SDL_Point screenCentre = SdlCores::getScreenCentre();
		this->boundsCentre = Vector2::make(screenCentre.x, screenCentre.y);
		this->sortingOrder = soringOrder;
		active = true;
		CameraStack::registerToStack(this);
	}

	Camera::~Camera() {
		CameraStack::removeFromStack(this);
	}

	bool Camera::isInsideBounds(Vector2 posToCheck) {
		float left = this->position.x - (2 * boundsCentre.x);
		float right = this->position.x + (2 * boundsCentre.x);

		float top = this->position.y + (2 * boundsCentre.x);
		float bottom = this->position.y - (2 * boundsCentre.x);

		bool inFromLeft = posToCheck.x >= left;
		bool inFromRight = posToCheck.x <= right;
		bool inFromTop = posToCheck.y <= top;
		bool inFromBottom = posToCheck.y >= bottom;

		return inFromLeft && inFromRight && inFromTop && inFromBottom;
	}
}