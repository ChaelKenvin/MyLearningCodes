// 邻接矩阵下图操作的实现

#include"seqlist-struct.h"

const int MaxSize = 100;
const int MaxVertices = 10;
const int MaxEdges = 100;
const int MaxWeight = 10000;

//图结构体
struct AdjMGraph
{
    SeqList<char> *Vertices;
    int edge[MaxVertices][MaxVertices];
    int EdgeNum;
};

//图初始化
void Init(AdjMGraph *&G, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                G->edge[i][j] = 0;
            }
            else
            {
                G->edge[i][j] = MaxWeight;
            }
        }
    }
    G->EdgeNum = 0;
    Init(G->Vertices);
}

//在图中插入节点vertex
template <class T>
void InsertVertex(AdjMGraph *G, T vertex)
{
    //
}