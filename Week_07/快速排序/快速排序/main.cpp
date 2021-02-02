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
 */
class Solution {
    
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
    vector<int> vec = {2,4,1,23,5,76,0,43,24,65};
    vector<int> result = solu.sortArray(vec);
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
