//
//  main.cpp
//  剑指 Offer 59 - I. 滑动窗口的最大值
//
//  Created by YJLi on 2021/3/29.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        deque<int>deq; //维护一个双端队列
        for (int i = 0; i < k; i++) {
            while (!deq.empty() && deq.back() < nums[i]) {//始终保持队首元素为最大值
                deq.pop_back();
            }
            deq.push_back(nums[i]);
        }
        res.push_back(deq.front());
        for (int i = k; i < nums.size(); i++) {
            if (deq.front() == nums[i-k]) {
                deq.pop_front();
            }
            while (!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            res.push_back(deq.front());
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
