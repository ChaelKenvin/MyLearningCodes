template <class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};

template <class DataType>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(DataType x);
    void pop();
    DataType top();
    bool empty();
    int size();

private:
    Node<DataType> *head;
};

template <class DataType>
Stack<DataType>::Stack()
{
    head = new (Node<DataType>);
    head->next = NULL;
}

template <class DataType>
Stack<DataType>::~Stack()
{
    Node<DataType> *p, *p1;
    p = head;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        delete (p1);
    }
}

template <class DataType>
void Stack<DataType>::push(DataType x)
{
    Node<DataType> *p = new (Node<DataType>);
    p->data = x;
    p->next = head->next;
    head->next = p;
}

template <class DataType>
void Stack<DataType>::pop()
{
    Node<DataType> *p = head->next;
    head->next = p->next;
    delete (p);
}

template <class DataType>
DataType Stack<DataType>::top()
{
    Node<DataType> *p = head->next;
    if (p == NULL)
    {
        cerr << "stack top error: stack is empty!" << endl;
        exit(1);
    }
    else
    {
        return p->data;
    }
}

template <class DataType>
bool Stack<DataType>::empty()
{
    Node<DataType> *p = head->next;
    if (p == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class DataType>
int Stack<DataType>::size()
{
    int j = 0;
    Node<DataType> *p = head->next;
    while (p != NULL)
    {
        p = p->next;
        j++;
    }
    return j;
}