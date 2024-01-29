#pragma once
#include <constants.h>
#include <global/sdlcores.h>
#include <camera/camera.h>
#include <camera/camerastack.h>

namespace meteor {

	MCamera::MCamera(SVector2 localPosition, uint8_t soringOrder) : MSpatialEntity(NULL) {
		this->localPosition = localPosition;
		SDL_Point screenCentre = MSdlCores::getScreenCentre();
		this->boundsCentre = SVector2::make(screenCentre.x, screenCentre.y);
		this->sortingOrder = soringOrder;
		active = true;
		MCameraStack::registerToStack(this);
	}

	MCamera::~MCamera() {
		MCameraStack::removeFromStack(this);
	}

	bool MCamera::isInsideBounds(SVector2 posToCheck) {
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