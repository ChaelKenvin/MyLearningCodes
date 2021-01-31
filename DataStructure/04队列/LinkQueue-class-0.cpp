#include<iostream>
using namespace std;

#include "LinkQueue-class.h"

int main()
{
    Queue<int> Q;
    for(int i = 0; i < 10; i++)
    {
        Q.push(i + 1);
    }
    cout<<Q.size()<<endl;
    Q.print();
    return 0;
}