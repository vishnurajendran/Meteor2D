#pragma once
#include <meteorutils/logging.h>
#include <input/inputmanagement.h>

namespace meteor {

	const Uint8* InputManager::keyStates = NULL;
	Uint8 InputManager::prevKeyStates[SDL_NUM_SCANCODES] = {0};

	void InputManager::Initialise() {
		//init our current key states
		keyStates = SDL_GetKeyboardState(nullptr);

		mLog("Input Manager Ready");
	}

	void InputManager::update() {
		SDL_PumpEvents();
		std::memcpy(prevKeyStates, keyStates, SDL_NUM_SCANCODES);
		keyStates = SDL_GetKeyboardState(nullptr);
	}

	bool InputManager::getKey(KeyCode key) {
		return keyStates[key] != 0;
	}

	bool InputManager::getKeyDown(KeyCode key) {
		return keyStates[key] != 0 && prevKeyStates[key] == 0;
	}

	bool InputManager::getKeyUp(KeyCode key) {
		return keyStates[key] == 0 && prevKeyStates[key] != 0;
	}
}