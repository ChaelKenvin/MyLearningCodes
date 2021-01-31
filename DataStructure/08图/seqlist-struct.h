const int MAX = 100;

template <class T>
struct SeqList
{
    T data[MAX];
    int size;
};

template <class T>
void Init(SeqList<T> *&L)
{
    L = new SeqList<T>;
    L->size = 0;
}

template <class T>
void Init(SeqList<T> *&L, T arr[], int n)
{
    Init(L);
    int num;
    if (n >= MAX)
    {
        num = MAX;
    }
    else
    {
        num = n;
    }
    for (int i = 0; i < n; i++)
    {
        L->data[i] = arr[i];
        L->size++;
    }
}

template <class T>
int Length(SeqList<T> *&L)
{
    return L->size;
}

template <class T>
bool IsEmpty(SeqList<T> *&L)
{
    if (L->size <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Print(SeqList<T> *&L)
{
    if (IsEmpty(L))
    {
        cerr << "Print error: seqlist is empty!" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < L->size; i++)
        {
            cout << L->data[i] << " ";
        }
    }
    cout << endl;
}

template <class T>
void Insert(SeqList<T> *&L, int pos, T X)
{
    if (L->size >= MAX)
    {
        cerr << "Insert error: seqlist is full!" << endl;
        return;
    }
    if (pos > L->size || pos < 0)
    {
        cerr << "Insert error: pos is invalid!" << endl;
        return;
    }
    else
    {
        for (int i = L->size - 1; i >= pos; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos] = X;
        L->size++;
    }
}

template <class T>
T Delete(SeqList<T> *&L, int pos)
{
    if (IsEmpty(L))
    {
        cerr << "Delete error: seqlist is empty!" << endl;
        return NULL;
    }

    if (pos < 0 || pos > L->size)
    {
        cerr << "Delete error: pos is invalid!" << endl;
        return NULL;
    }

    else
    {
        T temp = L->data[pos];
        for (int i = pos + 1; i < L->size; i++)
        {
            L->data[i] = L->data[i + 1];
        }
        L->size--;
        return temp;
    }
}

template <class T>
T Get(SeqList<T> *&L, int pos)
{
    if (pos < 0 || pos >= L->size)
    {
        cerr << "Get error: pos is invalid!" << endl;
    }
    else
    {
        return L->data[pos];
    }
}
