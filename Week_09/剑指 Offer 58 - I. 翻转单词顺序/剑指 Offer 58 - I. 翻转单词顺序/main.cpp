//
//  main.cpp
//  剑指 Offer 58 - I. 翻转单词顺序
//
//  Created by YJLi on 2021/3/29.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
    
public:
    string reverseWords(string s) {
        int len = (int)s.length();
        
        if (len == 0) {
            return "";
        }
        
        int j = len - 1;
        string res = "";
        
        while (j >= 0) {
            if (s[j] == ' ') {
                // 当 s[j] 是空格时，j 不断左移
                j--;
                continue;
            }
            
            while (j >= 0 && s[j] != ' ') {
                // 注意 while 里必须用 && 短路求值，且 j >= 0 要放前面
                // 不然如果 j 变成 -1，那么计算 s[j] 会发生溢出错误！
                j--;
            }
            
            int pos = j; // 用 pos 保存 j 当前的位置
            j++; // j 现在指向的是一个空格，需要右移一位才能指向一个单词的开头
            
            while (s[j] != ' ' && j < len) {
                // 向 res 中添加单词
                res += s[j];
                j++;
            }
            
            j = pos; // j 回到新添加的单词的最左端再往左一个空格处
            res += ' '; // 单词添加完毕后需要加上一个空格
        }
        
        if (res[res.length() - 1] == ' ') {
            // 删除 res 最后一位的多余空格
            res.erase(res.length() - 1, 1);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
