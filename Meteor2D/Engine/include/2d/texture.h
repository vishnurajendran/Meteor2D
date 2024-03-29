#pragma once
#include <string>
#include <meteorutils/vector2d.h>
#include <rendering/renderer.h>
#include <entities/entity.h>
#include <SDL.h>

namespace meteor {
	/**
	 * @brief This class holds an image that can be rendererd to the screen.
	*/
	class MTexture : public MEntity {
	public:
		/**
		 * @brief Constructor
		 * @param path Texture file path
		*/
		MTexture(std::string path);
		~MTexture();
		/**
		 * @brief Gets the img source path in disk
		 * @return Path as string
		*/
		inline std::string getSrcPath() { return srcPath; }
		/**
		 * @brief get the internal SDL Texture implementation
		 * @return 
		*/
		inline SDL_Texture* getCoreTexture() { return coreTexture; }
		/**
		 * @brief returns the size of Texture in pixel
		 * @return Vector2 containing width and height of texture
		*/
		inline SVector2 getSize() { return size; }
		/**
		 * @return true if texture is valid 
		*/
		inline bool valid() { return isValid; }
		/**
		 * @brief Initialised the SDL texture loader
		 * DO NOT TOUCH or INVOKE!!
		 * @return 
		*/
		static bool initialiseTextureLoader();
		/**
		 * @brief Sets the internal renderer used for texture generation.
		 * DO NOT TOUCH or INVOKE!!
		 * @param renderer 
		*/
		static void setGenerationRenderer(MRenderer* renderer) { texGenRenderer = renderer; }
	private:
		SVector2 size;
		std::string srcPath;
		SDL_Texture* coreTexture;
		static MRenderer* texGenRenderer;
		bool isValid;
	};
}