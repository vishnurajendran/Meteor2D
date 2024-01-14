#pragma once
#include <assetmanagement/assetmanager.h>
#include <audio/audioengine.h>
#include <meteorutils/logging.h>

namespace meteor {
	const std::string IMG_PATH = "resS\\img\\";
	const std::string ANIM_PATH = "resS\\anim\\";
	const std::string SCENE_PATH = "resS\\scene\\";
	const std::string UI_PATH = "resS\\ui\\";
	const std::string AUDIO_PATH = "resS\\audio\\";

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
		auto aniMap = AnimationMap::loadMap(assetPath);
		if (aniMap != NULL) {
			animMap[assetPath] = aniMap;
			return aniMap;
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

	AudioClip* AssetManager::getAudioClip(std::string path, bool relative) {
		auto assetPath = relative ? AUDIO_PATH + path : path;
		if (animMap.contains(assetPath)) {
			return audioMap.at(assetPath);
		}

		mLog("loading audio clip: {}", assetPath);
		auto clip = AudioEngine::getClip(assetPath);
		if (clip != NULL) {
			audioMap[assetPath] = clip;
			return clip;
		}

		return NULL;
	}

	void AssetManager::cleanup() {
		
		mLog("Cleaning Animations References");
		for (auto i = animMap.begin(); i != animMap.end(); i++)
		{
			delete i->second;
		}

		mLog("Cleaning Textures References");
		for (auto i = texMap.begin(); i != texMap.end(); i++)
		{
			delete i->second;
		}

		mLog("Cleaning XMLDefinitions References");
		for (auto i = xmlMap.begin(); i != xmlMap.end(); i++)
		{
			delete i->second;
		}

		mLog("Cleaning Audio References");
		for (auto i = audioMap.begin(); i != audioMap.end(); i++)
		{
			delete i->second;
		}
	}
}