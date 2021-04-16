//
//  main.cpp
//  归并排序
//
//  Created by YJLi on 2021/3/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    void mergeSort(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) /2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        
        merge(nums, left, mid, right);
    }
    void merge(vector<int> &nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int i = left, j = mid+1, k = 0;
        while (i <= mid && j <= right) {
            tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= right) {
            tmp[k++] = nums[j++];
        }
        for (int i = left, k= 0; i<= right; ) {
            nums[i++] = tmp[k++];
        }
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
    vector<int> vec = {7,5,6,4, 3,2,9,0};
    solu.mergeSort(vec, 0, (int)vec.size()-1);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
