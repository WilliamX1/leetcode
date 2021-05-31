#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNum(string str) {
        string ans = "";
        for (auto i : str) {
            ans += '0' + (i - 'a');
        };
        return atoi(ans.c_str());
    } 
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getNum(firstWord) + getNum(secondWord) == getNum(targetWord);
    }
};