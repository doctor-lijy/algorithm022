//
//  main.cpp
//  二叉树的前序遍历-144
//
//  Created by YJLi on 2021/1/11.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

class Solution {
    
public:
    int sum(int n) {
        if (n <= 0) {
            return 0;
        }
        return n + sum(n-1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "============\n";
    Solution solu;
    cout<<"求和 = "<<solu.sum(100)<<endl;
    
    std::cout << "============\n";
    return 0;
}
