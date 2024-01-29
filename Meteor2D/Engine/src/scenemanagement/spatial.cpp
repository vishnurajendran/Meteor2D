#pragma once
#include <meteorutils/logging.h>
#include <entities/spatial.h>
#include <scenemanagement/scenemanager.h>
#include <scenemanagement/scene.h>

namespace meteor {

	const float PI = 3.1515926535898f;
	const float DEG_TO_RAD = PI / 180.0f;

	void makeRootEntity(MSpatialEntity* entity) {
		if (entity->getParent() != NULL)
			return;
		MSceneManager::getActiveScene()->addToRoot(entity);
	}

	void removeFromRoot(MSpatialEntity* entity, MScene* scene) {
		auto rootEntities = scene->getRootEntities();
		std::vector<MSpatialEntity*>::iterator it = std::find(rootEntities->begin(), rootEntities->end(), entity);
		if (it == rootEntities->end())
			return;

		int diff = it - rootEntities->begin();
		rootEntities->erase(rootEntities->begin() + diff);
	}

	MSpatialEntity::MSpatialEntity(MSpatialEntity* parent) {
		name = "Spatial";
		localScale.x = localScale.y = 1;
		children = new std::vector<MSpatialEntity*>();
		if (parent == NULL)
			makeRootEntity(this);
		else
			parent->addChild(this);
		onStart();
	}

	void MSpatialEntity::addChild(MSpatialEntity* entity) {
		std::vector<MSpatialEntity*>::iterator it = std::find(children->begin(), children->end(), entity);
		if (it != children->end())
			return;

		if (entity->getParent() != NULL)
			entity->getParent()->removeChild(entity);

		this->children->push_back(entity);
		entity->setParent(this);

		// remove from root
		// this is a by-product of un-parenting an entity using removeChild.
		// since the entity becomes a independant, it will be considered as a root entity
		// and appended to the scene root list.
		removeFromRoot(entity, MSceneManager::getActiveScene());
	}

	void MSpatialEntity::removeChild(MSpatialEntity* entity) {
		std::vector<MSpatialEntity*>::iterator it = std::find(children->begin(), children->end(), entity);
		if (it == children->end())
			return;

		int diff = it - children->begin();
		children->erase(children->begin() + diff);
		entity->setParent(NULL);
		makeRootEntity(entity);
	}

	MSpatialEntity::~MSpatialEntity() {
		if (children == NULL)
			return;

		for (auto& child : *children) {
			delete child;
		}
	}

	void MSpatialEntity::onStart() {
	}

	void MSpatialEntity::onUpdate(float deltaTime) {
		updateRotations();
		updatePositions();
		updateScale();
		updateChildren(deltaTime);
	}

	void MSpatialEntity::onExit() {

	}

	void MSpatialEntity::updatePositions() {
		SVector2 fixedPoint;
		float parentRot=0;
		
		if (parent == NULL) {
			//if this is not parented, 
			//local and global positions are the same
			position = localPosition;
			return;
		}

		fixedPoint = parent->position;
		parentRot = parent->rotation;
		// compute position without rotation
		SVector2 posWitoutRot;
		posWitoutRot.x = fixedPoint.x + localPosition.x;
		posWitoutRot.y = fixedPoint.y + localPosition.y;

		float dist = SVector2::dist(posWitoutRot, fixedPoint);
		SVector2 posDelta = SVector2::make(sin(parentRot* DEG_TO_RAD), cos(parentRot* DEG_TO_RAD));
		SVector2 deltaWithRFactored = posDelta * dist;
		
		// set final position
		position = fixedPoint + deltaWithRFactored;
		//rotation = 
	}

	void MSpatialEntity::updateRotations() {
		float parentRotDelta=0;
		if (parent != NULL) {
			parentRotDelta = parent->rotation;
		}
		
		rotation = fmod((parentRotDelta + localRotation),360.0f);
	}

	void MSpatialEntity::updateScale() {
		SVector2 parentScale = SVector2::one();
		if (parent != NULL) {
			parentScale = parent->localScale;
		}

		localScale = SVector2::scale(localScale, parentScale);
	}

	void MSpatialEntity::updateChildren(float deltaTime) {
		for (int i = 0; i < children->size(); i++) {
			children->at(i)->onUpdate(deltaTime);
		}
	}
}

