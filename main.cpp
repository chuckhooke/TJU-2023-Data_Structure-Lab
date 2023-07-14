//
//  main.cpp
//  test
//
//  Created by Yevon on 2022/3/9.
//

#include <iostream>
#include "linearList.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // float i[5] = {-2.2,1.2,0,-0.0001,0};
    // float val;
    // linkList ll(5, i);
    // ll.print(); // 3:1.3,4.5,0.4
    // ll.tailInsertItem(-2.2);
    // ll.print(); // 4:1.3,4.5,0.4,5.5
    // ll.headInsertItem(1);
    // ll.print(); // 5:7,1.3,4.5,0.4,5.5
    // ll.deleteItem(1.3);//返回1
    // ll.print();// 4: 7,4.5,0.4,5.5
    // ll.locate(9,val);//返回false
    // ll.locate(4.5);//返回1
    // ll.print();// 4:7, 4.5,0.4,5.5
    // ll.reverse();//
    // ll.print();// 4: 5.5,0.4,4.5,7
    // ll.insertItem(0,1);
    // ll.print(); // 5: 5.5,10.2,0.4,4.5,7
    
    
    // float i[5]={-2.2,1.2,0,-0.0001,0};
    // float val;
    // sequenceList sl(6, 5, i); //顺序表容量，初始化数组长度，初始化数组值
    // sl.print(); // 3:1.3,4.5,0.4
    // sl.insertItem(5, -2.2);
    // sl.print(); // 4:1.3,4.5,0.4,5.5
    // sl.insertItem(0, 1);
    // sl.print(); // 4:1.3,4.5,0.4,5.5
    // sl.deleteItem(1.3);//返回0
    // sl.print();// 3: 4.5,0.4,5.5
    // sl.locate(9,val);//返回false
    // sl.locate(4.5);//返回0
    // sl.print();// 3: 4.5,0.4,5.5
    // sl.reverse();//
    // sl.print();// 3: 5.5,0.4,4.5
    
    
    float a[3]={1.3,4.5,0.4};
    float b[4]={1.5,8.5,0.1,6.2};
    linkList alist(3, a);
    linkList blist(4, b);
    alist.print();//3:1.3,4.5,0.4
    blist.print();//4: 1.5,8.5,0.1,6.2
    alist.ascendingOrder();
    blist.ascendingOrder();
    alist.print();//3:0.4,1.3,4.5
    blist.print();//4:0.1,1.5,6.2,8.5
    merge(alist, blist);
    alist.print();//7:8.5,6.2,4.5,1.5,1.3,0.4,0.1
    
    return 0;
}
