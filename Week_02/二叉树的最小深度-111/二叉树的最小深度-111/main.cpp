//
//  main.cpp
//  二叉树的最小深度-111
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

//最小深度是从根节点到最近叶子节点的最短路径上的节点数量
//叶子节点是指没有子节点的节点

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
