#pragma once
#include<iostream>
#include<vector>
#include <entities/entity.h>
#include<rendering/rendercommand.h>

namespace meteor {
	/**
	 * @brief Maintains a sorted queue of all render commands submitted for rendering.
	*/
	class MRenderQueue : public MEntity {
	public:
		MRenderQueue() : worldQueue{}, uiQueue{}, debugQueue{} {}
		~MRenderQueue();
		void submit(MRenderCommand* cmd);
		bool hasNext(ERenderLayer layer);
		void prepare();
		MRenderCommand* next(ERenderLayer layer);
		static MRenderQueue* getQueue();
	private:
		std::vector<MRenderCommand*> worldQueue;
		std::vector<MRenderCommand*> uiQueue;
		std::vector<MRenderCommand*> debugQueue;
		static MRenderQueue* activeQueue;
	};
}