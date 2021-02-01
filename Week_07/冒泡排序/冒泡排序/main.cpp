//
//  main.cpp
//  冒泡排序
//
//  Created by YJLi on 2021/2/1.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 交换相同类型的两个变量内容
 template<class T>
 void swap(T &a, T &b) {
     T temp = a;
     a = b;
     b = temp;
 }
 */
/*
 冒泡排序 一种交换排序
 基本思想是：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止
 */

class Solution {
    
public:
    /*
     不算是标准的冒泡排序的算法，因为它不满足“两两比较相邻记录”的冒泡排序思想。
     它的思路就是让每一个关键字，都与它后面的每一个关键字比较，如果大则交换，这样第一个位置的关键字在一次循环后一定变成最小值。
     */
    void BubbleSort(vector<int> &nums) {
        for (int i = 0; i < nums.size() ; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
    
    /*
     标准的冒泡排序
     为什么想到从后到前面开始遍历？？？
     这样遍历的过程就是从下到上像起泡一样向上逐步上升
     */
    void BubbleSort2(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++){
            for (int j = (int)nums.size() - 1; j >= i; j--) {
                if (nums[j] < nums[j-1]) {
                    swap(nums[j], nums[j-1]);
                }
            }
        }
    }
    
    /*
     冒泡优化
     如果待排序的序列是{2, 1, 3, 4, 5, 6, 7, 8, 9}，除了第一和第二的关键字需要交换外，别的都是已经正常的顺序。
     当i=0时交换了2和1，此时序列已经有序，但是算法仍然不依不饶的将i = 1
     到8以及每个循环中的j都循环都执行一遍，尽管并没有交换数据，但是之后的大量比较还是大大地多余了
     */
    void BubbleSort3(vector<int> &nums) {
        bool flag = true;//用flag来标记
        for (int i = 1; i < nums.size(); i++) {
            flag = false;
            for (int j = (int)nums.size() - 1; j >= i; j--) {
                if (nums[j] < nums[j-1]) {//这里比较的是j 和j+1，所以循环就是从i=1开始
                    swap(nums[j], nums[j-1]);
                    flag = true;//如果有数据交换，则flag为true
                }
            }
            if (!flag) {//如果，没有数据交换，则flag为false，直接跳出循环
                break;
            }
        }
    }
    /*
     时间复杂度：
     最好的情况：待排序的序列本身是有序的，根据改进后的代码推断就是n-1次的比较，没有数据交换，时间复杂度O(n);
     最差的情况：待排序的序列本身是逆序的，根据改进后的代码推断就是1+2+3+...+n-1次的比较，并做等量级的数据移动交换，时间复杂度O(n*n);
     */
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    
    vector<int> vec = {9, 1, 5, 8, 3, 7, 4, 6, 2, 7};
    cout<<"size = "<<vec.size()<<endl;
    cout<<"vec[0] = "<<vec[0]<<" vec[1] = "<<vec[1]<<endl;
//    solu.BubbleSort(vec);
    solu.BubbleSort2(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    
    cout<<endl;
    
    vector<int> vec2 = {2, 1, 3, 4, 5, 6, 7, 8, 9};
    solu.BubbleSort3(vec2);
    cout<<"size2 = "<<vec2.size()<<endl;
    cout<<"vec2[0] = "<<vec2[0]<<" vec2[size-1] = "<<vec2[vec2.size()-1]<<endl;
    for (int i = 0; i < vec2.size(); i++) {
        cout<<vec2[i]<<" ";
    }
    
    cout<<endl;
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
