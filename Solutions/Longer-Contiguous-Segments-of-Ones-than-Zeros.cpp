#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        int tmp = 1, ans = 0;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) tmp++;
            else {
                if (tmp > ans && s[i - 1] == '1') flag = true;
                else if (tmp >= ans && s[i - 1] == '0') flag = false;
                ans = max(ans, tmp);
                tmp = 1;
            }
        };
        if (tmp > ans && s[n - 1] == '1') flag = true;
        else if (tmp >= ans && s[n - 1] == '0') flag = false;
        
        return flag;
    }
};