//
//  main.cpp
//  四数之和-18
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

 「注意：」

 答案中不可以包含重复的四元组。

 示例：
 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 满足要求的四元组集合为：
 [ [-1,  0, 0, 1], [-2, -1, 1, 2], [-2,  0, 0, 2] ]
 */

/*
 首先理解题意，一个整数数组和目标值target，数组中包含四个元素使得 a + b + c + d 的值与 target 相等，找出满足条件不重复的四元组
 */

class Solution {
    
public:
    vector<vector<int>> fourSum(vector<int>&nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 这种剪枝是错误的，这道题目target 是任意值
            // if (nums[k] > target) {
            //     return result;
            // }
            // 去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = (int)nums.size() - 1;
                while (right > left) {
                    if (nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    } else if (nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left--;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 去重逻辑应该放在找到一个四元组之后
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        
                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    vector<int> vec = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solu.fourSum(vec, target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
