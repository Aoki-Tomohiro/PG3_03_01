#pragma once
#include <Novice.h>
#include "Vector2.h"

class Enemy {
public:
	void Initialize();
	void Update();
	void Draw();
	Vector2 GetPosition() { return position_; };
	Vector2 GetRadius() { return radius_; };
private:
	Vector2 position_{};
	Vector2 radius_{};
	float speed_ = 6.0f;
};

