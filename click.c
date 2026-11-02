#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define HOTKEY_TOGGLE 1
#define HOTKEY_QUIT 2

static void click()
{

    INPUT inputs[2] = {0};

    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(2, inputs, sizeof(INPUT));
}

int main(int argx, char *argv[])
{
    Sleep(3000);

    while(!(GetAsyncKeyState(VK_SPACE) & 0x8000)){
        click();
        Sleep(100);
    }

    return 0;
}


