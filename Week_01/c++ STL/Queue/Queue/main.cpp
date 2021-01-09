//
//  main.cpp
//  Queue
//
//  Created by YJLi on 2021/1/5.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    
    /*
     back() : 返回最后一个元素
     empty() : 如果队列空则返回真
     front() : 返回第一个元素
     pop() : 删除第一个元素
     push() : 在末尾加入一个元素
     size() : 返回队列中元素的个数
     */
    
    queue<string> myQueue;
    
//    cout <<"front = "<<myQueue.front()<<endl;
//    cout<<"back = "<<myQueue.back()<<endl;
    
    myQueue.push("a");
    myQueue.push("b");
    myQueue.push("c");
    myQueue.push("d");
    myQueue.push("e");
    myQueue.push("f");
    
    cout<<"queue 的元素个数 = "<<myQueue.size()<<endl;
    
    while (!myQueue.empty()) {
        cout<<"front = "<<myQueue.front()<<" "<<"back = "<<myQueue.back()<<endl;;
        myQueue.pop();
    }
    cout<<endl;
    
    std::cout << "==============\n";
    return 0;
}
