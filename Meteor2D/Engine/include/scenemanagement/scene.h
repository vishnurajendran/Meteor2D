#pragma once
#include<vector>
#include<entities/spatial.h>

namespace meteor {
	class Scene : public Entity {
		//make spatial a friend class to access the protected members
		friend class Spatial;
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
}