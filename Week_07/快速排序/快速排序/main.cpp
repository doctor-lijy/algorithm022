//
//  main.cpp
//  快速排序
//
//  Created by YJLi on 2021/2/2.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 希尔排序 是 插入排序 的升级 插入排序类
 堆排序 是 简单选择排序 的升级 选择排序类
 快速排序 是 冒泡排序 的升级 交换排序类
 */

/*
 快速排序的基本思想：
 通过一趟待排序记录分割成独立的两部分，其中一部分记录的关键字均比另一部分记录的关键字小，则可分别对这部分记录继续进行排序，以达到整个序列有序的目的
 
 数组取标杆pivot，将小元素放pivot左边，大元素放pivot右边，以此对右边和左边的子数组继续快排，以达到整个序列有序
 */
class Solution {
    
public:
    
    int partition(vector<int> &nums, int begin, int end) {
        //pivot 标杆位置 counter 小于poivt的元素的个数
        int pivot = end, counter = begin;
        for (int i = begin; i < end; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums[i], nums[counter]);
                counter++;
            }
        }
        swap(nums[pivot], nums[counter]);
        return counter;
    }
    void quickSort(vector<int> &nums, int begin, int end) {
        if (end <= begin) return;
        int pivot = partition(nums, begin, end);
        quickSort(nums, begin, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
    vector<int> vec = {2,4,1,23,5,76,0,43,24,65};
    solu.quickSort(vec, 0, (int)vec.size() - 1);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
