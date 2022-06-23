class Solution
{
  public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int sumPos = 0, sumNeg = 0, n = nums.size(), ans = 0;
        for (const int &num : nums)
        {
            if (num >= 0)
            {
                sumPos += num;
                ans = max(ans, sumPos);
                sumNeg = min(0, sumNeg + num);
            }
            else
            {
                sumNeg += num;
                ans = max(ans, -sumNeg);
                sumPos = max(0, sumPos + num);
            };
        };
        return ans;
    }
};