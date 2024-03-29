#pragma once
#include <map>
#include <2d/spritesheet.h>
namespace meteor {
	
	/**
	 * @brief This class holds the relationship between SpriteSheets and Animation name.
	 * Needs to be created using the loadMap function
	*/
	class MAnimationMap : public MEntity {
	public:
		~MAnimationMap();
		/**
		 * @brief get the sprite-sheet for animation to play
		 * @param name Animation clip name.
		 * @return Ptr to SpriteSheet instance.
		*/
		MSpriteSheet* getAnim(std::string name);
		/**
		 * @brief get the default spritesheet for animation
		 * @return Ptr to the first SpriteSheet instance
		*/
		MSpriteSheet* getDefault();

		/**
		 * @brief Loads an AnimationMap from a file.
		 * @param fileName relative path to file. evaluated to resS\\anim\\<fileName>
		 * @return Ptr to AnimationMap instance
		*/
		static MAnimationMap* loadMap(std::string fileName);
	private:
		std::map<std::string, MSpriteSheet*> animMapping;
	};
}