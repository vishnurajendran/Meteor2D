#pragma once
#include <meteorutils/logging.h>
#include <rendering/renderer.h>

namespace meteor {
	MRenderer::MRenderer(MRenderQueue* queue, SDL_Renderer* renderCore) {
		this->queue = queue;
		this->renderCore = renderCore;
	}

	void MRenderer::renderAll() {
		queue->prepare();
		while (queue->hasNext(ERenderLayer::World)) {
			render(queue->next(ERenderLayer::World));
		}
		while (queue->hasNext(ERenderLayer::UI)) {
			render(queue->next(ERenderLayer::UI));
		}
		while (queue->hasNext(ERenderLayer::Debug)) {
			render(queue->next(ERenderLayer::Debug));
		}
	}

	void MRenderer::render(MRenderCommand* cmd) {
		cmd->setRenderCore(renderCore);
		cmd->render();
	}

	void MRenderer::setLogicalSize(size_t width, size_t height) {
		SDL_RenderSetLogicalSize(renderCore, width, height);
	}
}