//
//  main.cpp
//  合并二叉树-617
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
 Q:合并两个二叉树上各个节点上的值然后组成一个新的二叉树
 
 */

class Solution {

public:
    
    /*
     二叉树的遍历一般都采用递归的方式
     递归实现两个二叉树合并
     1.确定递归函数的参数和返回值：
     首先那么要合入两个二叉树，那么参数至少是要传入两个二叉树的根节点，返回值就是合并之后二叉树的根节点。
     */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        /*
         2.递归终止条件
         因为传入的是两个二叉树，如果t1为NULL，合并的结果就是t2，如果t2为NULL，合并的结果就是t1（如果t2为空也没关系，结果就是NULL）
         */
        if (t1 == NULL) return t2;// 如果t1为空，合并之后就应该是t2
        if (t2 == NULL) return t1;// 如果t2为空，合并之后就应该是t1
        /*
         3.确定单层循环逻辑
         这里重复利用t1这个树，t1就是合并了之后树的根节点（修改了原来树的结构）
         1.t1->val += t2->val;
         2.t1 的左子树是：合并 t1左子树 t2左子树之后的左子树
         3.t1 的右子树：是 合并 t1右子树 t2右子树之后的右子树
         */
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
