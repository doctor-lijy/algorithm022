//
//  main.cpp
//  有效的括号-20
//
//  Created by YJLi on 2021/1/4.
//

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 数据结构和算法应用往往隐藏在我们看不到的地方
 */

/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

 有效字符串需满足：

 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。
 示例 1:
 输入: "()"
 输出: true

 示例 2:
 输入: "()[]{}"
 输出: true

 示例 3:
 输入: "(]"
 输出: false

 示例 4:
 输入: "([)]"
 输出: false

 示例 5:
 输入: "{[]}"
 输出: true
 */

/*
 括号匹配是使用栈解决的经典问题
 */

class Solution {
    
    /*
     ASCII值
     ( ->72、 ) ->73、[ ->91、] ->93、{ ->123、} ->125
     */
public:
    bool isValid(string s) {
        if (s == "") {
            return true;
        }
        //利用数组当做栈使用，只从最后面插入和删除，数组栈
        vector<char> stack;
        stack.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (stack.empty()) {//如果数组为空，就先插入一个元素到栈里面去
                stack.push_back(s[i]);
            } else if (s[i] - stack.back() == 1 || s[i] - stack.back() == 2) {//使用ASCII差值来判断当前字符和栈顶字符是否匹配成一对，若是弹出栈顶字符
                stack.pop_back();
            } else {
                stack.push_back(s[i]);//当前字符与栈顶字符不匹配，将当前字符压入栈中
            }
        }
        return stack.empty();//判断栈是否为空，即可判断字符串s元素是否相匹配
    }
    
    bool isValid2(string s) {
        unordered_map<char, int> map{{'(',1},{'[',2},{'{',3},
            {')',4},{']',5},{'}',6}};//使用哈希表存储字符
        stack<char> stack;
        
        for(char c:s) {//遍历字符串 c依次取的是s里面的字符,直到取完为止
            int flag = map[c];//得到字符对应的哈希值
            if (stack.empty()) {
                stack.push(c);//若栈为空将字符压入栈中
            } else if (map[stack.top()]== flag - 3) {
                stack.pop();//若当前字符和栈顶字符刚好匹配一对，弹出栈顶元素
            } else {
                stack.push(c);//若当前字符和栈顶字符不匹配，将字符压入栈
            }
        }
        return stack.empty();//判断栈是否为空，即可判断字符串s元素是否相匹配
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===========\n";
    
    Solution solu;
//    cout<<"result = "<<solu.isValid("()")<<endl;
//    cout<<"result = "<<solu.isValid("()[]{}")<<endl;
//    cout<<"result = "<<solu.isValid("(]")<<endl;
//    cout<<"result = "<<solu.isValid("([)]")<<endl;
//    cout<<"result = "<<solu.isValid("{[]}")<<endl;
    
    cout<<"result = "<<solu.isValid2("()")<<endl;
    cout<<"result = "<<solu.isValid2("()[]{}")<<endl;
    cout<<"result = "<<solu.isValid2("(][)")<<endl;
    cout<<"result = "<<solu.isValid2("([)]")<<endl;
    cout<<"result = "<<solu.isValid2("{[]}")<<endl;
    
    std::cout << "===========\n";
    return 0;
}
