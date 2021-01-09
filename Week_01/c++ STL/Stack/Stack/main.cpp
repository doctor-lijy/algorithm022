//
//  main.cpp
//  Stack
//
//  Created by YJLi on 2021/1/5.
//

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    
    /* empty() 堆栈为空则返回真
     
     pop() 移除栈顶元素

     push() 在栈顶增加元素

     size() 返回栈中元素数目

     top() 返回栈顶元素*/
    
    //创建栈对象
    stack<int> s;
    cout<<"栈是否为空，1 空， 0不空 = "<<s.empty()<<endl;
    
    //空栈访问栈顶元素崩溃
//    cout<<"栈顶元素 = "<<s.top()<<endl;
    
    // 元素入栈
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    
    bool isEmpty = s.empty();
    if (!isEmpty) {
        cout<<"栈元素个数 = "<<s.size()<<endl;
        cout<<"栈顶元素 = "<<s.top()<<endl;
    }
    
    // 元素依次出栈
    while (!s.empty()) {
        // 打印栈顶元素
        cout<<s.top()<<" ";
        // 出栈
        s.pop();
    }
    cout<<endl;
    
    std::cout << "==============\n";
    return 0;
}
