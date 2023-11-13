#pragma once
#include "IScene.h"
#include "Input/InputManager.h"
#include "Object/Player.h"
#include "Object/Enemy.h"
#include <memory>

class StageScene : public IScene {
public:
	StageScene();
	~StageScene() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	InputManager* inputManager_ = nullptr;
	std::unique_ptr<Player> player_ = nullptr;
	std::unique_ptr<Enemy> enemy_ = nullptr;
};

