#include<windows.h>

LRESULT CALLBACK MainWindowCallback(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam) {
	LRESULT result = NULL;
	switch (message) {
	case WM_SIZE: {
	}	break;
	case WM_DESTROY: {
	}	break;
	case WM_CLOSE: {
	}	break;
	case WM_ACTIVATEAPP: {
	}	break;
	case WM_PAINT: {
		PAINTSTRUCT paint;
		HDC deviceContext = BeginPaint(windowHandle, &paint);
		int height = paint.rcPaint.bottom - paint.rcPaint.top;
		int width = paint.rcPaint.right - paint.rcPaint.left;
		PatBlt(deviceContext, paint.rcPaint.left, paint.rcPaint.top, width, height, WHITENESS);
		EndPaint(windowHandle, &paint);
	}	break;
	default: {
		result = DefWindowProc(windowHandle, message, wParam, lParam);
	}	break;
	}
	return result;
}

int CALLBACK WinMain(HINSTANCE instanceHandle, HINSTANCE previowsInstanceHandle, LPSTR commandLine, int nCmdShow) {

	WNDCLASS windowClass = {};
	windowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	windowClass.hInstance = instanceHandle;
	windowClass.lpfnWndProc = MainWindowCallback;
	windowClass.lpszClassName = TEXT("handmadeHeroTutorialWindowClass");

	if (RegisterClass(&windowClass)) {
		HWND windowHandle = CreateWindowEx(0,
			windowClass.lpszClassName,
			TEXT("Handmade Hero"),
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			instanceHandle,
			NULL);
		MSG message;
		if (windowHandle) {
			for (;;) {
				BOOL messageResult = GetMessage(&message, NULL, NULL, NULL);
				if (messageResult > 0) {
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
				else {
					break;
				}
			}
		}
		else {
			//TODO: logging
		}
	}
	else {
		//TODO: logging 
	}
	return 0;
}
