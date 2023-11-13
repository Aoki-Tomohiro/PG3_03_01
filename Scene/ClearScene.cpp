#include "ClearScene.h"
#include "ImGuiManager.h"

void ClearScene::Initialize() {
	inputManager_ = InputManager::GetInstance();
}

void ClearScene::Update() {
	if (inputManager_->GetKeyDown(DIK_SPACE)) {
		sceneNo = TITLE;
	}

	ImGui::Begin("ClearScene");
	ImGui::Text("SPACE : TITLE");
	ImGui::End();
}

void ClearScene::Draw() {

}