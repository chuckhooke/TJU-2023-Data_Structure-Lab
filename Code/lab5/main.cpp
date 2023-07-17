#include <iostream>
#include "myGraph.h"
using namespace std;
int main()
{
int nodeNum = 9;
int edgeNum = 10;
char nodeList[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
int edgeStartList[10] = {0, 0, 0, 1, 1, 4, 2, 3, 5, 7};
int edgeEndList[10] = {1, 2, 3, 2, 4, 6, 5, 5, 7, 8};
MyGraph g(nodeNum, edgeNum, nodeList, edgeStartList, edgeEndList);
cout << g.printGraph() << endl;
cout << g.graph_DFS_Traverse() << endl;
cout << g.graph_BFS_Traverse() << endl;
return 0;
}
/*
控制台运行结果为：
A: D C B
B: E C A
C: F B A
D: F A
E: G B
F: H D C
G: E
H: I F
I: H
A D F H I C B E G
A D C B F E H G I
*/