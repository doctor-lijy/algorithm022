//
//  main.cpp
//  盛水最多的容器-11
//
//  Created by YJLi on 2021/1/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ans = 0;
        while (left < right) {
            int area = min(height[left], height[right])*(right-left);
            ans = max(ans, area);
            if (height[left] <= height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===========\n";
    
    Solution solu;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int area = solu.maxArea(height);
    cout<<"area = "<<area<<endl;
    
    std::cout << "===========\n";
    return 0;
}
