#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <conio.h> // отслеживание нажатий пользователя
#include <fstream> //ввод вывод

#include <thread>
#include <chrono> // для времени

using namespace std;


int Skins;
int score = 0;
int lv = 0;

const int width = 81;
const int height = 30;
const int MAX_TAIL_SNAKE = 200;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int snake_dir = UP;

bool isRunning = true;
bool gameOver = false;

int snake_x[MAX_TAIL_SNAKE] = {0};
int snake_y[MAX_TAIL_SNAKE] = {0};

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
int snake_Tail = 1;
char apple = '*';
int apple_x = rand() % width;
int apple_y = rand() % height;

char Bad_apple = '?';
int Bad_apple_x = rand() % width;
int Bad_apple_y = rand() % width;

int puddle = '-';
int puddle_len = 2;
int puddle_x = rand() % width;
int puddle_y = rand() % height;

int main()
{
    snake_x[0] = width / 2;
    snake_y[0] = height / 2;
    double time = clock();
    
    while (isRunning) {
        if (snake_x[0] == Bad_apple_x && snake_y[0] == Bad_apple_y) {
            if (GetKeyState('W') & 0x8000)
                {
                    if (snake_dir != UP) {
                        snake_dir = DOWN;
                    }
                }
                if (GetKeyState('A') & 0x8000)
                {
                    if (snake_dir != LEFT) {
                        snake_dir = RIGHT;
                    }
                }
                if (GetKeyState('S') & 0x8000)
                {
                    if (snake_dir != DOWN) {
                        snake_dir = UP;
                    }
                }
                if (GetKeyState('D') & 0x8000)
                {
                    if (snake_dir != RIGHT) {
                        snake_dir = LEFT;
                    }
                }
                if (GetKeyState(' ') & 0x8000)
                {
                    ((clock() - time) / CLOCKS_PER_SEC >= 0.30);
                    time = clock();
                }
    }
    else {
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
    if (GetKeyState(' ') & 0x8000)
    {
        ((clock() - time) / CLOCKS_PER_SEC >= 0.30);
        time = clock();
    }

    }


        if ((clock() - time) / CLOCKS_PER_SEC >= 1) {
            time = clock();
            if (snake_x[0] == apple_x && snake_y[0] == apple_y) {
                ++snake_Tail;
                apple_x = rand() % width;
                apple_y = rand() % height;
            }
            if (snake_x[0] == Bad_apple_x && snake_y[0] == Bad_apple_y) {
                if (snake_dir == DOWN) {
                    ++snake_y[0];
                }
                if (snake_dir == UP) {
                    --snake_y[0];
                }
                if (snake_dir == LEFT) {
                    --snake_x[0];
                }
                if (snake_dir == RIGHT) {
                    ++snake_x[0];
                }

                Bad_apple_x = rand() % width;
                Bad_apple_y = rand() % height;

            }
            for (int i = snake_Tail -2; i >= 0; --i) {
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
                cout<<"Restart the game? y/n";
                _getch();
                cout<<endl;
                    if (_kbhit()) {
                    switch (_getch ()) {
                        case 'n':
                        return 1;
                        }
                    }
                    if (_kbhit()) {
                    switch (_getch ()) {
                        case 'y':
                        isRunning = true;
                        }
                    }
                }
            for (int i = 1; i < snake_Tail; ++i) {
                if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]) {
                isRunning = false;
                i = snake_Tail;
                }
            }
            
            gotoxy(0, 0);
            cout << "Score: " << snake_Tail << endl;
            ofstream file("Score.txt");
            if (file) {
                file<<snake_Tail;
                file.close();
            }

            Map[apple_y * width + apple_x] = apple;
            Map[Bad_apple_y * width + Bad_apple_x] = Bad_apple;
            
            for (int i = 0; i < snake_Tail; ++i) {
                Map[snake_y[i] * width + snake_x[i]] = snake;
            }
            cout << Map;
            for (int i = 0; i < snake_Tail; ++i) {
                Map[snake_y[i] * width + snake_x[i]] = ' ';
            }
            if (snake_Tail >= 200) {
                cout<<"You win! (y/n to restart)";
                _getch();
                cout<<endl;
                if (_kbhit()) {
                    switch (_getch ()) {
                        case 'n':
                        isRunning = false;
                        }
                    }
                    if (_kbhit()) {
                    switch (_getch ()) {
                        case 'y':
                        isRunning = true;
                        }
                    }
                }
        } 
    }
}