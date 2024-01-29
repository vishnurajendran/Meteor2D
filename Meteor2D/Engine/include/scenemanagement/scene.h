#pragma once
#include<vector>
#include<entities/spatial.h>
#include<pugixml/pugixml.hpp>

namespace meteor {
	/**
	 * @brief A scene holds a collection of spatial entity for a specific level.
	*/
	class MScene : public MEntity {
		friend class Spatial;
	public:
		
		/**
		 * @brief Constructor
		 * @param deltaTime 
		*/
		MScene();
		~MScene();
		/**
		 * @brief Invoked when scene loads.
		*/
		void startScene();
		/**
		 * @brief Invoked once per frame.
		*/
		void update(float deltaTime);
		/**
		 * @brief Invoked during scene unload.
		*/
		void onClose();
		
		/**
		 * @brief Adds a SpatialEntity to the scene root.
		*/
		void addToRoot(MSpatialEntity* entity);
		/**
		 * @brief Returns size of root.
		*/
		inline size_t getRootSize() { return rootEntities == NULL ? 0 : rootEntities->size(); }
		/**
		 * @brief Return a list of root entities
		*/
		inline std::vector<MSpatialEntity*>* getRootEntities() { return rootEntities; };
		/**
		 * @brief Tries to parse and load a scene state.
		*/
		bool tryParse(pugi::xml_document* doc);
		
		/**
		 * @return true when a scene is closing 
		*/
		inline bool isClosing() { return sceneClosing; }

		/**
		 * @brief Finds a Spatial Entity within this scene.
		*/
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
		std::vector<MSpatialEntity*>* rootEntities;
		void recursivelyLoadEntity(pugi::xml_node* currNode, MSpatialEntity* parent);
		bool sceneClosing = false;
	public:
		static const std::string VALID_SCENE_FILE_XML_TAG;
	};
}