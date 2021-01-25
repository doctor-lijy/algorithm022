//
//  main.cpp
//  从中序与后序遍历序列构造二叉树-106
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
 遇到二叉树首先应该想到的就是递归解法，至于怎么使用递归在慢慢分析题目！！！
 */

class Solution {
    
public:
    TreeNode *traversal(vector<int> &inorder, vector<int>&postorder) {
        //第一步
        if (postorder.size() == 0) return NULL;
        
        //第二步：后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);
        
        //叶子节点
        if (postorder.size() == 1) return root;
        
        //第三步：找到中序遍历切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        
        //第四步：切割中序数组，得到 中序左数组和中序右数组
        //第五步：切割后续数组，得到 后序左数组和后序右数组
        
        //切割中序数组
        //左闭右开区间 [0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin()+delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        
        //postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);
        
        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
        
        //第六步
//        root->left = traversal(中序左数组, 后序左数组);
//        root->right = traversal(中序右数组, 后序右数组);
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        
        return traversal(inorder, postorder);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
