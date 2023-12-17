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
	inline unsigned int getId() { return id; }
private:
	unsigned static int nextId;
	inline void setId();
protected:
	unsigned int id;
};
