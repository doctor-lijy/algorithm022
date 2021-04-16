//
//  main.cpp
//  树的子结构-剑指26
//
//  Created by YJLi on 2021/3/8.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

/*
 这也搞了一段时间了，效率还是太低了，要有自己的总结
 对于二叉树，二叉树的遍历相关，脑子中要有一个印象模板使用递归去求解
 不要太去拘泥这个具体的纠结套路，脑中有一个 根节点，左子树，右子树的模板在这
 首先去判空，然后去比较根节点，然后左子树和右子树，不能跳进去了，加油啊兄弟，现在都太慢了
 */

/*
 输入两棵二叉树A，B，判断B不是A的子结构。
 ps：约定空树不是任意一个树的子结构
 */

class Solution {
    bool recur(TreeNode *A, TreeNode *B) {
        if (B == NULL) return true;
        if (A == NULL || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        return (A != NULL && B != NULL) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
