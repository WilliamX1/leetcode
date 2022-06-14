class Solution
{
  public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> v(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                v[i][j] = true;

        for (int step = 1; step < n; step++)
            for (int start = 0; start + step < n; start++)
            {
                int end = start + step;
                v[start][end] = (s[start] == s[end]) && v[start + 1][end - 1];
            };

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (v[i][j])
                    m[j].push_back(i);

        vector<int> dp(n, 1e9 + 7);

        for (int i = 0; i < n; i++)
        {
            vector<int> tmp = m[i];
            for (const int &start : tmp)
            {
                if (start == 0)
                    dp[i] = min(dp[i], 0);
                else
                    dp[i] = min(dp[i], dp[start - 1] + 1);
            };
        };

        return dp[n - 1];
    }
};