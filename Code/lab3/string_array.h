#include <iostream>

using namespace std;

class myStr
{
private:
    char* data;
    int length;

    int* next;
    int* nextVal;

public:
    myStr(const char*);
    ~myStr();
    //其他可以考虑的构造函数
    //myStr(const int&);
    //myStr(const myStr&);

    int findStr(const myStr& , const int&);
    void print();
    void kmp_next();
    void kmp_nextVal();
    void printNext();
    void printNextVal();
    
    friend bool replaceStr(myStr&, const int&, const myStr&, const myStr&);
    friend int kmpMatch(const myStr&, const myStr&);
    friend int simpleMatch(const myStr&, const myStr&);

};

struct matrixNode
{
    int row;
    int col;
    int value;
};


class myMatrix
{
private:
    matrixNode* nodeList;
    int rowNum;
    int colNum;
    int nodeNum;

public:
    myMatrix(const int&, const int&, const int&, const int*);
    ~myMatrix();
    //建议加入的构造函数
    myMatrix();
    //myMatrix(const myMatrix&);

    void printMatrix();
    void FastTransposeSMatrix(myMatrix&);
};






