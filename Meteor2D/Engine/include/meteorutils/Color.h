#pragma once
#include <iostream>

namespace meteor {
	/**
	 * @brief A struct representing a color
	*/
	struct SColor{
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

		inline SColor() {
			r = g = b = a = 0;
		}

		inline SColor(uint8_t red, uint8_t green, uint8_t blue) {
			r = red;
			b = blue;
			g = green;
			a = 0;
		}

		inline SColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
			r = red;
			b = blue;
			g = green;
			a = alpha;
		}

		inline static SColor black() { return SColor(0, 0, 0); }
		inline static SColor white() { return SColor(255, 255, 255); }
		inline static SColor red() { return SColor(255, 0, 0); }
		inline static SColor green() { return SColor(0, 255, 0); }
		inline static SColor blue() { return SColor(0, 0, 255); }
	};
}