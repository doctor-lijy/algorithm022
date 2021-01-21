//
//  main.cpp
//  赎金信-383
//
//  Created by YJLi on 2021/1/19.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
    
public:
    bool canConstruct(string ransomNote, string magazine) { {
        int record[26] = {0};
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j]-'a']--;
            if (record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
