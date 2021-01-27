//
//  main.cpp
//  分发饼干-455
//
//  Created by YJLi on 2021/1/27.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 贪心的本质是选择每一阶段的局部最优，从而达到全局最优
 
 如何验证可不可以用贪心算法？
 最好用的策略就是举反例，如果想不到反例，就试一试贪心
 
 想清楚局部最优，想清楚全局最优，感觉局部最优是可以推出全局最优，并想不出反例，那么就试一试贪心
 */

class Solution {
    
    /*
     如何去理解题意才是最重要的，不要去想的太多有的没的，好好去看题意就好
     
     这里的局部最优就是大饼干喂给胃口大得，充分利用饼干尺寸喂饱一个，全局最优就是喂饱尽可能多的小孩
     */
    
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = (int)s.size() - 1; //饼干数组的下标
        int result = 0;
        for (int i = (int)g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
    vector<int> g = {2, 3, 4, 5};
    vector<int> s = {1 ,1 ,1};
    int result = solu.findContentChildren(g, s);
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
