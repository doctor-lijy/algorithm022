//
//  main.cpp
//  二叉树最大的深度-104
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

//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数

class Solution {
    
public:
    int getDepth(TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
