#pragma once

#include "GameScene.h"
#include "TestScene.h"
#include "Graphics.h"

class GameController
{
	GameController() {};
	static Graphics* graphics;
	static GameScene* currentScene;
public:
	static void SwitchScene(GameScene* scene);

	static void Init(HWND windowHandle);
	static void Render();
	static void Update();
};