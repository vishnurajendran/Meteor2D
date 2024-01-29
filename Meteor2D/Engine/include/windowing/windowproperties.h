#pragma once
#include<string>
#include <constants.h>
#include <meteorutils/color.h>

namespace meteor {
	/**
	 * @brief A encapsulate properties window creation
	*/
	struct SWindowProperties {
	public:
		std::string name = "Meteor2D";
		size_t width = SCREEN_WIDTH;
		size_t height = SCREEN_HEIGHT;
		bool fullscreen = FULLSCREEN;
		bool vsync = USE_VSYNC;
		SColor backgroundColor;

		SWindowProperties() {};

		SWindowProperties(std::string name, SColor backgroundColor) {
			this->name = name;
			this->backgroundColor = backgroundColor;
		}
	};
}
