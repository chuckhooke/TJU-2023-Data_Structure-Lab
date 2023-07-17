#ifndef MYSEARCH_H_INCLUDED
#define MYSEARCH_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class SSTable{ // 顺序查找表类
private:
    int length; // 元素个数
    int* origin; // 元素

public:
    SSTable();
    SSTable(int, int*);
    ~SSTable();
    int getLength();
    int* getOrigin();
    void setLength(int);
    void setOrigin(int*);
    int binSearch(int); // 折半查找，返回元素的下标（从0开始），不存在返回-1
};

class BSTreeNode{ // 二叉排序树节点类
private:
    int data; // 节点值
    BSTreeNode* lchild; // 左子树
    BSTreeNode* rchild; // 右子树

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

class BSTree{ // 二叉排序树类
private:
    int num; // 排序树节点个数
    BSTreeNode* root; // 排序树根节点

public:
    BSTree();
    BSTree(int, int*); // 排序树初始化
    ~BSTree();
    int getNum();
    BSTreeNode* getRoot();
    void setRoot(BSTreeNode*);
    void setNum(int);
    string printTree(); // 前序遍历输出排序树
    bool searchNode(int); // 排序树查找，找到返回true，未找到返回false
    bool addNode(int); // 排序树添加节点
    bool deleteNode(int); // 排序树删除节点，删除成功返回true，所删除的节点不存在返回false
};

#endif // MYSEARCH_H_INCLUDED
