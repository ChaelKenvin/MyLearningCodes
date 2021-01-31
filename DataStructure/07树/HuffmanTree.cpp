/*
-------------------------
C++ 哈夫曼树
-------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

//叶子节点数
const int n = 10;

template <class T>
struct Tree
{
    T data;
    int weight;
    Tree<T> *left;
    Tree<T> *right;
};

//初始化叶子节点
template <class T>
Tree<T> *InitLeaf(T data_, int w, Tree<T> *LeftNode = NULL, Tree<T> *RightNode = NULL)
{
    Tree<T> *t = new Tree<T>;
    t->data = data_;
    t->weight = w;
    t->left = LeftNode;
    t->right = RightNode;
    return t;
}

//打印二叉树
template <class T>
void Print(Tree<T> *&t, int n = -1)
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
        cout << "---- ";
        cout << t->data << endl;
    }
    Print(t->left, n + 1);
}

//创建保存二叉树节点的向量
vector<Tree<char> *> V;

int main()
{
    //哈夫曼树的叶子节点用具体字母表示
    Tree<char> *Trees[n] =
        {
            InitLeaf('A', 4),
            InitLeaf('B', 5),
            InitLeaf('C', 1),
            InitLeaf('D', 2),
            InitLeaf('E', 3),
            InitLeaf('F', 10),
            InitLeaf('G', 7),
            InitLeaf('H', 8),
            InitLeaf('I', 6),
            InitLeaf('J', 9),
        };

    for (int i = 0; i < n; i++)
    {
        V.push_back(Trees[i]);
    }

    while (V.size() > 1) //当向量中只剩下一个节点时它就是所求的哈夫曼树
    {
        Tree<char> *MinTree1, *MinTree2;

        //找权值最小的节点
        int min1 = 0;
        for (int i = 0; i < V.size(); i++)
        {
            if (V[i]->weight <= V[min1]->weight)
            {
                min1 = i;
            }
        }
        MinTree1 = V[min1];        //从向量里取出节点存在mintree1中
        V.erase(V.begin() + min1); //从向量里删除这个节点

        //找权值第二小的节点
        int min2 = 0;
        for (int i = 0; i < V.size(); i++)
        {
            if (V[i]->weight <= V[min2]->weight)
            {
                min2 = i;
            }
        }
        MinTree2 = V[min2];
        V.erase(V.begin() + min2);

        //为两个节点添加同一个父节点并存入向量中
        Tree<char> *Father = new Tree<char>;
        Father->data = 'X'; //哈夫曼树的非叶子节点用X表示
        Father->weight = MinTree1->weight + MinTree2->weight;
        Father->left = MinTree1;
        Father->right = MinTree2;
        V.push_back(Father);

        //重新调整向量的大小
        // V.shrink_to_fit();
    }

    Tree<char> *HuffmanTree = *V.begin();
    Print(HuffmanTree, 0);

    V.clear();
    system("pause");
    return 0;
}
