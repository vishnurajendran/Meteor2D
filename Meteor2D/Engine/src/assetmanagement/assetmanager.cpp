#pragma once
#include <assetmanagement/assetmanager.h>
#include <meteorutils/logging.h>

namespace meteor {
	const std::string IMG_PATH = "resS\\img\\";
	const std::string ANIM_PATH = "resS\\anim\\";
	const std::string SCENE_PATH = "resS\\scene\\";
	const std::string UI_PATH = "resS\\ui\\";

	const std::string PATH_DELIM_WIN = "\\";
	const std::string PATH_DELIM_OTHER = "/";

	AssetManager* AssetManager::instance = NULL;

	AssetManager* AssetManager::getInstance() {
		if (instance == NULL)
			instance = new AssetManager();

		return instance;
	}

	Texture* AssetManager::getTexture(std::string path, bool relative) {
		auto assetPath = relative ? IMG_PATH + path : path;
		if (texMap.contains(assetPath)) {
			return texMap.at(assetPath);
		}

		mLog("loading texture: {}", assetPath);
		auto tex = new Texture(assetPath);
		if (tex->valid()) {
			texMap[assetPath] = tex;
			return tex;
		}

		return NULL;
	}

	AnimationMap* AssetManager::getAnimationMap(std::string path, bool relative) {
		auto assetPath = relative ? ANIM_PATH + path : path;
		if (animMap.contains(assetPath)) {
			return animMap.at(assetPath);
		}

		mLog("loading animation: {}", assetPath);
		auto map = AnimationMap::loadMap(assetPath);
		if (map != NULL) {
			animMap[assetPath] = map;
			return map;
		}

		return NULL;
	}

	pugi::xml_document* AssetManager::getSceneDefinition(std::string path, bool relative) {
		auto assetPath = relative ? SCENE_PATH + path : path;
		auto xmlDoc = getXmlDocument(assetPath);
		if (xmlDoc == NULL)
			return NULL;

		return xmlDoc;
	}

	pugi::xml_document* AssetManager::getUIDefinition(std::string path, bool relative) {
		auto assetPath = relative ? SCENE_PATH + path : path;
		auto xmlDoc = getXmlDocument(assetPath);
		if (xmlDoc == NULL)
			return NULL;

		return xmlDoc;
	}

	//TODO: wrap this XML library with our own implementation, I really don't want to expose the library :p.
	pugi::xml_document* AssetManager::getXmlDocument(std::string assetPath) {
		if (xmlMap.contains(assetPath)) {
			return xmlMap.at(assetPath);
		}

		mLog("loading xml document: {}", assetPath);
		auto xmlDoc = new pugi::xml_document();
		auto res = xmlDoc->load_file(assetPath.c_str());
		if (res.status == pugi::xml_parse_status::status_ok) {
			xmlMap[assetPath] = xmlDoc;
			return xmlDoc;
		}
		mError("Failed xml document load, reason: {}.", res.description());
		return NULL;
	}
}