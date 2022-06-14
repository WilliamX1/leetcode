#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
  public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size(), sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(sum + 1, 0);

        for (int i = 0; i < n; i++)
            for (int j = sum; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            };

        int ans = 0x7fffffff;
        for (int i = 0; i <= sum; i++)
            if (sum - dp[i] * 2 >= 0)
                ans = min(ans, sum - dp[i] * 2);
        return ans;
    }
};