//
//  main.cpp
//  剑指offer19-正则表达式匹配
//
//  Created by YJLi on 2021/3/22.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    
    /*
     动态规划解析：
     1、状态定义： 设动态规划矩阵 dp ， dp[i][j] 代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配。

     2、转移方程： 需要注意，由于 dp[0][0] 代表的是空字符的状态， 因此 dp[i][j] 对应的添加字符是 s[i - 1] 和 p[j - 1] 。

     当 p[j - 1] = '*' 时， dp[i][j] 在当以下任一情况为 true 时等于 true ：

     dp[i][j - 2]： 即将字符组合 p[j - 2] * 看作出现 0 次时，能否匹配；
     dp[i - 1][j] 且 s[i - 1] = p[j - 2]: 即让字符 p[j - 2] 多出现 1 次时，能否匹配；
     dp[i - 1][j] 且 p[j - 2] = '.': 即让字符 '.' 多出现 1 次时，能否匹配；
     当 p[j - 1] != '*' 时， dp[i][j] 在当以下任一情况为 truetrue 时等于 truetrue ：

     dp[i - 1][j - 1] 且 s[i - 1] = p[j - 1]： 即让字符 p[j - 1] 多出现一次时，能否匹配；
     dp[i - 1][j - 1] 且 p[j - 1] = '.'： 即将字符 . 看作字符 s[i - 1] 时，能否匹配；
     初始化： 需要先初始化 dp 矩阵首行，以避免状态转移时索引越界。

     3、
     dp[0][0] = true： 代表两个空字符串能够匹配。
     dp[0][j] = dp[0][j - 2] 且 p[j - 1] = '*'： 首行 s 为空字符串，因此当 p 的偶数位为 * 时才能够匹配（即让 p 的奇数位出现 0 次，保持 p 是空字符串）。因此，循环遍历字符串 p ，步长为 2（即只看偶数位）。
     返回值： dp 矩阵右下角字符，代表字符串 s 和 p 能否匹配。
     */
    
public:
    bool isMatch(string s, string p) {
        int m = (int)s.size() + 1, n = (int)p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int j = 2; j < n; j+=2) {
            dp[0][j] = dp[0][j-2] && p[j-1] == '*';
        }
        //状态转移
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (p[j-1] == '*') {
                    if (dp[i][j - 2]) dp[i][j] = true; //1.
                    else if (dp[i-1][j] && s[i -1] == p[j -2]) dp[i][j] = true; // 2.
                    else if (dp[i - 1][j] && p[j -2] == '.') dp[i][j] = true; //3.
                } else {
                    if (dp[i - 1][j-1] && s[i -1] == p[j - 1]) dp[i][j] = true;//1.
                    else if (dp[i - 1][j-1] && p[j - 1] == '.') dp[i][j] = true;//2.
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
