#pragma once
#include <2d/texture.h>
#include <2d/animationmap.h>
#include <map>
 
namespace meteor {
	class AssetManager {
	public:
		Texture* getTexture(std::string path, bool relative = true);
		AnimationMap* getAnimationMap(std::string path, bool relative = true);
		static AssetManager* getInstance();
	private:
		std::map<std::string, Texture*> texMap;
		std::map<std::string, AnimationMap*> animMap;
		static AssetManager* instance;
	};
}