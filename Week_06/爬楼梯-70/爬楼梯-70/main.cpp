//
//  main.cpp
//  爬楼梯-70
//
//  Created by YJLi on 2021/1/27.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 动态规划
 1、确定dp数组以及下标的定义
 dp[i]：爬到第i层楼梯，有dp[i]种方法
 
 2、确定递推公式
 如果可以推出dp[i]呢？

 从dp[i]的定义可以看出，dp[i] 可以有两个方向推出来。

 首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。

 还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么。

 那么dp[i]就是 dp[i - 1]与dp[i - 2]之和！

 所以dp[i] = dp[i - 1] + dp[i - 2] 。

 在推导dp[i]的时候，一定要时刻想着dp[i]的定义，否则容易跑偏。

 这体现出确定dp数组以及下标的含义的重要性！
 
 3、dp数组如何初始化
 
 4、确定遍历顺序
 
 5、举例推导dp数组
 
 */

class Solution {
    
public:
    int climbStairs (int n) {
        if (n <= 1) return n;// 因为下面直接对dp[2]操作了，防止空指针
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {// 注意i是从3开始的
            dp[i] = dp[i -1] + dp[i - 2];
        }
        return dp[n];
    }
    /*
     时间复杂度：O(n)
     空间复杂度：O(n)
     */
    
    int climbStairs2 (int n) {
        if (n <= 1) return n;
        int dp[3];//我觉得这里有点牛逼的，数组元素个数为什么选择3个
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    int result = solu.climbStairs2(4);
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
