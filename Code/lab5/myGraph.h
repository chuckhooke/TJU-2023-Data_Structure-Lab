#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class EdgeNode{ // �߽ڵ���
private:
    int dest; // �ߵ��յ��±꣨��0��ʼ��
    EdgeNode* link; // ָ����һ���߽ڵ�

public:
    EdgeNode();
    EdgeNode(int, EdgeNode*);
    ~EdgeNode();
    int getDest();
    EdgeNode* getNext();
    void setDest(int);
    void setNext(EdgeNode*);
};

class VertexNode{ // ����ڵ���
private:
    char data; // ����ڵ�ֵ
    EdgeNode* firstEdge; // �߽ڵ������ͷ

public:
    VertexNode();
    VertexNode(char, EdgeNode*);
    ~VertexNode();
    char getData();
    EdgeNode* getFirstEdge();
    void setData(char);
    void setFirstEdge(EdgeNode*);
};

class MyGraph{ // ͼ��
private:
    int nodeNum; // ������Ŀ
    int edgeNum; // ����Ŀ
    VertexNode* VexList; // �ڽӱ�

public:
    MyGraph();
    MyGraph(int, int, char*, int*, int*);
    ~MyGraph();
    int getNodeNum();
    int getEdgeNum();
    string printGraph(); // ��ӡͼ

    // ��������
    void DFS(int, int*, string&);
    void BFS(int, int*, string&);
    int getFirstNeighbor(int, int*);
    int getNextNeighbor(int, int, int*);

    // DFS��BFS����
    string graph_BFS_Traverse();
    string graph_DFS_Traverse();
};


#endif // MYGRAPH_H_INCLUDED
