#pragma once
#include <meteorutils/logging.h>
#include <input/inputmanagement.h>

namespace meteor {

	const Uint8* MInputManager::keyStates = NULL;
	Uint8 MInputManager::prevKeyStates[SDL_NUM_SCANCODES] = {0};
	std::set<EKeyCode> MInputManager::keyMemory;

	void MInputManager::initialise() {
		//init our current key states
		keyStates = SDL_GetKeyboardState(nullptr);

		mLog("Input Manager Ready");
	}

	void MInputManager::update() {
		std::memcpy(prevKeyStates, keyStates, SDL_NUM_SCANCODES);
		SDL_PumpEvents();

		std::vector<EKeyCode> codesToRemove;
		for (auto key : keyMemory) {
			if (getKeyUp(key))
				codesToRemove.push_back(key);
		}

		while (codesToRemove.size() > 0){
			keyMemory.erase(keyMemory.find(codesToRemove[0]));
			codesToRemove.erase(codesToRemove.begin());
		}
	}

	bool MInputManager::getKey(EKeyCode key) {
		return keyStates[key] != 0;
	}

	bool MInputManager::getKeyDown(EKeyCode key) {
		bool res =  keyStates[key] != 0 && prevKeyStates[key] == 0 && !keyMemory.contains(key);
		if (res) {
			keyMemory.insert(key);
		}
		return res;
	}

	bool MInputManager::getKeyUp(EKeyCode key) {
		return keyStates[key] == 0 && prevKeyStates[key] != 0;
	}
}