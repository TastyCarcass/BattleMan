#include <Windows.h>
#include "GameController.h"

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

	ShowWindow(windowHandle, nCmdShow);

	GameController::Init(windowHandle);

	MSG message;
	message.message = WM_NULL;
	while (message.message != WM_QUIT) {
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&message);
		}
		else {
			// update
			GameController::Render();
		}
	};

	return 0;
};