#pragma once
#include <meteorutils/logging.h>
#include <rendering/renderqueue.h>
#include <iostream>
#include <algorithm>

RenderQueue* RenderQueue::activeQueue = NULL;

RenderQueue* RenderQueue::getQueue() {
	if (activeQueue == NULL)
		activeQueue = new RenderQueue();

	return activeQueue;
}

RenderQueue::~RenderQueue() {
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

void RenderQueue::submit(RenderCommand* cmd) {
	switch (cmd->getLayer()) {
	case RenderLayer::World:
			worldQueue.push_back(cmd);
			break;
		case RenderLayer::UI:
			uiQueue.push_back(cmd);
			break;
		case RenderLayer::Debug:
			debugQueue.push_back(cmd);
			break;
	}
}

void RenderQueue::prepare() {
	if(!worldQueue.empty())
		std::sort(worldQueue.begin(), worldQueue.end(), [](RenderCommand* a, RenderCommand* b) { return a->getSortingOrder() < b->getSortingOrder(); });

	if (!uiQueue.empty())
		std::sort(uiQueue.begin(), uiQueue.end(), [](RenderCommand* a, RenderCommand* b) { return a->getSortingOrder() < b->getSortingOrder(); });

	if (!debugQueue.empty())
		std::sort(debugQueue.begin(), debugQueue.end(), [](RenderCommand* a, RenderCommand* b) { return a->getSortingOrder() < b->getSortingOrder(); });
}

bool RenderQueue::hasNext(RenderLayer layer) {
	switch (layer) {
		case RenderLayer::Debug: return !debugQueue.empty();
		case RenderLayer::UI: return !uiQueue.empty();
		case RenderLayer::World: return !worldQueue.empty();
	}
}

RenderCommand* RenderQueue::next(RenderLayer layer) {
	std::vector<RenderCommand*>* queueToUse = NULL;
	switch (layer) {
	case RenderLayer::World: queueToUse = &worldQueue;
		break;
	case RenderLayer::UI: queueToUse = &uiQueue;
		break;
	case RenderLayer::Debug: queueToUse = &debugQueue;
		break;
	}

	RenderCommand* cmd = queueToUse->front();
	queueToUse->erase(queueToUse->begin());
	return cmd;
}