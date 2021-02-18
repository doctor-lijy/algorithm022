//
//  main.cpp
//  三数之和-15
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 给你一个包含 n 个整数的数组 nums ，判断 nums 中 是否存在三个元素a， b， c，使得a+b+c = 0？找出所有满足条件且不重复的三元组。
 
 注意：答案中不可以包含重复的三元组。

 示例：

 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

 满足要求的三元组集合为：[ [-1, 0, 1], [-1, -1, 2] ]
 */

class Solution {
    
public:
    
    /*
     双指针法：
     
     1、拿这个nums数组来举例，首先将数组排序，然后有一层for循环，i从下表0的地方开始，同时定一个下表left 定义在i+1的位置上，定义下表right 在数组结尾的位置上。

     依然还是在数组中找到 abc 使得a + b +c =0，我们这里相当于  a = nums[i] b = nums[left]  c = nums[right]。

     2、接下来如何移动left 和right呢， 如果nums[i] + nums[left] + nums[right] > 0  就说明 此时三数之和大了，因为数组是排序后了，所以right下表就应该向左移动，这样才能让三数之和小一些。

     3、如果 nums[i] + nums[left] + nums[right] < 0 说明 此时 三数之和小了，left 就向右移动，才能让三数之和大一些，直到left与right相遇为止。

     时间复杂度：O(n^2)。
     */
    vector<vector<int>>threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重方法，将会漏掉-1,-1,2 这种情况
            /*
             if (nums[i] == nums[i + 1]) {
             continue;
             }
             */
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = (int)nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                 while (right > left && nums[right] == nums[right - 1]) right--;
                 while (right > left && nums[left] == nums[left + 1]) left++;
                 */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
