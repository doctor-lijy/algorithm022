//
//  main.cpp
//  希尔排序
//
//  Created by YJLi on 2021/2/1.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 希尔排序，也称为缩小增量排序法，是插入排序的一种改进版本
 
 工作原理：排序对不相邻的记录进行比较和移动：
 1、将待排序序列分为若干个子序列（每个子序列的元素在原始数组中间距相同）；
 2、对这些子序列进行插入排序；
 3、减少每个子序列中元素之间的间距，重复上述过程直至间距减少为1.
 
 希尔排序是一种不稳定的排序算法
 
 时间复杂度：
 最优时间复杂度为O(n)
 希尔排序的平均时间复杂度和最坏时间复杂度与间距序列的选取（就是间距如何减小到 1）有关，比如「间距每次除以 3」的希尔排序的时间复杂度是 O(sqrt(n*n*n)) 。已知最好的最坏时间复杂度为 n*logn 。
 空间复杂度：O(n)
 */

class Solution {
    
public:
    /*
     直接插入排序
     */
    void InsertSort(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            int key = nums[i];//待排序的第一个元素
            int j = i - 1;//已经排过序的最后一个元素
            while (j >= 0 && key < nums[j]) {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;//找到合适的位置了，在索引 j 的后面设置 j 的值
        }
    }
    
    /*
     对直接插入排序的优化
     {12, 15, 9, 20, 6, 31, 24 }
     gap = 7/2 = 3、3/2 = 1
     */
    void ShellSort(vector<int> &num) {
        int i, j, gap;
        for (gap = (int)num.size() / 2; gap > 0; gap /= 2) {//步长
            for (i = 0; i < gap; i++) {//直接插入排序
                for (j = i + gap; j < num.size(); j += gap) {
                    if (num[j] < num[j - gap]) {
                        int key = num[j];
                        int k = j - gap;
                        while (k >= 0 && num[k] > key) {
                            num[k + gap] = num[k];
                            k -= gap;
                        }
                        num[k + gap] = key;
                    }
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
    vector<int> vec = {12, 15, 9, 20, 6, 31, 24 };
    solu.ShellSort(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
