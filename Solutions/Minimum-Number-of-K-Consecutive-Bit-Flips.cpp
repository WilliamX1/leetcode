class Solution
{
  public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size(), flip = 0;
        vector<int> minus(n, 0);
        for (int i = 0; i < n; i++)
        {
            flip += i > 0 ? minus[i] : 0;
            if ((flip & 1) ^ nums[i])
                continue;
            else if (i + k - 1 < n)
            {
                ans++;
                flip++;
                if (i + k < n)
                    minus[i + k]++;
            }
            else
                return -1;
        };

        return ans;
    }
};