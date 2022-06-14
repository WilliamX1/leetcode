#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
  public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        /* dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1]
                        ^ dp[i - 1][j - 1] ^ matrix[i][j] */
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] ^ matrix[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j];
        /* print */
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         printf("%d ", dp[i][j]);
        //     printf("\n");
        // }
        /* sort */
        vector<int> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res.push_back(dp[i][j]);

        nth_element(res.begin(), res.begin() + k - 1, res.end(), greater<int>());
        return res[k - 1];
    }
};