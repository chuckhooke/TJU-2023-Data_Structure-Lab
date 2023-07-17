#include<bits/stdc++.h>
#include"string_array.h"
using namespace std;

int main()
{
	// 字符串测试
	myStr s1("ABBABABCDABAADDEADA");
	myStr m1("AA");
    myStr r1("CC");
    myStr answer1("BCC");

    // 1. replace 找到了要替换的串 + 替换后的串
    cout << replaceStr(s1, 1, m1, r1) << " ";
    // 2. replace 找不到要替换的串
    cout << replaceStr(s1, 15, r1, r1) << endl; // 1 0

    cout << replaceStr(s1, 1, answer1, answer1) << endl; // 1

    myStr m2("BCC");
    // 3. simpleMatch 有匹配
    cout << simpleMatch(s1, m2) << endl; // 11
    // 4. simpleMatch 无匹配
    cout << simpleMatch(s1, m1) << endl; // -1

    m1.kmp_next();
    m1.kmp_nextVal();

	// 5. KMP寻找不存在的子串
    cout << kmpMatch(s1, m1) << endl; //-1


    myStr m3("CDA");
    // 6-7. KMP m3中间值
    m3.kmp_next();
    m3.kmp_nextVal();
    m3.printNext(); //011
    m3.printNextVal(); //011

    // 8-9. KMP s1
    s1.kmp_next();
    s1.kmp_nextVal();
    s1.printNext(); //0111232311231111121
    s1.printNextVal(); //0110131310131111020

    // 10. KMP寻找存在的子串
    cout << kmpMatch(s1, m3) << endl; //8


    // 矩阵测试

    // 11-14. 转置矩阵
    int s[]={1,2,3, 4,4,8, 5,6,4};
    myMatrix N(10, 10, 3, s);
    myMatrix N2;
    N.FastTransposeSMatrix(N2);
    N2.printMatrix();
    /*
      10,10,3
      2,1,3
      4,4,8
      6,5,4
    */

    // 15-20. 打印稀疏矩阵（按行优先输出）
    int t[]={5,3,2, 3,6,8, 1,4,1, 4,3,6, 1,2,7};
    myMatrix M(9, 9, 5, t);
    M.printMatrix();

    /*
      9,9,5
      1,2,7
      1,4,1
      3,6,8
      4,3,6
      5,3,2
    */

    return 0;

}