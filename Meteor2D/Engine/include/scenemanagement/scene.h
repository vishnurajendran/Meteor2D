#pragma once
#include<vector>
#include<entities/spatial.h>
#include<pugixml/pugixml.hpp>

namespace meteor {
	class Scene : public Entity {
		//make spatial a friend class to access the protected members
		friend class Spatial;
	public:
		static const std::string VALID_SCENE_FILE_XML_TAG;

		Scene();
		~Scene();
		void onStart();
		void onUpdate(float deltaTime);
		void onExit();
		void addToRoot(SpatialEntity* entity);
		inline size_t getRootSize() { return rootEntities == NULL ? 0 : rootEntities->size(); }
		inline std::vector<SpatialEntity*>* getRootEntities() { return rootEntities; };
		bool tryParse(pugi::xml_document* doc);
		
		template<typename T>
		T* find(std::string name) {
			if (rootEntities->size() <= 0)
				return NULL;

			for (auto rootEntity : *rootEntities) {
				auto res = rootEntity->find<T>(name);
				if (res != NULL)
					return res;
			}

			return NULL;
		}

	private:
		std::vector<SpatialEntity*>* rootEntities;
		void recursivelyLoadEntity(pugi::xml_node* currNode, SpatialEntity* parent);
	};
}