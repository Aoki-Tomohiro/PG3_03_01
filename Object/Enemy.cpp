#include "Enemy.h"

void Enemy::Initialize() {
	position_ = { 1280.0f / 2.0f,720.0f / 4.0f };
	radius_ = { 32.0f,32.0f };
}

void Enemy::Update() {
	//移動処理
	position_.x += speed_;

	//画面外に出ないようにする
	if (position_.x + radius_.x >= 1280.0f || position_.x - radius_.x <= 0.0f) {
		speed_ *= -1.0f;
	}
}

void Enemy::Draw() {
	//描画
	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_.x), int(radius_.y), 0.0f, RED, kFillModeSolid);
}