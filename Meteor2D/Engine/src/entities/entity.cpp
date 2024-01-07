#include<entities/entity.h>

namespace meteor {
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
		onStart();
	}

	Entity::~Entity() {
		onExit();
	}
}
