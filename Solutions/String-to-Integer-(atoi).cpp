#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int idx = 0, sign = 1;
        int64_t res = 0;
        while (idx < len && s[idx] == ' ') idx++; // 丢弃前导空格
        if (idx < len && (s[idx] == '-' || s[idx] == '+')) sign = s[idx++] == '-' ? -1 : 1;

        while (idx < len && '0' <= s[idx] && s[idx] <= '9') {
            res = res * 10 + s[idx++] - '0';
            if (sign * res > INT32_MAX) {
                res = INT32_MAX;
                break;
            } else if (sign * res < INT32_MIN) {
                res = INT32_MIN;
                break;
            };
        };
        return sign * res;
    }
};