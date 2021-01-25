//
//  main.cpp
//  二叉树的最近公共祖先-236
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:
    
    /*
     思想有点不集中，没看明白这个回溯到底是怎么回事
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == q || root == p || root == NULL) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        
        if (left == NULL && right != NULL) return right;
        else if (left != NULL && right != NULL) return left;
        else {//  (left == NULL && right == NULL)
            return NULL;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
