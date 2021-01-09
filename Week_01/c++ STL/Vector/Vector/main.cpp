//
//  main.cpp
//  Vector
//
//  Created by YJLi on 2021/1/5.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===============\n";
    
    /*
     assign()对Vector中的元素赋值
     at() : 返回指定位置的元素
     back() : 返回最末一个元素
     begin() : 返回第一个元素的迭代器
     capacity() : 返回vector所能容纳的元素数量(在不重新分配内存的情况下）
     clear() : 清空所有元素
     empty() : 判断Vector是否为空（返回true时为空）
     end() : 返回最末元素的迭代器(译注:实指向最末元素的下一个位置)
     erase() : 删除指定元素
     front() : 返回第一个元素
     get_allocator() : 返回vector的内存分配器
     insert() : 插入元素到Vector中
     max_size() : 返回Vector所能容纳元素的最大数量（上限）
     pop_back() : 移除最后一个元素
     push_back() : 在Vector最后添加一个元素
     rbegin() : 返回Vector尾部的逆迭代器
     rend() : 返回Vector起始的逆迭代器
     reserve() : 设置Vector最小的元素容纳数量
     resize() : 改变Vector元素数量的大小
     size() : 返回Vector元素数量的大小
     swap() : 交换两个Vector
     */
    
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    //插入元素
    vec.insert(vec.begin()+4, 100);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    //删除元素
    vec.erase(vec.begin()+2);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    vector<int>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    
    cout<<endl;
    std::cout << "===============\n";
    return 0;
}
