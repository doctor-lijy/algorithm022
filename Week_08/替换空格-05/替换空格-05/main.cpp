//
//  main.cpp
//  替换空格-05
//
//  Created by YJLi on 2021/2/22.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 示例 1：
 输入：s = "We are happy."
 输出："We%20are%20happy."
 */

/*
 把这道题做到极致，就不要只用额外的辅助空间了
 
 1、扩充数组到每个空格替换成“%20”之后的大小
 2、然后从后向前替换空格，使用双指针法
 
 这种需要扩充一般都是需要从后向前填充，不能从前向后填充，因为从前向后填充就是0(n*n)的时间复杂度了
 */

/*
 很多数组填充类问题，都可以先预先给数组扩容带填充后的大小，然后从后向前进行操作

 1、不用申请新数组
 2、从后向前填充元素，避免了从前向后填充元素要来的每次天津爱元素都要将添加元素之后的所有元素向后移动
 */

class Solution {
    
public:
    string replaceSpace(string s) {
        int count = 0; //统计空格的个数
        int sOldSize = (int)s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        //扩充字符串s的大小，也就是每个空格替换成“%20”之后的大小
        s.resize(s.size() + count * 2); //有点扯犊子了，一个空格替换成“%20”，需要增加count*2个大小
        int sNewSize = (int)s.size();
        //从后向前将空格替换成“%20”
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i-=2;
            }
        }
        return s;
    }
    /*
     时间复杂度：O(n)
     空间复杂度：O(1)
     */
    
    /*
     在c++中，提供一个string类，string类会提供size接口，可以用来判断string类字符串是否结束，就不用'\0'来判断是否结束。
     
     vector<char> 和string有什么区别？
     在基本操作上没有什么区别，但是string提供更多的字符串处理相关接口，例如string重载了+，而vector却没有
     */
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    string result = solu.replaceSpace("We are happy.");
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i];
    }
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
