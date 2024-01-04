#pragma once

namespace meteor {
	struct Vector2 {
	public:
		float x = 0;
		float y = 0;
		
		/************* VECTOR ARITHM*******/

		Vector2 operator+(Vector2 const& other) {
			Vector2 nVector;
			nVector.x = x + other.x;
			nVector.y = y + other.y;
			return nVector;
		}

		Vector2 operator-(Vector2 const& other) {
			Vector2 nVector;
			nVector.x = x - other.x;
			nVector.y = y - other.y;
			return nVector;
		}

		/************ SCALAR******************/
		Vector2 operator*(int const& scalar) {
			Vector2 nVector;
			nVector.x = x * scalar;
			nVector.y = y * scalar;
			return nVector;
		}

		Vector2 operator/(int const& scalar) {
			Vector2 nVector;
			nVector.x = x / scalar;
			nVector.y = y / scalar;
			return nVector;
		}
		
		Vector2 operator*(float const& scalar) {
			Vector2 nVector;
			nVector.x = x * scalar;
			nVector.y = y * scalar;
			return nVector;
		}

		Vector2 operator/(float const& scalar) {
			Vector2 nVector;
			nVector.x = x /  scalar;
			nVector.y = y / scalar;
			return nVector;
		}

		/************ UTILS ******************/

		static Vector2 make(float x, float y) {
			Vector2 v;
			v.x = x;
			v.y = y;
			return v;
		}

		// euclidian distance
		static float dist(Vector2 v1, Vector2 v2) {
			return sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
		}
	};
}