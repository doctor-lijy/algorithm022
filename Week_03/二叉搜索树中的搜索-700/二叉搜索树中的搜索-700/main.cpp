//
//  main.cpp
//  二叉搜索树中的搜索-700
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

/*
 需要数值这基本的概念
 二叉搜索树 BST：
 1、二叉搜索树是一个有序树；
 2、若它的左子树不为空，则左子树上所有节点的值均小于它的根节点的值；
 3、若它的的右子树不为空，则右子树上所有节点的值均大于他的根节点的值；
 4、它的左右子树也分别为二叉搜索树
 */

class Solution {
    
public:
    /*
     二叉树遍历使用递归实现
     1、确定递归函数的参数和返回值
     递归函数的参数传入的就是根节点和要搜索的数值
     */
    TreeNode *searchBST(TreeNode *root, int val) {
        /*
         2、终止条件
         如果root为空，或者找到这个数值了，就返回root节点
         */
        if (root == NULL || root->val == val) return root;
        
        /*
         3、单层递归逻辑
         因为二叉搜索树的节点是有序的，所以可以采用有方向的去搜索
         如果root->val > val，搜索左子树，如果root->val 《 val，就搜索右子树，如果最后没有所有到就返回NULL
         */
        
        /*
         这里需要知道的是对二叉树的遍历只需要通过传入根节点就可以遍历整个树
         同样的这里只需要返回搜到的节点就可以通过这个返回的节点做根节点的二叉树
         */
        if (root->val > val) return searchBST(root->left, val);
        if (root->val < val) return searchBST(root->right, val);
        
        return NULL;
    }
    
    /*迭代法*/
    
    TreeNode *searchBST2(TreeNode *root, int val) {
        while (root != NULL) {
            if (root->val > val) {
                root = root->left;
            } else if (root->val < val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
