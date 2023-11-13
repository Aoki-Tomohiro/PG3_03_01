#include "Player.h"
#include "ImGuiManager.h"

void Player::Initialize() {
	inputManager_ = InputManager::GetInstance();
	position_ = { 1280.0f / 2.0f,720.0f / 4.0f * 3.0f };
	radius_ = { 32.0f,32.0f };
}

void Player::Update() {
	//移動処理
	if (inputManager_->GetKey(DIK_A)) {
		position_.x -= speed_;
	}

	if (inputManager_->GetKey(DIK_D)) {
		position_.x += speed_;
	}

	//画面外に出ないようにする
	if (position_.x - radius_.x <= 0.0f) {
		position_.x = 0.0f + radius_.x;
	}
	else if (position_.x + radius_.x >= 1280.0f) {
		position_.x = 1280.0f - radius_.x;
	}

	//弾の削除
	bullets_.remove_if([](std::unique_ptr<Bullet>& bullet) {
		if (bullet->GetIsDead()) {
			bullet.reset();
			return true;
		}
		return false;
		});

	//弾の発射処理
	const int kFireInterval = 10;
	if (inputManager_->GetKey(DIK_SPACE)) {
		if (--bulletTimer_ < 0.0f) {
			bulletTimer_ = kFireInterval;
			Bullet* newBullet = new Bullet();
			newBullet->Initialize({ position_.x,position_.y });
			bullets_.push_back(std::unique_ptr<Bullet>(newBullet));
		}
	}

	//弾の更新処理
	for (std::unique_ptr<Bullet>& bullet : bullets_) {
		bullet->Update();
	}
}

void Player::Draw() {
	//弾の描画
	for (std::unique_ptr<Bullet>& bullet : bullets_) {
		bullet->Draw();
	}

	//自機の描画
	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_.x), int(radius_.y), 0.0f, WHITE, kFillModeSolid);
}