#include <iostream>
using namespace std;

#include "seqlist-struct.h"

int main()
{
    SeqList<int> *L;
    int arr[7] = {1, 4, 7, 11, 15, 19, 23};
    Init(L, arr, 7);
    Print(L);

    


    return 0;
}