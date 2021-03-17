//https://www.cplusplus.com/forum/general/229964/
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR cmdLine, int windowMode) {
	TCHAR className[] = TEXT("Win32 INSTANCE");
	TCHAR windowName[] = TEXT("Win32 Api testing");
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;//window_class

	wc.hInstance = hInstance;
	wc.lpszClassName = className;
	wc.lpfnWndProc = WndProc;
	wc.style = 0;

	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 5));

	if (RegisterClass(&wc) == 0) {
		MessageBox(NULL, L"Could not load the window", L"ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(className, windowName, WS_OVERLAPPEDWINDOW, 0, 0, 200, 200, NULL, NULL, hInstance, NULL);
	
	if (hwnd == NULL) {
		MessageBox(NULL, L"Could not create the main window", L"ERROR MAIN WINDOW", MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, 1);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
