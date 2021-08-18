#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (!x) return 0;

        int sign = x >= 0 ? 1 : -1;
        string num = "";

        x = abs(x);
        while (x > 0) {
            num = num + char (x % 10 + '0');
            x /= 10;
        };

        return stol(num) > INT32_MAX || stol(num) < INT32_MIN ? 0 : sign * stol(num);
    }
};