#pragma once
#include <Windows.h>
#include <d2d1.h>

class Graphics
{
	static Graphics *instance;
	Graphics();
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;
public: 
	static Graphics* getInstance();

	bool Init(HWND windowHandle);

	void BeginDraw() { renderTarget->BeginDraw(); };
	void EndDraw() { renderTarget->EndDraw(); };

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);
	void DrawFillRect(float x, float y, float width, float height, float r, float g, float b, float a);
};