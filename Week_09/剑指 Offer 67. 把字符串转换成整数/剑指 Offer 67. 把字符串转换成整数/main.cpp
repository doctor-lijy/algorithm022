//
//  main.cpp
//  剑指 Offer 67. 把字符串转换成整数
//
//  Created by YJLi on 2021/3/29.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
    
public:
    int strToInt(string str) {
        int res = 0, bndry = INT_MAX/10;
        int i = 0, sign = 1, length = (int)str.size();
        if (length == 0) return 0;
        while (str[i] == ' ') {
            if (++i == length) return 0;
        }
        if (str[i] == '-') {
            sign = -1;
        }
        if (str[i] == '-' || str[i] == '+') {
            i++;
        }
        for (int j = i; j < length; j++) {
            if (str[j] < '0' || str[j] > '9') break;
            if (res > bndry || (res == bndry && str[j] > '7')) {
                return sign == 1 ? INT_MAX :INT_MIN;
            }
            res = res*10 + (str[j] - '0');
        }
        return sign*res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
