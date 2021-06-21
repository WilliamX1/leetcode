#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int idx = num.size() - 1;
        while (idx >= 0 && ((num[idx] - '0') % 2 == 0)) idx--;
        return idx < 0 ? "" : num.substr(0, idx + 1);
    }
};