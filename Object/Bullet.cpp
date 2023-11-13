#include "Bullet.h"

void Bullet::Initialize(const Vector2& position) {
	position_ = position;
	radius_ = { 5.0f,5.0f };
}

void Bullet::Update() {
	//移動処理
	position_.y -= speed_;

	//画面外に出たら死亡フラグを立てる
	if (position_.y + radius_.y <= 0.0f) {
		isDead_ = true;
	}
}

void Bullet::Draw() {
	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_.x), int(radius_.y), 0.0f, RED, kFillModeSolid);
}