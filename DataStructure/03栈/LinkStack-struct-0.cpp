#include <iostream>
using namespace std;

template <class T>
struct Stack
{
    T data;
    Stack<T> *next;
};

template <class T>
void Init(Stack<T> *&S)
{
    S = new Stack<T>;
    S->next = NULL;
}

template <class T>
bool IsEmpty(Stack<T> *&S)
{
    if (S->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Print(Stack<T> *&S)
{
    if (IsEmpty(S))
    {
        cerr << "Print stack error: S is empty!" << endl;
        return;
    }
    else
    {
        Stack<T> *p = S->next;
        while (p != NULL)
        {
            cout << p->data << ' ';
            p = p->next;
        }
    }
    cout << endl;
}

template <class T>
int Length(Stack<T> *&S)
{
    int len;
    if (IsEmpty(S))
    {
        len = 0;
    }
    else
    {
        Stack<T> *p = S->next;
        while (p)
        {
            len++;
            p = p->next;
        }
    }
    return len;
}

template <class T>
void Push(Stack<T> *&S, T X)
{
    Stack<T> *p = S;
    Stack<T> *temp = new Stack<T>;
    temp->data = X;
    temp->next = p->next;
    p->next = temp;
}

template <class T>
T Pop(Stack<T> *&S)
{
    if (IsEmpty(S))
    {
        cerr << "Pop error: S is empty!" << endl;
        exit(1);
    }
    else
    {
        Stack<T> *p = S->next;
        S->next = p->next;
        T value = p->data;
        delete p;
        return value;
    }
}

template <class T>
T Top(Stack<T> *&S)
{
    if (IsEmpty(S))
    {
        cerr << "Get top error: S is empty!" << endl;
        exit(1);
    }
    else
    {
        Stack<T> *p = S->next;
        return p->data;
    }
}

int main()
{
    Stack<int> *S;
    Init(S);
    for (int i = 0; i < 10; i++)
    {
        Push(S, i + 1);
    }
    cout << Length(S) << endl;
    Print(S);
    cout<<Pop(S)<<endl;
    Print(S);
    return 0;
}