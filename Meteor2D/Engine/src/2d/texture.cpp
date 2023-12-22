#include <meteorutils/logging.h>
#include <global/sdlcores.h>
#include <2d/texture.h>
#include <SDL_image.h>

namespace meteor {
    bool Texture::initialiseTextureLoader() {
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            error("SDL_image could not initialize! SDL_image Error: {}", IMG_GetError());
            return false;
        }
        return true;
    }

    Texture::Texture(std::string path) {
        SDL_Surface* tempSurface = IMG_Load(path.c_str());
        if (tempSurface == NULL) {
            error("Unable to load image {}!, Error {}", path, IMG_GetError());
            isValid = false;
            return;
        }
        if (SdlCores::getActiveRenderer() == NULL) {
            error("SDL renderer core missing, cannot generate texture");
            isValid = false;
            return;
        }
        coreTexture = SDL_CreateTextureFromSurface(SdlCores::getActiveRenderer(), tempSurface);
        SDL_FreeSurface(tempSurface);
        int sizeX, sizeY = 1;
        SDL_QueryTexture(coreTexture, NULL, NULL, &sizeX, &sizeY);
        size.x = sizeX;
        size.y = sizeY;
        isValid = true;
    }
}
