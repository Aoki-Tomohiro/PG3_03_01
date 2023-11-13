#include "StageScene.h"
#include "ImGuiManager.h"

StageScene::StageScene() {}

StageScene::~StageScene() {}

void StageScene::Initialize() {
	inputManager_ = InputManager::GetInstance();
	player_ = std::make_unique<Player>();
	player_->Initialize();
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void StageScene::Update() {
	//更新処理
	player_->Update();
	enemy_->Update();

	//当たり判定
	const std::list<std::unique_ptr<Bullet>>& bullets = player_->GetBullets();
	Vector2 enemyPosition = enemy_->GetPosition();
	Vector2 enemyRadius = enemy_->GetRadius();
	for (const std::unique_ptr<Bullet>& bullet : bullets) {
		Vector2 bulletPosition = bullet->GetPosition();
		Vector2 bulletRadius = bullet->GetRadius();
		float distance = (enemyPosition.x - bulletPosition.x) * (enemyPosition.x - bulletPosition.x) + (enemyPosition.y - bulletPosition.y) * (enemyPosition.y - bulletPosition.y);
		float radius = (enemyRadius.x + bulletRadius.x) * (enemyRadius.y + bulletRadius.y);
		if (radius == distance || radius > distance) {
			sceneNo = CLEAR;
			bullet->SetIsDead();
		}
	}

	ImGui::Begin("StageScene");
	ImGui::Text("A D : Move");
	ImGui::Text("SPACE : Shot");
	ImGui::End();
}

void StageScene::Draw() {
	//描画処理
	player_->Draw();
	enemy_->Draw();
}