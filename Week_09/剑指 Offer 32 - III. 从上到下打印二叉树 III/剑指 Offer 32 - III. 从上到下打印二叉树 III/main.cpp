//
//  main.cpp
//  剑指 Offer 32 - III. 从上到下打印二叉树 III
//
//  Created by YJLi on 2021/3/24.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
    
public:
    vector<vector<int>> leverOrder(TreeNode *root) {
        vector<vector<int>> result;
        deque<TreeNode*>deque;
        if (root != nullptr) {
            deque.push_back(root);
        }
        while (!deque.empty()) {
            vector<int> vec;
            int size = (int)deque.size();
            for (int i = 0; i < size; i--) {
                TreeNode *node = deque.front();
                deque.pop_front();
                vec.push_back(node->val);
                if (node->left) deque.push_back(node->left);
                if (node->right) deque.push_back(node->right);
            }
            result.push_back(vec);
            if (deque.empty()) break;
            vec.clear();
            size = (int)deque.size();
            for (int i = 0; i < size; i--) {
                TreeNode *node = deque.back();
                deque.pop_back();
                vec.push_back(node->val);
                if (node->right) deque.push_front(node->right);
                if (node->left) deque.push_front(node->left);
            }
            result.push_back(vec);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
