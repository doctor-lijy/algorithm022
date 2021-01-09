//
//  main.cpp
//  List
//
//  Created by YJLi on 2021/1/5.
//

#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    
    /*
     assign() : 给list赋值
     back() : 返回最后一个元素
     begin() : 返回指向第一个元素的迭代器
     clear() : 删除所有元素
     empty() : 如果list是空的则返回true
     end() : 返回末尾的迭代器
     erase() : 删除一个元素
     front() : 返回第一个元素
     get_allocator() : 返回list的配置器
     insert() : 插入一个元素到list中
     max_size() : 返回list能容纳的最大元素数量
     merge() : 合并两个list
     pop_back() : 删除最后一个元素
     pop_front() : 删除第一个元素
     push_back() : 在list的末尾添加一个元素
     push_front() : 在list的头部添加一个元素
     rbegin() : 返回指向第一个元素的逆向迭代器
     remove() : 从list删除元素
     remove_if() : 按指定条件删除元素
     rend() : 指向list末尾的逆向迭代器
     resize() : 改变list的大小
     reverse() : 把list的元素倒转
     size() : 返回list中的元素个数
     sort() : 给list排序
     splice() : 合并两个list
     swap() : 交换两个list
     unique() : 删除list中重复的元素
     */
    
    //创建空的 list 容器
    list<double> values;
    
    //向容器中添加元素
        values.push_back(3.1);
        values.push_back(2.2);
        values.push_back(2.9);
        cout << "values size：" << values.size() << endl;
        //对容器中的元素进行排序
    values.sort();
        //使用迭代器输出list容器中的元素
        for (list<double>::iterator it = values.begin(); it != values.end(); ++it) {
            cout << *it << " ";
        }
    cout<<endl;
    
    std::cout << "==============\n";
    return 0;
}
