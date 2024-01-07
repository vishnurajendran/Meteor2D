#pragma once
#include <2d/texture.h>
#include <2d/animationmap.h>
#include <pugixml/pugixml.hpp>
#include <map>
 
namespace meteor {
	class AssetManager {
	public:
		Texture* getTexture(std::string path, bool relative = true);
		AnimationMap* getAnimationMap(std::string path, bool relative = true);
		pugi::xml_document* getSceneDefinition(std::string path, bool relative = true);
		pugi::xml_document* getUIDefinition(std::string path, bool relative = true);
		static AssetManager* getInstance();
	private:
		std::map<std::string, Texture*> texMap;
		std::map<std::string, AnimationMap*> animMap;
		std::map<std::string, pugi::xml_document*> xmlMap;

		static AssetManager* instance;
	
		pugi::xml_document* getXmlDocument(std::string path);
	};
}