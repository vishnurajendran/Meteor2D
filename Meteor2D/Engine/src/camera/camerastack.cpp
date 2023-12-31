#pragma once
#include <algorithm>
#include <camera/camerastack.h>

namespace meteor {

	std::vector<Camera*> CameraStack::cameraStack;
	Camera* CameraStack::activeCamera;

	std::vector<Camera*>::iterator contains(std::vector<Camera*>& stack, Camera* cam);

	bool CameraStack::hasActiveCamera() {
		return getActiveCamera() != NULL;
	}

	Camera* CameraStack::getActiveCamera() {
		if (cameraStack.size() <= 0)
			return NULL;

		if (activeCamera == NULL || !activeCamera->isActive())
			return NULL;

		return activeCamera;
	}

	void CameraStack::registerToStack(Camera* camera) {
		auto pos = contains(cameraStack, camera);
		if (pos != cameraStack.end())
			return;

		cameraStack.push_back(camera);
		updateStack();
	}

	void CameraStack::removeFromStack(Camera* camera) {
		auto pos = contains(cameraStack, camera);
		if (pos == cameraStack.end())
			return;

		cameraStack.erase(pos);
		updateStack();
	}

	void CameraStack::updateStack() {
		if (cameraStack.size() <= 0){
			activeCamera = NULL;
			return;
		}

		std::sort(cameraStack.begin(), cameraStack.end(), [](Camera* a, Camera* b) {return a->getSortingOrder() < b->getSortingOrder(); });
		int i = 0;
		activeCamera = NULL;
		while (i < cameraStack.size()) {
			activeCamera = cameraStack[i++];
			if (activeCamera->isActive()) {
				break;
			}
		}
	}

	std::vector<Camera*>::iterator contains(std::vector<Camera*>& stack, Camera* cam) {
		if (stack.size() <= 0)
			return stack.end();

		return std::find(stack.begin(), stack.end(), cam);
	}
}