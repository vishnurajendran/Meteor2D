#pragma once
#include <meteorutils/vector2d.h>
#include <windowing/window.h>

namespace meteor {
	class MGlobals {
	private:
		static bool initialised;
		static SVector2 resolution;
	public:
		static SVector2 getInternalResolution();
		static void intialise(SVector2 resolution);
	};
}