#include <iostream>
using namespace std;

const int MAX = 100;

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
    S->top = 0;
    S->data = new T[MAX];
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
int Length(Stack<T> *&S)
{
    return S->top;
}

template <class T>
void Print(Stack<T> *&S)
{
    if (IsEmpty(S))
    {
        cerr << "Stack print error: stack is empty!" << endl;
        return;
    }
    else
    {
        for (int i = S->top - 1; i >= 0; i--)
        {
            cout << *(S->data + i) << " ";
        }
        cout << endl;
        return;
    }
}

template <class T>
void Push(Stack<T> *&S, T X)
{
    if (S->top >= MAX)
    {
        cerr << "Stack push error: stack is full!" << endl;
        return;
    }
    else
    {
        *(S->data + S->top) = X;
        S->top++;
    }
}

template <class T>
T Pop(Stack<T> *&S)
{
    if (IsEmpty(S))
    {
        cerr << "Stack pop error: stack is empty!" << endl;
        exit(1);
    }
    else
    {
        return *(S->data + (--S->top));
    }
}

int main()
{
    cout << "hello world" << endl;
    Stack<int> *S;
    Init(S);
    for (int i = 0; i < 10; i++)
    {
        Push(S, i + 1);
    }
    Print(S);
    // cout<<Pop(S)<<' '<<Pop(S)<<endl;
    cout << Pop(S) << endl;
    cout << Pop(S) << endl;
    Print(S);

    return 0;
}