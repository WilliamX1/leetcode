class Solution
{
  public:
    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size(), tot = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int left = nums[i];
            int mid_left_idx = lower_bound(nums.begin() + i + 1, nums.end(), left * 2) - nums.begin();
            int mid_right_idx = upper_bound(nums.begin() + i + 1, nums.end(), (tot - left) / 2 + left) - nums.begin();
            // cout << "i: " << i << " mid_left_idx: " << mid_left_idx << " mid_right_idx: " << mid_right_idx << endl;

            ans = (ans + max(0, min(n - 1, mid_right_idx) - mid_left_idx)) % mod;
        };
        return ans;
    }
};