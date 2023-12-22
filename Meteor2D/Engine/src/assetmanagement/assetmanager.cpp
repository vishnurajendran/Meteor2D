#pragma once
#include <assetmanagement/assetmanager.h>
#include <meteorutils/logging.h>

namespace meteor {
	const std::string IMG_PATH = "resS\\img\\";

	AssetManager* AssetManager::instance = NULL;

	AssetManager* AssetManager::getInstance() {
		if (instance == NULL)
			instance = new AssetManager();

		return instance;
	}

	Texture* AssetManager::getTexture(std::string path, bool relative) {
		auto assetPath = relative ? IMG_PATH + path : path;
		if (texMap.find(path) != texMap.end()) {
			return texMap.at(assetPath);
		}

		log("loading: {}", assetPath);
		auto tex = new Texture(assetPath);
		if (tex->valid()) {
			texMap[assetPath] = tex;
			return tex;
		}

		return NULL;
	}
}