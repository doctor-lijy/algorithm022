//
//  main.cpp
//  最大子序和-53
//
//  Created by YJLi on 2021/1/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    
    /*
     暴力解法
     */
    int maxSubArray(vector<int> &nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {// 设置起始位置
            count = 0;
            for (int j = i; j < nums.size(); j++) {// 每次从起始位置i开始遍历寻找最大值
                count += nums[j];
                result = count > result ? count : result;
            }
        }
        return result;
    }
    
    /*
     贪心解法
     
     之后再好好总结一下这个题目为什么可以采用贪心，贪心在哪里，比暴力破解优化的部分在哪里
     */
    int maxSubArray2(vector<int> &nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { //取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count <= 0) count = 0; //相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
