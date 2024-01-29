#pragma once
#include <algorithm>
#include <camera/camerastack.h>

namespace meteor {

	std::vector<MCamera*> MCameraStack::cameraStack;
	MCamera* MCameraStack::activeCamera;

	std::vector<MCamera*>::iterator contains(std::vector<MCamera*>& stack, MCamera* cam);

	bool MCameraStack::hasActiveCamera() {
		return getActiveCamera() != NULL;
	}

	MCamera* MCameraStack::getActiveCamera() {
		if (cameraStack.size() <= 0)
			return NULL;

		if (activeCamera == NULL || !activeCamera->isActive())
			return NULL;

		return activeCamera;
	}

	void MCameraStack::registerToStack(MCamera* camera) {
		auto pos = contains(cameraStack, camera);
		if (pos != cameraStack.end())
			return;

		cameraStack.push_back(camera);
		updateStack();
	}

	void MCameraStack::removeFromStack(MCamera* camera) {
		auto pos = contains(cameraStack, camera);
		if (pos == cameraStack.end())
			return;

		cameraStack.erase(pos);
		updateStack();
	}

	void MCameraStack::updateStack() {
		if (cameraStack.size() <= 0){
			activeCamera = NULL;
			return;
		}

		std::sort(cameraStack.begin(), cameraStack.end(), [](MCamera* a, MCamera* b) {return a->getSortingOrder() < b->getSortingOrder(); });
		int i = 0;
		activeCamera = NULL;
		while (i < cameraStack.size()) {
			activeCamera = cameraStack[i++];
			if (activeCamera->isActive()) {
				break;
			}
		}
	}

	std::vector<MCamera*>::iterator contains(std::vector<MCamera*>& stack, MCamera* cam) {
		if (stack.size() <= 0)
			return stack.end();

		return std::find(stack.begin(), stack.end(), cam);
	}
}