//
//  main.cpp
//  螺旋矩阵-54
//
//  Created by YJLi on 2021/2/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        
        int u = 0;
        int d = (int)matrix.size() - 1;
        int l = 0;
        int r = (int)matrix[0].size() - 1;
        
        while (true) {
            for (int i = l; i <= r; ++i) {//向右移动直到最右
                ans.push_back(matrix[u][i]);
            }
            if (++u > d) {//重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
                break;
            }
            for (int i = u; i <= d; ++i) {//向下
                ans.push_back(matrix[i][r]);
            }
            if (--r < l) {//重新设定有边界
                break;
            }
            for (int i = r; i >= l; --i) {//向左
                ans.push_back(matrix[d][i]);
            }
            if (--d < u) {//重新设定下边界
                break;
            }
            for (int i = d; i >= u; --i) {//向上
                ans.push_back(matrix[i][l]);
            }
            if (++l > r) {//重新设定左边界
                break;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    vector<vector<int>> vec = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> result = solu.spiralOrder(vec);
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
