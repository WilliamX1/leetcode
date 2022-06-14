class Solution
{
  public:
    int countSpecialSubsequences(vector<int> &nums)
    {
        int64_t t0 = 0, t1 = 0, t2 = 0, t2_t1_t0 = 0;
        int64_t len = nums.size(), mod = 1000000000 + 7;
        for (auto num : nums)
        {
            if (num == 0)
            {
                t0 = (2 * t0 + 1) % mod;
            }
            else if (num == 1)
            {
                t1 = (t0 + 2 * t1) % mod;
            }
            else if (num == 2)
            {
                t2 = (t1 + 2 * t2) % mod;
            };
        };
        return t2 % mod;
    }
};