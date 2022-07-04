class Solution
{
  public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0, n = nums.size(), tot = 0, ans = 0x7fffffff;
        while (right < n)
        {
            while (right < n && (tot += nums[right]) < target)
                right++;
            while (left < n && (tot - nums[left]) >= target)
            {
                tot -= nums[left];
                left++;
            };
            if (tot >= target)
                ans = min(ans, right - left + 1);
            tot -= nums[left++];
            right++;
        };
        return ans == 0x7fffffff ? 0 : ans;
    }
};