//
//  main.cpp
//  二叉搜索树的最小绝对差-530
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
 题目的意思是要求在二叉搜索树上求任意两节点的值差的绝对值的最小值
 */
/*
 二叉搜索树是有序的
 通过中序遍历刚好是一个有序的序列
 */
/*
 遇到二叉搜索树上求什么最值，差值之类的，就把它想成在一个有序数组上求最值，求差值
 */

class Solution {
    int result = INT_MAX;
    TreeNode *pre;
    void traversal(TreeNode *cur) {
        if (cur == NULL) {
            return;
        }
        traversal(cur->left);//左
        if (pre != NULL) {//这里判空的原因是当找到最左边叶子节点前，cur==NULL
            result = min(result, cur->val - pre->val);
        }
        pre = cur;//指针指向前一个节点
        traversal(cur->right);//右
    }
public:
    int getMInimumDifference(TreeNode *root) {
        traversal(root);
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
