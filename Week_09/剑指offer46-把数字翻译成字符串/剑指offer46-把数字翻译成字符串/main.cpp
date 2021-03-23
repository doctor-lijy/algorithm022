//
//  main.cpp
//  剑指offer46-把数字翻译成字符串
//
//  Created by YJLi on 2021/3/22.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
    
    /*
     初始状态： dp[0] = dp[1] = 1dp[0]=dp[1]=1 ，即 “无数字” 和 “第 11 位数字” 的翻译方法数量均为 11 ；

     返回值： dp[n]dp[n] ，即此数字的翻译方案数量；

     Q： 无数字情况 dp[0] = 1dp[0]=1 从何而来？
     A： 当 numnum 第 1, 21,2 位的组成的数字 \in [10,25]∈[10,25] 时，显然应有 22 种翻译方法，即 dp[2] = dp[1] + dp[0] = 2dp[2]=dp[1]+dp[0]=2 ，而显然 dp[1] = 1dp[1]=1 ，因此推出 dp[0] = 1dp[0]=1 。

     */
    
public:
    int translateNum(int num) {
        string s = to_string(num);
        int a = 1, b = 1, len = (int)s.length();
        for (int i = 2; i <= len; i++) {
            string tmp = s.substr(i-2, 2);
            int c = tmp.compare("10") >= 0 && tmp.compare("25") <= 0 ? a+b : a;
            b = a;
            a = c;
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    int result = solu.translateNum(12258);
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
