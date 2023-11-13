#pragma once
#include "IScene.h"
#include "Input/InputManager.h"

class ClearScene : public IScene {
public:
	~ClearScene() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	InputManager* inputManager_ = nullptr;
};

