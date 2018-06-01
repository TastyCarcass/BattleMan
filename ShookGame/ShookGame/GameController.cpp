#include "GameController.h"

GameScene* GameController::currentScene;
Graphics* GameController::graphics;

void GameController::Init(HWND windowHandle)
{
	graphics = new Graphics();
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
	currentScene->Update();
}