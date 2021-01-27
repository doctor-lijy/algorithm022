//
//  main.cpp
//  使用最小花费爬楼梯-746
//
//  Created by YJLi on 2021/1/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    /*
     动态规划
     
     1、确定dp数组以及下标的含义
     使用动态规划，就要有一个数组来记录状态，本题只需要一个一维数组dp[i]就可以了。

     dp[i]的定义：第i个台阶所花费的最少体力为dp[i]。
     
     2、确定递推公式
     可以有两个途径得到dp[i]，一个是dp[i-1] 一个是dp[i-2]。

     那么究竟是选dp[i-1]还是dp[i-2]呢？

     一定是选最小的，所以dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];

     注意这里为什么是加cost[i]，而不是cost[i-1],cost[i-2]之类的，因为题目中说了：每当你爬上一个阶梯你都要花费对应的体力值
     
     3、dp数组如何初始化
     根据dp数组的定义，dp数组初始化其实是比较难的，因为不可能初始化为第i台阶所花费的最少体力。

     那么看一下递归公式，dp[i]由dp[i-1]，dp[i-2]推出，既然初始化所有的dp[i]是不可能的，那么只初始化dp[0]和dp[1]就够了，其他的最终都是dp[0]dp[1]推出
     
     4、确定遍历顺序
     
     5、举例推导dp数组
     */
    
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
    /*
     时间复杂度：O(n)
     空间复杂度：O(n)
     */
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    vector<int> vec = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int result = solu.minCostClimbingStairs(vec);
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
