//
//  main.cpp
//  爬楼梯-70
//
//  Created by YJLi on 2021/1/4.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    Solution solu;
    int result = solu.climbStairs(5);
    cout<<"result = "<<result<<endl;
    
    std::cout << "==============\n";
    return 0;
}
