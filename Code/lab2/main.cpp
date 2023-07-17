#include <iostream>
#include "stack_queue.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // //栈测试
	// MyStack s;
	// int val = 1024;

	// //1. 初始化
	// s.push(3);
	// s.printStack(); //3

	// //2. 连续入栈
	// s.push(-3);
	// s.push(146);
	// s.push(0);
	// s.push(4);
	// s.printStack(); //4,0,146,-3,3

	// //3. 出栈，获取栈顶元素
	// s.pop(val);
    // cout << val << endl; // 4

    // //4. 出栈后结果
    // s.printStack(); //0,146,-3,3

    // //5. 获取栈顶元素
    // s.getTop(val);
    // cout << val << " ";
    // s.printStack(); // 0 0,146,-3,3

    // //6. 清空栈，以及非法出栈
    // s.pop(val);
    // s.pop(val);
    // s.pop(val);
    // s.pop(val);

    // s.pop(val);
    // cout << s.getTop(val) << endl; // 0 (false, 栈为空)


    // //队列测试
    // MyQueue q(7);
    // int val = 1024;

    // // 7. 连续入队，打印结果
    // q.enQueue(3);
    // q.enQueue(-1);
    // q.enQueue(4);
    // q.enQueue(2);
    // q.enQueue(0);
    // q.enQueue(203);
    // q.printQueue(); //3,-1,4,2,0,203

    // // 8. 非法入队，已满
    // cout << q.enQueue(-1) << endl; //0(false, 队列已满）

    // // 9. 出队后结果
    // q.deQueue(val);
    // q.deQueue(val);
    // q.printQueue(); //4,2,0,203

    // // 10. 出队，队首元素
    // cout << val << endl; //-1

    // // 11. 队首元素
    // q.getFront(val);
    // cout << val << endl; //4

    // // 12. 非法出队
    // q.deQueue(val);
    // q.deQueue(val);
    // q.deQueue(val);
    // q.deQueue(val);
    // q.deQueue(val);
    // cout << q.deQueue(val) << endl; //0(false, 队列已空）

    // 杨辉三角测试
    // 13-17. n=5杨辉三角
    /*
        1,1
        1,2,1
        1,3,3,1
        1,4,6,4,1
        1,5,10,10,5,1
    */
    yanghui(5);

    // //表达式转换测试
    // //18. 中缀转后缀
    // string s1 = "9+(3*7-5)/2+1*8";
    // string result;
    // postfixExpression(s1, result);
    // cout << result << endl; //937*5-2/+18*+

    // //19. 计算中缀
    // int val = 1024;
    // expressionVal(s1, val);
    // cout << val << endl;    //25

    // //20. 非法中缀转后缀
    // string s2 = "(5*-5))";
    // postfixExpression(s2, result);
    // cout << result << endl; // Expression is wrong!
    // return 0;

}
