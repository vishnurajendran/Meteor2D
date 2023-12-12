#pragma once
#include<iostream>
#include<vector>
#include<rendering/rendercommand.h>

class RenderQueue {
public:
	RenderQueue() : worldQueue{}, uiQueue{}, debugQueue{} {}
	void submit(RenderCommand* cmd);
	bool hasNext(RenderLayer layer);
	void prepare();
	RenderCommand* next(RenderLayer layer);
private:
	std::vector<RenderCommand*> worldQueue;
	std::vector<RenderCommand*> uiQueue;
	std::vector<RenderCommand*> debugQueue;
};