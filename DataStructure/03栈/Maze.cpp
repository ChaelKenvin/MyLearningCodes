#include <iostream>
using namespace std;

#define NULL 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define UP 4

const int MAX = 250;

//迷宫
bool maze[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

//标记已走过的点
bool mark[10][10];

//---栈---
template <class T>
struct Stack
{
    T *data;
    int top;
};

template <class T>
void Init(Stack<T> *&S)
{
    S = new Stack<T>;
    S->data = new T[MAX];
    S->top = 0;
}

template <class T>
int Length(Stack<T> *&S)
{
    return S->top;
}

template <class T>
bool IsEmpty(Stack<T> *&S)
{
    if (S->top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Push(Stack<T> *&S, T X)
{
    if (Length(S) >= MAX)
    {
        cerr << "stack push error: stack is full!" << endl;
        return;
    }
    else
    {
        *(S->data + S->top) = X;
        S->top++;
    }
}

template <class T>
void Pop(Stack<T> *&S)
{
    S->top--;
}

template <class T>
void Print(Stack<T> *&S)
{
    if (IsEmpty(S))
    {
        cerr << "stack print error: stack is empty" << endl;
        return;
    }
    else
    {
        for (int i = S->top - 1; i >= 0; i--)
        {
            cout << *(S->data + i) << ' ';
        }
        cout << endl;
    }
}

template <class T>
T Top(Stack<T> *&S)
{
    if (IsEmpty(S))
    {
        cerr << "stack top error: stack is empty!" << endl;
        return;
    }
    else
    {
        return *(S->data + (S->top - 1));
    }
}

//---记录点--
struct Point
{
    int x;
    int y;
};

Point SetPoint(int _x, int _y)
{
    Point temp;
    temp.x = _x;
    temp.y = _y;
    return temp;
}

void PrintPoint(Point &p)
{
    cout << "(" << p.x << " , " << p.y << ")";
}

//行走
bool Go(Point &p, int direction)
{
    switch (direction)
    {
    case LEFT:
        p.x--;
        // mark[p->x, p->y] = 1;
        return 1;
    case RIGHT:
        p.x++;
        return 1;
    case DOWN:
        p.y++;
        return 1;
    case UP:
        p.y--;
        return 1;
    default:
        break;
    }
    return 0;
}

//寻找哪边能走且没走过
int Search(Point &p)
{
    //右边能走并且没走过
    if (maze[p->x, p->y + 1] && !mark[p->x, p->y + 1])
    {
        return RIGHT;
    }
    //下面能走并且没走过
    else if (maze[p->x + 1, p->y] && !mark[p->x + 1, p->y])
    {
        return DOWN;
    }
    //左边能走并且没走过
    else if (maze[p->x, p->y - 1] && !mark[p->x, p->y - 1])
    {
        return LEFT;
    }
    //上面能走并且没走过
    else if (maze[p->x - 1, p->y] && !mark[p->x - 1, p->y])
    {
        return UP;
    }
    //都不能走
    else
    {
        return NULL;
    }
}

int main()
{
    Point start = SetPoint(1, 1);
    Point end = SetPoint(8, 8);

    Stack<Point> *S;
    Init(S);

    Point curr = start;

    Push(S, start);

    do
    {
        switch (Search(curr))
        {
        case LEFT:
        {
            curr = Top(S);
            if(Go(curr, LEFT))
            {
                Push(S, curr);
            }
            //记录下这一点已走过
            break;
        }
        
        case NULL:
        {
            Pop(S);
            break;
        }
        }
    } while (!IsEmpty(S));

    return 0;
}