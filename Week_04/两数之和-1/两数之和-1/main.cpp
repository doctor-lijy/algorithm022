//
//  main.cpp
//  两数之和-1
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map <int,int> map;
            for(int i = 0; i < nums.size(); i++) {
                auto iter = map.find(target - nums[i]);
                if(iter != map.end()) {
                    return {iter->second, i};
                }
                map.insert(make_pair(nums[i], i));
            }
            return {};
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "============\n";
    Solution solu;
    vector<int> vec = {2, 7, 11, 15};
    vector<int> result = solu.twoSum(vec, 9);
    for (int i = 0; i < result.size(); i++) {
        cout<<result.at(i)<<" ";
    }
    cout<<endl;
    
    std::cout << "============\n";
    return 0;
}
