#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dp[nums.size()]; dp[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
                if (nums[i] % nums[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
        };

        int idx = max_element(dp, dp + nums.size()) - dp, prev_idx = idx;

        vector<int> ans; ans.push_back(nums[idx]);
        while (--idx >= 0) {
            if (nums[prev_idx] % nums[idx] == 0
                && dp[prev_idx] - dp[idx] == 1) {
                    ans.push_back(nums[idx]);
                    prev_idx = idx;
                };
        };

        reverse(ans.begin(), ans.end());

        return ans;
    };
};

int main()
{
    Solution S;
    vector<int> v = {1,2,4,3,8};
    S.largestDivisibleSubset(v);
    return 0;
}