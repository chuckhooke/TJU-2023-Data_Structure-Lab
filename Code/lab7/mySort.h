#ifndef MYSORT_H_INCLUDED
#define MYSORT_H_INCLUDED

#include <string>
using namespace std;

class MySort{
public:
    int num; // 数据个数
    int* origin; // 原始数据数组
    MySort();
    MySort(int, int*);
    ~MySort();
    void changeSwap(int&, int&); // 辅助函数
    string printNum(); // 辅助函数
    string paritySort(); // 奇偶交换排序
    string bubbleSort(); // 冒泡排序
};

#endif // MYSORT_H_INCLUDED
