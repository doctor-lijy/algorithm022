//
//  main.cpp
//  二叉搜索树中的众数-501
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
 二叉搜索树BST:
 1、节点左子树中包含节点的值小于等于当前节点的值；
 2、节点右子树中包含节点的值大于等于当前节点的值；
 3、左子树和右子树都是二叉搜索树
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
