class Solution
{
  public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans = 0, tt = 0;
        for (const int &num : nums)
        {
            if (num == 0)
                tt++;
            else
            {
                ans += tt * (tt + 1) / 2;
                tt = 0;
            };
        };
        ans += tt * (tt + 1) / 2;
        return ans;
    }
};