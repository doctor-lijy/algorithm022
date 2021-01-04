//
//  main.cpp
//  移动零-283
//
//  Created by YJLi on 2021/1/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
    void moveZeroes2(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
    void printNums(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout<< nums.at(i) <<" ";
        }
        cout<<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===========\n";
    Solution solu;
    vector<int> vec = {0,1,0,3,12};
//    solu.moveZeroes(vec);
    solu.moveZeroes2(vec);
    solu.printNums(vec);
    
    std::cout << "===========\n";
    return 0;
}
