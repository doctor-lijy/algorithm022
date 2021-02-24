//
//  main.cpp
//  左旋转字符串
//
//  Created by YJLi on 2021/2/22.
//

#include <iostream>
#include <string>

using namespace std;

/*
 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 示例 1：
 输入: s = "abcdefg", k = 2
 输出: "cdefgab"

 示例 2：
 输入: s = "lrloseumgh", k = 6
 输出: "umghlrlose"
   限制：
 1 <= k < s.length <= 10000
 */

/*
 不能申请额外空间，只能在本串上操作
 */

class Solution {
    
public:
    /*
     解题思路：
     1、反转区间为前 n 的子串
     2、反转区间为 n 到末尾的子串
     3、反转整个字符串
     
     「最后就可以得到左旋n的目的，而不用定义新的字符串，完全在本串上操作。」

     例如 ：示例1中 输入：字符串abcdefg，n=2

     反转区间为前n的子串 ：bacdefg
     反转区间为n到末尾的子串：bagfedc
     反转整个字符串：cdefgab
     最终得到左旋2个单元的字符串：cdefgab
     */
    
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        
        return s;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    string s = "abcdefg";
    int n = 2;
    string result = solu.reverseLeftWords(s, n);
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i];
    }
    cout<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
