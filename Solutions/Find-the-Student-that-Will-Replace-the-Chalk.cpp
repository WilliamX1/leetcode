#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int64_t acc = 0, idx = 0, n = chalk.size();
        for (int i = 0; i < n; i++) acc += chalk[i];
        k %= acc;
        
        while (k >= chalk[idx]) {
            k -= chalk[idx];
            idx = (idx + 1) % n;
        };
        return idx;
    }
};