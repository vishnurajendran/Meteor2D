#pragma once
#include <meteorutils/logging.h>
#include <rendering/renderqueue.h>
#include <iostream>
#include <algorithm>

namespace meteor {
	MRenderQueue* MRenderQueue::activeQueue = NULL;

	MRenderQueue* MRenderQueue::getQueue() {
		if (activeQueue == NULL)
			activeQueue = new MRenderQueue();

		return activeQueue;
	}

	MRenderQueue::~MRenderQueue() {
		for (auto cmd : worldQueue) {
			delete cmd;
		}
		for (auto cmd : uiQueue) {
			delete cmd;
		}
		for (auto cmd : debugQueue) {
			delete cmd;
		}
	}

	void MRenderQueue::submit(MRenderCommand* cmd) {
		switch (cmd->getLayer()) {
		case ERenderLayer::World:
			worldQueue.push_back(cmd);
			break;
		case ERenderLayer::UI:
			uiQueue.push_back(cmd);
			break;
		case ERenderLayer::Debug:
			debugQueue.push_back(cmd);
			break;
		}
	}

	void MRenderQueue::prepare() {
		
		if (!worldQueue.empty())
			std::sort(worldQueue.begin(), worldQueue.end(), [](MRenderCommand* a, MRenderCommand* b) { return a->getSortingOrder() < b->getSortingOrder(); });

		if (!uiQueue.empty())
			std::sort(uiQueue.begin(), uiQueue.end(), [](MRenderCommand* a, MRenderCommand* b) { return a->getSortingOrder() < b->getSortingOrder(); });

		if (!debugQueue.empty())
			std::sort(debugQueue.begin(), debugQueue.end(), [](MRenderCommand* a, MRenderCommand* b) { return a->getSortingOrder() < b->getSortingOrder(); });
	}

	bool MRenderQueue::hasNext(ERenderLayer layer) {
		switch (layer) {
		case ERenderLayer::Debug: return !debugQueue.empty();
		case ERenderLayer::UI: return !uiQueue.empty();
		case ERenderLayer::World: return !worldQueue.empty();
		}
	}

	MRenderCommand* MRenderQueue::next(ERenderLayer layer) {
		std::vector<MRenderCommand*>* queueToUse = NULL;
		switch (layer) {
		case ERenderLayer::World: queueToUse = &worldQueue;
			break;
		case ERenderLayer::UI: queueToUse = &uiQueue;
			break;
		case ERenderLayer::Debug: queueToUse = &debugQueue;
			break;
		}

		MRenderCommand* cmd = queueToUse->front();
		queueToUse->erase(queueToUse->begin());
		return cmd;
	}
}