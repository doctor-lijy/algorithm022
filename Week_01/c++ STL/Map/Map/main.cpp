//
//  main.cpp
//  Map
//
//  Created by YJLi on 2021/1/5.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "=================\n";
    
    /*
     C++ maps是一种关联式容器，包含“关键字/值”对

          begin()         返回指向map头部的迭代器

          clear(）        删除所有元素

          count()         返回指定元素出现的次数

          empty()         如果map为空则返回true

          end()           返回指向map末尾的迭代器

          equal_range()   返回特殊条目的迭代器对

          erase()         删除一个元素

          find()          查找一个元素

          get_allocator() 返回map的配置器

          insert()        插入元素

          key_comp()      返回比较元素key的函数

          lower_bound()   返回键值>=给定元素的第一个位置

          max_size()      返回可以容纳的最大元素个数

          rbegin()        返回一个指向map尾部的逆向迭代器

          rend()          返回一个指向map头部的逆向迭代器

          size()          返回map中元素的个数

          swap()           交换两个map

          upper_bound()    返回键值>给定元素的第一个位置

          value_comp()     返回比较元素value的函数
     */
    
    map<int, string> mapStudent;
    
    //数据的插入--第一种：用insert函数插入pair数据
//    mapStudent.insert(pair<int, string> (4, "student_two"));
//    mapStudent.insert(pair<int, string> (1, "student_one"));
//    mapStudent.insert(pair<int, string>(3, "student_three"));
    
    //第二种：用insert函数插入value_type数据，下面举例说明
//    mapStudent.insert(map<int, string>::value_type(4, "student_two"));
//    mapStudent.insert(map<int, string>::value_type(1, "student_one"));
//    mapStudent.insert(map<int, string>::value_type(3, "student_three"));
    
    //第三种：用数组方式插入数据，下面举例说明
//    mapStudent[1] = "student_one";
//    mapStudent[3] = "student_three";
//    mapStudent[4] = "student_two";
    /*
     以上三种用法，虽然都可以实现数据的插入，但是它们是有区别的，当然了第一种和第二种在效果上是完成一样的，
     （1）用insert函数插入数据，在数据的插入上涉及到集合的唯一性这个概念，即当map中有这个关键字时，insert操作是插入数据不了的，
     （2）但是用数组方式就不同了，它可以覆盖以前该关键字对 应的值，
     用程序说明
     */
    
    //验证插入函数的作用效果
//    pair<map<int, string>::iterator, bool> Insert_Pair;
//
//    Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_one"));
//    if (Insert_Pair.second == true) {
//        cout<<"元素 Insert Successfully"<<endl;
//    } else {
//        cout<<"元素 Insert Failure"<<endl;
//    }
//
//    Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_two"));
//    if (Insert_Pair.second == true) {
//        cout<<"元素修改 Insert Successfully"<<endl;
//    } else {
//        cout<<"元素修改 Insert Failure"<<endl;
//    }
    
    //验证数组形式插入数据的效果
    mapStudent[1] = "student_one";
    mapStudent[1] = "student_two";
    mapStudent[2] = "student_three";
    
    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout<<iter->first<<"="<<iter->second<<endl;
    }
    cout<<endl;
    
    cout<<"map中插入的数据元素个数 = "<<mapStudent.size()<<endl;
    
    //反向迭代器
    mapStudent[5] = "student_five";
    mapStudent[100] = "student_six";
    map<int, string>::reverse_iterator reverse_iter;
    for (reverse_iter = mapStudent.rbegin(); reverse_iter != mapStudent.rend(); reverse_iter++) {
        cout<<reverse_iter->first<<"="<<reverse_iter->second<<endl;
    }
    cout<<endl;

    cout<<"map中插入的数据元素个数 = "<<mapStudent.size()<<endl;
    
    //第三种：用数组方式输出反向迭代器
    //这里奇怪的的点就是使用数组插入的方式map的个数会很多，不知道为何？？？？
    
    //此处应注意，应该是 for(int nindex = 1; nindex <= nSize; nindex++)
    //而不是 for(int nindex = 0; nindex < nSize; nindex++)
    for (int nindex = 1; nindex <= mapStudent.size(); nindex++) {
        cout<<mapStudent[nindex]<<endl;
    }
    cout<<endl;
    
    cout<<"map中插入的数据元素个数 = "<<mapStudent.size()<<endl;
        
    std::cout << "=================\n";
    return 0;
}
