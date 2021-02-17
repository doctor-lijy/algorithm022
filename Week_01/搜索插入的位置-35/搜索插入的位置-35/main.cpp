//
//  main.cpp
//  搜索插入的位置-35
//
//  Created by YJLi on 2021/2/17.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被顺序插入的位置
 假设数组中无重复元素
 */
/*
 理解：
 1、数组是已排序的，数组元素无重复
 2、目标值在数组元素之后
 3、目标值在数组元素之前
 4、目标值等于数组元素中某一个元素
 5、目标值插入数组中的位置
 */

class Solution {
    
public:
    /* 暴力解法*/
    int searchInsert(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            /*
             分别处理如下三种情况：
             1、目标值在数组所有元素之前
             2、目标值等于数组中某一个元素
             3、目标值插入数组中的位置
             */
            /*
             这里只考虑了数组升序的情况，若是降序数组需要在遍历之前判断是升序还是降序，只判断首尾两个元素的大小即可
             */
            if (nums[i] >= target) {// 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                return i;
            }
        }
        
        /*
         目标值在数组所有元素之后
         如果target是最大的，或者 nums 为空，则返回nums的长度
         */
        return (int)nums.size();
    }
    /*
    时间复杂度：O(n)
     空间复杂度：O(1)
     */
    
    /*
     二分法
     
     只要看到面试题里给出的数组是排序数组，都可以想一想是否可以使用二分法
     
     binary search中计算mid=(beg+end)/2与mid=beg+(end-beg)/2的区别:
     这两种写法应该都见过，突然想起了这个问题，自己没想出来什么结果，感觉没有不同。后来再各种论坛问了问，结果都没能说出什么道理，还是stackoverflow比较牛，刚post上去没两分钟就给出来了答案。以后多逛逛stackoverflow吧。http://stackoverflow.com/questions/20998982/whats-the-difference-between-mid-begend-2-and-mid-begend-beg-2-in-binary

     1、首先第一种写法与第二种数学上得到的结果是完全一样的，这个可以通过取整函数的方法证明。但是beg＋end操作很可能会出现溢出的风险，但是后一种写法不会出现比end要大的中间数据，所以比较安全。

     2、你要是看c＋＋stl源码就会发现用的也是第二种，因为考虑了通用性，用第一种如果beg和end是指针或者迭代器的话是无法编译通过的，因为指针和迭代器运算不支持相加运算，却支持相减运算，所以第二种通用性强。（迭代器的话要求是随机访问迭代器random access iterator）。

     基本就是这两点原因了，这个问题也是c＋＋primer fifth edition 3.26 上问到的。
     */
    
    /*
     例如到底是 while(left < right) 还是 while(left <= right)，到底是right = middle呢，还是要right = middle - 1呢？
     */
    /*
     左闭右闭
     「仔细看注释，思考为什么要写while(left <= right)， 为什么要写right = middle - 1」。
     */
    int searchInsert2(vector<int> &nums, int targrt) {
        int n = (int)nums.size();
        int left = 0;
        int right = n - 1; //定义target在左闭右闭的区间里，[left, right]
        while (left <= right) {// 当left==right，区间[left, right]依然有效
            int middle = left + (right - left) / 2; // 防止溢出 等同于(left + right)/2
            if (nums[middle] > targrt) { // target 在左区间，所以[left, middle - 1]
                right = middle - 1;
            } else if (nums[middle] < targrt) { // target 在右区间，所以[middle + 1, right]
                left = middle + 1;
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， return right + 1
        return right + 1;
    }
    /*
     时间复杂度：O(logn)
     空间复杂度：O(1)
     */
    
    /*
     左闭右开
     「仔细看注释，思考为什么要写while (left < right)， 为什么要写right = middle」
     */
    int searchInsert3(vector<int> &nums, int target) {
        int n = (int)nums.size();
        int left = 0;
        int right = n;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在 [middle+1, right)中
            } else {
                return middle; // 数组中找到目标值的情况，直接返回下标
            }
        }
        return right;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> vec = {1,3,5,6, 10, 14, 19, 20};
    Solution solu;
    
    int result = solu.searchInsert2(vec, 4);
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
