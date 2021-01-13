#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score; // 머리위치, 과일위치, 점수
int tailX[100], tailY[100]; // 꼬리의 좌표
int nTail;

enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDir dir; //

void Setup()
{
    gameOver = false; // 기본은 flase임, 종료시 true로 변환
    dir = STOP; // 움직이지 않는 상태 
    x = width / 2; // snake 시작위치를 중심으로 
    y = height / 2;
    fruitX = rand() % width;  // 과일 위치는 랜덤으로 
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls"); // 이방식 때문에 화면이 깜빡임...
    for (int i(0); i < width + 2; i++) // 상단 벽
        cout << "#";
    cout << endl;

    for (int i(0); i < height; i++)
    {
        for (int j(0); j < width; j++)
        {
            if (j == 0) // 왼쪽벽면 
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX) // random위치의 fruit
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i) // 위치에 맞으면 꼬리출력
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) // 아닌경우 빈공간 출력 
                    cout << " ";
            }

            if (j == width - 1) // 오른쪽 벽면
                cout << "#";
        }
        cout << endl;
    }

    for (int i(0); i < width + 2; i++) // 하단 벽 
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

void Input()
{
    if (_kbhit()) // 키보드가 눌렸다면 
    {
        switch (_getch()) // 누른 키값 ASII로 반환
        { // 방향키 handler
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            gameOver = true; // bool값 true로 변경       
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x; // 첫꼬리는 머리에 붙어서 
    tailY[0] = y;

    for (int i(1); i < nTail; i++) // 꼬리가 따라오는 
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    //if (x > width || x < 0 || y > height || y < 0) // 종료조건 
    //    gameOver = true;
    if (x >= width) x = 0; // 벽 통과 가능
    else if (x < 0) x = width - 1;
    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    for (int i(0); i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;  // 과일 위치는 랜덤으로 
        fruitY = rand() % height;
        nTail++; // 과일먹을시 꼬리증가
    }

}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }

    return 0;
}