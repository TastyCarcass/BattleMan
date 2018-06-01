#pragma once

#include "GameScene.h"
#include "TestScene.h"
#include "Graphics.h"
#include "HPTimer.h"

class GameController
{
	GameController() {};
	static Graphics* graphics;
	static GameScene* currentScene;
	static HPTimer* hpTimer;
public:
	static void SwitchScene(GameScene* scene);

	static void Init(HWND windowHandle);
	static void Render();
	static void Update();
};