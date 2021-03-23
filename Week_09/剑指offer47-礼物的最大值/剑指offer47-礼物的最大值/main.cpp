//
//  main.cpp
//  剑指offer47-礼物的最大值
//
//  Created by YJLi on 2021/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    int maxValue(vector<vector<int>>& grid) {
            int m = (int)grid.size(), n = (int)grid[0].size();
            vector<vector<int>>dp(m, vector<int>(n));
            dp[0][0] = grid[0][0];
            for(int i = 1; i < m; i++) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }
            for(int j = 1; j < n; j++) {
                dp[0][j] = dp[0][j-1] + grid[0][j];
            }
            for(int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])+grid[i][j];
                }
            }
            return dp[m-1][n-1];
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    vector<vector<int>> vec = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout<<"result = "<< solu.maxValue(vec)<<endl;
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
