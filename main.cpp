#include <iostream>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score; // 머리위치, 과일위치, 점수

enum eDir {STOP = 0, LEFT, RIGHT, UP, DWON;} 
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
    for(int i(0); i < width+2; i++) // 상단 벽
        cout << "#";
    cout << endl;

    for(int i(0); i < height; i++)
    {
        for(int j(0); j<width; j++)
        {
            if(j == 0) // 왼쪽벽면 
                cout << "#";
            else
            {
                cout << " ";
            }

            if(j == width-1) // 오른쪽 벽면
                cout << "#"; 
            
        }
        cout << endl;
    }

    for(int i(0); i < width+2; i++) // 하단 벽 
        cout << "#";
    cout<< endl;
}

void Input()
{

}

void Logic()
{

}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
    }

    return 0;
}