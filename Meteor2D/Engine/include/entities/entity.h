#pragma once
#include <iostream>
class Entity {
public:
	Entity();
	~Entity();
	virtual void onStart()= 0;
	virtual void onUpdate(float deltaTime) = 0;
	virtual void onExit() = 0;
	virtual inline bool equals(Entity* other);
private:
	unsigned static int nextId;
	unsigned int id;
	inline void setId();
};
