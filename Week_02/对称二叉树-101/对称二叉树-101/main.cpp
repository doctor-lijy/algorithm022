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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    
    cout<<endl;
    std::cout << "==============\n";
    return 0;
}
