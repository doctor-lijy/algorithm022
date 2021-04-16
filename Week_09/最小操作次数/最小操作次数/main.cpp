//
//  main.cpp
//  最小操作次数
//
//  Created by YJLi on 2021/4/8.
//

#include <iostream>

using namespace std;
/*
 给出两个数  a b , 对a的每一次操作只能是 +1 -1 或者 *2，求 a到b的最小操作次数;
 */

class Solution {
    
public:
    int minOperating(int a, int b) {
        int count = 0;
        if (a >= b) return a-b;
        while (a << 1 < b) {
            count++;
            a <<= 1;
        }
        
        return count+b-a;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    
    cout<<"result = "<<solu.minOperating(2, 10)<<endl;
    
    std::cout << "Hello, World!\n";
    
    return 0;
}
