#pragma once
#include <SDL.h>
#include <set>
#include <entities/entity.h>
#include <input/keycodes.h>

namespace meteor {
    /**
     * @brief manages user input events.
    */
    class MInputManager : public MEntity {
    public:
        /**
         * @brief Initialise the input manager, IMP: DO NOT TOUCH or INVOKE.
        */
        static void initialise();
        /**
         * @brief request InputManager to refresh its input state.
        */
        static void update();
        /**
         * @brief Returns true if a key if held down, on release returns false
         * @param key KeyCode to check press status.
         * @return true if key is pressed down
        */
        static bool getKey(EKeyCode key);
        /**
         * @brief Returns true if a key was pressed and then released.
         * @param key KeyCode to check press status.
         * @return  true if key is pressed down and released
        */
        static bool getKeyDown(EKeyCode key);
        /**
         * @brief Returns true if a key was released.
         * @param key KeyCode to check press status.
         * @return true if a key was released.
        */
        static bool getKeyUp(EKeyCode key);
    private:
        static const Uint8* keyStates;
        static Uint8 prevKeyStates[SDL_NUM_SCANCODES];
        static std::set<EKeyCode> keyMemory;
    };
}
