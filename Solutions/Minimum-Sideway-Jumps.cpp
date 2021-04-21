#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int len = obstacles.size();
        const int track_num = 3;
        const int MAX = 2147483647 - 10;
        int dp[len][track_num];
        memset(dp, 0, sizeof(dp));

        dp[0][1] = 0; dp[0][0] = dp[0][2] = 1;
        for (int i = 1; i < len; i++) {
            switch (obstacles[i] - 1)
            {
            case 0:
                dp[i][0] = MAX;
                switch (obstacles[i - 1] - 1)
                {
                case 0:
                    dp[i][1] = min(dp[i - 1][1], dp[i - 1][2] + 1);
                    dp[i][2] = min(dp[i - 1][1] + 1, dp[i - 1][2]);
                    break;
                case 1:
                    dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][2] + 1);
                    dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][2]);
                    break;
                case 2:
                    dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
                    dp[i][2] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
                    break;
                default:
                    dp[i][1] = min(dp[i - 1][1], min(dp[i - 1][0], dp[i - 1][2]) + 1);
                    dp[i][2] = min(dp[i - 1][2], min(dp[i - 1][0], dp[i - 1][1]) + 1);
                    break;
                };
                break;
            case 1:
                dp[i][1] = MAX;
                switch (obstacles[i - 1] - 1)
                {
                case 0:
                    dp[i][0] = min(dp[i - 1][1] + 2, dp[i - 1][2] + 1);
                    dp[i][2] = min(dp[i - 1][1] + 1, dp[i - 1][2]);
                    break;
                case 1:
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][2] + 1);
                    dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][2]);
                    break;
                case 2:
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                    dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
                    break;
                default:
                    dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]) + 1);
                    dp[i][2] = min(dp[i - 1][2], min(dp[i - 1][0], dp[i - 1][1]) + 1);
                    break;
                };
                break;
            case 2:
                dp[i][2] = MAX;
                switch (obstacles[i - 1] - 1)
                {
                case 0:
                    dp[i][0] = min(dp[i - 1][1] + 1, dp[i - 1][2] + 2);
                    dp[i][1] = min(dp[i - 1][1], dp[i - 1][2] + 1);
                    break;
                case 1:
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][2] + 1);
                    dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][2] + 2);
                    break;
                case 2:
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                    dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
                    break;
                default:
                    dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]) + 1);
                    dp[i][1] = min(dp[i - 1][1], min(dp[i - 1][0], dp[i - 1][2]) + 1);
                    break;
                };
                break;
            default:
                dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]) + 1);
                dp[i][1] = min(dp[i - 1][1], min(dp[i - 1][0], dp[i - 1][2]) + 1);
                dp[i][2] = min(dp[i - 1][2], min(dp[i - 1][0], dp[i - 1][1]) + 1);
                break;
            };
        };
        return min(dp[len - 1][0], min(dp[len - 1][1], dp[len - 1][2]));
    }
};

int main()
{
    Solution S;
    vector<int> v = {0,0,2,0};
    printf("%d", S.minSideJumps(v));
    return 0;
}