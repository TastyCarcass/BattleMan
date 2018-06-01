#include "TestScene.h"

void TestScene::Load()
{
};

void TestScene::Unload()
{
};

void TestScene::Render(Graphics* graphics) {
	graphics->BeginDraw();
	graphics->ClearScreen(0.0f, 0.0f, 0.5f);
	graphics->DrawCircle(100, 100, 50, 1.0f, 0.0, 0.0, 1.0);
	graphics->DrawFillRect(300, 400, 200, 200, 0.0, 1.0, 0.0, 1.0);
	graphics->EndDraw();
};

void TestScene::Update()
{
};