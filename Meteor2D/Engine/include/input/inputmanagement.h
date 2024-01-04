#pragma once
#include <SDL.h>
#include <unordered_map>
#include <input/keycodes.h>

namespace meteor {
    class InputManager {
    public:
        static void Initialise();
        static void update();
        static bool getKey(KeyCode key);
        static bool getKeyDown(KeyCode key);
        static bool getKeyUp(KeyCode key);
    private:
        static const Uint8* keyStates;
        static Uint8 prevKeyStates[SDL_NUM_SCANCODES];
    };
}
