#include<entities/entity.h>

namespace meteor {

	bool MEntity::equals(MEntity* other) {
		if (other == NULL)
			return false;
		//address compare
		return this == other;
	}

	std::string MEntity::toString() {
		return name + "@" + std::to_string((int)this);
	}
}
