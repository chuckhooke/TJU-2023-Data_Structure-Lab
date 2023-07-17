#include <iostream>
#include "mySearch.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int n1 = 6;
    int data1[6] = {1, 2, 4, 5, 6, 9};
    SSTable s(n1, data1);

    cout << s.binSearch(4) << endl;
    cout << s.binSearch(7) << endl;

    int n2 = 5;
    int data2[5] = {3, 1, 2, 5, 4};
    BSTree b(n2, data2);

    cout << b.printTree() << endl;
    cout << b.searchNode(2) << endl;
    cout << b.searchNode(7) << endl;

    cout << b.addNode(7) << endl;
    cout << b.addNode(7) << endl;
    cout << b.deleteNode(2) << endl;
    cout << b.deleteNode(2) << endl;
    cout << b.printTree() << endl;
    cout << b.searchNode(2) << endl;
    cout << b.searchNode(7) << endl;


    return 0;
}

/*
bool BSTree::deleteNode(int val) {
    BSTreeNode* p = root;
    BSTreeNode* q = nullptr;   // q表示p的父节点
    bool found = false;       // 找到val的标志
    
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
    
    if(!found) return false;    // 没有找到val,删除失败
    
    // 找到val,判断节点p的类型并进行相应删除
    else {  
        BSTreeNode* s = nullptr;  // 记录p的左子树或右子树
        
        if(p->getLChild() == nullptr) { // p为叶子节点或只有一个子树
            if(q == nullptr) root = p->getRChild();  // p是根节点,删除后右子树接替
            else if(q->getLChild() == p) q->setLChild(p->getRChild());  
            else q->setRChild(p->getRChild());
        }
        else if(p->getRChild() == nullptr) {   // p为叶子节点或只有一个子树
            if(q == nullptr) root = p->getLChild();
            else if(q->getLChild() == p) q->setLChild(p->getLChild());
            else q->setRChild(p->getLChild());
        }
        else {    // p有两个子树,找后继节点s接替p的位置
            
            s = p->getRChild();  
            while(s->getLChild() != nullptr) s = s->getLChild();
            
            if(q == nullptr) root = s;      // p是根节点,s接替根节点    
            else if(q->getLChild() == p) q->setLChild(s);   
            else q->setRChild(s); 
            
            s->setLChild(p->getLChild());   // s的左子树设为p的左子树
        }
        delete p;     // 删除节点p
        num--;
        return true;
    }
}
*/