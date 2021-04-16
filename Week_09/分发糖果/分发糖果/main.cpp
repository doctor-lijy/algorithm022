//
//  main.cpp
//  分发糖果
//
//  Created by YJLi on 2021/4/1.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<vector<int>> candy(vector<int> &ratings) {
        int n = (int)ratings.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i-1]) {
                dp[i] = dp[i-1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        
        int right = 0;
        vector<int> res;
        for (int i = n-1; i >= 0; i--) {
            if (i < n-1 && ratings[i] > ratings[i+1]) {
                right++;
            } else {
                right = 1;
            }
            res.push_back(max(dp[i], right));
        }
        vector<vector<int>> result;
        result.push_back(dp);
        result.push_back(res);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    vector<int> vec = {1,2,3,4,3,2,1};
    vector<int> vec2 = {1,0,2};
    vector<int> vec3 = {1,2,3,4,5,6,7};
    vector<int> vec4 = {7,6,5,4,3,2,1};
    vector<vector<int>> result = solu.candy(vec2);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
