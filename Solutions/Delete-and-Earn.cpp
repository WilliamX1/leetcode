#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
  public:
    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        const int n = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> cnt(n, 0);

        for (int i = 0; i < nums.size(); i++)
            cnt[nums[i]]++;
        /*动态规划*/
        vector<int> dp(n, 0);
        /*dp[i] = max(dp[i - 1], dp[i - 2] + i * dp[i]*/
        dp[0] = 0, dp[1] = cnt[1];
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
        return dp[n - 1];
    }
};

int main()
{
    Solution S;
    vector<int> v = {2, 2, 3, 3, 3, 4};
    printf("%d", S.deleteAndEarn(v));
    return 0;
}