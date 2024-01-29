#pragma once
#include <meteorutils/logging.h>
#include <scenemanagement/scene.h>
#include <sceneserialization/scene_entity_typemap.h>

namespace meteor {

	const std::string MScene::VALID_SCENE_FILE_XML_TAG = "mscene";
	void updateSpatialEntitiesRecursive(MSpatialEntity* entity, float deltaTime);

	MScene::MScene() {
		rootEntities = new std::vector<MSpatialEntity*>();
		startScene();
	}

	MScene::~MScene() {
		delete rootEntities;
	}

	void MScene::startScene() {
		//logNoFormat("Loading scene");
		for (int i = 0; i < rootEntities->size(); i++) {
			rootEntities->at(i)->onStart();
		}
	}

	void MScene::update(float deltaTime) {
		//logNoFormat("updating scene");
		for (int i = 0; i < rootEntities->size(); i++) {
			rootEntities->at(i)->onUpdate(deltaTime);
		}
	}

	void MScene::onClose() {
		//logNoFormat("cleaning scene");
		sceneClosing = true;
		for (int i = 0; i < rootEntities->size(); i++) {
			rootEntities->at(i)->onExit();
		}
	}

	void MScene::addToRoot(MSpatialEntity* entity) {
		if (entity->getParent() != NULL)
			return;
		auto it = std::find(rootEntities->begin(), rootEntities->end(), entity);
		if (it != rootEntities->end())
			return;
		rootEntities->push_back(entity);
	}

	bool MScene::tryParse(pugi::xml_document* doc) {
		if (doc == NULL)
			return false;

		if (!doc->child(VALID_SCENE_FILE_XML_TAG.c_str()))
			return false;

		for (auto& child : doc->child(VALID_SCENE_FILE_XML_TAG.c_str()).children()) {
			recursivelyLoadEntity(&child, NULL);
		}

		mLog("scene loaded from Xml!");
		startScene();
		return true;
	}

	void MScene::recursivelyLoadEntity(pugi::xml_node* currNode, MSpatialEntity* parent) {
		if (currNode == NULL)
			return;
		auto type = currNode->name();
		auto deserializer = MSceneEntityTypeMap::getDeserializer(type);
		//stop this tree serializaion, we can't deserialize this..
		if (deserializer == NULL) {
			mWarn("cannot find deserializer for {}, skipping this branch.", type);
			return;
		}
		MSpatialEntity* entity = deserializer->deserialize(currNode);
		if (entity == NULL)
		{
			mWarn("deserialized entity for {} is NULL, skipping this branch.", type);
			return;
		}

		if (parent != NULL)
			parent->addChild(entity);

		for (auto& child : currNode->children()) {
			recursivelyLoadEntity(&child, entity);
		}
	}
}