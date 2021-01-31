#include<iostream>
#include<cstdio>
using namespace std;

#include"Tree-struct.h"

int main()
{	
	Tree<char> *T;
	string str1;
	cout<<"input the char seq to create a tree: "<<endl;
	cin>>str1;	
	
	CreateBiTree(T, str1);
	Print(T);
	
	cout<<"hello world"<<endl;
	return 0;
}
								   
/*ABC##DE#G##F###*/

