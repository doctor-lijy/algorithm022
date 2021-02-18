//
//  main.cpp
//  两数之和-1
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 给定一个整数数组 nums 和一个目标值 target，在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
 
 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 「示例:」

 给定 nums = [2, 7, 11, 15], target = 9
 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]
 */

class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            /*
             find(key)
             查找以值为 key 的元素，如果找到，则返回一个指向该元素的正向迭代器；
             反之，则返回一个指向容器中最后一个元素之后位置的迭代器（如果 end() 方法返回的迭代器）
             
             unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
             */
            auto iter = map.find(target - nums[i]); //这种写法等同于上面那种写法
            if (iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(nums[i], i);
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "============\n";
    Solution solu;
    vector<int> vec = {2, 7, 11, 15};
    vector<int> result = solu.twoSum(vec, 9);
    for (int i = 0; i < result.size(); i++) {
        cout<<result.at(i)<<" ";
    }
    cout<<endl;
    
    std::cout << "============\n";
    return 0;
}
