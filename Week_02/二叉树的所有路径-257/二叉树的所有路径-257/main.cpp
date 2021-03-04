//
//  main.cpp
//  二叉树的所有路径-257
//
//  Created by YJLi on 2021/1/18.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

//给定一个二叉树，返回所有从根节点到叶子节点路径

class Solution {
    
public:
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result) {
        path.push_back(cur->val);
        if (cur->left == NULL && cur->right == NULL) { //遇到叶子节点
            string sPath;
            for (int i = 0; i < path.size() - 1; i ++) {//将path里记录的路径转为string格式
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]); //记录最后一个节点（叶子节点）
            result.push_back(sPath);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            traversal(cur, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        traversal(root, path, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
