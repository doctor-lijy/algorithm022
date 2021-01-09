//
//  main.cpp
//  Dequeue
//
//  Created by YJLi on 2021/1/5.
//

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "================\n";
    
    /*
     back();//返回最后一个元素
     front();//返回第一个元素
     insert();//
     pop_back();//删除尾部的元素
     pop_front();//删除头部的元素
     push_back();//在尾部加入一个元素
     push_front();//在头部加入一个元素
     at();//访问指定位置元素
     empty();//判断队列是否为空
     size();//返回队列的大小
     
     operator[] (size_type n);//重载[]操作符
     */
    
    deque<int> dq;
    
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    
    cout<<"dq 元素个数 = "<<dq.size()<<endl;
    
    deque<int>::iterator iter;
    for (iter = dq.begin(); iter != dq.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    
    dq.push_front(4);
    dq.push_front(5);
    dq.push_front(6);
    cout<<"dq 元素个数 = "<<dq.size()<<endl;
    
    for (iter = dq.begin(); iter != dq.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    
    //向双端队列中插入元素
    dq.insert(dq.begin()+2, 0);
    
    for (iter = dq.begin(); iter != dq.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"dq 元素个数 = "<<dq.size()<<endl;
    
    cout<<"第一个元素 = "<<dq.front()<<endl;
    cout<<"最后一个元素 = "<<dq.back()<<endl;
    
    dq.pop_front();
    dq.pop_back();
    for (iter = dq.begin(); iter != dq.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    
    //operator[] (size_type n);//重载[]操作符
    int myints[] = {16,2,77,29};
    deque<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    for (deque<int>::iterator it = fifth.begin(); it!=fifth.end(); ++it)
          cout << " "<< *it;
    
    cout<<endl;
    
    std::cout << "================\n";
    return 0;
}
