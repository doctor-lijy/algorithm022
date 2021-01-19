//
//  main.cpp
//  有效的字母异位词-242
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <string>

using namespace std;

//什么样的题型可以想起来用哈希表来做？？？？

//数组就是一个简单的哈希表，但数组的大小是受限的
//字母异位词指字母相同，但排列不同的字符串

/*
 1、定义一个数组叫做record用来上记录字符串s里字符出现的次数。
 需要把字符映射到数组也就是哈希表的索引下表上，「因为字符a到字符z的ASCII是26个连续的数值，所以字符a映射为下表0，相应的字符z映射为下表25。」

 2、再遍历字符串s的时候，「只需要将 s[i] - ‘a’ 所在的元素做+1 操作即可，并不需要记住字符a的ASCII，只要求出一个相对数值就可以了。」 这样就将字符串s中字符出现的次数，统计出来了。

 3、那看一下如何检查字符串t中是否出现了这些字符，同样在遍历字符串t的时候，对t中出现的字符映射哈希表索引上的数值再做-1的操作。

4、 那么最后检查一下，「record数组如果有的元素不为零0，说明字符串s和t一定是谁多了字符或者谁少了字符，return false。」

 5、最后如果record数组所有元素都为零0，说明字符串s和t是字母异位词，return true。

 时间复杂度为O(n)，空间上因为定义是的一个常量大小的辅助数组，所以空间复杂度为O(1)
 */

class Solution {
    
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "============\n";
    
    Solution solu;
    cout<<"两者是异位词"<<solu.isAnagram("anagram", "nagaram")<<endl;
    
    std::cout << "============\n";
    return 0;
}
