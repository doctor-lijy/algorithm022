//
//  main.cpp
//  三数之和-15
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<vector<int>>threeSum(vector<int> &nums) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return result;
            }
            
            
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
