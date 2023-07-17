#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class EdgeNode{ // 边节点类
private:
    int dest; // 边的终点下标（从0开始）
    EdgeNode* link; // 指向下一个边节点

public:
    EdgeNode();
    EdgeNode(int, EdgeNode*);
    ~EdgeNode();
    int getDest();
    EdgeNode* getNext();
    void setDest(int);
    void setNext(EdgeNode*);
};

class VertexNode{ // 顶点节点类
private:
    char data; // 顶点节点值
    EdgeNode* firstEdge; // 边节点链表表头

public:
    VertexNode();
    VertexNode(char, EdgeNode*);
    ~VertexNode();
    char getData();
    EdgeNode* getFirstEdge();
    void setData(char);
    void setFirstEdge(EdgeNode*);
};

class MyGraph{ // 图类
private:
    int nodeNum; // 顶点数目
    int edgeNum; // 边数目
    VertexNode* VexList; // 邻接表

public:
    MyGraph();
    MyGraph(int, int, char*, int*, int*);
    ~MyGraph();
    int getNodeNum();
    int getEdgeNum();
    string printGraph(); // 打印图

    // 辅助函数
    void DFS(int, int*, string&);
    void BFS(int, int*, string&);
    int getFirstNeighbor(int, int*);
    int getNextNeighbor(int, int, int*);

    // DFS、BFS函数
    string graph_BFS_Traverse();
    string graph_DFS_Traverse();
};


#endif // MYGRAPH_H_INCLUDED
