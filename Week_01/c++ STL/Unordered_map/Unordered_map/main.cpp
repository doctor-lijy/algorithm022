//
//  main.cpp
//  Unordered_map
//
//  Created by YJLi on 2021/1/9.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===========\n";
    /*
     C++ STL中，哈希表对应的容器是 unordered_map
     哈希表是根据关键码值(key value)而直接进行访问的数据结构。也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度，这个映射函数叫做散列函数。

     哈希表的一个重要问题就是如何解决映射冲突的问题。常用的有两种：开放地址法 和 链地址法
     
     与 map 的区别
     STL中，
     map 对应的数据结构是 红黑树。
     红黑树是一种近似于平衡的二叉查找树，里面的数据是有序的。
     在红黑树上做查找操作的时间复杂度为 O(logN)。
     
     而 unordered_map 对应 哈希表，哈希表的特点就是查找效率高，时间复杂度为常数级别 O(1)， 而额外空间复杂度则要高出许多。
     所以对于需要高效率查询的情况，使用 unordered_map 容器。
     而如果对内存大小比较敏感或者数据存储要求有序的话，则可以用 map 容器
     */
    
    unordered_map<int, string> map;
    
    map.insert(make_pair(1, "Scala"));
    map.insert(make_pair(2, "Haskell"));
    map.insert(make_pair(3, "C++"));
    map.insert(make_pair(6, "Java"));
    map.insert(make_pair(14, "Erlang"));
    
    //map.find()返回的是一个迭代器
    cout<<"14 = "<<map.find(14)->second<<endl;
    
    unordered_map<int, string>::iterator iter;
    for (iter = map.begin(); iter != map.end(); iter++) {
        cout<<iter->first<<" = "<<iter->second<<endl;
    }
    
    cout<<endl;
    std::cout << "===========\n";
    return 0;
}
