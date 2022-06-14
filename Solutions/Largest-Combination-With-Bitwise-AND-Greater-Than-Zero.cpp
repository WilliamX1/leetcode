class Solution
{
  public:
    int largestCombination(vector<int> &candidates)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int tmp = 0;
            for (int j = 0; j < candidates.size(); j++)
                if ((candidates[j] >> i) & 1)
                    tmp++;
            ans = max(ans, tmp);
        };
        return ans;
    }
};