//
//  main.cpp
//  三数之和-15
//
//  Created by YJLi on 2021/1/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first-1]) {
                continue;;
            }
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "================\n";
    Solution solu;
    vector<vector<int>> ans;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    ans = solu.threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout<<"{";
        for (int j = 0; j < ans.at(i).size(); j++) {
            cout<<ans.at(i).at(j)<<" ";
        }
        cout<<"}"<<endl;
    }
    
    std::cout << "================\n";
    return 0;
}
