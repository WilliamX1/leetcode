class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size(), ans = 0;
        vector<vector<int>> dp_greater(len, vector<int>(3, 0)), dp_less(len, vector<int>(3, 0));
        for (int i = 0; i < len; i++)
        {
            dp_greater[i][0]++;
            dp_less[i][0]++;
            for (int j = i - 1; j >= 0; j--)
            {
                if (rating[i] > rating[j]) 
                {
                    dp_greater[i][1] += dp_greater[j][0];
                    dp_greater[i][2] += dp_greater[j][1];
                };
                if (rating[i] < rating[j])
                {
                    dp_less[i][1] += dp_less[j][0];
                    dp_less[i][2] += dp_less[j][1];
                }
            };
            ans += dp_greater[i][2] + dp_less[i][2];
        };
        return ans;
    }
};