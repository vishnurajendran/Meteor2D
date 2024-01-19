#pragma once
#include <meteorutils/logging.h>
#include <input/inputmanagement.h>

namespace meteor {

	const Uint8* InputManager::keyStates = NULL;
	Uint8 InputManager::prevKeyStates[SDL_NUM_SCANCODES] = {0};
	std::set<KeyCode> InputManager::keyMemory;

	void InputManager::initialise() {
		//init our current key states
		keyStates = SDL_GetKeyboardState(nullptr);

		mLog("Input Manager Ready");
	}

	void InputManager::update() {
		std::memcpy(prevKeyStates, keyStates, SDL_NUM_SCANCODES);
		SDL_PumpEvents();

		std::vector<KeyCode> codesToRemove;
		for (auto key : keyMemory) {
			if (getKeyUp(key))
				codesToRemove.push_back(key);
		}

		while (codesToRemove.size() > 0){
			keyMemory.erase(keyMemory.find(codesToRemove[0]));
			codesToRemove.erase(codesToRemove.begin());
		}
	}

	bool InputManager::getKey(KeyCode key) {
		return keyStates[key] != 0;
	}

	bool InputManager::getKeyDown(KeyCode key) {
		bool res =  keyStates[key] != 0 && prevKeyStates[key] == 0 && !keyMemory.contains(key);
		if (res) {
			keyMemory.insert(key);
		}
		return res;
	}

	bool InputManager::getKeyUp(KeyCode key) {
		return keyStates[key] == 0 && prevKeyStates[key] != 0;
	}
}