//
//  main.cpp
//  找出最大组合数-179
//
//  Created by YJLi on 2021/3/3.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    
public:
    static bool comparison(const int &a, const int &b) {
        string concatenation1 = to_string(a) + to_string(b);
        string concatenation2 = to_string(b)+to_string(b);
        
        return concatenation1 > concatenation2;
    }
    string largestNumber(vector<int> &nums) {
        if (nums.empty()) return "";
        if (nums.size() == 1) {
            return to_string(nums[0]);
        }
        sort(nums.begin(), nums.end(), comparison);
        string result = "";
        for (int i : nums) {
            result += to_string(i);
        }
        if (result[0] == '0') {
            return "0"; // 特殊case，全是0的时候应该输出0而不是00000
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
