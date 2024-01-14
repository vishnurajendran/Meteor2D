#pragma once
#include <2d/texture.h>
#include <2d/animationmap.h>
#include <audio/audioclip.h>
#include <pugixml/pugixml.hpp>
#include <map>
 
namespace meteor {
	/**
	 * @brief AssetManager handles asset loads and cleanup. AssetManager
	 * maintains references to loaded asset, to avoid duplicate asset loads.
	*/
	class AssetManager : public Entity {
	public:
		/**
		 * @brief Gets a Texture reference loaded from provided disk path.
		 * @param path Path to Texture file.
		 * @param relative true by default, defines if path is relative or absolute
		 * @return Texture reference.
		*/
		Texture* getTexture(std::string path, bool relative = true);
		/**
		 * @brief Gets a AnimationMap reference loaded from provided disk path.
		 * @param path Path to .anim file.
		 * @param relative true by default, defines if path is relative or absolute
		 * @return AnimationMap reference.
		*/
		AnimationMap* getAnimationMap(std::string path, bool relative = true);
		/**
		 * @brief Gets a XmlDocument reference loaded from provided disk path.
		 * @param path Path to .scml file.
		 * @param relative true by default, defines if path is relative or absolute
		 * @return XmlDocument reference.
		*/
		pugi::xml_document* getSceneDefinition(std::string path, bool relative = true);
		/**
		 * @brief Gets a XmlDocument reference loaded from provided disk path.
		 * @param path Path to .uiml file.
		 * @param relative true by default, defines if path is relative or absolute
		 * @return XmlDocument reference.
		*/
		pugi::xml_document* getUIDefinition(std::string path, bool relative = true);
		/**
		 * @brief Gets a AudioClip reference loaded from provided disk path.
		 * @param path Path to audio file.
		 * @param relative true by default, defines if path is relative or absolute
		 * @return AudioClip reference.
		*/
		AudioClip* getAudioClip(std::string path, bool relative = true);
		/**
		 * @brief cleans up all cached assets in memory, IMP: DO NOT CALL!!
		*/
		void cleanup();
		/**
		 * @brief Gets singleton instance to AssetManager. 
		 * @return AssetManager refrence.
		*/
		static AssetManager* getInstance();
		
	private:
		std::map<std::string, Texture*> texMap;
		std::map<std::string, AnimationMap*> animMap;
		std::map<std::string, pugi::xml_document*> xmlMap;
		std::map<std::string, AudioClip*> audioMap;

		static AssetManager* instance;
	
		pugi::xml_document* getXmlDocument(std::string path);
	};
}