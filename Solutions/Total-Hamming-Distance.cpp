#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        int digit = sizeof(int) << 3;
        vector<int> ans(digit, 0);
        for (int i = 0; i < len; i++)
        {
            int x = nums[i];
            for (int j = 0; j < digit && x > 0; j++) {
                ans[j] += x & 1;
                x >>= 1;
            };
        };

        int res = 0;
        for (auto i : ans) res += i * (len - i);
        return res;
    }
};
int main()
{
    vector<int> v = {4, 14, 2};
    Solution S;
    S.totalHammingDistance(v);
    return 0;
}