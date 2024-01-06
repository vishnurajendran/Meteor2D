#pragma once
#include <iostream>

namespace meteor {
	class Entity {
	public:
		Entity();
		~Entity();
		virtual void onStart() {};
		virtual void onUpdate(float deltaTime) {};
		virtual void onExit() {};
		virtual inline bool equals(Entity* other);
		inline unsigned int getId() { return id; }
		inline std::string getName() { return name; }
		inline void setName(std::string name) { this->name = name; }
	private:
		unsigned static int nextId;
		inline void setId();
	protected:
		unsigned int id;
		std::string name;
	};
}
