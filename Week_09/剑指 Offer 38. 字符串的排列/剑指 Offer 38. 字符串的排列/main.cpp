//
//  main.cpp
//  剑指 Offer 38. 字符串的排列
//
//  Created by YJLi on 2021/3/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {

    vector<string> res;
    void dfs(string s, int x) {
        if (x == s.size()-1) {
            res.push_back(s);
            return;
        }
        set<int> st;
        for (int i = x; i < s.size(); i++) {
            if (st.find(s[i]) != st.end()) continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            dfs(s, x+1);
            swap(s[i], s[x]);
        }
    }
    
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
