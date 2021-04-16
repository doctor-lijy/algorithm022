//
//  main.cpp
//  剑指 Offer 51. 数组中的逆序对
//
//  Created by YJLi on 2021/3/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int mergeSort(vector<int> &nums, int left, int right, vector<int>&tmp) {
        if (left >= right) return 0;
        int mid = left + (right-left) /2;
        int res = mergeSort(nums, left, mid, tmp) + mergeSort(nums, mid+1, right, tmp);
        
        int i = left, j = mid+1;
        for (int k = left; k <= right; k++) {
            tmp[k] = nums[k];
        }
        for (int k = left; k <= right; k++) {
            if (i == mid + 1) {
                nums[k] = tmp[j++];
            } else if (j == right+1 || tmp[i] <= tmp[j]) {
                nums[k] = tmp[i++];
            } else {
                nums[k] = tmp[j++];
                res += mid-i+1;
            }
        }
        return res;
    }
    
public:
    int reversePairs(vector<int> &nums) {
        vector<int> tmp(nums.size());
        return mergeSort(nums, 0, (int)nums.size()-1, tmp);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    vector<int> vec = {7,5,6,4};
    cout<<"res = "<<solu.reversePairs(vec);
    cout<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
