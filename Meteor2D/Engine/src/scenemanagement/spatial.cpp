#include <meteorutils/logging.h>
#include <entities/spatial.h>
#include <scenemanagement/scenemanager.h>
#include <scenemanagement/scene.h>

namespace meteor {
	void makeRootEntity(SpatialEntity* entity) {
		if (entity->getParent() != NULL)
			return;
		SceneManager::getActiveScene()->addToRoot(entity);
	}

	SpatialEntity::SpatialEntity(SpatialEntity* parent) {
		localScale.x = localScale.y = 1;
		children = new std::vector<SpatialEntity*>();
		if (parent == NULL)
			makeRootEntity(this);
		else
			parent->setChild(this);
	}

	void SpatialEntity::setChild(SpatialEntity* entity) {
		std::vector<SpatialEntity*>::iterator it = std::find(children->begin(), children->end(), entity);
		if (it != children->end())
			return;

		if (entity->getParent() != NULL)
			entity->getParent()->removeChild(entity);

		this->children->push_back(entity);
		entity->setParent(this);
	}

	void SpatialEntity::removeChild(SpatialEntity* entity) {
		std::vector<SpatialEntity*>::iterator it = std::find(children->begin(), children->end(), entity);
		if (it == children->end())
			return;

		int diff = it - children->begin();
		children->erase(children->begin() + diff);
		entity->setParent(NULL);
		makeRootEntity(entity);
	}

	SpatialEntity::~SpatialEntity() {
		if (children == NULL)
			return;

		for (auto& child : *children) {
			delete child;
		}
	}

	void SpatialEntity::onStart() {
		log("started spatial {}", getId());
	}

	void SpatialEntity::onUpdate(float deltaTime) {
		updatePositions();

		//update the children
		for (int i = 0; i < children->size(); i++) {
			children->at(i)->onUpdate(deltaTime);
		}
	}

	void SpatialEntity::updatePositions() {
		Vector2 parentDelta;
		if (parent != NULL) {
			parentDelta.x = parent->position.x;
			parentDelta.y = parent->position.y;
		}

		position.x = parentDelta.x + localPosition.x;
		position.y = parentDelta.y + localPosition.y;
	}

	void SpatialEntity::onExit() {

	}
}

