#ifndef MYSORT_H_INCLUDED
#define MYSORT_H_INCLUDED

#include <string>
using namespace std;

class MySort{
public:
    int num; // ���ݸ���
    int* origin; // ԭʼ��������
    MySort();
    MySort(int, int*);
    ~MySort();
    void changeSwap(int&, int&); // ��������
    string printNum(); // ��������
    string paritySort(); // ��ż��������
    string bubbleSort(); // ð������
};

#endif // MYSORT_H_INCLUDED
