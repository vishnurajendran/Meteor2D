#pragma once

namespace meteor {
	struct Vector2 {
	public:
		float x = 0;
		float y = 0;
		
		/************* VECTOR ARITHM*******/


		void operator+=(Vector2 const& other) {
			x += other.x;
			y += other.y;
		}

		void operator-=(Vector2 const& other) {
			x += other.x;
			y += other.y;
		}

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

		/// <summary>
		/// returns a vector2 using x and y. (similar to Vector(x,y) constructor)
		/// </summary>
		/// <param name="x">value in x-axis</param>
		/// <param name="y">value in y-axis</param>
		/// <returns>vector2 containing (x,y)</returns>
		static Vector2 make(float x, float y) {
			return Vector2(x,y);
		}

		// returns (1,1)
		static Vector2 one() {
			return Vector2(1,1);
		}

		// returns (0,0)
		static Vector2 zero() {
			return Vector2(1, 1);
		}

		/// <summary>
		/// multiplies each component of v1 with their respective parts in v2
		/// </summary>
		/// <param name="v1">vector 1</param>
		/// <param name="v2">vector 2</param>
		/// <returns>scaled vector</returns>
		static Vector2 scale(Vector2 v1, Vector2 v2) {
			return Vector2(v1.x * v2.x, v1.y * v2.y);
		}

		/// <summary>
		/// computes the euclidian distance
		/// </summary>
		/// <param name="v1"> vector 1 </param>
		/// <param name="v2"> vector 2 </param>
		/// <returns>distance between the two given vectors</returns>
		static float dist(Vector2 v1, Vector2 v2) {
			return sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
		}

	};
}