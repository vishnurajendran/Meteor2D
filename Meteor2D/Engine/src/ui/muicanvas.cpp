#include <ui/muicanvas.h>
#include <meteorutils/rect.h>
#include <meteorutils/vector2d.h>
#include <global/meteorglobals.h>
#include <assetmanagement/assetmanager.h>

namespace meteor {

	MUICanvas::MUICanvas(): MUICanvas(NULL) {
	}

	MUICanvas::MUICanvas(MSpatialEntity* parent) : MSpatialEntity(parent) {
		name = "Canvas";
		initialise();
		onStart();
	}

	void MUICanvas::initialise() {
		SRect rect;
		rect.position = SVector2(0,0);
		rect.size = MGlobals::getInternalResolution();
		command = new MTexRenderCmd(ERenderLayer::UI, 0);
		command->setName("Canvas Test");
		command->bindTexture(MAssetManager::getInstance()->getTexture("ui\\white.png"));
		command->updateScale(SVector2(0.15f,0.15f));
		command->updatePivot(SVector2(0.5f,0.5f));
		command->updateRect(rect);
	}

	void MUICanvas::buildCanvas() {

	}

	void MUICanvas::draw() {
		MRenderQueue::getQueue()->submit(command);
	}

	void MUICanvas::onStart() {
		MSpatialEntity::onStart();
	}

	void MUICanvas::onUpdate(float deltaTime) {
		MSpatialEntity::onUpdate(deltaTime);
		draw();
	}

	void MUICanvas::onExit() {
		MSpatialEntity::onExit();
		delete command;
	}
}