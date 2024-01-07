#pragma once
#include<iostream>
#include<vector>
#include<rendering/rendercommand.h>

namespace meteor {
	/**
	 * @brief Maintains a sorted queue of all render commands submitted for rendering.
	*/
	class RenderQueue {
	public:
		RenderQueue() : worldQueue{}, uiQueue{}, debugQueue{} {}
		~RenderQueue();
		void submit(RenderCommand* cmd);
		bool hasNext(RenderLayer layer);
		void prepare();
		RenderCommand* next(RenderLayer layer);
		static RenderQueue* getQueue();
	private:
		std::vector<RenderCommand*> worldQueue;
		std::vector<RenderCommand*> uiQueue;
		std::vector<RenderCommand*> debugQueue;
		static RenderQueue* activeQueue;
	};
}