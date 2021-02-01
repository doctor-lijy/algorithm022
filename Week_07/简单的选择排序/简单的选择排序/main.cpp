//
//  main.cpp
//  简单的选择排序
//
//  Created by YJLi on 2021/2/1.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 简单选择排序就是通过n-i次关键字间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i个记录交换之
 */

class Solution {
    
public:
    void SelectSort(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int min = i;//将当前下标i定义为最小值
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {//如果有小于当前最小值
                    min = j;//将次关键字的下标赋值给min
                }
            }
            if (i != min) {//如果min不等于i说明找到最小值交换
                swap(nums[i], nums[min]);
            }
        }
    }
    /*
     从简单选择排序的过程中来看，它最大的特点就是交换移动数据次数相当少，这样也就节约了响应的时间。
     分析它的时间复杂度发现，无论最好最差的情况，其比较次数都是一样的多，第i趟排序需要进行n-i次关键字的比较，此时需要比较的次数是n-1+n-2+...+2+1 = n*(n-1)/2次。而对于交换次数而言，当最好的时候，交换次数为0ci，最差的时候也就是初始降序时，交换次数为n-1次，基于最终的排序时间是比较与交换的次数的总和，因此，总的时间复杂度是O(n*n)。
     尽管与冒泡排序同为O(n*n)，但是简单选择排序的性能上还是略优于冒泡排序。
     */
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
    vector<int> vec = {9, 1, 5, 8, 3, 7, 4, 6, 2, 7};
    solu.SelectSort(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
