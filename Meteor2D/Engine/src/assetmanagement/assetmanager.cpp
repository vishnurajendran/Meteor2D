#pragma once
#include <assetmanagement/assetmanager.h>
#include <meteorutils/logging.h>

namespace meteor {
	const std::string IMG_PATH = "resS\\img\\";
	const std::string ANIM_PATH = "resS\\anim\\";

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
		if (texMap.find(assetPath) != texMap.end()) {
			return texMap.at(assetPath);
		}

		mLog("loading: {}", assetPath);
		auto tex = new Texture(assetPath);
		if (tex->valid()) {
			texMap[assetPath] = tex;
			return tex;
		}

		return NULL;
	}

	AnimationMap* AssetManager::getAnimationMap(std::string path, bool relative) {
		auto assetPath = relative ? ANIM_PATH + path : path;
		if (animMap.find(assetPath) != animMap.end()) {
			return animMap.at(assetPath);
		}

		mLog("loading: {}", assetPath);
		auto map = AnimationMap::loadMap(assetPath);
		if (map != NULL) {
			animMap[assetPath] = map;
			return map;
		}

		return NULL;
	}
}