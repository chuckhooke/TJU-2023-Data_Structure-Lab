#include "myGraph.h"
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

EdgeNode::EdgeNode(){
    dest = -1;
    link = nullptr;
}

EdgeNode::EdgeNode(int dest, EdgeNode* link){
    this->dest = dest;
    this->link = link;
}

EdgeNode::~EdgeNode(){
    dest = -1;
    link = nullptr;
}

int EdgeNode::getDest(){
    return dest;
}

EdgeNode* EdgeNode::getNext(){
    return link;
}

void EdgeNode::setDest(int dest){
    this->dest = dest;
}

void EdgeNode::setNext(EdgeNode* link){
    this->link = link;
}

VertexNode::VertexNode(){
    data = ' ';
    firstEdge = nullptr;
}

VertexNode::VertexNode(char data, EdgeNode* firstEdge){
    this->data = data;
    this->firstEdge = firstEdge;
}

VertexNode::~VertexNode(){
    data = ' ';
    firstEdge = nullptr;
}

char VertexNode::getData(){
    return data;
}

EdgeNode* VertexNode::getFirstEdge(){
    return firstEdge;
}

void VertexNode::setData(char data){
    this->data = data;
}

void VertexNode::setFirstEdge(EdgeNode* firstEdge){
    this->firstEdge = firstEdge;
}

MyGraph::MyGraph(){

}

MyGraph::MyGraph(int nodeNum, int edgeNum, char* nodeList, int* edgeStartList, int* edgeEndList) {
    this->nodeNum = nodeNum;
    this->edgeNum = edgeNum;
    VexList = new VertexNode[nodeNum];

    for (int i = 0; i < nodeNum; i++) {
        VexList[i].setData(nodeList[i]);
        VexList[i].setFirstEdge(nullptr);
    }

    for (int i = edgeNum - 1; i > -1; i--) {
        int start = edgeStartList[i];
        int end = edgeEndList[i];

        EdgeNode* newEdgeNode = new EdgeNode(end, nullptr);

        EdgeNode* p = VexList[start].getFirstEdge();
        if(p == nullptr){
            VexList[start].setFirstEdge(newEdgeNode);
        }
        else{
            while(p->getNext() != nullptr){
                p = p->getNext();
            }
            p->setNext(newEdgeNode);
        }

        EdgeNode* newEdgeNode2 = new EdgeNode(start, nullptr);

        EdgeNode* q = VexList[end].getFirstEdge();
        if(q == nullptr){
            VexList[end].setFirstEdge(newEdgeNode2);
        }
        else{
            while(q->getNext() != nullptr){
                q = q->getNext();
            }
            q->setNext(newEdgeNode2);
        }
    }
}

MyGraph::~MyGraph(){
    nodeNum = 0;
    edgeNum = 0;
    delete VexList;
}

int MyGraph::getNodeNum(){
    return nodeNum;
}

int MyGraph::getEdgeNum(){
    return edgeNum;
}

string MyGraph::printGraph() {
    string output;

    for (int i = 0; i < nodeNum; ++i) {
        output += VexList[i].getData();
        output += ": ";

        EdgeNode* currentEdge = VexList[i].getFirstEdge();
        while (currentEdge != nullptr) {
            output += VexList[currentEdge->getDest()].getData();

            if (currentEdge->getNext() != nullptr) {
                output += ' ';
            }

            currentEdge = currentEdge->getNext();
        }
        
        if (i < nodeNum - 1) {
            output += '\n';
        }
    }

    return output;
}



string MyGraph::graph_DFS_Traverse(){
    bool* visited = new bool [nodeNum];
    string result = "";
    for(int i = 0; i < nodeNum; i++){
        visited[i] = false;
    }
    stack <VertexNode> stk;
    stk.push(VexList[0]);
    while(!stk.empty()){
        int index = -1;
        for(int i = 0; i < nodeNum; i++){
            if(VexList[i].getData() == stk.top().getData()) index = i;
        }
        if(!visited[index]){
            result += stk.top().getData();
            result += " ";
            visited[index] = true;
            stk.pop();

            stack <VertexNode> stk2;
            EdgeNode* p = VexList[index].getFirstEdge();
            if(p == nullptr){}
            else{
                do{
                    stk2.push(VexList[p->getDest()]);
                    p = p->getNext();
                } while(p!= nullptr);
                
            }

            while(!stk2.empty()){
                VertexNode v;
                v = stk2.top();
                stk2.pop();
                stk.push(v);
            }
        }
        else{
            stk.pop();
        }
        
    }
    return result;


}


string MyGraph::graph_BFS_Traverse(){
bool* visited = new bool [nodeNum];
    string result = "";
    for(int i = 0; i < nodeNum; i++){
        visited[i] = false;
    }
    queue <VertexNode> q;
    q.push(VexList[0]);
    while(!q.empty()){
        int index = -1;
        for(int i = 0; i < nodeNum; i++){
            if(VexList[i].getData() == q.front().getData()) index = i;
        }
        if(!visited[index]){
            result += q.front().getData();
            result += " ";
            visited[index] = true;
            EdgeNode* p = VexList[index].getFirstEdge();
            if(p == nullptr){}
            else{
                do{
                    q.push(VexList[p->getDest()]);
                    p = p->getNext();
                } while(p!= nullptr);
                
            }
        }
        q.pop();
    }
    return result;
}
