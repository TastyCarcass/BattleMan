#pragma once
#include "Graphics.h"

class GameScene
{
public:
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render(Graphics* graphics) = 0;
	virtual void Update(double delta, double timeTotal) = 0;
};