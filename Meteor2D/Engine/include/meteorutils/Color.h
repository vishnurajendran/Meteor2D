#pragma once
#include <iostream>

namespace meteor {
	struct Color {
	public:
		/// <summary>
		/// red channel
		/// </summary>
		uint8_t r;
		/// <summary>
		/// green channel
		/// </summary>
		uint8_t g;
		/// <summary>
		/// blue channel
		/// </summary>
		uint8_t b;
		/// <summary>
		/// alpha channel
		/// </summary>
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