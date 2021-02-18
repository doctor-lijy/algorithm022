//
//  main.cpp
//  快乐数-202
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <unordered_set>

using namespace std;

/*
 编写一个算法来判断一个数 n 是不是快乐数。
 
 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
 
 如果 n 是快乐数就返回 True ；不是，则返回 False 。
 
 「示例：」

 输入：19
 输出：true
 解释：
 12 + 92 = 82
 8*8 + 2*2 = 68
 6*6 + 8*8 = 100
 1*1 + 0 + 0 = 1
 */
/*
 题目中提到了 无限循环，这就是在求和的过程中，sum会重复出现，因为出现了重复的sum值，所以才会循环，这个对解题很重要！
 
 当遇到了要快速判断一个元素是否出现集合里的时候，就要考虑使用哈希法了
 */
class Solution {
    
    /*
     解题的思路在于：
     采用哈希法，来判断这个sum是否重复出现，如果重复了就return false ，否则一直找到sum为1weizhi
     */
public:
    // 取数值各个位上的单数之和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> set;
        
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            /*
             find(key)
             查找以值为 key 的元素，如果找到，则返回一个指向该元素的正向迭代器；反之，则返回一个指向容器中最后一个元素之后位置的迭代器（如果 end() 方法返回的迭代器）
             
             如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
             */
            if (set.find(sum) != set.end()) {
                return  false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    
    cout <<"66 是否是素数 = "<<solu.isHappy(19)<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
