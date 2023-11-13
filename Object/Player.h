#pragma once
#include <Novice.h>
#include <memory>
#include <list>
#include "Vector2.h"
#include "Input/InputManager.h"
#include "Bullet.h"

class Player {
public:
	void Initialize();
	void Update();
	void Draw();
	Vector2 GetPosition() { return position_; };
	Vector2 GetRadius() { return radius_; };
	const std::list<std::unique_ptr<Bullet>>& GetBullets() { return bullets_; };
private:
	InputManager* inputManager_ = nullptr;
	Vector2 position_{};
	Vector2 radius_{};
	float speed_ = 10.0f;
	std::list<std::unique_ptr<Bullet>> bullets_{};
	int bulletTimer_ = 0;
};

