#pragma once
#include<vector>
#include<entities/spatial.h>

class Scene : public Entity {
public:
	Scene();
	~Scene();
	void onStart();
	void onUpdate(float deltaTime);
	void onExit();
	void addToRoot(SpatialEntity* entity);
	inline size_t getRootSize() { return rootEntities == NULL ? 0 : rootEntities->size(); }
	inline std::vector<SpatialEntity*>* getRootEntities() { return rootEntities; };
private:
	std::vector<SpatialEntity*>* rootEntities;
};