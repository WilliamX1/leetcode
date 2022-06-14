class Solution
{
  public:
    int halfQuestions(vector<int> &questions)
    {
        vector<int> dp(1000 + 1, 0);
        for (auto q : questions)
            dp[q]++;
        sort(dp.begin(), dp.end(), greater<int>());
        int N = questions.size() >> 1, idx = 0;
        while (N > 0)
        {
            N -= dp[idx++];
        };
        return idx;
    }
};