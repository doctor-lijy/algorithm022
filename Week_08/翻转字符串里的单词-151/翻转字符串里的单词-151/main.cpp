//
//  main.cpp
//  翻转字符串里的单词-151
//
//  Created by YJLi on 2021/2/22.
//

#include <iostream>
#include <string>

using namespace std;

/*
 给定一个字符串，逐个翻转字符串中的每个单词
 
 示例 1：
 输入: "the sky is blue"
 输出: "blue is sky the"

 示例 2：
 输入: "  hello world!  "
 输出: "world! hello"
 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

 示例 3：
 输入: "a good   example"
 输出: "example good a"
 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 */

/*
 不适用辅助空间，空间复杂度要求为O(1)
 
 解题思路：
 1、移除多余空格
 2、将整个字符串反转
 3、将每个单词反转
 */

class Solution {
    
public:
    //反转字符串s中左闭右闭的区间[start, end]
    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    
    /*
     使用双指针法移除冗余空格
     fastIndex走的快，slowIndex走的慢，最后slowIndex就标记着移除多余空格后新字符串的长度
     */
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0; //定义快指针，慢指针
        //去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            //去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { //去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); //重新设置字符串大小
        }
    }
    
    string reverseWords(string &s) {
        removeExtraSpaces(s); // 去掉冗余空格
        reverse(s, 0, (int)s.size() - 1); // 将字符串全部反转
        int start = 0; // 反转的单词在字符串里起始位置
        int end = 0; // 反转的单词在字符串里终止位置
        bool entry = false; // 反转的单词在字符串里终止位置
        
        for (int i = 0; i < s.size(); i++) { // 开始反转单词
            if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {
                start = i; // 确定单词起始位置
                entry = true; // 进入单词区间
            }
            // 单词后面有空格的情况，空格就是分词符
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1; // 确定单词终止位置
                entry = false;
                reverse(s, start, end);
            }
            
            if (entry && (i == (s.size() - 1)) && s[i] != ' ') {
                end = i;
                entry = false;
                reverse(s, start, end);
            }
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    string s = "    the sky is blue    ";
    string result = solu.reverseWords(s);
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i];
    }
    cout<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
