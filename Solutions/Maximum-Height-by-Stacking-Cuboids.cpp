#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &cuboid : cuboids)
            sort(cuboid.begin(), cuboid.end(), less<int>());
        sort(cuboids.begin(), cuboids.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0])
                if (a[1] == b[1])
                    return a[2] < b[2];
                else
                    return a[1] < b[1];
            else
                return a[0] < b[0];
        });

        for (auto cuboid : cuboids)
            std::cout << cuboid[0] << ' ' << cuboid[1] << ' ' << cuboid[2] << endl;

        int n = cuboids.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = cuboids[i][2];
            for (int j = i - 1; j >= 0; j--)
            {
                if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2])
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
            };
        };
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i]);

        return ans;
    }
};