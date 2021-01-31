#include <queue>

template <class T>
struct Tree
{
    T data;
    Tree<T> *LeftChild;
    Tree<T> *RightChild;
};

template <class T>
void Initiate(Tree<T> *&t)
{
    t = new Tree<T>;
    t->LeftChild = NULL;
    t->RightChild = NULL;
}

template<class T>
void CreateBiTree(Tree<T> *&t, string str)
{
	static int i = 0;
	char ch;
	if(i == str.length())
	{
		return ;
	}
	else
	{
		ch = str[i];
	}
	if(ch == '#')
	{
		t = NULL;
	}
	else
	{
		t = new Tree<T>;
		t->data = ch;
		CreateBiTree(t->LeftChild, str);
		CreateBiTree(t->RightChild, str);
	}
	i++;
}

template <class T>
Tree<T> *InsertLeftNode(Tree<T> *&curr, T x)
{
    Tree<T> *t, *s;

    if (curr == NULL)
    {
        cerr << "insert left node error!" << endl;
        exit(1);
    }
    else
    {
        t = curr->LeftChild;
        s = new Tree<T>;
        s->data = x;
        s->LeftChild = t;
        s->RightChild = NULL;

        curr->LeftChild = s;
        return curr->LeftChild;
    }
}

template <class T>
Tree<T> *InsertRightNode(Tree<T> *&curr, T x)
{
    Tree<T> *t, *s;

    if (curr == NULL)
    {
        cerr << "insert right node error!" << endl;
        exit(1);
    }
    else
    {
        t = curr->RightChild;
        s = new Tree<T>;
        s->data = x;
        s->RightChild = t;
        s->LeftChild = NULL;

        curr->RightChild = s;
        return curr->RightChild;
    }
}

template <class T>
Tree<T> *DeleteLeftTree(Tree<T> *&curr)
{
    if (curr == NULL || curr->LeftChild == NULL)
    {
        cerr << "delete left tree error!" << endl;
        exit(1);
    }
    else
    {
        delete curr->LeftChild;
        curr->LeftChild = NULL;
        return curr;
    }
}

template <class T>
Tree<T> *DeleteRightTree(Tree<T> *&curr)
{
    if (curr == NULL || curr->RightChild == NULL)
    {
        cerr << "delete right tree error!" << endl;
        exit(1);
    }
    else
    {
        delete curr->RightChild;
        curr->RightChild = NULL;
        return curr;
    }
}

template <class T>
void PreOrder(Tree<T> *&t)
{
    if (t != NULL)
    {
        cout << t->data;
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

template <class T>
void InOrder(Tree<T> *&t)
{
    if (t != NULL)
    {
        InOrder(t->LeftChild);
        cout << t->data;
        InOrder(t->RightChild);
    }
}

template <class T>
void PostOrder(Tree<T> *&t)
{
    if (t != NULL)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout << t->data;
    }
}

//交换二叉树左右子树
template <class T>
void Exchange(Tree<T> *&t)
{
    //先序和后序成立，中序不成立
    if (!t || !t->LeftChild && !t->RightChild) return;
    Tree<T> *p = new Tree<T>;
    p = t->RightChild;
    t->RightChild = t->LeftChild;
    t->LeftChild = p;
    Exchange(t->LeftChild);
    Exchange(t->RightChild);
}

//复制二叉树
template<class T>
void Copy(Tree<T>*& t1, Tree<T>*& t2)
{
    if (!t1)
    {
        t2 = NULL;
    }
    else
    {
        t2 = new Tree<T>;
        t2->data = t1->data;
        Copy(t1->LeftChild, t2->LeftChild);
        Copy(t1->RightChild, t2->RightChild);
    }
}

//由前缀表达式创建二叉树
template<class T>
void CreateExpressionTree(Tree<T>*& t, const char str[], int n)
{
    static int i = 0;
    char ch = str[i];
    if (i == n)
    {
        return;
    }
    else
    {
        i++;
    }

    t = new Tree<T>;
    t->data = ch;
    
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
    {
        t->LeftChild = NULL;
        t->RightChild = NULL;
    }
    else
    {
        CreateExpressionTree(t->LeftChild, str, n);
        CreateExpressionTree(t->RightChild, str, n);
    }
}

template <class T>
void Destroy(Tree<T> *&t)
{
    if (t != NULL && t->LeftChild != NULL)
    {
        Destroy(t->LeftChild);
    }
    if (t != NULL && t->RightChild != NULL)
    {
        Destroy(t->RightChild);
    }
    delete t;
}

template <class T>
void Print(Tree<T> *&t, int n = -1)
{
    if (t == NULL)
    {
        return;
    }
    Print(t->RightChild, n + 1);
    for (int i = 0; i < n; i++)
    {
        cout << "   ";
    }
    if (n >= 0)
    {
        cout << "---- ";
        cout << t->data << endl;
    }
    Print(t->LeftChild, n + 1);
}

//层次遍历
template <class T>
void Traverse(Tree<T> *&t)
{
    Tree<T> *p = new Tree<T>;
    if (!t)
    {
        return;
    }
    else
    {
        queue<Tree<T> *> Q;
        Q.push(t);
        while (!Q.empty())
        {
            p = Q.front();
            Q.pop();
            cout << p->data;
            if (p->LeftChild)
                Q.push(p->LeftChild);
            if (p->RightChild)
                Q.push(p->RightChild);
        }
    }
}

//计算节点数
template <class T>
int Number(Tree<T> *&t)
{
    if (!t)
    {
        return 0;
    }
    else
    {
        int nl = Number(t->LeftChild);
        int nr = Number(t->RightChild);
        return (nl + nr + 1);
    }
}

//计算叶子数
template <class T>
int Leaves(Tree<T> *&t)
{
    if (!t)
    {
        return 0;
    }
    if (!t->LeftChild && !t->RightChild)
    {
        return 1;
    }
    else
    {
        int nl = Leaves(t->LeftChild);
        int nr = Leaves(t->RightChild);
        return nl + nr;
    }
}

//计算深度
template <class T>
int Height(Tree<T> *&t)
{
    if (!t)
    {
        return 0;
    }
    else
    {
        int lh = Height(t->LeftChild);
        int rh = Height(t->RightChild);
        int max = lh > rh ? lh : rh;
        return max + 1;
    }
}
