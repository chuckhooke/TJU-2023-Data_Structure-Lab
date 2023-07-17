#include <iostream>
#include "mySort.h"

using namespace std;

int main()
{
	int num = 6;
	int origin1[6] = {7, 3, 2, 3, 6, 4};
    int origin2[6] = {2, 2, 6, 8, 1, 7};
	MySort m1(num, origin1);
    MySort m2(num, origin2);

	cout << m2.bubbleSort();
    cout << m1.paritySort();

	return 0;
}