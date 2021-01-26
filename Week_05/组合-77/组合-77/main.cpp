//
//  main.cpp
//  组合-77
//
//  Created by YJLi on 2021/1/26.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 给定两个整数 n 和 k，返回 1 。。。n中所有可能的k个数的组合
 */

/*
 回溯模板
 void backtracking(参数) {
     if (终止条件) {
         存放结果；
         return;
     }
     for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
         处理节点；
         backtracking(路径，选择列表)；//递归
         回溯，撤销处理结果
     }
 }
 */


class Solution {
    
    vector<vector<int>> result;// 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n , int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back();// 回溯，撤销处理的节点
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();  // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==========\n";
    Solution solu;
    vector<vector<int>> vec;
    vec = solu.combine(4, 2);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    std::cout << "==========\n";
    return 0;
}
