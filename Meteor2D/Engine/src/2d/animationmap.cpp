#pragma once
#include <fstream>
#include <meteorutils/logging.h>
#include <nlohmann/json.hpp>
#include <2d/animationmap.h>


namespace meteor {

	const std::string ANIM_JSON_NAME = "name";
	const std::string ANIM_JSON_SPRITESHEET_CONTAINER = "spriteSheet";
	const std::string ANIM_JSON_TEXTURE = "tex";
	const std::string ANIM_JSON_RECT_CONTAINER = "rects";
	const std::string ANIM_JSON_RECT_POSX = "x";
	const std::string ANIM_JSON_RECT_POSY = "y";
	const std::string ANIM_JSON_RECT_SIZEW = "w";
	const std::string ANIM_JSON_RECT_SIZEH = "h";

	SpriteSheet* parseSpriteSheet(nlohmann::json);

	SpriteSheet* AnimationMap::getAnim(std::string name){

		if (animMapping.empty())
			return NULL;

		if (animMapping.contains(name))
			return animMapping.at(name);

		return NULL;
	}

	SpriteSheet* AnimationMap::getDefault() {
		if (animMapping.empty())
			return NULL;
		return animMapping.begin()->second;
	}

	AnimationMap* AnimationMap::loadMap(std::string filename) {
		std::ifstream file(filename, std::ios::in);
		if(!file.is_open())
			return NULL;
		
		AnimationMap* mapping = new AnimationMap();
		nlohmann::json js;
		file >> js;
		for (auto ssItm : js) {
			std::string name = ssItm[ANIM_JSON_NAME];
			auto ss = parseSpriteSheet(ssItm);
			mapping->animMapping[name]=ss;
		}

		return mapping;
	}

	SpriteSheet* parseSpriteSheet(nlohmann::json jsNode) {
		auto ss = jsNode[ANIM_JSON_SPRITESHEET_CONTAINER];
		std::string tex = ss[ANIM_JSON_TEXTURE];
		std::vector<Rect> rects;
		for (auto rectDat : ss[ANIM_JSON_RECT_CONTAINER]) {
			Rect rect;
			rect.position.x = rectDat[ANIM_JSON_RECT_POSX];
			rect.position.y = rectDat[ANIM_JSON_RECT_POSY];
			rect.size.x = rectDat[ANIM_JSON_RECT_SIZEW];
			rect.size.y = rectDat[ANIM_JSON_RECT_SIZEH];
			rects.push_back(rect);
		}
		return new SpriteSheet(tex, rects);
	}
}