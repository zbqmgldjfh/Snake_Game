# Snake_Game
 
## 컴퓨터공학 포토폴리오 김지우

<img src = "https://user-images.githubusercontent.com/60593969/104793572-917e4c00-57e6-11eb-83b0-796b9b6f6d77.gif" width="700px">\

**간단한 C++ 연습용 게임 만들기**

## Code 설명

Logic함수 내부의 꼬리가 머리를 따라오는 코드를 설명하겠습니다.
```C
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
    ...
}
```

tailX[0]과 tailY[0]은 머리가 있던 위치를 저장합니다.
```C
    tailX[0] = x; // 첫꼬리는 머리에 붙어서 
    tailY[0] = y;
```

따라서 머리의 좌표가 1(행),1(열) 이라면 
```
     1234
    1Oooo
    2
```
머리가 2(행),1(열)로 움직일때 첫꼬리는 1,1의 정보를 갖고있으니 1,1 지역에 출력됩니다.
```
     1234
    1ooo
    2O
```

다음으로는 반복문을 사용해 추가적인 꼬리들을 구현합니다.   
i가 1부터 시작하는 이유는 2번째 꼬리이기 때문입니다. i==0은 첫번째 꼬리입니다.
```C
    for (int i(1); i < nTail; i++) // 꼬리가 따라오는 
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
```

총 꼬리의 길이인 nTail만큼 반복문일 실행하며, 좌표의 교환방식은 마치 포인터를 활용한 변수값의 교환과 같은 방식입니다.   
1) 우선 prev2X와 2Y에 tailX[1], tailY[1]의 정보를 저장해놉니다.  
2) 반복문 위에서 정해준 꼬리1의 위치인 tailX[0],tailY[0](1행1열)을 꼬리2(tailX[1], tailY[1]) 에게 넘겨줍니다.
3) prev2X와 2Y에 담긴 tailX[1], tailY[1]의 꼬리2의 정보를 prevX,Y에 저장합니다.
4) 다시 반복합니다.
    
간단히 다음꼬리가 이전꼬리의 정보를 저장하고, 이를 반복한다. 라고 생각하면 됩니다.

나머지 코드를 간단하여 주석의 설명을 봐주시면 감사하겠습니다.
