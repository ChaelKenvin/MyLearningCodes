template <class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};

template <class DataType>
class Queue
{
public:
    Queue();
    ~Queue();
    bool empty();
    void push(DataType x);
    void pop();
    int size();
    void print();
    DataType get_front();
    DataType get_rear();

private:
    Node<DataType> *front;
    Node<DataType> *rear;
};

template <class DataType>
Queue<DataType>::Queue()
{
    this->front = NULL;
    this->rear = NULL;
}

template <class DataType>
Queue<DataType>::~Queue()
{
    Node<DataType> *p, *p1;
    p = this->front;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        delete (p);
    }
}

template <class DataType>
bool Queue<DataType>::empty()
{
    if (this->front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class DataType>
void Queue<DataType>::push(DataType x)
{
    Node<DataType> *p;
    p = new (Node<DataType>);

    p->data = x;
    p->next = NULL;
    if (this->rear != NULL)
    {
        this->rear->next = p;
    }
    this->rear = p;
    if (this->front == NULL)
    {
        this->front = p;
    }
    return;
}

template <class DataType>
void Queue<DataType>::pop()
{
    Node<DataType> *p;

    if (this->front == NULL)
    {
        cerr << "queue pop error: queue is empty!" << endl;
        return;
    }
    p = this->front;
    this->front = this->front->next;
    if (this->front == NULL)
    {
        this->rear = NULL;
    }
    delete (p);
    return;
}

template <class DataType>
int Queue<DataType>::size()
{
    Node<DataType> *p = new (Node<DataType>);
    p = this->front;
    int j = 0;
    while (p != NULL)
    {
        j++;
        p = p->next;
    }
    delete (p);
    return j;
}

template <class DataType>
void Queue<DataType>::print()
{
    Node<DataType> *p = new (Node<DataType>);
    p = this->front;
    if (p == NULL)
    {
        cerr << "queue print error: queue is empty!" << endl;
        exit(1);
    }
    else
    {
        while (p != NULL)
        {
            cout << p->data << ' ';
            p = p->next;
        }
    }
    delete (p);
    return;
}

template <class DataType>
DataType Queue<DataType>::get_front()
{
    if (this->front == NULL)
    {
        cerr << "queue get front error: queue is empty!" << endl;
        exit(1);
    }
    else
    {
        return this->front->data;
    }
}

template <class DataType>
DataType Queue<DataType>::get_rear()
{
    if (this->rear == NULL)
    {
        cerr << "queue get rear error: queue is empty!" << endl;
        exit(1);
    }
    else
    {
        return this->rear->data;
    }
}
