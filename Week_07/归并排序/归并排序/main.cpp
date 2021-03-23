//
//  main.cpp
//  归并排序
//
//  Created by YJLi on 2021/2/2.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 归并排序 Merge Sort- 分治
 
 1、把长度为n的输入序列分为两个长度为n/2的子序列
 2、对这两个子序列分别采用归并排序
 3、将两个排序好的子序列合并成一个最终的排序序列
 */

class Solution {
    
public:
    void mergeSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int> nums, int left, int mid, int right) {
        vector<int> tmp(right-left+1); //默认值初始化，ilist4中将包含7个元素，每个元素进行缺省的值初始化
        int i = left, j = mid +1, k = 0;
        while (i <= mid && j <= right) {
            tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= right) {
            tmp[k++] = nums[j++];
        }
        for (i = left, k = 0; i <= right; ) {
            nums[i++] = tmp[k++];
        }
    }
        
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
