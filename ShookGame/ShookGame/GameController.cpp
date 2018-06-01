#include "GameController.h"

GameScene* GameController::currentScene;
Graphics* GameController::graphics;
HPTimer* GameController::hpTimer;

void GameController::Init(HWND windowHandle)
{
	graphics = Graphics::getInstance();
	graphics->Init(windowHandle);

	currentScene = new TestScene();
	currentScene->Load();
}

void GameController::SwitchScene(GameScene *scene)
{
	currentScene->Unload();
	scene->Load();
	delete currentScene;
	currentScene = scene;
}

void GameController::Render() {
	currentScene->Render(graphics);
}

void GameController::Update() {
	hpTimer->Update();
	currentScene->Update(hpTimer->GetTimeDelta(), hpTimer->GetTimeTotal());
}