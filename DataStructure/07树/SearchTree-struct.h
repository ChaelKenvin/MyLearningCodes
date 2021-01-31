
//查找二叉树

template <class T>
struct SearchTree
{
    T data;
    SearchTree<T> *left;
    SearchTree<T> *right;
};

template <class T>
void Init(SearchTree<T> *&t)
{
    t = new SearchTree<T>;
    t->left = NULL;
    t->right = NULL;
}

template <class T>
SearchTree<T> *MakeEmpty(SearchTree<T> *&t)
{
    if (t != NULL)
    {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        delete t;
    }
    return NULL;
}

template <class T>
SearchTree<T> *Find(T X, SearchTree<T> *&t)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (X < t->data)
    {
        return Find(X, t->left);
    }
    else if (X > t->data)
    {
        return Find(t->right);
    }
    else //X == t->data
    {
        return t;
    }
}

template <class T>
SearchTree<T> *FindMin(SearchTree<T> *&t)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->left == NULL)
    {
        return t;
    }
    else
    {
        return FindMin(t->left);
    }
}

template <class T>
SearchTree<T> *FindMax(SearchTree<T> *&t)
{
    // if (t != NULL)
    // {
    //     while (t->right != NULL)
    //     {
    //         t = t->right;
    //     }
    // }
    // return t;
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->right == NULL)
    {
        return t;
    }
    else
    {
        return FindMax(t->right);
    }
}

template <class T>
SearchTree<T> *Insert(SearchTree<T> *&t, T X)
{
    SearchTree<T>* temp = t;
    if (temp == NULL)
    {
        temp = new SearchTree<T>;
        if (temp == NULL)
        {
            cerr << "out of space !" << endl;
            exit(1);
        }
        else
        {
            temp->data = X;
            temp->right = NULL;
            temp->left = NULL; 
        }
    }
    else if(X > temp->data)
    {
        temp->right = Insert(temp->right, X);
    }
    else if (X < temp->data)
    {
        temp->left = Insert(temp->left, X);
    }
    return temp;
}

template <class T>
SearchTree<T> *Delete(T X, SearchTree<T> *&t)
{
    SearchTree<T> *temp = new SearchTree<T>;
    if (t == NULL)
    {
        cerr << "element not found!" << endl;
        exit(1);
    }
    else if (X < t->data)
    {
        t->left = Delete(X, t->left);
    }
    else if (X > t->data)
    {
        t->right = Delete(X, t->right);
    }
    else if (t->left && t->right) //两个孩子
    {
        temp = FindMin(t->right);
        t->data = temp->data;
        t->right = Delete(t->data, t->right);
    }
    else //一个或没有孩子
    {
        temp = t;
        if (t->left == NULL)
        {
            t = t->right;
        }
        else if (t->right == NULL)
        {
            t = t->left;
        }
        delete temp;
    }
    return t;
}

template <class T>
void Print(SearchTree<T> *&t, int n)
{
    if (t == NULL)
    {
        return;
    }
    Print(t->right, n + 1);
    for (int i = 0; i < n; i++)
    {
        cout << "   ";
    }
    if (n >= 0)
    {
        cout << "----";
        cout << t->data << endl;
    }
    Print(t->left, n + 1);
}
