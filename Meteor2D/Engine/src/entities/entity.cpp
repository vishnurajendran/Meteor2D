#include<entities/entity.h>
#include<entities/entitymanager.h>

unsigned int Entity::nextId = 0;

void Entity::setId() {
	this->id = nextId++;
}

bool Entity::equals(Entity* other) {
	if (other == NULL)
		return false;
	return this->id == other->id;
}

Entity::Entity() {
	setId();
	EntityManager::put(this);
}

Entity::~Entity() {
	EntityManager::remove(this);
}
