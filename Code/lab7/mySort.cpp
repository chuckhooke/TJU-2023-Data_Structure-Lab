#include "mySort.h"
#include <iostream>
#include <string>

MySort::MySort(){
    num = 0;
    origin = nullptr;
}

MySort::MySort(int num, int* origin){
    this->num = num;
    this->origin = origin;
}

MySort::~MySort(){
    num = 0;
    origin = nullptr;
}

void MySort::changeSwap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp; 
}

string MySort::printNum(){
    string res;
    for (int i = 0; i < num - 1; i++) {
        res += to_string(origin[i]) + " ";
    }
    res += to_string(origin[num-1]);
    res += "\n";
    return res;
}

string MySort::paritySort(){
    int n = num;
    bool sorted = false;
    string res;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n - 1; i += 2) {
            if (origin[i] > origin[i + 1]) {
                swap(origin[i], origin[i + 1]);
                sorted = false;
                res += printNum();
            }
        }
        for (int i = 0; i < n - 1; i += 2) {
            if (origin[i] > origin[i + 1]) {
                swap(origin[i], origin[i + 1]);
                sorted = false;
                res += printNum();
            }
        }
    }
    return res;
}

string MySort::bubbleSort(){
    int n = num;
    int left = 0, right = n - 1;
    bool sorted = false;
    string res;
    while (!sorted) {
        sorted = true;
        for (int i = left; i < right; i++) {
            if (origin[i] > origin[i + 1]) {
                swap(origin[i], origin[i + 1]);
                sorted = false;
                res += printNum();
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (origin[i] < origin[i - 1]) {
                swap(origin[i], origin[i - 1]);
                sorted = false;
                res += printNum();
            }
        }
        left++;
    }
    return res;
}
