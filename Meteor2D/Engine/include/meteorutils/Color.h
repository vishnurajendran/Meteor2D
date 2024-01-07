#pragma once
#include <iostream>

namespace meteor {
	/**
	 * @brief A struct representing a color
	*/
	struct Color {
	public:
		/**
		 * @brief Red
		*/
		uint8_t r;
		/**
		 * @brief Green
		*/
		uint8_t g;
		/**
		 * @brief Blue
		*/
		uint8_t b;
		/**
		 * @brief Alpha
		*/
		uint8_t a;

		inline Color() {
			r = g = b = a = 0;
		}

		inline Color(uint8_t red, uint8_t green, uint8_t blue) {
			r = red;
			b = blue;
			g = green;
			a = 0;
		}

		inline Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
			r = red;
			b = blue;
			g = green;
			a = alpha;
		}

		inline static Color black() { return Color(0, 0, 0); }
		inline static Color white() { return Color(255, 255, 255); }
		inline static Color red() { return Color(255, 0, 0); }
		inline static Color green() { return Color(0, 255, 0); }
		inline static Color blue() { return Color(0, 0, 255); }
	};
}