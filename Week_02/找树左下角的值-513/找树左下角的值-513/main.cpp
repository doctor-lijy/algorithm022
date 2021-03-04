//
//  main.cpp
//  找树左下角的值-513
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class solution {
    
public:
    int maxLen = INT_MIN;
    int maxLeftValue;
    void traversal(TreeNode *root, int leftLen) {
        if (root->left == NULL && root->right == NULL) {
            if (leftLen > maxLen) {
                maxLen = leftLen;
                maxLeftValue = root->left->val;
            }
            return;
        }
        if (root->left) {
            leftLen++;
            traversal(root->left, leftLen);
            leftLen--;
        }
        if (root->right) {
            leftLen++;
            traversal(root->right, leftLen);
            leftLen--;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxLeftValue;
    }
    
    int findBottomLeftValue2(TreeNode* root) {
        queue<TreeNode *> que;
        if (root != NULL) {
            que.push(root);
        }
        int result = 0;
        while (!que.empty()) {
            int size = (int)que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (i == 0) {
                    result = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
