#pragma once
#include <map>
#include <2d/spritesheet.h>
namespace meteor {
	
	class AnimationMap {
	public:
		SpriteSheet* getAnim(std::string name);
		SpriteSheet* getDefault();
		static AnimationMap* loadMap(std::string fileName);
	private:
		std::map<std::string, SpriteSheet*> animMapping;
	};
}