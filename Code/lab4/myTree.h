#include <iostream>
#include <string.h>

using namespace std;

typedef enum{Link, Thread} NodeTag;

class TreeNode
{
private:
    char data;              //值
    TreeNode* leftChild;    //左孩子
    TreeNode* rightChild;   //右孩子
    NodeTag lTag, rTag;     //线索Tag

    friend class MyTree;    //树类
public:
    TreeNode(char, TreeNode*, TreeNode*, NodeTag, NodeTag);
    TreeNode();
    ~TreeNode();

    void printNode();
    char getdata() const;
    NodeTag getltag() const;
    NodeTag getrtag() const;
    TreeNode* getlchild() const;
    TreeNode* getrchild() const;
};

class MyTree
{
private:
     TreeNode* root;        //根指针
     bool isThread;         //线索二叉树标志
public:
    MyTree();               //无参构造
    MyTree(const char[]);   //构造函数
    MyTree(const MyTree&);  //拷贝函数
    ~MyTree();              //析构函数

    TreeNode* constructTree(const char* preorder, int& index);
    TreeNode* copySubtree(TreeNode* node);
    void deleteSubtree(TreeNode* node);
    void clearThread(TreeNode* node);
    TreeNode*getNextInOrderNode(TreeNode* node) ;
    void preOrderTraverse();    //前序遍历
    void inOrderTraverse();     //中序遍历
    void postOrderTraverse();   //后序遍历
    int countLeaf();            //叶结点计数
    int countHeight();          //计算树的深度
    bool isThreadedTree();      //判断是否为线索二叉树
    bool inOrderThreading();    //线索化
    void inOrderThreadingHelper(TreeNode* node, TreeNode*& pre);
    TreeNode& locateNode(const char&);  //结点定位
    TreeNode& preNode(const TreeNode&); //获取前驱结点
    TreeNode& nextNode(const TreeNode&);//获取后继结点

};


class HuffmanTreeNode
{
private:
    int data;              //值
    HuffmanTreeNode* leftChild;    //左孩子
    HuffmanTreeNode* rightChild;   //右孩子

    friend class HuffmanTree;    //树类
public:
    HuffmanTreeNode(int, HuffmanTreeNode*, HuffmanTreeNode*);
    HuffmanTreeNode();
    ~HuffmanTreeNode();

    void printNode();
    int getdata() const;
    HuffmanTreeNode* getlchild() const;
    HuffmanTreeNode* getrchild() const;
};

class HuffmanTree
{
private:
    //添加必要的数据成员
    HuffmanTreeNode* root;        //根指针
  
public:
    HuffmanTree(const int&,const int[]);    //构造函数
    ~HuffmanTree();     //析构函数

    //输出哈夫曼编码
    //格式为：每行输出一个节点，节点排序递减
    //节点1值：编码
    //节点2值：编码
    //....
    //cpp中未给出该函数，遵守输出格式规范
    void destroyHuffmanTree(HuffmanTreeNode*);
    void printHuffmanCodes();  
    void printHuffmanCodesHelper(HuffmanTreeNode* , string ) ;
    class Compare {
public:
    bool operator()(const HuffmanTreeNode* a, const HuffmanTreeNode* b) const {
        return (*a).getdata() > (*b).getdata();
    }
};


};


