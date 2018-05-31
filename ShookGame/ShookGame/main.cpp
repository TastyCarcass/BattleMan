#include <Windows.h>
#include "Graphics.h"

Graphics* graphics;

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
) 
{
	if (uMsg == WM_DESTROY) 
	{
		PostQuitMessage(0); 
		return 0;
	}

	if (uMsg == WM_PAINT) 
	{
		graphics->BeginDraw();
		graphics->ClearScreen(0.0f, 0.0f, 0.5f);
		graphics->DrawCircle(100, 100, 50, 1.0f, 0.0, 0.0, 1.0);
		graphics->DrawFillRect(300, 400, 200, 200, 0.0, 1.0, 0.0, 1.0);
		graphics->EndDraw();
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
};

int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	LPWSTR cmd,
	int nCmdShow) 
{
	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.hbrBackground = (HBRUSH) COLOR_WINDOW;
	windowClass.hInstance = hInstance;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.lpszClassName = "MainWindow";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowClass);

	RECT rect = { 0, 0, 1280, 720 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);
	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MainWindow", "ShookGame!", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowHandle) return -1;

	graphics = new Graphics();
	if (!graphics->Init(windowHandle))
	{
		delete graphics;
		return -1;
	}


	ShowWindow(windowHandle, nCmdShow);

	MSG message;
	while (GetMessage(&message, NULL, 0, 0)) 
	{
		DispatchMessage(&message);
	}

	return 0;
};