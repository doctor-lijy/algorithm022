//
//  main.cpp
//  有效的括号-20
//
//  Created by YJLi on 2021/1/4.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===========\n";
    
    Solution solu;
    cout<<"result = "<<solu.isValid("()")<<endl;
    cout<<"result = "<<solu.isValid("()[]{}")<<endl;
    cout<<"result = "<<solu.isValid("(]")<<endl;
    cout<<"result = "<<solu.isValid("([)]")<<endl;
    cout<<"result = "<<solu.isValid("{[]}")<<endl;
    
    std::cout << "===========\n";
    return 0;
}
