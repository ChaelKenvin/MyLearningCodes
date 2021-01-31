#include<iostream>
using namespace std;

#include "LinkStack-class.h"

int main()
{
    Stack<int> S;
    for(int i = 0;i < 10; i++)
    {
        S.push(i);
    }
    cout<<S.size()<<endl;
    return 0;
}