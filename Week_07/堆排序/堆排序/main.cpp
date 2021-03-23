//
//  main.cpp
//  堆排序
//
//  Created by YJLi on 2021/2/2.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 堆是具有下列性质的完全二叉树：
 1、每个结点的值都大于或等于其左右孩子结点的值，称为大顶推；
 2、每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆；
 */

/*
 堆排序就是利用堆进行排序的方法。
 
 它的工作原理为对所有待排序元素建堆，然后依次取出堆顶元素，就可以得到排好序的序列。
 当当前的结点下标为 i 时，父结点、左子结点和右子结点的选择方式如下：

 //这里 floor 函数将实数映射到最小的前导整数。
 iParent(i) = floor((i - 1) / 2);
 iLeftChild(i) = 2 * i + 1;
 iRightChild(i) = 2 * i + 2;
 
 基本思想是：将待排序的序列构造成一个大顶堆。此时，整个序列的最大值就是堆顶的根节点。将它移走（其实就是将其与堆数组的末尾元素交换，此时末尾元素就是做大值），然后将剩余的n-1个序列重新构造成一个堆，这样就会得到n个元素中的次小值。如此反复执行，便能得到一个有序序列了。
 */

class Solution {
    
public:
    void headify(vector<int> &nums, int length, int i) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int largest = i;
        if (left < length && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < length && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            headify(nums, length, largest);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
    vector<int> vec = {1, 2, 4, 5, 3};
    solu.headify(vec, (int)vec.size(), 0);
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
