#pragma once
#include <iostream>

namespace meteor {
	/**
	 * @brief An Entity is the base class for all data and behaviour oriented objects in meteor.
	 * This class contains properties and function used by meteor for its operation.
	*/
	class Entity {
	public:
		Entity();
		~Entity();
		/**
		 * @brief Invoked when object is instantiated
		*/
		virtual void onStart() {};
		/**
		 * @brief Invoked every frame, default behaviour does not invoke this method.
		 * @param deltaTime time difference between last and last-to-last frame.
		*/
		virtual void onUpdate(float deltaTime) {};
		/**
		 * @brief Invoked when object is destroyed
		*/
		virtual void onExit() {};
		/**
		 * @brief Checks equality between two entities.
		 * @param other entity to check with.
		*/
		virtual inline bool equals(Entity* other);
		/**
		 * @return nstance Id of entiity.
		*/
		inline unsigned int getId() { return id; }
		/**
		 * @return Name of entity
		*/
		inline std::string getName() { return name; }
		/**
		 * @brief Sets name of entity
		*/
		inline void setName(std::string name) { this->name = name; }
	private:
		unsigned static int nextId;
		inline void setId();
	protected:
		unsigned int id;
		std::string name;
	};
}
