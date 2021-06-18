#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judge_symbol(char ch) {
        return ch == '+' || ch == '-';
    };
    bool judge_char_valid(char ch) {
        return '0' <= ch && ch <= '9'; 
    };
    bool judge_number(string s) {
        if (s.size() == 0) return false;
        for (auto ch : s) 
            if (ch < '0' || ch > '9') return false;
        return true;
    };
    bool judge_integer(string s) {
        if (s.size() == 0) return false;
        
        if (judge_symbol(s[0])) 
            s = s.substr(1);
        
        return judge_number(s);
    };
    bool judge_decimal(string s) {
        if (s.size() == 0) return false;
        
        if (judge_symbol(s[0]))
            s = s.substr(1);
        
        if (s.size() == 0) return false;

        int index = s.find_first_of('.');
        if (index == s.npos || index != s.find_last_of('.')) return false;

        if (index == 0) return judge_number(s.substr(1));
        else if (index == s.size() - 1) return judge_number(s.substr(0, index));
        else return judge_number(s.substr(0, index)) && judge_number(s.substr(index + 1));
        return true;
    }
    bool isNumber(string s) {
        int index_e = s.find_first_of('e'), index_E = s.find_first_of('E');
        if (index_e == s.npos && index_E == s.npos) return judge_integer(s) || judge_decimal(s);
        else {
            if (index_e != s.npos && index_E != s.npos) return false;
            else {
                int index = index_e != s.npos ? index_e : index_E;
                char ch = index_e != s.npos ? 'e' : 'E';
                if (index != s.find_last_of(ch)) return false;
                else return (judge_integer(s.substr(0, index)) || judge_decimal(s.substr(0, index))) && judge_integer(s.substr(index + 1));
            };
        };
    };
};