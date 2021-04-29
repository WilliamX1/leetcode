#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool cross(vector<int>& stones, int cur_idx, int k) {
    //     if (cur_idx == stones.size() - 1) return true;
    //     bool flag = false;
    //     auto next_idx = lower_bound(stones.begin(), stones.end(), stones[cur_idx] + k - 1) - stones.begin();
    //     auto end_idx = upper_bound(stones.begin(), stones.end(), stones[cur_idx] + k + 1) - stones.begin();
    //     for (auto i = next_idx; i < end_idx; i++)
    //         if (i > cur_idx) flag |= cross(stones, i, stones[i] - stones[cur_idx]);
    //     return flag;
    // }   
    bool canCross(vector<int>& stones) {
        if (stones[1] - stones[0] != 1) return false;
        /*深度搜索*/
        // return cross(stones, 1, 1);
        /*动态规划*/
        bool dp[stones.size()][stones.size()];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;

        for (int i = 1; i < stones.size(); i++)
            if (stones[i] - stones[i - 1] > i) return false;

        for (int i = 1; i < stones.size(); i++)
            for (int j = i - 1; j >= 0; j--)
            {
                int k = stones[i] - stones[j];
                if (k > j + 1) break;

                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];

                if (i == stones.size() - 1 && dp[i][k]) return true; 
            };
        return false;
    }
};

int main()
{
    Solution S;
    vector<int> v = {0,1,3,5,6,8,12,17};
    printf("%d", S.canCross(v));
    return 0;
}

