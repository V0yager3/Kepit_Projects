#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int Game;
int Skins;
int Levels;
int score;
int x, y;
bool gameOver;

const int width = 81;
const int height = 30;
const int MAX_LEN_SNAKE = 200;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int snake_dir = UP;
bool isRunning = true;


    void Setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
    score = 0;
}

void gotoxy( int x, int y ) { 
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

char Map[] =
"################################################################################\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"#                                                                              #\n"
"################################################################################\n";


char snake = 'Z';
int snake_x [MAX_LEN_SNAKE] = {0};
int snake_y [MAX_LEN_SNAKE] = {0};
int snake_len = 1;

char apple = '*';
int apple_x = 1 + (rand() % (width - 3));
int apple_y = 1 + (rand() % (height- 2));

bool StartGame() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        printf("Console handle is invalid!");
        return 1;
    }
    CONSOLE_CURSOR_INFO cinfo;
    GetConsoleCursorInfo(hConsole, &cinfo);
    cinfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cinfo);

snake_x[0] = width / 2;
snake_y[0] = height / 2;
double time = clock();

while (isRunning) {

    if (GetKeyState('W') & 0x8000)
    {
        if (snake_dir != DOWN) {
            snake_dir = UP;
        }
    }
    if (GetKeyState('A') & 0x8000)
    {
        if (snake_dir != RIGHT) {
            snake_dir = LEFT;
        }
    }
    if (GetKeyState('S') & 0x8000)
    {
        if (snake_dir != UP) {
            snake_dir = DOWN;
        }
    }
    if (GetKeyState('D') & 0x8000)
    {
        if (snake_dir != LEFT) {
            snake_dir = RIGHT;
        }
    }

    if((clock() - time) / CLOCKS_PER_SEC >= 0.30) {
        time = clock();
        if (snake_x[0] == apple_x && snake_y[0] == apple_y) {
            ++snake_len;
            apple_x = 1 + (rand() % (width - 3));
            apple_y = 1 + (rand() % (height- 2));
        }

        for (int i = snake_len - 2; i >= 0; --i) {
        snake_x[i + 1] = snake_x[i];
        snake_y[i + 1] = snake_y[i];
        }

    if (snake_dir == UP) {
        --snake_y[0];
    }
    if (snake_dir == DOWN) {
        ++snake_y[0];
    }
    if (snake_dir == RIGHT) {
        ++snake_x[0];
    }
    if (snake_dir == LEFT) {
        --snake_x[0];
    }
    if (snake_x[0] == 0 || snake_y[0] == 0 || snake_x[0] == width - 2 || snake_y[0] == height - 1) {
        ((clock() - time) / CLOCKS_PER_SEC >= 0);
        system("pause");
        wchar_t tryAgain;
        printf("\n Wanna try again? (y/n)");
        if (tryAgain== 'y' || tryAgain == 'Y') { return true;}
        if (tryAgain== 'n' || tryAgain == 'N') { return false;}
        }
    }

    gotoxy(0, 0);
    std::cout << "Points: " << snake_len << std::endl;
    Map[apple_y * width + apple_x] = apple;
    for (int i = 0; i < snake_len; ++i) {
        Map[snake_y[i] * width + snake_x[i]] = snake;
    }
    std::cout << Map;
    for (int i = 0; i < snake_len; ++i) {
        Map[snake_y[i] * width + snake_x[i]] = ' ';
        }
    }
}

void gameRunning () {
    if (StartGame()) { gameRunning(); }
}

int showMenu() {
    int variant;
    system("cls");
    std::cout << "New game\n" << std::endl;
    std::cout << "Levels\n" << std::endl;
    std::cout << "Skins\n" << std::endl;
    std::cout << "Exit\n" << std::endl;
    cin >> variant;
    return variant;
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
                Game;
            }
            else if (activeMenuItem == 2) {
                Levels;
            }
            else if (activeMenuItem == 3) {
                Skins;
            }
            else if (activeMenuItem == 4) {
                exit = true;
            }
        break;
        }
    }
}
}