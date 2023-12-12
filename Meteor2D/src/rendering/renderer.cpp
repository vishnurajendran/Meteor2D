#include <rendering/renderer.h>

Renderer::Renderer(RenderQueue* queue, SDL_Renderer* renderCore) {
	this->queue = queue;
	this->renderCore = renderCore;
}

void Renderer::renderAll() {
	queue->prepare();
	while (queue->hasNext(RenderLayer::World)) {
		render(queue->next(RenderLayer::World));
	}

	while (queue->hasNext(RenderLayer::UI)) {
		render(queue->next(RenderLayer::UI));
	}

	while (queue->hasNext(RenderLayer::Debug)) {
		render(queue->next(RenderLayer::Debug));
	}
}

void Renderer::render(RenderCommand* cmd) {
	cmd->setRenderCore(renderCore);
	cmd->render();
}
