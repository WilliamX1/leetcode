class Solution
{
  public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.size();
        vector<int> preSumT(n + 1), preSumF(n + 1);
        preSumT[0] = -1e9;
        preSumT[0] = -1e9;
        for (int i = 0; i < n; i++)
        {
            preSumT[i + 1] = preSumT[i] + (answerKey[i] == 'T');
            preSumF[i + 1] = preSumF[i] + (answerKey[i] == 'F');
        };
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (int)(i + 1 -
                                 (lower_bound(preSumF.begin(), preSumF.end(), preSumF[i + 1] - k) - preSumF.begin())));
            ans = max(ans, (int)(i + 1 -
                                 (lower_bound(preSumT.begin(), preSumT.end(), preSumT[i + 1] - k) - preSumT.begin())));
        };
        return ans;
    }
};