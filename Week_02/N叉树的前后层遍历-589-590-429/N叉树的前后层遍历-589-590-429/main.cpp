//
//  main.cpp
//  N叉树的前后层遍历-589-590-429
//
//  Created by YJLi on 2021/1/16.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Node {
    
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    
    Node(int _val) {
        val = _val;
    }
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//这里有点尴尬，二叉树的构造还写不出来，目前也只是抄写下代码写个注释，稍后把构造二叉树或者n叉树的方法写出来再来重新回顾下这个题目

/* 递归法实现*/
class Solution {
    vector<int> result;
    void preTraversal(Node *root) {
        if (root == NULL) {
            return;
        }
        result.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            preTraversal(root->children[i]);
        }
    }
    
public:
    vector<int> preorderTraversal(Node *root) {
        result.clear();
        preTraversal(root);
        return result;
    }
    
    //迭代法实现
    vector<int>preorderTraversal2(Node *root) {
        vector<int> result;
        stack<Node *>st;
        if (root == NULL) {
            return result;
        }
        st.push(root);
        while (!st.empty()) {
            Node *node = st.top();
            st.pop();
            result.push_back(node->val);
            // 注意要倒叙，这样才能达到前序（中左右）的效果
            for (unsigned long i = node->children.size()-1; i >= 0; i--) {
                if (node->children[i]) {//时刻要记得先判断是否为空
                    st.push(node->children[i]);
                }
            }
        }
        
        return result;
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node *>que;
        if (root != NULL) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = (int)que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                Node *node = que.front();
                vec.push_back(node->val);
                que.pop();
                for (int i = 0; i < node->children.size(); i++) {
                    if (node->children[i]) {
                        que.push(node->children[i]);
                    }
                }
            }
            result.push_back(vec);
        }
        return result;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===================\n";
    
    
    std::cout << "===================\n";
    return 0;
}
