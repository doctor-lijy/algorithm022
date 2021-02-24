//
//  main.cpp
//  反转字符串II-541
//
//  Created by YJLi on 2021/2/22.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 给定一饿字符串 s 和 一个整数 k ，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
 
 如果剩余的字符少于 k 个，则将剩余字符全部反转
 
 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 
 示例:
 输入: s = "abcdefg", k = 2
 输出: "bacdfeg"
 */

/*
 这里字符串如下情况：
 1、字符串长度小于 k
 2、字符串长度 大于等于 k 但小于 2k
 3、字符串长度 大于 2k
 */

class Solution {
    
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) {
            //每隔 2k 个 字符的前 k 个字符进行反转
            //剩余字符小于 2k 但但大于或等于 k 个，则反转前 k 个字符
            /*
             这里的处理逻辑是每隔 2k 个字符，那就将 2k作为一个单元，
             将每一个单元的前 k 个字符进行反转
             */
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            //3、剩余字符少于 k 个，则剩余字符全部反转
            reverse(s.begin() + i, s.begin() + s.size());
            /*
             这里我终于看明白了，之所以这么处理的原因是如果字符串的长度小于 k
             也就是说字符串长度不满足于一个2k单元的长度，且长度小于 k，则字符串需要全部翻转
             */
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;

    string result = solu.reverseStr("abcdefghil", 11);
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i];
    }
    
//    for (int i = 0; i < 5; i++) {
//        if (i == 3) {
//            continue;
//        }
//        cout<<"i = "<<i<<endl;
//    }
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
