#pragma once
#include <entities/entity.h>
#ifndef EntityContainer_H
class Entity;
class EntityContainer {
public:

	inline EntityContainer(Entity* entity, EntityContainer* nextContainer) {
		this->entity = entity;
		this->nextContainer = nextContainer;
	}

	inline void SetNext(EntityContainer* container) {
		this->nextContainer = container;
	}

	inline Entity* getEntity() { return entity; }
	inline EntityContainer* next() { return nextContainer; }
private:
	Entity* entity;
	EntityContainer* nextContainer;
};
#endif // !EntityContainer_H