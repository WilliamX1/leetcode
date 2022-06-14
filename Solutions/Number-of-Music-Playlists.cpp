class Solution
{
  public:
    int numMusicPlaylists(int N, int L, int K)
    {
        vector<vector<int64_t>> dp(L + 1, vector<int64_t>(N + 1, 0));
        dp[0][0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= L; i++)
            for (int j = 1; j <= N; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (int64_t)(N - j + 1)) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * (int64_t)max(j - K, 0)) % mod;
            };
        return dp[L][N];
    }
};