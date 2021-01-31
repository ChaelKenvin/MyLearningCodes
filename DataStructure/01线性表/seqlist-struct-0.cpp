#include <iostream>
using namespace std;

const int MAX = 100;

struct LNode
{
	int data[MAX];
	int Last;
} * List;

LNode *MakeEmpty()
{
	LNode *PtrL;
	PtrL = new (LNode);
	PtrL->Last = -1;
	return PtrL;
}

int Find(int X, LNode *PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->data[i] != X)
		i++;
	if (i > PtrL->Last)
		return -1;
	else
		return i;
}

void Insert(int X, int i, LNode *PtrL)
{
	int j;
	if (PtrL->Last == MAX - 1)
	{
		cout << "the list is full!" << endl;
		return;
	}
	if (i < 1 || i > PtrL->Last + 2)
	{
		cout << "the position is invalid!" << endl;
		return;
	}
	for (j = PtrL->Last; j >= i; j--)
	{
		PtrL->data[j + 1] = PtrL->data[j];
	}
	PtrL->data[i - 1] = X;
	PtrL->Last++;
}

void Delete(int i, LNode *PtrL)
{
	int j;
	if (i < 1 || i > PtrL->Last + 1)
	{
		cout << "the element doesnot exist!" << endl;
		return;
	}
	for (j = i; j <= PtrL->Last; j++)
	{
		PtrL->data[j - 1] = PtrL->data[j];
	}
	PtrL->Last--;
	return;
}

void show(LNode *PtrL)
{
	LNode *p = PtrL;
	cout << "the list is: ";
	for (int i = 0; i < p->Last + 1; i++)
	{
		cout << p->data[i] << ' ';
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	List = MakeEmpty();
	for (int i = 1; i <= 10; i++)
	{
		Insert(i * 11, i, List);
	}
	// for(int i=0;i<10;i++)
	// {
	// 	cout<<List->data[i]<<' ';
	// }
	show(List);
	cout << List->Last + 1;
	return 0;
}
