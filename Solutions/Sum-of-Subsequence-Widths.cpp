class Solution
{
  public:
    int sumSubseqWidths(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int64_t mod = 1e9 + 7, n = nums.size();
        vector<int64_t> pow(n, 1);
        for (int64_t i = 1; i < n; i++)
            pow[i] = (pow[i - 1] << 1) % mod;
        int64_t ans = 0;
        for (int64_t i = 0; i < n; i++)
            ans = (ans + (pow[i] - pow[n - i - 1]) * nums[i]) % mod;
        return ans;
    }
};