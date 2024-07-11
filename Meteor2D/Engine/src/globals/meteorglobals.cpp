#include<global/meteorglobals.h>

namespace meteor {
	
	SVector2 MGlobals::resolution = SVector2(-1,-1);
	bool MGlobals::initialised = false;

	void MGlobals::intialise(SVector2 res) {
		resolution = res;
		initialised = true;
	}

	SVector2 MGlobals::getInternalResolution() {
		if (!initialised)
			return SVector2(-1, -1);
		return resolution;
	}
}