#include<entities/entity.h>

namespace meteor {

	bool Entity::equals(Entity* other) {
		if (other == NULL)
			return false;
		//address compare
		return this == other;
	}

	std::string Entity::toString() {
		return name + "@" + std::to_string((int)this);
	}
}
