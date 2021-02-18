//
//  main.cpp
//  四数之和II-454
//
//  Created by YJLi on 2021/2/18.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

 「例如:」

 输入: A = [ 1, 2] B = [-2,-1] C = [-1, 2] D = [ 0, 2]

 输出: 2

 「解释:」

 两个元组如下:

 (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */

/*
 首要的目的就是要弄清题干的意思，题干要求是求有多少个元组
 
 而这道题目是四个独立的数组，只要找到A[i] + B[j] + C[k] + D[l] = 0就可以，不用考虑有重复的四个元素相加等于0的情况，所以相对于题目18. 四数之和，题目15.三数之和，还是简单了不少！」
 
 如果本题想难度升级：就是给出一个数组（而不是四个数组），在这里找出四个元素相加等于0，答案中不可以包含重复的四元组
 */

/*
 题解步骤：
 本题采用的是哈希法实现，使用键值映射关系去计算和结果为0的次数。
 
 1、首先定义一个unordered_map，key放a和b两数之和，value放a和b两数之和出现的次数；
 2、遍历A和B数组，统计两个数组元素之和，和出现的次数，放到map中；
 3、定义int变量count，用来统计a+b+c+d = 0出现的次数。
 4、在遍历C和D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
 5、最后返回统计值 count 就可以了
 */

class Solution {
    
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int, int> umap; //key:a+b的数值，value:a+b数值出现的次数
        // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
        for (int a : A) {
            for (int b : B) {
                umap[a+b]++;
            }
        }
        int count = 0; // 统计a+b+c+d = 0 出现的次数
        // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end() ) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solu;
//    vector<int> A = {1, 2, 3, 4};
//    vector<int> B = {5, 6, 7, 8};
//    vector<int> C = {-1, -2, -3, -4};
//    vector<int> D = {-5, -6, -7, -8};
    vector<int> A = {1, 2};
    vector<int> B = {5, 6};
    vector<int> C = {-1, -2};
    vector<int> D = {-5, -6};
    int count = solu.fourSumCount(A, B, C, D);
    cout<<"count = "<<count<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
