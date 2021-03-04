//
//  main.cpp
//  左叶子之和-404
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
    
public:
    int sumOfLeftleaves(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int leftValue = sumOfLeftleaves(root->left);
        int rightValue = sumOfLeftleaves(root->right);
        
        int midValue = 0;
        if (root->left && !root->left->left && !root->left->right) {
            midValue = midValue;
        }
        return midValue + leftValue + rightValue;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
