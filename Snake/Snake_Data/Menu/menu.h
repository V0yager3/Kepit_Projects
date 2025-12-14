#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int showMenu() {
    system("cls");
    cout << "New game\n" << endl;
    cout << "Skins\n" << endl;
    cout << "Exit\n" << endl;
}


void gotoxy( int x, int y ) { 
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

int main(int argc, char* argv[])
{
    int ch = 0;
    bool exit = false;
    int activeMenuItem = 0;
    while(!exit) 
    {
        showMenu();
        gotoxy(0, activeMenuItem);
        ch = _getch(); {
            if (ch == 224)
            ch = _getch();
            }
    switch (ch) {
        case 27: exit = true; {
            break;
        }
        case 72: activeMenuItem--; {
            break;
        }
        case 80: activeMenuItem++; {
            break;
        }
        case 13: {
            if (activeMenuItem == 1) {
                "main.cpp";
            }
            else if (activeMenuItem == 4) {
                exit = true;
            }
        break;
        }
    }
}
}