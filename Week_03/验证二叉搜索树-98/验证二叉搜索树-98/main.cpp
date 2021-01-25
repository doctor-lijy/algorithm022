//
//  main.cpp
//  验证二叉搜索树-98
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

/*
 二叉搜索树的特点：
 1、节点的左子树只包含小于当前节点的树
 2、节点的右子树只包含大于当前节点的树
 3、所有左子树和右子树自身必须也是二叉搜索树
 */

/*
 二叉搜索树中序遍历输出的节点的数值是有序序列
 
 验证二叉搜索树，相当于变成了判断一个序列是不是递增的
 */

class Solution {
    
public:
    vector<int> vec;
    void traversal(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        traversal(root->left);
        vec.push_back(root->val);// 将二叉搜索树转换为有序数组
        traversal(root->right);
    }
    
    bool isVaildBST(TreeNode *root) {
        vec.clear();// 不加这句在leetcode上也可以过，但最好加上
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i-1]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
