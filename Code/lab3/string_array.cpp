#include "string_array.h"
#include <iostream>
using namespace std;

//字符串初始化myStr(const char*)，提示：字符串以\0结尾
myStr::myStr(const char* s){
        int len = 0;
        while (s[len] != '\0') len++; 
        data = new char[len + 1]; 
        length = len;
        for (int i = 0; i <= len; i++) {
            data[i] = s[i]; 
        }
        
}

// 字符串销毁~myStr()
myStr::~myStr(){
    delete data;
    length = 0;
}

// 寻找匹配子串的位置
int myStr::findStr(const myStr& T, const int& pos) {
    if (pos <= 0 || pos > length) {
        return -1;
    }

    for (int i = pos-1 ; i < length - T.length + 1; i++) {
        bool found = true;
        for (int j = 0; j < T.length; j++) {
            if (data[i + j] != T.data[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i + 1; 
        }
    }

    return -1; 
}


bool replaceStr(myStr& S, const int& start, const myStr& T, const myStr& V) {
    if (start <= 0 || start > S.length || T.length == 0) {
        return false;
    }

    int pos = S.findStr(T, start);
    if (pos == -1) {
        return false;
    }
    pos -= 1;

    int newLength = S.length - T.length + V.length;
    char* newData = new char[newLength + 1]; 

    for (int i = 0; i < pos; i++) {
        newData[i] = S.data[i];
    }

    for (int i = 0; i < V.length; i++) {
        newData[pos + i] = V.data[i];
    }

    for (int i = pos + T.length; i < S.length; i++) {
        newData[V.length + i - T.length] = S.data[i];
    }

    newData[newLength] = '\0'; 
    delete[] S.data;
    S.data = newData;
    S.length = newLength;

    return true;
}



void myStr::kmp_next(){
    for(int i = length; i > 0; i--){
        data[i] = data[i-1];
    }

    next = new int [length+1];
    next[1] = 0;
    next[2] = 1;
    int j = 2;
    int k = 1;
    while(j < length){
        if(data[j] == data[k]){
            next[j+1] = k + 1;
            j++;
            k++;
        }
        else k = next[k];
        if(k == 0){
            next[j+1] = 1;
            j++;
            k = 1;
        }
    }

    for(int i = 0; i < length; i++){
        data[i] = data[i+1];
        next[i] = next[i+1];
    }    


}


void myStr::kmp_nextVal(){
    for(int i = length; i > 0; i--){
        data[i] = data[i-1];
    }

    nextVal = new int [length+1];
    nextVal[1] = 0;

    int j = 1;
    int k = 0;

    while(j < length){
        if(k == 0 || data[j] == data[k]){
            j++;
            k++;
            if(data[k] != data[j]) nextVal[j] = k;
            else nextVal[j] = nextVal[k];
        }
        else k = nextVal[k];
    }

    for(int i = 0; i < length; i++){
        data[i] = data[i+1];
        nextVal[i] = nextVal[i+1];
    }    

}

int simpleMatch(const myStr& S, const myStr& T){
    for (int i = 0 ; i < S.length - T.length + 1; i++) {
        bool found = true;
        for (int j = 0; j < T.length; j++) {
            if (S.data[i + j] != T.data[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i + 1; 
        }
    }

    return -1; 
}

int kmpMatch(const myStr& S, const myStr& T){
    for(int i = S.length; i > 0; i--){
        S.data[i] = S.data[i-1];
    }
    for(int i = T.length; i > 0; i--){
        T.data[i] = T.data[i-1];
    }
    for(int i = T.length; i > 0; i--){
        T.nextVal[i] = T.nextVal[i-1];
    }

    int i = 1;
    int j = 1;
    while(i <= S.length && j <=T.length){
        if(j == 0 || S.data[i] == T.data[j]){
            i++;
            j++;
        }
        else j = T.nextVal[j];
    }

    for(int i = 0; i < S.length; i++){
        S.data[i] = S.data[i+1];
    }

    for(int i = 0; i < T.length; i++){
        T.data[i] = T.data[i+1];
        T.nextVal[i] = T.nextVal[i+1];
    }
    if(j > T.length) return i - T.length;
    else return -1;
}




void myStr::print(){
    for(int i = 0; i < length; i++)
        cout << data[i];
    cout << endl;
}

void myStr::printNext(){
    for(int i = 0; i < length; i++)
        cout << next[i];
    cout << endl;
}

void myStr::printNextVal(){
    for(int i = 0; i < length; i++)
        cout << nextVal[i];
    cout << endl;
}



myMatrix::myMatrix(const int& rNum, const int& cNum, const int& nNum, const int*data){
        rowNum = rNum;
        colNum = cNum;
        nodeNum = nNum;
        nodeList = new matrixNode[nNum];
        for (int i = 0; i < nNum; i++) {
            nodeList[i].row = data[i*3];
            nodeList[i].col = data[i*3+1];
            nodeList[i].value = data[i*3+2];
        }
}

myMatrix::~myMatrix(){
    rowNum = 0;
    colNum = 0;
    nodeNum = 0;
    delete nodeList;
}

myMatrix::myMatrix(){
}


void myMatrix::FastTransposeSMatrix(myMatrix& T){
    T.rowNum=colNum; 
    T.colNum=rowNum; 
    T.nodeNum=nodeNum;

    T.nodeList = new matrixNode[nodeNum];

    int* num = new int [colNum+1];
    int* cpot = new int [colNum+1];

    
    if(T.nodeNum){
        for(int col = 1; col <= colNum; col++) 
            num[col]=0;
        for(int i = 0; i < nodeNum; i++) {
            num[nodeList[i].col]++;
        }

        cpot[1]=1;
        for(int col = 2; col <= colNum; col++)
            cpot[col] = cpot[col-1] + num[col-1];
        

        for(int p = 0 ; p < nodeNum; p++){
            int col = nodeList[p].col; 
            int q = cpot[col] - 1;
            T.nodeList[q].row=nodeList[p].col;
            T.nodeList[q].col=nodeList[p].row;
            T.nodeList[q].value=nodeList[p].value; 
            cpot[col]++;
        }
    }
}


// void myMatrix::printMatrix(){
//     cout << rowNum << "," << colNum << "," << nodeNum << endl;

//     for(int i = 0; i < nodeNum; i++)
//         cout << nodeList[i].row << "," << nodeList[i].col << "," << nodeList[i].value << endl;
// }

void myMatrix::printMatrix() {
cout << rowNum << "," << colNum << "," << nodeNum << endl;

for(int i = 1; i <= rowNum; i++){
    for(int j = 1; j <= colNum; j++){
        for(int u = 0; u < nodeNum; u++){
            if(nodeList[u].row == i && nodeList[u].col == j)
            cout << nodeList[u].row << "," << nodeList[u].col << "," << nodeList[u].value << endl;
        }
        
    }
}
}