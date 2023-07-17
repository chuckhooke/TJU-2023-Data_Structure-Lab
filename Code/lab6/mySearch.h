#ifndef MYSEARCH_H_INCLUDED
#define MYSEARCH_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class SSTable{ // ˳����ұ���
private:
    int length; // Ԫ�ظ���
    int* origin; // Ԫ��

public:
    SSTable();
    SSTable(int, int*);
    ~SSTable();
    int getLength();
    int* getOrigin();
    void setLength(int);
    void setOrigin(int*);
    int binSearch(int); // �۰���ң�����Ԫ�ص��±꣨��0��ʼ���������ڷ���-1
};

class BSTreeNode{ // �����������ڵ���
private:
    int data; // �ڵ�ֵ
    BSTreeNode* lchild; // ������
    BSTreeNode* rchild; // ������

public:
    BSTreeNode();
    BSTreeNode(int);
    BSTreeNode(int, BSTreeNode*, BSTreeNode*);
    ~BSTreeNode();
    int getData();
    BSTreeNode* getLChild();
    BSTreeNode* getRChild();
    void setData(int);
    void setLChild(BSTreeNode*);
    void setRChild(BSTreeNode*);

};

class BSTree{ // ������������
private:
    int num; // �������ڵ����
    BSTreeNode* root; // ���������ڵ�

public:
    BSTree();
    BSTree(int, int*); // ��������ʼ��
    ~BSTree();
    int getNum();
    BSTreeNode* getRoot();
    void setRoot(BSTreeNode*);
    void setNum(int);
    string printTree(); // ǰ��������������
    bool searchNode(int); // ���������ң��ҵ�����true��δ�ҵ�����false
    bool addNode(int); // ��������ӽڵ�
    bool deleteNode(int); // ������ɾ���ڵ㣬ɾ���ɹ�����true����ɾ���Ľڵ㲻���ڷ���false
};

#endif // MYSEARCH_H_INCLUDED
