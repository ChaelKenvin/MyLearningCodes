#include <iostream>
using namespace std;

#include"../../Coding/数据结构/07树/SearchTree-struct.h"

int main()
{
    SearchTree<int> *root;
    Init(root);

    Insert(root, 6);
    Insert(root, 2);
    Insert(root, 8);
    Insert(root, 1);
    Insert(root, 4);
    Insert(root, 3);
    Insert(root, 7);
    // Insert(root, 10);

    cout<<"the tree is: "<<endl;
    Print(root, -1);
    cout<<endl;

    // SearchTree<int> *t1 = FindMin(root->right);
    // cout<<"min is "<<t1->data<<endl;
    // SearchTree<int> *t2 = FindMax(root->right);
    // cout<<"max is "<<t2->data<<endl;
    return 0;
}