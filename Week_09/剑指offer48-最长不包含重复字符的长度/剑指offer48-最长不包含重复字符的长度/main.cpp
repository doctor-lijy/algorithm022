//
//  main.cpp
//  剑指offer48-最长不包含重复字符的长度
//
//  Created by YJLi on 2021/3/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    
    /*
     1、状态定义： 设动态规划列表 dp，dp[j] 代表以字符 s[j] 为结尾的 “最长不重复子字符串” 的长度。

     2、转移方程： 固定右边界 j ，设字符 s[j] 左边距离最近的相同字符为 s[i] ，即 s[i] = s[j]。

     1.当 i < 0，即 s[j]左边无相同字符，则 dp[j] = dp[j-1] + 1；
     2.当 dp[j - 1] < j - i，说明字符 s[i]在子字符串 dp[j-1]区间之外 ，则 dp[j] = dp[j - 1] + 1；
     3.当 dp[j−1]≥j−i ，说明字符 s[i] 在子字符串 dp[j-1]区间之中 ，则 dp[j]的左边界由 s[i] 决定，即 dp[j] = j - i ；

     当 i < 0 时，由于 dp[j−1]≤j 恒成立，因而 dp[j - 1] < j - i恒成立，因此分支 1. 和 2. 可被合并
     
     3、返回值： max(dp) ，即全局的 “最长不重复子字符串” 的长度

     */
    
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, tmp = 0, len = (int)s.length();
        for (int j = 0; j < len; j++) {
            int i = j - 1;
            while (i >= 0 && s[i] != s[j]) {
                i--;
            }
            tmp = tmp < j - i ? tmp+1 :j-i;
            res = max(res, tmp);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    
    
    std::cout << "Hello, World!\n";
    return 0;
}
