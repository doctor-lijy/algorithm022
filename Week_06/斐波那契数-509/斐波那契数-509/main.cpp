//
//  main.cpp
//  斐波那契数-509
//
//  Created by YJLi on 2021/1/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    /*
     动态规划：
     1.确定dp数组以及下标的含义
     dp[i]的定义为：第i个数的斐波那契数值是dp[i]
     
     2.确定递推公式
     
     3.dp数组如何初始化
     
     4.确定遍历顺序
     
     5.举例推导dp数组
     */

    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i -2];
        }
        return dp[n];
    }
    
    /*
     时间复杂度：O(n)
     空间复杂度：O(n)
     */
    
    /*
     当然可以发现，我们只需要维护两个数值就可以了，不需要记录整个序列
     */
    int fib2(int n) {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
    /*
     时间复杂度：O(n)
     空间复杂度：O(1)
     */

    /*
     递归解法
     */
    int fib3(int n) {
        if (n < 2) return n;
        return fib3(n - 1) + fib3(n - 2);
    }
    /*
     时间复杂度：O(2^n)
     空间复杂度：O(n)  算上了编程语言中实现递归的系统栈所占空间
     */
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    int result = solu.fib2(4);
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
