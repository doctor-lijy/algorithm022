//
//  main.cpp
//  Map2
//
//  Created by YJLi on 2021/1/5.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==================\n";
    map<int, string> mapStudent;
    
    //查找并获取map中的元素（包括判定这个关键字是否在map中出现）
    mapStudent.insert(pair<int, string>(1, "student_one"));
        mapStudent.insert(pair<int, string>(2, "student_two"));
        mapStudent.insert(pair<int, string>(3, "student_three"));
    mapStudent.insert(pair<int, string>(6, "student_six"));
        mapStudent.insert(pair<int, string>(7, "student_seven"));
        mapStudent.insert(pair<int, string>(8, "student_eight"));
    /*
     这里给出三种数据查找方法
     第一种：用count函数来判定关键字是否出现，其缺点是无法定位数据出现位置,由于map的特性，一对一的映射关系，就决定了count函数的返回值只有两个，要么是0，要么是1，出现的情况，当然是返回1了
     第二种：用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器。
     查找map中是否包含某个关键字条目用find()方法，传入的参数是要查找的key，在这里需要提到的是begin()和end()两个成员，
     分别代表map对象中第一个条目和最后一个条目，这两个数据的类型是iterator.
     */
    cout<<"查找关键字是否出现 = "<<mapStudent.count(4)<<endl;
    
    map<int, string>::iterator iter;
    iter = mapStudent.find(4);
    
    if (iter != mapStudent.end()) {
        cout<<"Find, the value is "<<iter->second<<endl;
    } else {
        cout<<"Do not Find"<<endl;
    }
    cout<<endl;
    
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout<<iter->first<<"="<<iter->second<<endl;
    }
    cout<<endl;
    
    //从map中删除元素
    /*
     移除某个map中某个条目用erase（）
     该成员方法的定义如下：
     iterator erase（iterator it);//通过一个条目对象删除
     iterator erase（iterator first，iterator last）//删除一个范围
     size_type erase(const Key&key);//通过关键字删除
     clear()就相当于enumMap.erase(enumMap.begin(),enumMap.end());

     这里要用到erase函数，它有三个重载了的函数，下面在例子中详细说明它们的用法
     */
    //如果你要演示输出效果，请选择以下的一种，你看到的效果会比较好
      
           //如果要删除1,用迭代器删除
//           iter = mapStudent.find(1);
//           mapStudent.erase(iter);
    
           //如果要删除1，用关键字删除
      
//           int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0
      
           //用迭代器，成片的删除
           //一下代码把整个map清空
           mapStudent.erase( mapStudent.begin(), mapStudent.end());
           //成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合
      
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout<<iter->first<<"="<<iter->second<<endl;
    }
    cout<<endl;
    
    
    std::cout << "==================\n";
    return 0;
}
