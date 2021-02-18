//
//  main.cpp
//  赎金信-383
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <string>

using namespace std;

/*
 给定一个赎金信(ransom)字符串和一个杂志(magazine)字符串，判断第一个字符串能不能有第二个字符串里面的字符构成。如果可以构成，返回ture，否则返回false。
 
 (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

 「注意：」

 你可以假设两个字符串均只含有小写字母。

 canConstruct("a", "b") -> false canConstruct("aa", "ab") -> false canConstruct("aa", "aab") -> true
 */

/*
 首先理解题干意思，字符不能重复使用，其次是使用b字符串去构造a字符串，也就是说b中包含a所需要的全部字符，反之则不能构成。
 */

class Solution {
    
public:
    
    /*
     暴力解法：
     */
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                if (magazine[i] == ransomNote[j]) {
                    // 在ransomNote中找到和magazine相同的字符
                    ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
                    break;
                }
            }
        }
        // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        if (ransomNote.length() == 0) {
            return true;
        }
        return false;
    }
    
    /*
     哈希解法：
     
     因为题目所只有小写字母，那可以采用空间换取时间的哈希策略， 用一个长度为26的数组还记录magazine里字母出现的次数。

     然后再用ransomNote去验证这个数组是否包含了ransomNote所需要的所有字母
    
     依然是数组在哈希法中的应用。

     一些同学可能想，用数组干啥，都用map完事了，「其实在本题的情况下，使用map的空间消耗要比数组大一些的，因为map要维护红黑树或者哈希表，而且还要做哈希函数。所以数组更加简单直接有效！」
     */
    bool canConstruct2(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            // 通过recode数据记录 magazine里各个字符出现次数
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[i] - 'a']--;
            // 如果小于零说明 magazine里出现的字符，ransomNote没有
            if (record[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
    /*
     时间复杂度：O(n)
     空间复杂度：O(1)
     */
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    bool result = solu.canConstruct("aac", "aab");
    cout<<"result = "<<result<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
