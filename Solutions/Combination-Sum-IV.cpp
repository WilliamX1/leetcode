#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        const int N = target + 1;
        uint64_t dp[N]; memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        
        for (int i = 0; i <= target; i++)
            for (int j = 0; j < nums.size() && nums[j] <= i; j++)
                dp[i] += dp[i - nums[j]];

        return dp[target];
    }
};

int main()
{
    Solution S;
    vector<int> v = {3,4,5,6,7,8,9,10};
    printf("%d", S.combinationSum4(v, 10));

    return 0;
}