#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        const int n = nums.size();
        if ((n & 1) == 0) return true;
        else {
            int ans = 0;
            for (int i = 0; i < n; i++)
                ans ^= nums[i];
            return ans == 0;
        }
    }
};