#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void get(vector<int>& nums, int idx, int cnt, int xo, int& ans)
    {
        if (cnt == 0) {
            ans += xo;
            return;
        }
        for (int i = idx; i < nums.size(); i++)
            get(nums, i + 1, cnt - 1, xo ^ nums[i], ans);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i <= nums.size(); i++)
            get(nums, 0, i, 0, ans);
        return ans;
    }
};
int main()
{
    Solution S;
    vector<int> v = {1,3};
    S.subsetXORSum(v);
    return 0;
}