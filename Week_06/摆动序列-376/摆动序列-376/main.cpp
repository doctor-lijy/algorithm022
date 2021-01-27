//
//  main.cpp
//  摆动序列-376
//
//  Created by YJLi on 2021/1/27.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 贪心的题目说简单有的时候就是常识，说难就难在都不知道该怎么用贪心
 */

class Solution {
    
public:
    int wigggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1) return (int)nums.size();
        int curDiff = 0; //当前一对差值
        int preDiff = 0;  //前一对差值
        int result = 1; //记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 1; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            
            //出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;;
    }
    /*
     保持区间波动，只需要把单调区间上的元素移除就可以了
     */
    
    /*
     时间复杂度O(n)，空间复杂度O(1)
     */
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
