#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class MyStack;

class listNode{
    friend class MyStack;
private:
    listNode* next;
    int data;
public:
    listNode();
    listNode(int nodeData, listNode* succ = NULL);
};

class MyStack
{
private:
    listNode* topNode;
    int stackSize;


public:
    MyStack();
    ~MyStack();

    bool isempty();
    bool push(const int&);
    bool pop(int&);
    bool getTop(int&);
    void printStack();
};


class MyStack1;

class listNode1{
    friend class MyStack1;
private:
    listNode1* next;
    char data;
public:
    listNode1();
    listNode1(char nodeData, listNode1* succ = NULL);
};

class MyStack1
{
private:
    listNode1* topNode;
    int stackSize;


public:
    MyStack1();
    ~MyStack1();

    bool isempty();
    bool push(const char&);
    bool pop(char&);
    bool getTop(char&);
    void printStack();
};



class MyQueue
{
private:
    int* queue;
    int capacity;
    int front;
    int rear;

public:
    MyQueue(const int&);
    ~MyQueue();

    bool enQueue(const int&);
    bool deQueue(int&);
    bool getFront(int&);
    void printQueue();

    bool isFull();
};

bool postfixExpression(const string&, string&);

bool expressionVal(const string&, int&);

void yanghui(const int&);

bool priority(char a, char b);

