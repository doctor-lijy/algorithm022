//
//  main.cpp
//  路径总和-112
//
//  Created by YJLi on 2021/1/23.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

/*
 这道题是需要遍历从根节点到叶子节点的路径总和是不是目标和
 */

class Solution {
    
public:
    
    /*
     递归函数什么时候需要返回值？什么时候不需要返回值？
     1、如果需要搜索整个二叉树，那么递归函数就不要返回值；
     2、如果要搜索其中一条符合条件的路径，递归函数就需要返回值，因为遇到符合条件的路径就要及时返回
     */
    
    /*
     1、确定递归函数的返回值和参数
     */
    bool traversal(TreeNode *cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; //遇到叶子节点，且count == 0
        if (!cur->left && !cur->right) return false; //遇到叶子节点但是count != 0 返回 false
        
        if (cur->left) {
            count -= cur->left->val; //递归，处理节点
            if (traversal(cur->left, count)) return true;
            count += cur->right->val; //回溯，撤销处理结果
        }
        if (cur->right) {
            count -= cur->right->val; //递归，处理节点
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; //回溯，撤销处理结果
        }
        return false;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
