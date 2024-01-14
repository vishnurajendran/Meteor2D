#pragma once
#include <string>

namespace meteor {
	/**
	 * @brief An Entity is the base class for all data and behaviour oriented objects in meteor.
	 * This class contains properties and function used by meteor for its operation.
	*/
	class Entity {
	public:
		/**
		 * @brief Checks equality between two entities.
		 * @param other entity to check with.
		*/
		virtual bool equals(Entity* other);
		/**
		 * @return Name of entity
		*/
		inline std::string getName() { return name; }
		/**
		 * @brief Sets name of entity
		*/
		inline void setName(std::string name) { this->name = name; }

		/**
		 * @brief Get this object as a string
		 * @return A string representing this object
		*/
		virtual std::string toString();
	protected:
		std::string name;
	};
}
