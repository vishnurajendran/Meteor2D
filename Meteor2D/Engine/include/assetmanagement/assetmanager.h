#pragma once
#include <2d/texture.h>
#include <map>
 
class AssetManager {
public:
	Texture* getTexture(std::string path, bool relative=true);
	static AssetManager* getInstance();
private:
	std::map<std::string, Texture*> texMap;
	static AssetManager* instance;
};