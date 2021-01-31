template <class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};

template <class DataType>
class LinkList
{
public:
    LinkList();
    LinkList(Node<DataType> *p);                  //专门接收复制的链表
    LinkList(DataType a[], int n);                //将一个数组顺序赋值给链表
    ~LinkList();                                  //删除释放链表
    int Length();                                 //获取链表长度
    DataType Get(int i);                          //获取第i个位置的数据
    int Locate(DataType x);                       //获得元素x的位置
    void Insert(int i, DataType x);               //在第i个位置插入元素x
    void InsertAsSeq(DataType x, int method = 1); //递增链表中按大小顺序插入一个x
    DataType Delete(int i);                       //删除位置i的元素并返回
    void PrintList();                             //打印
    bool Increase();                              //判断链表的数据是否递增
    bool Decrease();                              //判断链表的数据是否递减
    void Reverse();                               //单链表反转1
    void Reverse2();                              //单链表反转2
    Node<DataType> *Copy();                       //复制链表，与构造函数2配合使用
private:
    Node<DataType> *first;
};

template <class DataType>
LinkList<DataType>::LinkList() //构造函数
{
    first = new Node<DataType>;
    first->next = 0;
}

template <class DataType>
LinkList<DataType>::LinkList(Node<DataType> *p)
{
    first = new Node<DataType>;
    first = p;
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
    //method_1
    /*first = new Node<DataType>;
	first->next = 0;
	for (int i = 0; i < n; i++)
	{
		this->Insert(i + 1, a[i]);
	}*/
    //method_2
    first = new Node<DataType>;
    Node<DataType> *r = first;
    for (int i = 0; i < n; i++)
    {
        Node<DataType> *s = new Node<DataType>;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

template <class DataType>
LinkList<DataType>::~LinkList() //析构函数
{
    while (first != 0)
    {
        Node<DataType> *q = first;
        first = first->next;
        delete q;
    }
}

template <class DataType>
int LinkList<DataType>::Length() //返回链表的长度
{
    Node<DataType> *p = first->next;
    int count = 0;
    while (p != 0)
    {
        p = p->next;
        count++;
    }
    return count;
}

template <class DataType>
int LinkList<DataType>::Locate(DataType x)
{
    Node<DataType> *p = first->next;
    int count = 1;
    while (p != 0)
    {
        if (p->data == x)
            return count;
        p = p->next;
        count++;
        /* code */
    }
    return 0;
}

template <class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
    Node<DataType> *p = first;
    int count = 0;
    while (p != 0 && count < i - 1) //使p指向第i-1个节点
    {
        p = p->next;
        count++;
    }
    if (p == 0)
        throw "error!";
    else
    {
        Node<DataType> *s = new Node<DataType>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template <class DataType>
void LinkList<DataType>::InsertAsSeq(DataType x, int method)
{
    if (method == 1)
    {
        Node<DataType> *s, *p;
        s = new Node<DataType>;
        s->data = x;
        p = first;

        while (p->next != NULL && p->next->data < x)
            p = p->next;

        s->next = p->next;
        p->next = s;
    }
    else if (method == 2)
    {
        Node<DataType> *s, *p, *pre;
        s = new Node<DataType>;
        s->data = x;
        pre = first;
        p = first->next;
        while (p != NULL && p->data < x)
        {
            pre = p;
            p = p->next;
        }
        s->next = p;
        pre->next = s;
    }
}

template <class DataType>
DataType LinkList<DataType>::Delete(int i)
{
    Node<DataType> *p = first;

    int count = 0;
    while (p != 0 && count < i - 1)
    {
        p = p->next;
        count++;
    }

    if (p == 0 || p->next == 0)
        throw "error!";
    else
    {
        Node<DataType> *q = p->next;
        int x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}

template <class DataType>
void LinkList<DataType>::PrintList()
{
    Node<DataType> *p = first->next;
    cout << "the linklist is: ";
    while (p != 0)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

template <class DataType>
bool LinkList<DataType>::Increase()
{
    Node<DataType> *p = first->next;
    while (p->next != NULL)
    {
        Node<DataType> *q = p->next;
        if (p->data < q->data)
            p = q; //p指向了下一个节点，为后面的判断做准备
        else
            return false;
    }
    return true;
}

template <class DataType>
bool LinkList<DataType>::Decrease()
{
    Node<DataType> *p = first->next;
    while (p->next != NULL)
    {
        Node<DataType> *q = p->next;
        if (p->data > q->data)
            p = q; //p指向了下一个节点，为后面的判断做准备
        else
            return false;
    }
    return true;
}

template <class DataType>
void LinkList<DataType>::Reverse()
{
    Node<DataType> *r, *p, *pre;
    p = first->next;
    pre = NULL;

    while (p != NULL)
    {
        r = p->next;
        p->next = pre;
        pre = p;
        p = r;
    }
    first->next = pre;
}

template <class DataType>
void LinkList<DataType>::Reverse2()
{
    Node<DataType> *p, *u;
    p = first->next;
    first->next = 0; //原来的first->next=NULL但p是新的节点，p!=NULL
    while (p != NULL)
    {
        u = p->next;
        p->next = first->next; //第一次循环时p->next=NULL
        first->next = p;
        p = u;
    }
}

template <class DataType>
Node<DataType> *LinkList<DataType>::Copy()
{
    Node<DataType> *p, *head, *r, *s;
    p = first->next;
    /*r = new (Node<DataType>);
	head = r;*/
    head = new (Node<DataType>);
    r = head;
    while (p != NULL)
    {
        s = new (Node<DataType>);
        s->data = p->data;
        r->next = s;
        r = s;
        p = p->next;
    }
    r->next = NULL;
    return head;
}
