//
//  main.cpp
//  剑指offer12-矩阵中的路径
//
//  Created by YJLi on 2021/3/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
    int rows, cols;
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }
        board[i][j] = '\0';
        bool res = dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j+1, k+1) || dfs(board, word, i, j-1, k+1);
        board[i][j] = word[k];
        return res;
    }
public:
    bool exist(vector<vector<char>> &board, string word) {
        rows = (int)board.size();
        cols = (int)board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::cout << "Hello, World!\n";
    return 0;
}
