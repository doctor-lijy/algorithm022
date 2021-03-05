//
//  main.cpp
//  斐波那契数-509
//
//  Created by YJLi on 2021/1/27.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 F(0) = 0，F(1) = 1
 F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 给你n ，请计算 F(n) 。

 示例 1：
 输入：2
 输出：1
 解释：F(2) = F(1) + F(0) = 1 + 0 = 1

 示例 2：输入：3
 输出：2
 解释：F(3) = F(2) + F(1) = 1 + 1 = 2

 示例 3：
 输入：4
 输出：3
 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
   提示：

 0 <= n <= 30
 */

class Solution {
    
public:
    /*
     动态规划
     动规五步曲
     
     这里用一个一维 dp 数组来保存递归的结果
     
     1.确定dp 数组以及下标的定义
     
     dp[i]的定义为：第i个数的斐波那契数值是 dp[i]
     
     2.确定递推公式
     
     状态转移方程: dp[i] = dp[i - 1] + dp[i - 2]
     
     3.dp数组 如何初始化
     
     dp[0] = 0;
     dp[1] = 1;
     
     4.确定遍历顺序
     
     从递推公式 dp[i] = dp[i - 1] + dp[i -2]中可以看出，dp[i]是依赖 dp[i - 1]和 dp[i -2]，那么遍历顺序一定是从前到后遍历的
     
     5. 举例推导 dp数组
     
     按照这个递推公式dp[i] = dp[i - 1] + dp[i - 2]，我们来推导一下，当N为10的时候，dp数组应该是如下的数列：

     0 1 1 2 3 5 8 13 21 34 55

     如果代码写出来，发现结果不对，就把dp数组打印出来看看和我们推导的数列是不是一致的
     
     */

    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1); //默认值初始化，dp中包含 n+1 个元素，每个元素进行缺省的值初始化，对于int，初始化为0
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
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
