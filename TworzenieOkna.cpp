#include <windows.h>
#include <windowsx.h>


LRESULT CALLBACK WindowProc(HWND hWnd,
                         UINT message,
                         WPARAM wParam,
                         LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{

    HWND hWnd;
 
    WNDCLASSEX wc;


    ZeroMemory(&wc, sizeof(WNDCLASSEX));


    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = L"WindowClass1";


    RegisterClassEx(&wc);

 
    hWnd = CreateWindowEx(NULL,
                          L"WindowClass1",    // name of the window class
                          L"Okno",   // title of the window
                          WS_OVERLAPPEDWINDOW,    // window style
                          300,    // x-position of the window
                          300,    // y-position of the window
                          500,    // width of the window
                          400,    // height of the window
                          NULL,    // we have no parent window, NULL
                          NULL,    // we aren't using menus, NULL
                          hInstance,    // application handle
                          NULL);    // used with multiple windows, NULL


    ShowWindow(hWnd, nCmdShow);




    MSG msg;


    while(GetMessage(&msg, NULL, 0, 0))
    {
 
        TranslateMessage(&msg);


        DispatchMessage(&msg);
    }


    return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   
    switch(message)
    {

        case WM_DESTROY:
            {
          
                PostQuitMessage(0);
                return 0;
            } break;
    }


    return DefWindowProc (hWnd, message, wParam, lParam);
}