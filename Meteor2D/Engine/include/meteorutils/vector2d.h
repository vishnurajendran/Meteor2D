#pragma once
#include <meteorutils/str_extensions.h>
#include <string>
#include <meteorutils/logging.h>


namespace meteor {
	/**
	 * @brief A structure representing a 2D Vector.
	*/
	struct SVector2 {
	public:
		float x = 0;
		float y = 0;
		
		/************* VECTOR ARITHM*******/


		void operator+=(SVector2 const& other) {
			x += other.x;
			y += other.y;
		}

		void operator-=(SVector2 const& other) {
			x += other.x;
			y += other.y;
		}

		SVector2 operator+(SVector2 const& other) {
			SVector2 nVector;
			nVector.x = x + other.x;
			nVector.y = y + other.y;
			return nVector;
		}

		SVector2 operator-(SVector2 const& other) {
			SVector2 nVector;
			nVector.x = x - other.x;
			nVector.y = y - other.y;
			return nVector;
		}

		/************ SCALAR******************/
		SVector2 operator*(int const& scalar) {
			SVector2 nVector;
			nVector.x = x * scalar;
			nVector.y = y * scalar;
			return nVector;
		}

		SVector2 operator/(int const& scalar) {
			SVector2 nVector;
			nVector.x = x / scalar;
			nVector.y = y / scalar;
			return nVector;
		}
		
		SVector2 operator*(float const& scalar) {
			SVector2 nVector;
			nVector.x = x * scalar;
			nVector.y = y * scalar;
			return nVector;
		}

		SVector2 operator/(float const& scalar) {
			SVector2 nVector;
			nVector.x = x /  scalar;
			nVector.y = y / scalar;
			return nVector;
		}


		std::string toString() {
			return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
		}

		/************ UTILS ******************/

		/**
		 * @brief returns a vector2 using x and y. (similar to Vector(x,y) constructor)
		 * @param x value in x-axis
		 * @param y value in y-axis
		 * @return vector2 containing (x,y)
		*/
		static SVector2 make(float x, float y) {
			return SVector2(x,y);
		}

		/**
		 * @return (1,1)
		*/
		static SVector2 one() {
			return SVector2(1,1);
		}

		/**
		 * @return (0,0) 
		*/
		static SVector2 zero() {
			return SVector2(1, 1);
		}

		/**
		 * @brief Multiplies each component of v1 with their respective parts in v2
		 * @param v1 vector 1
		 * @param v2 vector 2
		 * @return scaled vector
		*/
		static SVector2 scale(SVector2 v1, SVector2 v2) {
			return SVector2(v1.x * v2.x, v1.y * v2.y);
		}

		/**
		 * @brief Computes the euclidian distance
		 * @param v1 vector 1
		 * @param v2 vector 2
		 * @return euclidian distance between the two vectors
		*/
		static float dist(SVector2 v1, SVector2 v2) {
			return sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
		}

		/**
		 * @brief Parses a string to a vector, serialized vector to be
		 * in the form '(x,y)'
		 * @param str serialised string containg vector2 data
		 * @param out Vector2 struct reference to update values.
		 * @return true is de-serialization was successful.
		*/
		static bool parse(std::string str, SVector2& out) {
			if (str[0] != '(') {
				mError("vector parse failed, reason: {}", "expected ( at the begining.");
				return false;
			}
			if (str[str.length() - 1] != ')') {
				mError("vector parse failed, reason: {}", "expected ) at the end.");
				return false;
			}
			
			str = string_utils::replace<std::string>(str,"(","");
			str = string_utils::replace<std::string>(str, ")", "");

			if (string_utils::numberOfOccurence<std::string>(str,",") != 1) {
				mError("vector parse failed, reason: {}", "too many or too few components");
				return false;
			}
			auto split = string_utils::split<std::string, std::string>(str, ",");
			if (!(string_utils::isInt(split[0]) || string_utils::isFloat(split[0]))) {
				mError("vector parse failed, reason: {} : x component is not a number", split[0]);
				return false;
			}
			if (!(string_utils::isInt(split[1]) || string_utils::isFloat(split[1]))) {
				mError("vector parse failed, reason: {} : y component is not a number", split[1]);
				return false;
			}

			out.x = std::stof(split[0]);
			out.y = std::stof(split[1]);
			return true;
		}
	};
}