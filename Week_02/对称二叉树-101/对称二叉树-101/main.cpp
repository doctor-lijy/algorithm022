//
//  main.cpp
//  对称二叉树-101
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

/*
 首先第一点也是最关键的点要弄明白的题目的要求，就是要弄懂题目的意思！！！
 
 判断对称二叉树要比较可不是左右节点，跟反转二叉树是有所区别
 这里要比较的是根节点的左子树和右子树是不是相互翻转的，
 这里要比较的是两个树，这两个树是根节点的左子树和右子树
 递归遍历过程中，也要同时遍历两棵树
 */

class solution {
    
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
    bool compare(TreeNode *left, TreeNode *right) {
        //首先排除空节点的情况
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        //排除了空节点在排除数值不相同的情况
        else if (left->val != right->val) return false;
        
        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right); // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left); // 左子树：右、 右子树：左
        return outside && inside; // 左子树：中、 右子树：中 （逻辑处理）
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    
    cout<<endl;
    std::cout << "==============\n";
    return 0;
}
