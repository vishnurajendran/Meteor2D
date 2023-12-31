#pragma once
#include<string>
#include <constants.h>
#include <meteorutils/color.h>

namespace meteor {
	struct WindowProperties {
	public:
		std::string name = "Meteor2D";
		size_t width = SCREEN_WIDTH;
		size_t height = SCREEN_HEIGHT;
		bool fullscreen = FULLSCREEN;
		bool vsync = USE_VSYNC;
		Color backgroundColor;

		WindowProperties() {};

		WindowProperties(std::string name, Color backgroundColor) {
			this->name = name;
			this->backgroundColor = backgroundColor;
		}
	};
}
