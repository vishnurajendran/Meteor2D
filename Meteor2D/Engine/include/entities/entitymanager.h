#pragma once
#include<entities/entity.h>
#include<entities/entitycontainer.h>

#ifndef EntityManager_H
class Entity;
class EntityManager {
public:
	static void put(Entity* entity);
	static void remove(Entity* entity);
	static void updateAll(float deltaTime);
private:
	static EntityContainer* llContainerHead;
};
#endif
