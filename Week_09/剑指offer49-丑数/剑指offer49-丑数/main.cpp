//
//  main.cpp
//  剑指offer49-丑数
//
//  Created by YJLi on 2021/3/22.
//

#include <iostream>

using namespace std;

class Solution {
    /*
     丑数的递推性质： 丑数只包含因子 2, 3, 5，因此有 “丑数 == 某较小丑数 × 某因子” （例如：10 = 5×2）
*/
    
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c= 0;
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2) a++;
            if (dp[i] == n3) b++;
            if (dp[i] == n5) c++;
        }
        return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
