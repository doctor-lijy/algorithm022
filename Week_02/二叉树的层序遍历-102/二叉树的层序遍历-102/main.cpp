//
//  main.cpp
//  二叉树的层序遍历-102
//
//  Created by YJLi on 2021/1/16.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 二叉树有两种遍历方式：
 1、深度优先遍历：先往深走，遇到叶子节点再往回走
 2、广度优先遍历：一层一层的去遍历
 */

/*
 层序遍历，从根节点逐层往下遍历
 队列先进先出，符合一层一层遍历，而用栈先进先出适合模拟深度优先遍历也就是递归的逻辑
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:
    
    /*
     使用二维向量存储每层的节点数值
     使用队列这种先进先出的结构来访问遍历二叉树
     1、先将根节点push到队列中；
     2、以判断当前队列是否为空为条件（若队列为空，说明二叉树节点全部遍历结束）；
     3、记录当前队列中元素个数size，队列循环size次，队首元素依次出队，同时将对手元素的左右孩子push到队列中；
     4、一层遍历结束，将存储该层的元素向量容器存储到向量容器中（二维向量容器）；
     5、重复步骤1->步骤4，直至队列为空，所有节点遍历结束
     */
    vector<vector<int>>levelOrderTraversal(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *>que;
        if (root == NULL) {
            return result;
        }
        que.push(root);
        while (!que.empty()) {
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            unsigned long size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();//当前队首元素出队，同时将左右孩子入队
                vec.push_back(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            result.push_back(vec);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    
    
    std::cout << "==============\n";
    return 0;
}
