class Solution
{
  public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        int ans = 0, mod = 1e9 + 7;

        vector<vector<int>> nums(k + 1, vector<int>(k + 1, 0));
        for (int n = 0; n <= k; n++)
            for (int m = 0; m <= n; m++)
                if (m == 0 || m == n)
                    nums[n][m] = 1;
                else if (n > m && m > 0)
                    nums[n][m] = (nums[n - 1][m] + nums[n - 1][m - 1]) % mod;

        for (int i = 0; i <= k; i++)
            if (i - (k - i) == endPos - startPos)
                ans = (ans + nums[k][i]) % mod;
        return ans;
    }
};