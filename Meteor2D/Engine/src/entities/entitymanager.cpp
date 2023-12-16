#include <entities/entitymanager.h>

EntityContainer* EntityManager::llContainerHead = NULL;

void EntityManager::put(Entity* entity) {
	llContainerHead = new EntityContainer(entity, llContainerHead);
}

void EntityManager::remove(Entity* entity) {
	EntityContainer* current = llContainerHead;
	EntityContainer* previous = NULL;
	while (current != NULL && !current->getEntity()->equals(entity)) {
		previous = current;
		current = current->next();
	}
	previous->SetNext(new EntityContainer(entity, NULL));
}

void EntityManager::updateAll(float deltaTime) {
	EntityContainer* current = llContainerHead;
	while (current != NULL) {
		current->getEntity()->onUpdate(deltaTime);
		current = current->next();
	}
}