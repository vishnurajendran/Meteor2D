#pragma once
#include <meteorutils/logging.h>
#include <scenemanagement/scene.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {

	const std::string Scene::VALID_SCENE_FILE_XML_TAG = "scene";
	void updateSpatialEntitiesRecursive(SpatialEntity* entity, float deltaTime);

	Scene::Scene() {
		rootEntities = new std::vector<SpatialEntity*>();
	}

	Scene::~Scene() {
		delete rootEntities;
	}

	void Scene::onStart() {
		//logNoFormat("Loading scene");
		for (int i = 0; i < rootEntities->size(); i++) {
			rootEntities->at(i)->onStart();
		}
	}

	void Scene::onUpdate(float deltaTime) {
		//logNoFormat("updating scene");
		for (int i = 0; i < rootEntities->size(); i++) {
			rootEntities->at(i)->onUpdate(deltaTime);
		}
	}

	void Scene::onExit() {
		//logNoFormat("cleaning scene");
		for (int i = 0; i < rootEntities->size(); i++) {
			rootEntities->at(i)->onExit();
		}
	}

	void Scene::addToRoot(SpatialEntity* entity) {
		if (entity->getParent() != NULL)
			return;
		auto it = std::find(rootEntities->begin(), rootEntities->end(), entity);
		if (it != rootEntities->end())
			return;
		rootEntities->push_back(entity);
	}

	bool Scene::tryParse(pugi::xml_document* doc) {
		if (doc == NULL)
			return false;

		if (!doc->child(VALID_SCENE_FILE_XML_TAG.c_str()))
			return false;

		for (auto& child : doc->child(VALID_SCENE_FILE_XML_TAG.c_str()).children()) {
			recursivelyLoadEntity(&child, NULL);
		}

		mLog("scene loaded from Xml!");
		return true;
	}

	void Scene::recursivelyLoadEntity(pugi::xml_node* currNode, SpatialEntity* parent) {
		if (currNode == NULL)
			return;
		auto type = currNode->name();
		auto deserializer = SceneEntityTypeMap::getDeserializer(type);
		//stop this tree serializaion, we can't deserialize this..
		if (deserializer == NULL) {
			mWarn("cannot find deserializer for {}, skipping this branch.", type);
			return;
		}
		SpatialEntity* entity = deserializer->deserialize(currNode);
		if (entity == NULL)
		{
			mWarn("deserialized entity for {} is NULL, skipping this branch.", type);
			return;
		}

		if (parent != NULL)
			parent->setChild(entity);

		for (auto& child : currNode->children()) {
			recursivelyLoadEntity(&child, entity);
		}
	}
}