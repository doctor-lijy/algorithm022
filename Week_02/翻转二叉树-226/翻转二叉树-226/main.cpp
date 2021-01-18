//
//  main.cpp
//  翻转二叉树-226
//
//  Created by YJLi on 2021/1/16.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:
    /*
     可以再纸上画一下翻转的二叉树情况
     这道题目使用前序遍历和后序遍历都可以，唯独中序遍历不行，因为中序遍历会把某些节点的左右孩子翻转了两次！建议拿纸画一画，就理解了
     */
    /*
     递归前序翻转
     */
    TreeNode* preInvertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        //先序遍历，先交换左右孩子节点，然后反转左子树，反转右子树
        swap(root->left, root->right);
        preInvertTree(root->left);
        preInvertTree(root->right);
        
        return root;
    }
    /*
     递归中序翻转
     */
    TreeNode *inInvertTree(TreeNode *root) {
        if (root == NULL) {
            return root;
        }
        postInvertTree(root->left);
        swap(root->left, root->right);
        postInvertTree(root->right);
        
        return root;
    }
    
    /*
     递归后序翻转
     */
    TreeNode *postInvertTree(TreeNode *root) {
        if (root == NULL) {
            return root;
        }
        postInvertTree(root->left);
        postInvertTree(root->right);
        swap(root->left, root->right);
        
        return root;
    }
    
    /*
     迭代法翻转
     */

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "=========\n";
    
    
    std::cout << "=========\n";
    return 0;
}
