//
//  main.cpp
//  两个数组的交集-349
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//这里需要再熟记下set map 的实现原理和特性，知道怎么用的才行

class Solution {
    
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result_set;//存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            //发现num2的元素，在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
