#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> flag(n, false); flag[0] = true;

        for (int i = 0; i < n - 1; i++) {
            if (flag[n - 1]) return true;
            if (!flag[i]) return false;
            else {
                for (int j = i + 1; j <= min(i + nums[i], n - 1); j++) {
                    flag[j] = true;
                };
            }
        };
        return flag[n - 1] == true;
    }
};