#include <iostream>
#include<cstring>
using namespace std;

#include "Tree-struct.h"

int main()
{
    /*
    Tree<char> *root, *t1, *t2;
    Initiate(root);

    t1 = InsertLeftNode(root, 'A');
    t1 = InsertLeftNode(t1, 'B');
    t1 = InsertLeftNode(t1, 'D');
    t1 = InsertRightNode(t1, 'G');
    t1 = InsertRightNode(root->LeftChild, 'C');

    t2 = t1;
    InsertLeftNode(t1, 'E');
    InsertRightNode(t2, 'F');

    Print(root, -1);

    // cout<<"--------------------"<<endl;
    // root = DeleteLeftTree(root->LeftChild);
    // Print(root, -1);

    // cout<<"--------------------"<<endl;
    // root = DeleteRightTree(root->LeftChild);
    // Print(root, -1);

    Traverse(root->LeftChild);

    cout<<endl;
    cout<<"number of nodes: "<<Number(root->LeftChild)<<endl;
    cout<<"number of leaves: "<<Leaves(root->LeftChild)<<endl;
    cout<<"height is: "<<Height(root->LeftChild)<<endl;

    cout<<"exchange left and right"<<endl;
    Exchange(root->LeftChild);
    Print(root);

    Tree<char>* root_;
    Copy(root, root_);
    cout << "copy: " << endl;
    Print(root_);
    */
    Tree<char>* ExTreeRoot;
    CreateExpressionTree(ExTreeRoot, "+*98*-14/823", 13);
    Print(ExTreeRoot, 0);
    return 0;
}
