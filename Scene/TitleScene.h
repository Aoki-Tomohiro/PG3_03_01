#pragma once
#include "IScene.h"
#include "Input/InputManager.h"

class TitleScene : public IScene {
public:
	~TitleScene() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	InputManager* inputManager_ = nullptr;
};

