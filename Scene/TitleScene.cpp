#include "TitleScene.h"
#include "ImGuiManager.h"

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize() {
	inputManager_ = InputManager::GetInstance();
}

void TitleScene::Update() {
	if (inputManager_->GetKeyDown(DIK_SPACE)) {
		sceneNo = STAGE;
	}
	ImGui::Begin("TitleScene");
	ImGui::Text("SPACE : STAGESCENE");
	ImGui::End();
}

void TitleScene::Draw() {
	
}