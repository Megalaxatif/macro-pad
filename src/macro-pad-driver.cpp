#include <windows.h>
#include <iostream>

bool isTetrisShortcutKeyPressed = false;
bool isSnakeShortcutKeyPressed = false;
bool close_program = false;

int main(){
    const char* _string = "the macro pad driver has stopped";
    while(!close_program){
        // close program with ctrl + shift + F1
        if(GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_F1) & 0x8000){
            AllocConsole(); // allocate a console
            HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // taking it's handle
            WriteConsole(console, _string, strlen(_string), NULL, NULL); // write on it
            close_program = true;
            Sleep(5000); // long delay before quiting the program
            FreeConsole();
        }
        // open tetris with ctrl + shift + F2
        if(GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_F2) & 0x8000){
            if (isTetrisShortcutKeyPressed == false){
                system("tetris");
                isTetrisShortcutKeyPressed = true;
            }
        }
        if(!(GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_F2) & 0x8000)){
            isTetrisShortcutKeyPressed = false;
        }
        // open snake with ctrl + shift + F3
        if(GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_F3) & 0x8000){
            if (isSnakeShortcutKeyPressed == false){
                system("snake");
                isSnakeShortcutKeyPressed = true;
            }
        }
        if(!(GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_F3) & 0x8000)){
            isSnakeShortcutKeyPressed = false;
        }
        Sleep(30); // short delay for performance
    }
    return 0;
}