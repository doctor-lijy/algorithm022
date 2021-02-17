//
//  main.cpp
//  移除元素-27
//
//  Created by YJLi on 2021/2/17.
//

#include <iostream>
#include <vector>

using namespace std;

class solution {
    
public:
    /*
     暴力解法
     */
    int removeElement(vector<int>& nums, int val) {
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i+1; j < size; j++) {
                    nums[j-1] = nums[j];
                }
                i--; // 因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
                size--;  // 此时数组的大小-1
            }
        }
        return size;
    }
    /*
     时间复杂度：O(n*n)
     */
    
    /*
     双指针法（快慢指针法）：「通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。」
     双指针解法：
     */
    int removeElement2(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
    /*
     双指针法将时间复杂度O(n^2)的解法优化为 O(n)的解法
     */
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> vec = {0,1,2,2,3,0,4,2};
    solution solu;
    int result = solu.removeElement(vec, 2);
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
