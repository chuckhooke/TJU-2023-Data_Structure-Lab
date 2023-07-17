#include "mySearch.h"
#include <iostream>
#include <string>
#include <stack>


using namespace std;

//顺序查找表的建立

SSTable::SSTable(int length,int* origin)
{
    this->length =length;
    this->origin = origin;
}

//其它类初始化、销毁、私有属性存取等基本功能 
SSTable::~SSTable()
{
    length = 0;
    origin = nullptr;
}

int SSTable::getLength()
{
    return length;
}

int* SSTable::getOrigin()
{
    return origin;
}

void SSTable::setLength(int length)
{
    this->length =length;
}

void SSTable::setOrigin(int* origin)
{
    this->origin = origin;
}

//顺序查找表的二分查找方法
int SSTable::binSearch(int val)
{
    int low = 1;
    int high = length;
    int mid= (low + high) / 2;
    while(low <= high){
        mid= (low + high) / 2;
        if(val == origin[mid]) return mid;
        else if(val < origin[mid]) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return -1;
}


//二叉排序树节点类 BSTreeNode
BSTreeNode::BSTreeNode(int data)
{
    this->data = data;
}

BSTreeNode::BSTreeNode(int data, BSTreeNode* lchild, BSTreeNode* rchild)
{
    this->data = data;
    this->lchild = lchild;
    this->rchild = rchild;
}

BSTreeNode::~BSTreeNode()
{
    this->data = 0;
    this->lchild = nullptr;
    this->rchild = nullptr;
}

int BSTreeNode::getData()
{
    return data;
}

BSTreeNode* BSTreeNode::getLChild()
{
    return lchild;
}

BSTreeNode* BSTreeNode::getRChild()
{
    return rchild;
}

void BSTreeNode::setData(int data)
{
    this->data = data;
}

void BSTreeNode::setLChild(BSTreeNode* lchild)
{
    this->lchild = lchild;
}

void BSTreeNode::setRChild(BSTreeNode* rchild)
{
    this->rchild = rchild;
}


//二叉排序树的建立 BSTree(int, int*)
BSTree::BSTree()
{
    num = 0;
    root = nullptr; 
}

BSTree::BSTree(int num, int* data)
{
    this->num = num;
    root = new BSTreeNode(data[0], nullptr, nullptr);
    for(int i = 1; i < num; i++){
        BSTreeNode* p = root;
        BSTreeNode* q = p;
        int flag = 0;
        while(p != nullptr) {
            q = p;
            if(data[i] < p->getData()) {
                flag = 1;
                if(p->getLChild() == nullptr) p = nullptr;
                else p = p->getLChild(); 
            }
            else {
                flag = 2;
                if(p->getRChild() == nullptr) p = nullptr;
                else p = p->getRChild(); 
            }      
        }
        BSTreeNode* lchild = nullptr;  
        BSTreeNode* rchild = nullptr;
        BSTreeNode* bs = new BSTreeNode(data[i], lchild, rchild);
        if(flag == 1){
            q->setLChild(bs);
        }
        else if(flag == 2){
            q->setRChild(bs);
        }
    }
}

BSTree::~BSTree()
{
    num = 0;
    root = nullptr;
}

int BSTree::getNum()
{
    return num;
}

BSTreeNode* BSTree::getRoot()
{
    return root;
}

void BSTree::setNum(int num)
{
    this->num = num;
}

void BSTree::setRoot(BSTreeNode* root)
{
    this->root = root;
}


//二叉排序树的遍历输出 string printTree() 
void printTemp(BSTreeNode* root, string& result)
{
    if(root != nullptr) {
            result += to_string(root->getData()) + " ";
            printTemp(root->getLChild(), result);
            printTemp(root->getRChild(), result); 
        }
}

string BSTree::printTree()
{
    string result;
    printTemp(root, result);
    return result;
}


//二叉排序树的查找 bool searchNode(int)
bool BSTree::searchNode(int val){
    BSTreeNode* p = root;
    while(p != nullptr){
        if(val == p->getData()) return true;
        else if(val < p->getData()) p = p->getLChild();
        else p = p->getRChild();
    }
    return false;
}


//二叉排序树添加节点 bool addNode(int)
bool BSTree::addNode(int val)
{
    BSTreeNode* p = root;
    BSTreeNode* q = p;
    int flag = 0;
    while(p != nullptr) {
        q = p;
        if(val == p->getData()) return false;
        else if(val < p->getData()) {
            flag = 1;
            p = p->getLChild(); 
        }
        else {
            flag = 2;
            p = p->getRChild(); 
        }      
    }
    BSTreeNode* lchild = nullptr;  
    BSTreeNode* rchild = nullptr;
    BSTreeNode* bs = new BSTreeNode(val, lchild, rchild);
    if(flag == 1){
        q->setLChild(bs);
    }
    else if(flag == 2){
        q->setRChild(bs);
    }
    return true;
}


//二叉排序树删除节点 bool deleteNode(int) 
bool BSTree::deleteNode(int val) {
    BSTreeNode* p = root;
    BSTreeNode* q = nullptr;   
    bool found = false;       
    
    while(p != nullptr && !found) {
        if(val < p->getData()) {
            q = p;
            p = p->getLChild();
        }
        else if(val > p->getData()) {
            q = p;
            p = p->getRChild();
        }
        else 
            found = true;
    }
    
    if(!found) return false;   
    
    else {  
        BSTreeNode* s = nullptr;  
        
        if(p->getLChild() == nullptr) { 
            if(q == nullptr) root = p->getRChild();  
            else if(q->getLChild() == p) q->setLChild(p->getRChild());  
            else q->setRChild(p->getRChild());
        }
        else if(p->getRChild() == nullptr) {   
            if(q == nullptr) root = p->getLChild();
            else if(q->getLChild() == p) q->setLChild(p->getLChild());
            else q->setRChild(p->getLChild());
        }
        else {    
            
            s = p->getRChild();  
            while(s->getLChild() != nullptr) s = s->getLChild();
            
            if(q == nullptr) root = s;      
            else if(q->getLChild() == p) q->setLChild(s);   
            else q->setRChild(s); 
            
            s->setLChild(p->getLChild());   
        }
        delete p;     
        num--;
        return true;
    }
}