#include<iostream>
using namespace std;

struct ListPoint
{
	int data;
	ListPoint *next;
}*List;

ListPoint *MakeEmpty()
{
	ListPoint *L = new (ListPoint);
	L = NULL;
	return L;
}

ListPoint *FindKth(int K, ListPoint *PtrL)
{
	ListPoint *p = PtrL;
	int i=1;
	while(p!=NULL&&i<K)
	{
		p=p->next;
		i++;
	}
	if(i==K) return p;
	else return NULL;
}

ListPoint *Find(int X,ListPoint *PtrL)
{
	ListPoint *p=PtrL;
	while(p!=NULL&&p->data!=X)
	{
		p=p->next;
	}
	return p;
}

int length(ListPoint *PtrL)
{
	ListPoint *p=PtrL;
	int j=0;
	while(p!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;
}

ListPoint *Insert(int X ,int i, ListPoint *PtrL)
{
	ListPoint *p,*s;
	if(i==1)
	{
		s = new (ListPoint);
		s->data=X;
		s->next=PtrL;
		return s;
	}
	p=FindKth(i-1,PtrL);
	if(p==NULL)
	{
		cerr<<"error!"<<endl;
		return NULL;
	}
	s= new (ListPoint);
	s->data=X;
	s->next=p->next;
	p->next=s;
	return PtrL;
}

ListPoint *Delete(int i,ListPoint *PtrL)
{
	ListPoint *p,*s;
	if(i==1)
	{
		s=PtrL;
		if(PtrL==NULL) PtrL=PtrL->next;
		else return PtrL;
		delete(s);
		return PtrL;
	}
	p=FindKth(i-1,PtrL);
	if(p==NULL)
	{
		cerr<<"No. "<<i-1<<" node doesnot exist!"<<endl;
		return NULL;
	}
	if(p->next==NULL)
	{
		cerr<<"No. "<<i<<" node doesnot exist!"<<endl;
		return NULL;
	}
	else
	{
		s=p->next;
		p->next=s->next;
		delete(s);
		return PtrL;
	}
}

void show(ListPoint *PtrL)
{
	ListPoint *p=PtrL;
	while(p)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
}

int main()
{
	List = MakeEmpty();
	for(int i=1;i<=10;i++)
	{
		List=Insert(i*11,i,List);
	}
	cout<<length(List)<<endl;
	ListPoint *p=FindKth(3,List);
	cout<<p->data<<endl;
	show(List);
	return 0;
}