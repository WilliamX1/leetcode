#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int val(char ch) {
        return ch - 'a' + 1;
    };
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        /* p * hash(i+1) - hash(i) = val(s[i + k]) * p ^ k - val(s[i]) * p ^ 0
         * hash(i) = p * hash(i + 1) + val(s[i]) - val(s[i + k]) * p ^ k
         * hash(len - 1) = ?
         */
        int len = s.size();
        vector<int64_t> ps(k + 1, 1);
        for (int i = 1; i <= k; i++)
            ps[i] = (ps[i - 1] * power) % modulo;
        
        int64_t last_value = 0, cnt = 0;
        for (int i = len - k; i < len; i++)
            last_value = (last_value + val(s[i]) * ps[cnt++]) % modulo;
        
        int idx = last_value % modulo == hashValue ? len - k : -1;
        int64_t cur_value = 0;
        for (int i = len - k - 1; i >= 0; i--)
        {
            cur_value = ((power * last_value + val(s[i])) % modulo - (val(s[i + k]) * ps[k]) % modulo + modulo) % modulo;
            if (cur_value % modulo == hashValue) idx = i;
            last_value = cur_value;
        }
        
        return s.substr(idx, k);
    }
};