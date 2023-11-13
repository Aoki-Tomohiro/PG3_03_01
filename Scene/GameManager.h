#pragma once
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "Input/InputManager.h"
#include <Novice.h>
#include <memory>

class GameManager {
public:
	GameManager();
	~GameManager();
	int Run();
private:
	std::unique_ptr<IScene> sceneArr_[3];
	int currentSceneNo_;
	int prevSceneNo_;
	InputManager* inputManager_ = nullptr;
};

