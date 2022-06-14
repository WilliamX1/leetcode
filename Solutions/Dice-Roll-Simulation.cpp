#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int dieSimulator(int n, vector<int> &rollMax)
    {
        int64_t mod = 1e9 + 7;
        int up = *max_element(rollMax.begin(), rollMax.end());
        vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(7, vector<int64_t>(up + 1, 0)));

        /* dp[i][j][k] 代表第i个位置填j且连续k次的数量 */
        dp[0][1][1] = dp[0][1][1] = dp[0][2][1] = dp[0][3][1] = dp[0][4][1] = dp[0][5][1] = dp[0][6][1] = 1;

        for (int i = 1; i < n; i++)
            for (int j = 1; j <= 6; j++)
                for (int k = 1; k <= rollMax[j - 1]; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k - 1];
                    if (k == 1)
                    {
                        for (int s = 1; s <= 6; s++)
                            if (s != j)
                            {
                                for (int m = 1; m <= up; m++)
                                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][s][m]) % mod;
                            };
                    };
                };
        int64_t ans = 0;
        for (int j = 1; j <= 6; j++)
        {
            for (int k = 1; k <= rollMax[j - 1]; k++)
            {
                cout << dp[n - 1][j][k] << ' ';
                ans = (ans + dp[n - 1][j][k]) % mod;
            };
            cout << endl;
        };

        return ans;
    }
};