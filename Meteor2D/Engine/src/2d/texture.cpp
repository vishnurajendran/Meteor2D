#include <meteorutils/logging.h>
#include <global/sdlcores.h>
#include <2d/texture.h>
#include <SDL_image.h>

namespace meteor {
    bool MTexture::initialiseTextureLoader() {
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            mError("SDL_image could not initialize! SDL_image Error: {}", IMG_GetError());
            return false;
        }
        return true;
    }

    MTexture::MTexture(std::string path) {
        SDL_Surface* tempSurface = IMG_Load(path.c_str());
        if (tempSurface == NULL) {
            mError("Unable to load image {}!, Error {}", path, IMG_GetError());
            isValid = false;
            return;
        }
        if (MSdlCores::getActiveRenderer() == NULL) {
            mError("SDL renderer core missing, cannot generate texture");
            isValid = false;
            return;
        }
        coreTexture = SDL_CreateTextureFromSurface(MSdlCores::getActiveRenderer(), tempSurface);
        SDL_FreeSurface(tempSurface);
        int sizeX, sizeY = 1;
        SDL_QueryTexture(coreTexture, NULL, NULL, &sizeX, &sizeY);
        size.x = sizeX;
        size.y = sizeY;
        isValid = true;
    }

    MTexture::~MTexture() {
        if(coreTexture != NULL)
            SDL_DestroyTexture(coreTexture);
    }
}
