#pragma once

#include "GameScene.h"
#include "Graphics.h"
class TestScene : public GameScene
{
public:
	void Load();
	void Unload();
	void Render(Graphics* graphics);
	void Update();
};