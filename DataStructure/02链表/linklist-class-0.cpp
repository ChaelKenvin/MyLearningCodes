#include <iostream>
using namespace std;

#include "LinkList-class.h"

int main()
{
	int arr[] = {11, 22, 33, 44};
	LinkList<int> *list = new (LinkList<int>)(arr, 4);
	list->PrintList();
	cout << "reverse:" << endl;
	list->Reverse2();
	list->PrintList();

	LinkList<int> *list_copy = new (LinkList<int>)(list->Copy());
	cout << "copy a linklist:" << endl;
	list_copy->PrintList();

	list->Reverse();
	list->InsertAsSeq(25, 2);
	list->PrintList();
	return 0;
}
