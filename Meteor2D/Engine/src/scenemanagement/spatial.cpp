#pragma once
#include <meteorutils/logging.h>
#include <entities/spatial.h>
#include <scenemanagement/scenemanager.h>
#include <scenemanagement/scene.h>

namespace meteor {

	const float PI = 3.1515926535898f;
	const float DEG_TO_RAD = PI / 180.0f;

	void makeRootEntity(SpatialEntity* entity) {
		if (entity->getParent() != NULL)
			return;
		SceneManager::getActiveScene()->addToRoot(entity);
	}

	void removeFromRoot(SpatialEntity* entity, Scene* scene) {
		auto rootEntities = scene->getRootEntities();
		std::vector<SpatialEntity*>::iterator it = std::find(rootEntities->begin(), rootEntities->end(), entity);
		if (it == rootEntities->end())
			return;

		int diff = it - rootEntities->begin();
		rootEntities->erase(rootEntities->begin() + diff);
	}

	SpatialEntity::SpatialEntity(SpatialEntity* parent) {
		name = "Spatial";
		localScale.x = localScale.y = 1;
		children = new std::vector<SpatialEntity*>();
		if (parent == NULL)
			makeRootEntity(this);
		else
			parent->addChild(this);
		onStart();
	}

	void SpatialEntity::addChild(SpatialEntity* entity) {
		std::vector<SpatialEntity*>::iterator it = std::find(children->begin(), children->end(), entity);
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
		removeFromRoot(entity, SceneManager::getActiveScene());
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
	}

	void SpatialEntity::onUpdate(float deltaTime) {
		updateRotations();
		updatePositions();
		updateScale();
		updateChildren(deltaTime);
	}

	void SpatialEntity::onExit() {

	}

	void SpatialEntity::updatePositions() {
		Vector2 fixedPoint;
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
		Vector2 posWitoutRot;
		posWitoutRot.x = fixedPoint.x + localPosition.x;
		posWitoutRot.y = fixedPoint.y + localPosition.y;

		float dist = Vector2::dist(posWitoutRot, fixedPoint);
		Vector2 posDelta = Vector2::make(sin(parentRot* DEG_TO_RAD), cos(parentRot* DEG_TO_RAD));
		Vector2 deltaWithRFactored = posDelta * dist;
		
		// set final position
		position = fixedPoint + deltaWithRFactored;
		//rotation = 
	}

	void SpatialEntity::updateRotations() {
		float parentRotDelta=0;
		if (parent != NULL) {
			parentRotDelta = parent->rotation;
		}
		
		rotation = fmod((parentRotDelta + localRotation),360.0f);
	}

	void SpatialEntity::updateScale() {
		Vector2 parentScale = Vector2::one();
		if (parent != NULL) {
			parentScale = parent->localScale;
		}

		localScale = Vector2::scale(localScale, parentScale);
	}

	void SpatialEntity::updateChildren(float deltaTime) {
		for (int i = 0; i < children->size(); i++) {
			children->at(i)->onUpdate(deltaTime);
		}
	}
}

