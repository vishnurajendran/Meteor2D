#include<meteorutils/logging.h>
#include<scenemanagement/scene.h>

void updateSpatialEntitiesRecursive(SpatialEntity* entity, float deltaTime);

Scene::Scene() {
	rootEntities = new std::vector<SpatialEntity*>();
}

Scene::~Scene() {
	delete rootEntities;
}

void Scene::onStart() {
	//logNoFormat("Loading scene");
}

void Scene::onUpdate(float deltaTime) {
	//logNoFormat("updating scene");
	for (int i = 0; i < rootEntities->size(); i++) {
		rootEntities->at(i)->onUpdate(deltaTime);
	}
}

void Scene::onExit() {
	//logNoFormat("cleaning scene");
}

void Scene::addToRoot(SpatialEntity* entity) {
	if (entity->getParent() != NULL)
		return;
	auto it = std::find(rootEntities->begin(), rootEntities->end(), entity);
	if (it != rootEntities->end())
		return;
	rootEntities->push_back(entity);
}