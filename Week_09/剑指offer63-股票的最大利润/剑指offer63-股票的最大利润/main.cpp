//
//  main.cpp
//  剑指offer63-股票的最大利润
//
//  Created by YJLi on 2021/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        int n = (int)prices.size();
        vector<int>dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            cost = min(cost, prices[i]);
            dp[i]=max(dp[i-1], prices[i]-cost);
        }
        return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
