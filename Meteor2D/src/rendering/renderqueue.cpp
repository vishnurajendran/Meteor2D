#include<rendering/renderqueue.h>
#include<iostream>
#include<algorithm>

void RenderQueue::submit(RenderCommand* cmd) {
	std::vector<RenderCommand*> queueToUse;
	switch (cmd->getLayer()) {
		case RenderLayer::World: queueToUse = worldQueue;
			break;
		case RenderLayer::UI: queueToUse = uiQueue;
			break;
		case RenderLayer::Debug: queueToUse = debugQueue;
			break;
	}
	queueToUse.push_back(cmd);
}

void RenderQueue::prepare() {
	if(!worldQueue.empty())
		std::sort(worldQueue.begin(), worldQueue.end(), [](RenderCommand* a, RenderCommand* b) { return a->getSortingOrder() > b->getSortingOrder(); });

	if (!uiQueue.empty())
		std::sort(uiQueue.begin(), uiQueue.end(), [](RenderCommand* a, RenderCommand* b) { return a->getSortingOrder() > b->getSortingOrder(); });

	if (!debugQueue.empty())
		std::sort(debugQueue.begin(), debugQueue.end(), [](RenderCommand* a, RenderCommand* b) { return a->getSortingOrder() > b->getSortingOrder(); });
}

bool RenderQueue::hasNext(RenderLayer layer) {
	switch (layer) {
		case RenderLayer::Debug: return !debugQueue.empty();
		case RenderLayer::UI: return !uiQueue.empty();
		case RenderLayer::World: return !worldQueue.empty();
	}
}

RenderCommand* RenderQueue::next(RenderLayer layer) {
	std::vector<RenderCommand*> queueToUse;
	switch (layer) {
	case RenderLayer::World: queueToUse = worldQueue;
		break;
	case RenderLayer::UI: queueToUse = uiQueue;
		break;
	case RenderLayer::Debug: queueToUse = debugQueue;
		break;
	}

	RenderCommand* cmd = queueToUse.front();
	queueToUse.erase(queueToUse.begin());
	return cmd;
}