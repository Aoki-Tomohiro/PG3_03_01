#pragma once
#include <Novice.h>
#include "Vector2.h"

class Bullet {
public:
	void Initialize(const Vector2& position);
	void Update();
	void Draw();
	Vector2 GetPosition() { return position_; };
	Vector2 GetRadius() { return radius_; };
	bool GetIsDead() { return isDead_; };
	void SetIsDead() { isDead_ = true; };
private:
	Vector2 position_{};
	Vector2 radius_{};
	float speed_ = 16.0f;
	bool isDead_ = false;
};

