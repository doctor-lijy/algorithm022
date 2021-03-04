//
//  main.cpp
//  完全二叉树的节点个数-222
//
//  Created by YJLi on 2021/1/18.
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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
