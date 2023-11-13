#include "InputManager.h"

InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

bool InputManager::GetKey(BYTE keyNumber) {
	if (keys[keyNumber] != 0) {
		return true;
	}
	return false;
}

bool InputManager::GetKeyDown(BYTE keyNumber) {
	if (preKeys[keyNumber] == 0 && keys[keyNumber] != 0) {
		return true;
	}
	return false;
}

bool InputManager::GetKeyUp(BYTE keyNumber) {
	if (preKeys[keyNumber] != 0 && keys[keyNumber] == 0) {
		return true;
	}
	return false;
}