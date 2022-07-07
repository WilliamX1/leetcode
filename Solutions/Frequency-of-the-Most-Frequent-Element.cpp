class Solution
{
  public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int64_t left = 0, right = 0, ans = 1, n = nums.size();
        while (++right < n)
        {
            k -= (right - left) * (nums[right] - nums[right - 1]);
            while (k < 0)
                k += (int64_t)(nums[right] - nums[left++]);
            ans = max(ans, right - left + 1);
        };
        return ans;
    }
};