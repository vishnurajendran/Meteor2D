#pragma once
#include <string>
#include <meteorutils/vector2d.h>
#include <rendering/renderer.h>
#include <entities/entity.h>
#include <SDL.h>

namespace meteor {
	class Texture : public Entity {
	public:
		Texture(std::string path);
		inline std::string getSrcPath() { return srcPath; }
		inline SDL_Texture* getCoreTexture() { return coreTexture; }
		inline Vector2 getSize() { return size; }
		inline bool valid() { return isValid; }
		static bool initialiseTextureLoader();
		static void setGenerationRenderer(Renderer* renderer) { texGenRenderer = renderer; }
	private:
		Vector2 size;
		std::string srcPath;
		SDL_Texture* coreTexture;
		static Renderer* texGenRenderer;
		bool isValid;
	};
}