#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int char2int(char ch)
    {
        return ch - 'A';
    };
    char int2char(int x)
    {
        return x + 'A';
    };
    int dis(char ch1, char ch2)
    {
        int x = char2int(ch1), y = char2int(ch2);
        return abs(x / 6 - y / 6) + abs(x % 6 - y % 6);
    };
    int minimumDistance(string word)
    {
        int n = word.size(), MAX = 1e9, ans = MAX;

        vector<vector<int>> distance(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                distance[i][j] = dis(word[i], word[j]);
            };

        vector<vector<int>> dp(n, vector<int>(n, MAX));
        dp[0][0] = 0;

        for (int i = 1; i < n; i++)
        {
            int s = i - 1;
            for (int j = 0; j < n; j++)
            {
                dp[j][i] = min(dp[j][i], dp[j][s] + distance[s][i]);
                dp[s][i] = min(dp[s][i], dp[j][s] + distance[j][i]);
            };
            dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][i - 1]);
            dp[i][i] = dp[i - 1][i - 1] + dis(word[i - 1], word[i]);
        };

        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[i][n - 1]);
        };
        return ans;
    }
};