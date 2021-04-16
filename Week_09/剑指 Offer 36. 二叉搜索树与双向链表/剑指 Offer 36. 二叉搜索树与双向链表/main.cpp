//
//  main.cpp
//  剑指 Offer 36. 二叉搜索树与双向链表
//
//  Created by YJLi on 2021/3/24.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
    /*
     // 打印中序遍历
     void dfs(Node* root) {
         if(root == nullptr) return;
         dfs(root->left); // 左
         cout << root->val << endl; // 根
         dfs(root->right); // 右
     }
     
     使用中序遍历访问树的各节点 cur ；并在访问每个节点时构建 cur 和前驱节点 pre 的引用指向；中序遍历完成后，最后构建头节点和尾节点的引用指向即可
     
     dfs(cur): 递归法中序遍历；

     1、终止条件： 当节点 cur 为空，代表越过叶节点，直接返回；
     2、递归左子树，即 dfs(cur.left) ；
     3、构建链表：
        1.当 pre 为空时： 代表正在访问链表头节点，记为 head ；
        2.当 pre 不为空时： 修改双向节点引用，即 pre.right = cur ， cur.left = pre ；
        3.保存 cur ： 更新 pre = cur ，即节点 cur 是后继节点的 pre ；
     4、递归右子树，即 dfs(cur.right) ；

     */
    TreeNode *pre, *head;
    void dfs(TreeNode *cur) {
        if (cur == nullptr) return;
        dfs(cur->left);
        if (pre != nullptr) pre->right = cur;
        else head = cur;
        cur->left = cur;
        pre = cur;
        dfs(cur->right);
    }
public:
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
