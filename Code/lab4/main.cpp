#include <iostream>
#include "myTree.h"
using namespace std;

int main()
{
    //树的构造
	MyTree t1("ABDG@@HJ@@K@@@CE@@F@I@@");

    // 前序遍历
    t1.preOrderTraverse(); //ABDGHJKCEFI
    cout << endl;

    // 中序遍历
    t1.inOrderTraverse(); //GDJHKBAECFI
    cout << endl;

    // 后序遍历
    t1.postOrderTraverse(); //GJKHDBEIFCA
    cout << endl;

    // 叶子节点个数
    cout << t1.countLeaf() << endl; //5

    // 深度
    cout << t1.countHeight() << endl;//5

    // 寻找树中节点
    TreeNode n1 = t1.locateNode('I');
    n1.printNode(); //I
    cout << endl;

    //树的构造
    MyTree t2("ABC@D@E@@@@");

    // 前序遍历
    t2.preOrderTraverse(); //ABCDE
    cout << endl;

    // 中序遍历
    t2.inOrderTraverse(); //CDEBA
    cout << endl;

    // 后序遍历
    t2.postOrderTraverse(); //EDCBA
    cout << endl;

    // 叶子节点个数
    cout << t2.countLeaf() << endl; //1

    // 深度
    cout << t2.countHeight() << endl;//5

    //线索化树
    MyTree t3(t1);
    t3.inOrderThreading();
    cout << t2.isThreadedTree() << endl; // 0
    cout << t3.isThreadedTree() << endl; // 1


    //线索化树寻找前后结点
    TreeNode n2 = t3.locateNode('A');
    n2.printNode(); //A
    cout << endl;
    TreeNode n3 = t3.preNode(n2);
    n3.printNode(); //B
    cout << endl;
    TreeNode n4 = t3.nextNode(n2);
    n4.printNode(); //E
    cout << endl;

    // n3.printNode(); // B
    // cout << endl;
    // n4.printNode(); // E
    // cout << endl;

    TreeNode n5 = t3.locateNode('E');
    n5.printNode(); // A
    TreeNode n6 = t3.preNode(t3.preNode(n5));
    //提示：若此处跨头结点会发生什么？
    cout << endl;

    n6.printNode(); // J
    cout << endl;

    //霍夫曼树
    int nodes[6]={3,7,8,1,9,56};
    HuffmanTree t4(6, nodes);
    t4.printHuffmanCodes();

    /*
        30:1
        16:01
        7:001
        3:0001
        1:0000
    */

    return 0;


    
}